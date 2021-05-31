#ifndef bird_H
#define bird_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

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

void loadFlappy()
{

	flappy.texture[0].loadFromFile("assets/gnu.png");
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