#ifndef displayingEvents_H
#define displayingEvents_H
#include "bird.hpp"
#include "definitions.hpp"
#include <SFML/Audio.hpp>
#include "pause.hpp"
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace sf;
using namespace std;

// Function to handle Events
void handleEvent(RenderWindow& window, Event& event, bool& isPaused, bool& isGameover)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case Event::Closed:
				window.close();
				break;

			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Q))
					window.close();
				if (isGameover)
				{
					gameLevel = 0;
				}
				else
				{
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
					else if (Keyboard::isKeyPressed(Keyboard::P))
					{
						isPaused = !isPaused;
						playPauseSound();
					}
				}
				break;
			case Event::KeyReleased:
				if (event.key.code == Keyboard::Key::Up)
				{
					flappy.velocity = flappy.jumpAcc;
					flappy.sprite.move(0, flappy.velocity);
					if (gameLevel != 0)
						flappy.jump.play();
				}
				break;
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
void displayBackground(RenderWindow& window)
{
	Texture backgroundImage;
	backgroundImage.loadFromFile("assets/background.png");
	Sprite background(backgroundImage);
	window.draw(background);
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

// Function to display Menu and reset score
void displayMenu(RenderWindow& window, int& score)
{
	score = 0;
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

void displayBoard(RenderWindow& window)
{
	Texture boardImage;
	boardImage.loadFromFile("assets/board.png");
	Sprite board(boardImage);
	board.setPosition(WID - 270, HEI - 100);
	window.draw(board);
}

// Function to display Game over Screen
void displayGameover(RenderWindow& window, int score, int usrHighScore)
{
	window.clear();
	Font font;
	font.loadFromFile("assets/font.ttf");
	Text text, userScore, HighScore;
	text.setFont(font);
	text.setOutlineThickness(3);
	text.setOutlineColor(Color::Black);
	text.setString("Game Over");
	text.setCharacterSize(130);
	text.setFillColor(Color::White);
	text.setPosition(WID - 325, HEI - 300);

	// Display userScore on Game Over screen
	string strUserScore;
	if (score > 99)
	{
		strUserScore = to_string(score);
	}
	else if (score > 9)
	{
		strUserScore = "0" + to_string(score);
	}
	else if (score <= 9)
	{
		strUserScore = "00" + to_string(score);
	}
	userScore.setFont(font);
	userScore.setOutlineThickness(3);
	userScore.setOutlineColor(Color::Black);
	userScore.setString(strUserScore);
	userScore.setCharacterSize(100);
	userScore.setFillColor(Color::White);
	userScore.setPosition(WID - 200, HEI);

	// Display userHighScore on Game Over screen
	string strUserHighScore;
	if (usrHighScore > 99)
	{
		strUserHighScore = to_string(usrHighScore);
	}
	else if (usrHighScore > 9)
	{
		strUserHighScore = "0" + to_string(usrHighScore);
	}
	else if (usrHighScore <= 9)
	{
		strUserHighScore = "00" + to_string(usrHighScore);
	}
	HighScore.setFont(font);
	HighScore.setOutlineThickness(3);
	HighScore.setOutlineColor(Color::Black);
	HighScore.setString(strUserHighScore);
	HighScore.setCharacterSize(100);
	HighScore.setFillColor(Color::White);
	HighScore.setPosition(WID + 70, HEI);

	displayBackground(window);
	displayBoard(window);
	window.draw(text);
	window.draw(userScore);
	window.draw(HighScore);
	window.display();
}

#endif // displayingEvents_H
