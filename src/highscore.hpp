#ifndef highscore_H
#define highscore_H
#include "definitions.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace sf;
using namespace std;

// Create 3 txt files for each lvl if not created and write 0 in it, if created reset their values
void txtHighscore(){

	ofstream writeFileEasy(".easy.txt");
	if (writeFileEasy.is_open())
		{
			int userHighScore = 0;
			writeFileEasy << userHighScore;
		}
		writeFileEasy.close();

	ofstream writeFileMedium(".medium.txt");
	if (writeFileMedium.is_open())
		{
			int userHighScore = 0;
			writeFileMedium << userHighScore;
		}
		writeFileMedium.close();

	ofstream writeFileHard(".hard.txt");
	if (writeFileHard.is_open())
		{
			int userHighScore = 0;
			writeFileHard << userHighScore;
		}
		writeFileHard.close();

}

// Function to Read/Write highscore from file for each game lvl
void Highscore(int score, int& userHighScore, int gameLevel, bool &isHighscore)
{
	if(gameLevel == 1){

		ifstream readFile;
		readFile.open(".easy.txt");

		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> userHighScore;
			}
		}
		readFile.close();

		ofstream writeFile(".easy.txt");
		if (writeFile.is_open())
		{
			if (score > userHighScore){
				userHighScore = score;
				isHighscore = true;
			}

			writeFile << userHighScore;
		}
		writeFile.close();
	}

	if(gameLevel == 500){

		ifstream readFile;
		readFile.open(".medium.txt");

		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> userHighScore;
			}
		}
		readFile.close();

		ofstream writeFile(".medium.txt");
		if (writeFile.is_open())
		{
			if (score > userHighScore){
				userHighScore = score;
				isHighscore = true;
			}

			writeFile << userHighScore;
		}
		writeFile.close();
	}

	if(gameLevel == 999){

		ifstream readFile;
		readFile.open(".hard.txt");

		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> userHighScore;
			}
		}
		readFile.close();

		ofstream writeFile(".hard.txt");
		if (writeFile.is_open())
		{
			if (score > userHighScore){
				userHighScore = score;
				isHighscore = true;
			}

			writeFile << userHighScore;
		}
		writeFile.close();
	}
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