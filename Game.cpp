#include "Game.h"
#include "funcs.h"

constexpr sf::Color bgColor = { 123,50,230 };


Game::Game(sf::RenderWindow& window, int mapID) : window(window),
map(mapID, border), player(map),  ghost1(map), ghost2(map),
font("./Fonts/alagard.ttf"),
score(font, "SCORE: ", 123), highScore(font, "HIGHSCORE: ", 123)
{

    delayTime = 0.f;
    timerTime = 0.f;

    //never changes
    gridLines = drawGrid(window, tile_size);

    arena.setSize({ tile_size * (board_cell_width), tile_size * (board_cell_height) });

    arena.setPosition({ width / 2.f, height / 2.f });
    arena.setOrigin(arena.getGeometricCenter());

    arena.setFillColor(sf::Color::Black);

    border.up_pos    = arena.getGlobalBounds().getCenter().y - arena.getSize().y / 2.f;
    border.down_pos  = arena.getGlobalBounds().getCenter().y + arena.getSize().y / 2.f;
    border.right_pos = arena.getGlobalBounds().getCenter().x + arena.getSize().x / 2.f;
    border.left_pos  = arena.getGlobalBounds().getCenter().x - arena.getSize().x / 2.f;


    player.texture.loadFromFile("./Sprites/Pacman.png");
}


void Game::inputSystem() {


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

    if (timerTime >= 3.f) {
        player.move();

        delayClock.restart();
    }
}

void Game::init() {
    timerClock.restart();

    moveSpeed = .03f; //smaller it gets faster player moves

    player.position = { tile_size * 16, tile_size * 25 }; //start point
    player.shape.setPosition(sf::Vector2f(player.position));

    player.score = 0;
    player.pelletCount = 0;

    map.load();

    //music


    std::cout << "Game Initilized :: Took, " << timerClock.getElapsedTime().asSeconds() << "s ." << std::endl;
}

void Game::update() {
    timerTime = timerClock.getElapsedTime().asSeconds();
    delayTime = delayClock.getElapsedTime().asSeconds();

    //std::cout << "TOTAL TIME: " << timer_time << std::endl;

	inputSystem();
    //GHOST MOVEMENT
}

void Game::render() {
    window.clear(bgColor);

    window.draw(arena);

    for (auto& tile : map.tileVector) {
        window.draw(tile);
    }
    
    window.draw(ghost1.shape);
    window.draw(ghost2.shape);

    window.draw(player.shape);
    //window.draw(player.sprite);

    //window.draw(grid_lines);

    window.display();
}