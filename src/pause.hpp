#ifndef pause_H
#define pause_H
#include "bird.hpp"
#include "definitions.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

// Function to display Pause Screen
void displayPause(RenderWindow& window)
{
	Font font;
	font.loadFromFile("assets/font.ttf");
	Text pause;
	pause.setFont(font);
	pause.setOutlineThickness(5);
	pause.setOutlineColor(Color::Black);
	pause.setString("Game Paused");
	pause.setCharacterSize(130);
	pause.setFillColor(Color::White);
	pause.setPosition(WID - 410, HEI - 300);
	window.draw(pause);
}

void playPauseSound()
{
	SoundBuffer resumeBuffer, pauseBuffer;
	Sound resume, pause;
	pauseBuffer.loadFromFile("audio/pause.wav");
	resumeBuffer.loadFromFile("audio/resume.wav");
	pause.setBuffer(pauseBuffer);
	resume.setBuffer(resumeBuffer);
	flappy.jump.stop(); // dont mix sounds
	if (isPaused)
	{
		resume.stop();
		pause.play();
	}
	else
	{
		pause.stop();
		resume.play();
	}
}

#endif // pipe_H