#ifndef highscore_H
#define highscore_H
#include "definitions.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace sf;
using namespace std;

// Function to Read/Write highscore from file
void Highscore(int score, int& userHighScore)
{
	ifstream readFile;
	readFile.open("highscore.txt");
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			readFile >> userHighScore;
		}
	}
	readFile.close();
	ofstream writeFile("highscore.txt");
	if (writeFile.is_open())
	{
		if (score > userHighScore)
			userHighScore = score;

		writeFile << userHighScore;
	}
	writeFile.close();
}

// Function to display while playing the Game
void displayScore(RenderWindow& window, int score)
{
	Font font;
	font.loadFromFile("assets/font.ttf");
	Text userScore;
	string strUserScore = to_string(score);
	userScore.setFont(font);
	userScore.setOutlineThickness(3);
	userScore.setOutlineColor(Color::Black);
	userScore.setString(strUserScore);
	userScore.setCharacterSize(70);
	userScore.setFillColor(Color::White);
	userScore.setPosition(15, 0);
	window.draw(userScore);
}

#endif // highscore_H