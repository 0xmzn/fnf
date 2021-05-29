#ifndef bird_H
#define bird_H
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

struct Flappy
{
	float x = 150, y = 200, velocity = 0;
	bool isAlive = 1;
	const float gravAcc = 0.004;
	const float jumpAcc = -1;
	Sprite sprite;
	Texture texture[3];
};

Flappy flappy;

void loadFlappy() {

	flappy.texture[0].loadFromFile("assets/bird.png");
	flappy.texture[1].loadFromFile("assets/bird.png");
	flappy.texture[2].loadFromFile("assets/bird.png");
	flappy.sprite.setScale(2, 2);
	flappy.sprite.setTexture(flappy.texture[1]);
	flappy.sprite.setPosition(flappy.x, flappy.y);
}
#endif // bird_H