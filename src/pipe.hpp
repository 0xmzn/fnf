#ifndef pipe_H
#define pipe_H
#include "definitions.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;
struct Pipe
{
    Texture texture;
    Sprite sprite;
};

Pipe pipeUp, pipeDown;
vector<Sprite> pipes;

void loadPipe()
{
    pipeUp.texture.loadFromFile("assets/pipe.png");
    pipeDown.texture.loadFromFile("assets/pipe.png");
    pipeUp.sprite.setTexture(pipeUp.texture);
    pipeDown.sprite.setTexture(pipeDown.texture);
}

void positionPipe(int random, int gap)
{
    pipeUp.sprite.setPosition(1000, random);
    pipeUp.sprite.setScale(0.5, -0.5);
    pipeDown.sprite.setPosition(1000, random + gap);
    pipeDown.sprite.setScale(0.5, 0.5);
}

#endif // pipe_H