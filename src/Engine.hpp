#ifndef DEF_ENGINE_HPP
#define DEF_ENGINE_HPP

#include "SplashScreen.hpp"
#include "Map.hpp"
#include "Player.hpp"

#include "Locator.hpp"
#include "ServiceAudioSFML.hpp"
#include "ServiceTexture.hpp"
#include "ConsoleLogger.hpp"

class Map;
class Player;

class Engine
{
private:
	enum GameState
	{ 
		Uninitialized,
		ShowingSplash,
		Paused,
		ShowingMenu,
		Playing,
		Exiting
	};

	static sf::RenderWindow m_window;
	static Map*				m_currentMap;
	static Player*			m_player;
	static GameState		m_gameState;
	static sf::Clock		m_clock;

	// methods
	static void update();
	static void render();
	static void processInputs();
	static void showSplashScreen();

public:
	static void start();
};

#endif