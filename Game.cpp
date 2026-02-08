#include "Game.h"
#include "funcs.h"



Game::Game(sf::RenderWindow& window, SoundManager& soundManager, sf::Font& font, int mapID) : window(window), soundManager(soundManager), font(font),
map(mapID, border), player(map, soundManager, window),  ghost1(map, soundManager), ghost2(map, soundManager),
score(font), highScore(font)
{


    delayTime = 0.f;
    timerTime = 0.f;

    //scoreSize = ((window.getSize().x / 4.f) - 20);

    //never changes
    //gridLines = drawGrid(window, tileSize);


    arena.setSize({ tileSize * (board_cell_width), tileSize * (board_cell_height) });

    arena.setPosition({ width / 2.f, height / 2.f });
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
        player.move();

        delayClock.restart();
    }
}

void Game::init() {
    timerClock.restart();

    moveSpeed = .03f; //smaller it gets, faster the player moves

    player.position = { tileSize * 16, tileSize * 25 }; //start point
    player.shape.setPosition(sf::Vector2f(player.position));
    //player.Psprite.setPosition(sf::Vector2f(player.position));
    

    player.score = 0;

    highScore.setString("HIGHSCORE: 0000");

    highScore.setPosition({ border.right_pos - highScore.getGlobalBounds().size.x, 0 }); //sağa yatık
    //highScore.setPosition({ score.getGlobalBounds().size.x + 100, 0 }); // sola yatık

    map.load();

    std::cout << "Game Initilized :: Took, " << timerClock.getElapsedTime().asSeconds() << "s ." << std::endl;

    //player.Psprite.setTexture(map.pelletTexture);
    

}

void Game::update() {
    soundManager.generalPlay();

    timerTime = timerClock.getElapsedTime().asSeconds();
    delayTime = delayClock.getElapsedTime().asSeconds();

    //std::cout << "TOTAL TIME: " << timer_time << std::endl;

	inputSystem();
    //GHOST MOVEMENT

    score.setString("SCORE: " + std::to_string(player.score));
    score.setPosition({ border.left_pos, 0 });

    if (0 == map.remainingPellet) {
        std::cout << "[GAME] : MAP CLEARED" << std::endl;

        for (int i = 0; i < board_cell_height * board_cell_width; i++) {
            if(Wall == map.checkCellbyTile( {i % board_cell_width, i / board_cell_width}))
                map.tileVector[i].setTexture(map.testTexture);
        }
    }

    
}

void Game::render() {
    window.clear(bgColor);

    window.draw(arena);

    for (auto& tile : map.tileVector) {
        window.draw(tile);
    }
    
    //window.draw(ghost1.shape);
    //window.draw(ghost2.shape);

    window.draw(ghost1.sprite);

    window.draw(player.shape);

    //window.draw(gridLines);

    window.draw(score);
    window.draw(highScore);

    window.display();
}

