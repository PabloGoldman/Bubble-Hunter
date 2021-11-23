#pragma once
#include "SFML/Audio.hpp"

class AudioManager
{
private:
	sf::Music menuMusic;
	sf::Music gameMusic;
	sf::Sound optionSound;

	bool menuMusicInited;
	bool gameMusicInited;
	bool optionSoundInited;

	bool musicInited;

public:
	AudioManager();
	~AudioManager();

	void InitMusic(sf::Music music);

	void GetMenuMusic();
	void StopAllMusics();
	void PlayMenuMusic();
	void PlayGameMusic();
	void PlayOptionSound();

};

