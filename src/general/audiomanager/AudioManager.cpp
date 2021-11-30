#include "AudioManager.h"

const float standardVolume = 0.3f;

AudioManager::AudioManager()
{
	musicInited = false;

	soundBuffer.loadFromFile("BallCollision.wav");
	collisionSound.setBuffer(soundBuffer);

	menuMusic.openFromFile("MenuSong.wav");
	gameMusic.openFromFile("GameSong.wav");
}

AudioManager::~AudioManager()
{

}

void AudioManager::GetMenuMusic()
{	
	
}

void AudioManager::StopAllMusics()
{
	menuMusic.stop();
	gameMusic.stop();
}

void AudioManager::PlayMenuMusic()
{
	if (!menuMusic.getStatus())
	{
		menuMusic.play();
	}
}

void AudioManager::PlayGameMusic()
{
	gameMusic.play();
}

void AudioManager::PlayOptionSound()
{
	collisionSound.play();
}

