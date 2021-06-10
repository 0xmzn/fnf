#ifndef highscore_H
#define highscore_H
#include "definitions.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace sf;
using namespace std;

// Create 3 txt files for each lvl if not created and write 0 in it, if created leave their values as it is
void txtHighscore()
{

    bool lvlEasy = true, lvlMedium = true, lvlHard = true;

    // r/w into .easy.txt 
    ifstream readFileEasy;
    readFileEasy.open(".easy.txt");
    if (readFileEasy.is_open())
    {
        int userHighScore = 0;
        while (!readFileEasy.eof())
        {
            readFileEasy >> userHighScore;
        }
        if (userHighScore > 0)
            lvlEasy = false;
    }
    readFileEasy.close();

    if (lvlEasy)
    {
        ofstream writeFileEasy(".easy.txt");
        if (writeFileEasy.is_open())
        {
            int userHighScore = 0;
            writeFileEasy << userHighScore;
        }
        writeFileEasy.close();
    }

    // r/w into .medium.txt
    ifstream readFileMedium;
    readFileMedium.open(".medium.txt");
    if (readFileMedium.is_open())
    {
        int userHighScore = 0;
        while (!readFileMedium.eof())
        {
            readFileMedium >> userHighScore;
        }
        if (userHighScore > 0)
            lvlMedium = false;
    }
    readFileMedium.close();

    if (lvlMedium)
    {
        ofstream writeFileMedium(".medium.txt");
        if (writeFileMedium.is_open())
        {
            int userHighScore = 0;
            writeFileMedium << userHighScore;
        }
        writeFileMedium.close();
    }

    // r/w into .hard.txt
    ifstream readFileHard;
    readFileHard.open(".hard.txt");
    if (readFileHard.is_open())
    {
        int userHighScore = 0;
        while (!readFileHard.eof())
        {
            readFileHard >> userHighScore;
        }
        if (userHighScore > 0)
            lvlHard = false;
    }
    readFileHard.close();

    if (lvlHard)
    {
        ofstream writeFileHard(".hard.txt");
        if (writeFileHard.is_open())
        {
            int userHighScore = 0;
            writeFileHard << userHighScore;
        }
        writeFileHard.close();
    }
}

// Function to Read/Write highscore from file for each game lvl
void Highscore(int score, int &userHighScore, string gameLevel, bool &isHighscore)
{
    // Easy
    if (gameLevel == gameStates[0])
    {

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
            if (score > userHighScore)
            {
                userHighScore = score;
                isHighscore = true;
            }

            writeFile << userHighScore;
        }
        writeFile.close();
    }
    // Medium
    if (gameLevel == gameStates[1])
    {

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
            if (score > userHighScore)
            {
                userHighScore = score;
                isHighscore = true;
            }

            writeFile << userHighScore;
        }
        writeFile.close();
    }
    // Hard
    if (gameLevel == gameStates[2])
    {

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
            if (score > userHighScore)
            {
                userHighScore = score;
                isHighscore = true;
            }

            writeFile << userHighScore;
        }
        writeFile.close();
    }
}

// Function to display while playing the Game
void displayScore(RenderWindow &window, int score)
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