#pragma once
#include "SFML/Audio.hpp"

class AudioManager
{
private:
	sf::SoundBuffer soundBuffer;
	sf::Sound collisionSound;

	sf::Music menuMusic;
	sf::Music gameMusic;



	bool menuMusicInited;
	bool gameMusicInited;
	bool optionSoundInited;

	bool musicInited;

public:
	AudioManager();
	~AudioManager();

	void GetMenuMusic();
	void StopAllMusics();
	void PlayMenuMusic();
	void PlayGameMusic();
	void PlayOptionSound();

};

