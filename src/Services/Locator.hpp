#ifndef DEF_LOCATOR_HPP
#define DEF_LOCATOR_HPP

#include "IAudio.hpp"
#include "ILogger.hpp"
#include "ServiceTexture.hpp"

//
// TODO: implement the NullService
//
class Locator
{
private:
	static IAudio*			m_audioService;
	static ServiceTexture*	m_textureService;
	static ILogger*			m_loggerService;

public:
	static IAudio*			getAudio() { return m_audioService; }
	static ServiceTexture*	getTextureManager() { return m_textureService; };
	static ILogger*			getLogger() { return m_loggerService; };
	

	// delete previous service?
	static void provide( IAudio* service )
	{
		m_audioService = service;
	}

	static void provide( ServiceTexture* service )
	{
		m_textureService = service;
	}

	static void provide( ILogger* service )
	{
		m_loggerService = service;
	}
};

#endif