#include "ServiceAudioSFML.hpp"

void ServiceAudioSFML::playSound( int soundID )
{
	!m_music.openFromFile("data/audio/YSO_026.ogg");
	m_music.setVolume( 5.f );
	m_music.play();
}

void ServiceAudioSFML::stopSound( int soundID )
{
	m_music.stop();
}

void ServiceAudioSFML::stopAllSounds()
{

}