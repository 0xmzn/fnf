#include "bird.hpp"
#include "displayingEvents.hpp"
#include "pipe.hpp"
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace sf;
using namespace std;

int main()
{
	// Create a window
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "fnf", Style::Default);
	window.setFramerateLimit(360);

	// Load flappy and pipe
	loadFlappy();
	loadPipe();

	// Game Loop
	while (window.isOpen())
	{
		Event event;
		handleEvent(window, event);

		// Startscreen or if esc is pressed

		if (gameLevel == 0)
		{
			displayMenu(window);
		}

		// Case easy
		if (gameLevel == 1)
		{
			// displayBackground(window); --> doesnt work?
			// generate pipes
			if (frames % 150 == 0)
			{
				// dark magic
				int random = rand() % 100 + 250, gap = 150;

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

			for (auto i : pipes)
			{

				float px, py, pw, ph;

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

				if (isColliding(flappy.sprite.getPosition().x, flappy.sprite.getPosition().y, flappy.sprite.getScale().x, flappy.sprite.getScale().y, px, py, pw, ph))
				{
					flappy.isAlive = false;
				}
			}

			if (flappy.sprite.getPosition().y >= 700 || !flappy.isAlive)
			{
				flappy.isAlive = 0;
				//	add gameOver screen
				break;
			}

			// gravity effect
			if (flappy.isAlive)
			{
				flappy.velocity += flappy.gravAcc;
				flappy.sprite.move(0, flappy.velocity);
			}

			// draw bird and pipes

			window.clear();
			window.draw(flappy.sprite);

			for (auto i : pipes)
			{
				window.draw(i);
			}

			window.display();

			// increment frames
			frames++;
		}
	}

	return 0;
}
