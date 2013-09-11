#ifndef DEF_IAUDIO_HPP
#define DEF_IAUDIO_HPP

class IAudio
{
public:
	virtual void playSound( int soundID ) = 0;
	virtual void stopSound( int soundID ) = 0;
	virtual void stopAllSounds() = 0;
};

#endif