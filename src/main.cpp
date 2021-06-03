#include "bird.hpp"
#include "definitions.hpp"
#include "displayingEvents.hpp"
#include "highscore.hpp"
#include "pause.hpp"
#include "pipe.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace sf;
using namespace std;

int main()
{

    // Create a window
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "fnf", Style::Close);
    window.setFramerateLimit(360);

    map<int, bool> markedPipes;

    // load flappy, pipes and background
    loadFlappy();
    loadPipe();
    Texture backgroundImage;
    backgroundImage.loadFromFile("assets/background.png");
    Sprite background(backgroundImage);

    // Create 3 txt files for each lvl if not created and write 0 in it, if created leave their values as it is
    txtHighscore();

    // Game Loop
    while (window.isOpen())
    {
        Event event;
        handleEvent(window, event, isPaused, isGameover);

        // Startscreen or if esc is pressed
        if (gameLevel == 0)
        {
            // reset
            pipeRate = 150, gap = 225, flappy.isAlive = 1;
            pipes.clear();
            flappy.x = 150, flappy.y = 200, flappy.velocity = 0;
            flappy.sprite.setPosition(flappy.x, flappy.y);

            // Displays Game Over Screen if isGameover flag is true
            if (isGameover)
            {
                displayGameover(window, score, userHighScore, isHighscore);
                if (event.key.code == Keyboard::Key::Escape)
                {
                    //stop sounds while playing if the user pressed the escape button
                    flappy.jump.stop();
                    flappy.collide.stop();
                    isGameover = false;
                    isHighscore = false;
                }
            }
            // Displays Main Menu Screen if isGameover flag is false
            else
            {
                displayMenu(window, score);
            }
        }
        else
        {
            // Start Game if isPaused flag is false
            if (!isPaused)
            {
                // stop sound
                flappy.collide.stop();

                // easy
                if (gameLevel == 1)
                {
                    pipeRate = 200;
                    gap = 250;
                }
                // medium
                if (gameLevel == 500)
                {
                    pipeRate = 150;
                    gap = 225;
                }
                // hard
                if (gameLevel == 999)
                {
                    pipeRate = 120;
                    gap = 200;
                }

                // generate pipes
                if (frames % pipeRate == 0)
                {
                    // dark magic
                    int random = rand() % 150 + 200;

                    // set position of new pipes
                    positionPipe(random, gap);

                    // push pipes to the vector
                    pipes.push_back(pipeDown.sprite);
                    pipes.push_back(pipeUp.sprite);

                    // clear map for scoring
                    markedPipes.clear();
                }

                // simulate moving
                for (auto itr = pipes.begin(); itr != pipes.end(); itr++)
                {
                    (*itr).move(-3, 0);
                }

                // remove pipes offscreen
                if (frames % 100 == 0)
                {
                    auto startIterator = pipes.begin();
                    auto endIterator = pipes.begin();

                    for (; endIterator != pipes.end(); endIterator++)
                    {
                        if ((*endIterator).getPosition().x > -104)
                        {
                            break;
                        }
                    }

                    pipes.erase(startIterator, endIterator);
                }

                // test collision
                for (auto i : pipes)
                {
                    float px, py, pw, ph;
                    float fx = flappy.sprite.getPosition().x, fy = flappy.sprite.getPosition().y;
                    float fw = 259.0 * flappy.sprite.getScale().x, fh = 253.0 * flappy.sprite.getScale().y; // bird width and high scaled

                    px = i.getPosition().x;
                    pw = 150 * i.getScale().x; // pipe width
                    if (i.getScale().y > 0)
                    {
                        py = i.getPosition().y;
                        ph = 800 * i.getScale().y; // pipe height
                    }
                    else
                    {
                        ph = -800 * i.getScale().y; // pipe height
                        py = i.getPosition().y - ph;
                    }

                    // check colliding and ground
                    if (isColliding(fx, fy, fw, fh, px, py, pw, ph) || hitGround(fy))
                    {
                        flappy.isAlive = false;
                        // Save Highscore
                        Highscore(score, userHighScore, gameLevel, isHighscore);
                    }
                }

                // stop game and return to main menu
                if (!flappy.isAlive)
                {
                    gameLevel = 0;
                    flappy.isAlive = 0;
                    flappy.collide.play();
                    isGameover = true;
                    continue;
                }

                // gravity effect
                if (flappy.isAlive)
                {
                    flappy.velocity += flappy.gravAcc;
                    flappy.sprite.move(0, flappy.velocity);
                }

                // draw bird and pipes

                window.clear();
                window.draw(background);
                displayScore(window, score);
                window.draw(flappy.sprite);

                for (auto i : pipes)
                {
                    window.draw(i);
                }
                window.display();
                // increment frames
                frames++;

                // Calculate Score
                for (int i = 0; i < pipes.size(); i++)
                {
                    // check if bird position exceeds pipe position + its scaled width
                    if (flappy.sprite.getPosition().x > pipes[i].getPosition().x + 150.0 * pipes[i].getScale().x && !markedPipes[i] && !markedPipes[i + 1])
                    {
                        score++;
                        markedPipes[i] = 1, markedPipes[i + 1] = 1;
                        break;
                    }
                }
            }
            // Pause Game if isPaused flag is true
            else
            {
                window.clear();
                window.draw(background);
                displayScore(window, score);
                window.draw(flappy.sprite);
                for (auto i : pipes)
                {
                    window.draw(i);
                }
                displayPause(window);
                window.display();
            }
        }
    }

    return 0;
}