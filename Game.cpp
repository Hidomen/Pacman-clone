#include "Game.h"
#include "funcs.h"



Game::Game(sf::RenderWindow& window, SoundManager& soundManager, sf::Font& font, int mapID) : window(window), soundManager(soundManager), font(font),
map(mapID, border), player(map, soundManager, window),  
ghost1(map, soundManager), ghost2(map, soundManager), ghost3(map, soundManager), ghost4(map, soundManager),
playerSprite(window, EntityType::Player),
score(font), highScore(font)
{
    delayTime = 0.f;
    timerTime = 0.f;

    //scoreSize = ((window.getSize().x / 4.f) - 20);

    entityList.push_back(&player);
    entityList.push_back(&ghost1);
    entityList.push_back(&ghost2);
    entityList.push_back(&ghost3);
    entityList.push_back(&ghost4);

    arena.setSize({ tileSize * (board_cell_width), tileSize * (board_cell_height) });

    arena.setPosition({ window_width / 2.f, window_height / 2.f });
    arena.setOrigin(arena.getGeometricCenter());

    arena.setFillColor(sf::Color::Black);

    border.up_pos    = arena.getGlobalBounds().getCenter().y - arena.getSize().y / 2.f;
    border.down_pos  = arena.getGlobalBounds().getCenter().y + arena.getSize().y / 2.f;
    border.right_pos = arena.getGlobalBounds().getCenter().x + arena.getSize().x / 2.f;
    border.left_pos  = arena.getGlobalBounds().getCenter().x - arena.getSize().x / 2.f;

    score.setCharacterSize(40);
    score.setFillColor(sf::Color::Black);

    highScore.setCharacterSize(40);
    highScore.setFillColor(sf::Color::Black);

    highScore.setString("HIGHSCORE: 0000");

    highScore.setPosition({ border.right_pos - highScore.getGlobalBounds().size.x, 0 }); //sağa yatık
    //highScore.setPosition({ score.getGlobalBounds().size.x + 100, 0 }); // sola yatık


    //map = new Map(1, border);

}


void Game::inputSystem() {
    //debugging
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::U)) {
        moveSpeed += 0.20f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::J)) {
        moveSpeed -= 0.20f;
    }
    //

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {

        player.changeDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {

        player.changeDirection(Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {

        player.changeDirection(Direction::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {

        player.changeDirection(Direction::Right);
    }
    
    if (moveSpeed > delayTime) return;


    //very first start of the game
    if (timerTime >= soundManager.startDuration) {
        
        movement();

        delayClock.restart();
    }
}

bool Game::checkEntityCollision(Entity entity) {
    //return false; //for debug

    for (int i = 0; i < entityList.size(); i++) {
        //if (entityList[i]->shape.getGlobalBounds().contains(nextStep)) {
        if (entityList[i]->position == entity.nextStep) {
            std::cout << "COLLİSİONNN" << std::endl;

            return true;
        }
    }

    return false;
}

void Game::movement() {
    for (auto e : entityList) {
        if (EntityType::Ghost == e->entityType) {
            e->changeDirection(static_cast<Direction>(rand() % 4));
        }
    }

    for (auto e : entityList) {
        if (EntityType::Player == e->entityType && map.isOnGrid(e->position)) {
            player.pellet();
        }
        e->computeNextPosition();
    }

    for (auto e : entityList) {
        if (!checkEntityCollision(*e)) { // true -> collides
            
            e->applyMovement();
        }
        else {
            e->applyMovement();

            if (EntityType::Player == e->entityType) {
                gameOver();
            }
        }
    }
}

void Game::init() {
    timerClock.restart();

    moveSpeed = .03f; //smaller it gets, faster the player moves

    setupEntities();
    setupMap();

    player.score = 0;

    std::cout << "Game Initilized :: Took, " << timerClock.getElapsedTime().asSeconds() << "s ." << std::endl;
}

void Game::update() {
    soundManager.generalPlay();

    timerTime = timerClock.getElapsedTime().asSeconds();
    delayTime = delayClock.getElapsedTime().asSeconds();

    //std::cout << "TOTAL TIME: " << timerTime << std::endl;
	
    inputSystem(); 

    score.setString("SCORE: " + std::to_string(player.score));
    score.setPosition({ border.left_pos, 0 });


    if (0 == map.remainingPellet) {
        std::cout << "[GAME] : MAP CLEARED" << std::endl;

        for (int i = 0; i < board_cell_height * board_cell_width; i++) {
            if(Wall == map.checkCellbyTile( {i % board_cell_width, i / board_cell_width}))
                map.tileVector[i].setTexture(map.testTexture);
        }

        setupEntities();
        setupMap();

    }

    playerSprite.sprite.setPosition(player.position);
}

void Game::setupMap() {
    map.tileVector.clear();
    map.load();
}

void Game::setupEntities() {
    
    timerClock.restart();
    delayClock.restart();

    soundManager.statePlay(MenuState::InGame);

    player.position = { tileSize * 15.5, tileSize * 25 }; //start point
    player.shape.setPosition(player.position);
    //player.entityDirection = Direction::Left;
    player.nextDirection = Direction::Left;

    ghost1.position = { tileSize * 3, tileSize * 3 }; //start point
    ghost1.shape.setPosition(sf::Vector2f(ghost1.position));
    ghost1.targetPosition = ghost1.position;

    ghost2.position = { tileSize * 9, tileSize * 3 };
    ghost2.shape.setPosition(ghost2.position);
    ghost2.targetPosition = ghost2.position;

    ghost3.position = { tileSize * 7, tileSize * 3 };
    ghost3.shape.setPosition(ghost3.position);
    ghost3.targetPosition = ghost3.position;

    ghost4.position = { tileSize * 5, tileSize * 3 };
    ghost4.shape.setPosition(ghost4.position);
    ghost4.targetPosition = ghost4.position;

}

void Game::gameOver() {
    if (0 == player.health) {
        //ITS OVER
    }
    //otherwise
    setupEntities();
    
}

void Game::render() {
    window.clear(bgColor);

    window.draw(arena);

    for (auto& tile : map.tileVector) {
        window.draw(tile);
    }
    
    window.draw(ghost1.shape);
    window.draw(ghost2.shape);
    window.draw(ghost3.shape);
    window.draw(ghost4.shape);

    window.draw(player.shape);

    //window.draw(gridLines);
    playerSprite.render();

    window.draw(score);
    window.draw(highScore);

    window.display();
}

