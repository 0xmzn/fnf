#ifndef pipe_H
#define pipe_H
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

bool isColliding(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	if (x1 + w1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 <= y2 + h2)
	{
		return true;
	}
	return false;
}

struct Pipe
{
	Texture texture;
	Sprite sprite;
};

Pipe pipeUp, pipeDown;
vector<Sprite> pipes;

void loadPipe()
{
	pipeUp.texture.loadFromFile("../assets/pipe.png");
	pipeDown.texture.loadFromFile("../assets/pipe.png");
	pipeUp.sprite.setTexture(pipeUp.texture);
	pipeDown.sprite.setTexture(pipeDown.texture);
}

void(positionPipe(int random, int gap))
{
	pipeUp.sprite.setPosition(1000, random);
	pipeUp.sprite.setScale(0.5, -0.5);
	pipeDown.sprite.setPosition(1000, random + gap);
	pipeDown.sprite.setScale(0.5, 0.5);
}

#endif // pipe_H