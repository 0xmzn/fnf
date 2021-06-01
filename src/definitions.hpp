#ifndef definitions_H
#define definitions_H

const unsigned int WIDTH = 1024;
const unsigned int HEIGHT = 768;
const unsigned int WID = 512;
const unsigned int HEI = 384;
int frames = 0;
int pipeRate = 150;
int gap = 225;
int gameLevel = 0; // 1 --> easy | 500 --> medium | 999 --> hard
int score = 0;
int userHighScore = 0;
bool isGameover = false;
bool isPaused = false;

#endif // definitions_H