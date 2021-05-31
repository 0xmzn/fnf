#ifndef displayingEvents_H
#define displayingEvents_H
#include "bird.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

const unsigned int WIDTH = 1024;
const unsigned int HEIGHT = 768;
const float WID = 512;
const float HEI = 384;
int frames = 0;
int gameLevel = 0; // 1 --> easy | 500 --> medium | 999 --> hard

// Function to handle Events
void handleEvent(RenderWindow& window, Event& event, bool& isPaused)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::E))
					gameLevel = 1;
				else if (Keyboard::isKeyPressed(Keyboard::M))
					gameLevel = 500;
				else if (Keyboard::isKeyPressed(Keyboard::H))
					gameLevel = 999;
				else if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					gameLevel = 0;
					isPaused = false;
				}
				else if (Keyboard::isKeyPressed(Keyboard::Q))
					window.close();
				else if (Keyboard::isKeyPressed(Keyboard::P))
					isPaused = !isPaused;
				break;
			case Event::KeyReleased:
				if (event.key.code == Keyboard::Key::Up)
				{

					flappy.velocity = flappy.jumpAcc;
					flappy.sprite.move(0, flappy.velocity);
					flappy.jump.play();
					break;
				}
		}
	}
}

// Fuction to display the Title in the Main Menu
void displayTitle(RenderWindow& window)
{
	Font font;
	font.loadFromFile("assets/font.ttf");
	Text title;
	title.setFont(font);
	title.setOutlineThickness(5);
	title.setOutlineColor(Color::Black);
	title.setString("FLAPPY BIRD");
	title.setCharacterSize(130);
	title.setFillColor(Color::White);
	title.setPosition(WID - 365, HEI - 300);
	window.draw(title);
}

// Function to display Background
// We could add a string parameter to the function to chose which background to draw
void displayBackground(RenderWindow& window)
{
	Texture backgroundImage;
	backgroundImage.loadFromFile("assets/background.png");
	Sprite background(backgroundImage);
	window.draw(background);
}

// Function to display Pause Screen
void displayPause(RenderWindow& window)
{
	Font font;
	font.loadFromFile("assets/font.ttf");
	Text pause;
	pause.setFont(font);
	pause.setOutlineThickness(5);
	pause.setOutlineColor(Color::Black);
	pause.setString("Game Paused");
	pause.setCharacterSize(130);
	pause.setFillColor(Color::White);
	pause.setPosition(WID - 410, HEI - 300);
	window.draw(pause);
}

// Function to display the bird in the main menu
void displayIntroBird(RenderWindow& window)
{
	Texture bird;
	bird.loadFromFile("assets/gnu.png");
	Sprite flappyBird(bird);
	flappyBird.setPosition(WID - 50, HEI + 200);
	flappyBird.setScale(0.5f, 0.5f);
	window.draw(flappyBird);
}

// Function to display Menu
void displayMenu(RenderWindow& window)
{
	window.clear();
	Font font;
	font.loadFromFile("assets/font.ttf");
	Text text;
	text.setFont(font);
	text.setOutlineThickness(3);
	text.setOutlineColor(Color::Black);
	text.setString("  E FOR EASY\n\nM FOR MEDIUM\n\n  H FOR HARD");
	text.setCharacterSize(50);
	text.setFillColor(Color::White);
	text.setPosition(WID - 170, HEI - 100);
	displayBackground(window);
	displayTitle(window);
	displayIntroBird(window);
	window.draw(text);
	window.display();
}

// Function to display Game over Screen
void displayGameover(RenderWindow& window)
{
	window.clear();
	Font font;
	font.loadFromFile("assets/font.ttf");
	Text text;
	text.setFont(font);
	text.setOutlineThickness(3);
	text.setOutlineColor(Color::Black);
	text.setString("Game Over");
	text.setCharacterSize(130);
	text.setFillColor(Color::White);
	text.setPosition(WID - 330, HEI - 300);
	displayBackground(window);
	window.draw(text);
	window.display();
}

#endif // displayingEvents_H
