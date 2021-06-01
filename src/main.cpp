#include "bird.hpp"
#include "displayingEvents.hpp"
#include "pipe.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace sf;
using namespace std;

bool isGameover = false;
bool isPaused = false;
int main()
{
	int score = 0;
	int userHighScore = 0;
	// Create a window
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "fnf", Style::Close);
	window.setFramerateLimit(360);
	Texture backgroundImage;
	backgroundImage.loadFromFile("assets/background.png");
	Sprite background(backgroundImage);

	// Load flappy and pipe
	loadFlappy();
	loadPipe();

	int frameRate = 150, gap = 225; // default

	// Game Loop
	while (window.isOpen())
	{
		Event event;
		handleEvent(window, event, isPaused, isGameover);

		// Startscreen or if esc is pressed
		if (gameLevel == 0)
		{
			// reset
			frameRate = 150, gap = 225, flappy.isAlive = 1;
			pipes.clear();
			flappy.x = 150, flappy.y = 200, flappy.velocity = 0;
			flappy.sprite.setPosition(flappy.x, flappy.y);
		
			// Save Highscore
			Highscore(score, userHighScore);
		
			// Displays Game Over Screen if isGameover flag is true
			if (isGameover)
			{
				displayGameover(window, score, userHighScore);
				if(event.key.code == Keyboard::Key::Escape)
				{
					isGameover = false;
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
					frameRate = 200;
					gap = 250;
				}
				// medium
				if (gameLevel == 500)
				{
					frameRate = 150;
					gap = 225;
				}
				// hard
				if (gameLevel == 999)
				{
					frameRate = 120;
					gap = 200;
				}

				// generate pipes
				if (frames % frameRate == 0)
				{
					// dark magic
					int random = rand() % 150 + 200;

					// set position of new pipes
					positionPipe(random, gap);

					// push pipes to the vector
					pipes.push_back(pipeDown.sprite);
					pipes.push_back(pipeUp.sprite);
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

					if (isColliding(fx, fy, fw, fh, px, py, pw, ph))
					{
						flappy.isAlive = false;
					}
				}

				// stop game and return to main menu
				if (flappy.sprite.getPosition().y >= 700 || !flappy.isAlive)
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
				for (auto i : pipes)
				{
					if (i.getPosition().x == 250)
					{
						score++;
						cout << score << endl;
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