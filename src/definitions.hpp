#ifndef definitions_H
#define definitions_H
#include <string>
const unsigned int WIDTH = 1024;
const unsigned int HEIGHT = 768;
const unsigned int WID = 512;
const unsigned int HEI = 384;
int frames = 0;
int pipeRate = 150;
int gap = 225;
int score = 0;
int userHighScore = 0;
bool isGameover = false;
bool isPaused = false;
bool isMuted = false;
bool isHighscore = false;
bool highscoreSoundPlayed = false;
bool pauseSoundPlayed = false;
bool checkedHighscore = false;
bool firstTime = false;
std::string gameStates[] = {"Easy", "Medium", "Hard", "Over"};
std::string gameLevel = gameStates[3]; // startscreen

#endif // definitions_H