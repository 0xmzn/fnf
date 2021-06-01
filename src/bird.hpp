#ifndef bird_H
#define bird_H
#include "definitions.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
struct Flappy
{
	float x = 150, y = 200, velocity = 0;
	bool isAlive = 1;
	const float gravAcc = 0.010;
	const float jumpAcc = -1;
	Sprite sprite;
	SoundBuffer jumpBuffer, collideBuffer;
	Sound jump, collide;
	Texture texture[3];
};

Flappy flappy;

bool isColliding(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	if (x1 + w1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 <= y2 + h2)
		return true;
	return false;
}

bool hitGround(float y)
{
	if (y >= 692.0)
		return true;
	return false;
}

void loadFlappy()
{
	flappy.texture[0].loadFromFile("assets/gnu.png"); // add animation
	flappy.texture[1].loadFromFile("assets/gnu.png");
	flappy.texture[2].loadFromFile("assets/gnu.png");
	flappy.sprite.setScale(0.3f, 0.3f);
	flappy.sprite.setTexture(flappy.texture[1]);
	flappy.sprite.setPosition(flappy.x, flappy.y);
	flappy.jumpBuffer.loadFromFile("audio/flap.wav");
	flappy.jump.setBuffer(flappy.jumpBuffer);
	flappy.collideBuffer.loadFromFile("audio/gameover.wav");
	flappy.collide.setBuffer(flappy.collideBuffer);
}
#endif // bird_H