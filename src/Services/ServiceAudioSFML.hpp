#ifndef DEF_SERVICEAUDIOSFML_HPP
#define DEF_SERVICEAUDIOSFML_HPP

#include <SFML/Audio.hpp>

#include "IAudio.hpp"

class ServiceAudioSFML : public IAudio
{
private:
	sf::Music m_music;

public:
	void playSound( int soundID );
	void stopSound( int soundID );
	void stopAllSounds();
};

#endif