#include "game.hpp"
#include "dbg.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

void Game::Run()
{
    debug("starting game");

    // C64 screen resolution
    float virtual_screen_width = 320.0f;
    float virtual_screen_height = 200.0f;
    string window_title = "Liberty Space Invaders C64";

    sf::VideoMode video_mode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow render_window(video_mode, window_title, sf::Style::Default);

    sf::View viewport(sf::FloatRect(0.f, 0.f, virtual_screen_width, virtual_screen_height));
    render_window.setView(viewport);

    render_window.setMouseCursorVisible(false);
    render_window.setVerticalSyncEnabled(true);

    // setup delta time
    sf::Clock delta_clock;
    sf::Time deltaTime = delta_clock.restart();

    // load a background to test window creation and scaling
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    backgroundTexture.loadFromFile("media/backgrounds/background.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    // The main loop - ends as soon as the window is closed
    while (render_window.isOpen())
    {
        //****************************************
        // handle player input
        //****************************************
        sf::Event event;
        while (render_window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
            {
                render_window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            render_window.close();
        }

        //****************************************
        // update game objects
        //****************************************

        deltaTime = delta_clock.restart();

        //****************************************
        // draw screen
        //****************************************
        render_window.clear();

        render_window.draw(backgroundSprite);

        render_window.display();
    }
    return;
}