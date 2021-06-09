#ifndef displayingEvents_H
#define displayingEvents_H
#include "bird.hpp"
#include "definitions.hpp"
#include <SFML/Audio.hpp>
#include "pause.hpp"
#include "bird.hpp"
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace sf;
using namespace std;

// Function to handle Events
void handleEvent(RenderWindow &window, Event &event, bool &isPaused, bool &isGameover)
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window.close();
            break;
        // Toggle Deafen
        case Event::KeyPressed:
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                isMuted = !isMuted;
                if (isMuted)
                {
                    flappy.collide.setVolume(0);
                    flappy.flap.setVolume(0);
                    flappy.highscoreSound.setVolume(0);
                    flappy.pauseSound.setVolume(0);
                }
                else
                {
                    flappy.collide.setVolume(100);
                    flappy.flap.setVolume(10);
                    flappy.highscoreSound.setVolume(100);
                    flappy.pauseSound.setVolume(100);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Q))
                window.close();
            if (isGameover)
            {
                gameLevel = gameStates[3]; // Over
            }
            else
            {
                if (Keyboard::isKeyPressed(Keyboard::E))
                    gameLevel = gameStates[0]; // Easy
                else if (Keyboard::isKeyPressed(Keyboard::M))
                    gameLevel = gameStates[1]; // Medium
                else if (Keyboard::isKeyPressed(Keyboard::H))
                    gameLevel = gameStates[2]; // Hard
                else if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    gameLevel = gameStates[3]; // Over
                    flappy.highscoreSound.stop(); // stop high score sound if it was playing
                    isPaused = false;
                }
                else if (Keyboard::isKeyPressed(Keyboard::P))
                {
                    isPaused = !isPaused;
                }
            }
            break;
        case Event::KeyReleased:
            if (event.key.code == Keyboard::Key::Up)
            {   
                // if isPaused and IsGameover flags are true ignore the Up command
                if (!isPaused && !isGameover)
                {
                    flappy.velocity = flappy.jumpAcc;
                    // Prevent going out of frame
                    if (flappy.sprite.getPosition().y + flappy.velocity < 0)
                        flappy.sprite.move(0, -flappy.sprite.getPosition().y);
                    else
                        flappy.sprite.move(0, flappy.velocity);

                    flappy.flap.play();
                }
            }
            break;
        }
    }
}

// Fuction to display the Title in the Main Menu
void displayTitle(RenderWindow &window)
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
void displayBackground(RenderWindow &window)
{
    Texture backgroundImage;
    backgroundImage.loadFromFile("assets/background.png");
    Sprite background(backgroundImage);
    window.draw(background);
}

// Function to display the bird in the main menu
void displayIntroBird(RenderWindow &window)
{
    Texture bird;
    bird.loadFromFile("assets/bird-mid.png");
    Sprite flappyBird(bird);
    flappyBird.setPosition(WID - 35, HEI + 200);
    flappyBird.setScale(2.5f, 2.5f);
    window.draw(flappyBird);
}

// Function to display Menu and reset score
void displayMenu(RenderWindow &window, int &score)
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

void displayBoard(RenderWindow &window)
{
    Texture boardImage;
    boardImage.loadFromFile("assets/board.png");
    Sprite board(boardImage);
    board.setPosition(WID - 270, HEI - 100);
    window.draw(board);
}

// Function to display Game over Screen
void displayGameover(RenderWindow &window, int score, int usrHighScore, bool isHighscore)
{
    window.clear();
    Font font;
    font.loadFromFile("assets/font.ttf");
    Text text, userScore, HighScore;
    text.setFont(font);
    text.setOutlineThickness(3);
    text.setOutlineColor(Color::Black);
    text.setFillColor(Color::White);

    //High Score splash screen if there is a new high score
    if (isHighscore)
    {
        text.setString("New High Score!");
        text.setCharacterSize(100);
        text.setPosition(WID - 395, HEI - 300);
    }
    else
    {
        text.setString("Game Over");
        text.setCharacterSize(130);
        text.setPosition(WID - 325, HEI - 300);
    }

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
