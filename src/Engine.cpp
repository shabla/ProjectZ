#include "stdafx.hpp"
#include "Engine.hpp"

//
//	Initialization of the static members
//
sf::RenderWindow	Engine::m_window;
Map*				Engine::m_currentMap = 0;
Player*				Engine::m_player = 0;
Engine::GameState	Engine::m_gameState = Uninitialized;
sf::Clock			Engine::m_clock;

//
//	Initialize the game
//
void Engine::start()
{
	if( m_gameState != Uninitialized )
		return;

	// init the service locator
	Locator::provide( new ServiceAudioSFML() );
	Locator::provide( new ServiceTexture() );
	Locator::provide( new ConsoleLogger() );

	Locator::getLogger()->log( "test" );

	//test music
	Locator::getAudio()->playSound(0);

	// load texture
	Locator::getTextureManager()->add( "data/tilesets/ZeldaTileset1_2.png" );
	Locator::getTextureManager()->add( "data/tilesets/remakertp01.png" );

	// init window
	m_window.create( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "Zeldawesome" );

	// show splash screen
	m_gameState = ShowingSplash;

	// inits
	m_currentMap = new Map( "test.tmx" );
	m_player = new Player( "data/tilesets/remakertp01.png" );

	

	// Game loop
	while( m_gameState != Engine::Exiting )
	{
		switch( m_gameState )
		{
			//	Game state: Splash Screen
			case Engine::ShowingSplash:
			{
				showSplashScreen();
				break;
			}

			//	Game state: Playing
			case Engine::Playing:
			{
				update();
				render();
				processInputs();
				break;
			}
		}
	}

	m_window.close();
}

//
//	Show the splash screen
//
void Engine::showSplashScreen()
{
	SplashScreen splash;
	splash.show( m_window );
	m_gameState = Playing;
}

//
//	Update game
//
void Engine::update()
{
	m_currentMap->update( m_player->getX(), m_player->getY() );
	m_player->update( m_currentMap, m_clock.getElapsedTime().asSeconds() );
	m_clock.restart();
}

//
//	Render
//
void Engine::render()
{
	m_window.clear( sf::Color::Red );

	if( m_currentMap )
		m_currentMap->draw( m_window );

	if( m_player )
		m_window.draw( m_player->getSprite() );

	sf::Text t( toString( m_player->getX() ) + ", " + toString( m_player->getY() ) + ", " + toString( m_player->getVelH() ) + ", " + toString( m_player->getVelV() ) );
	m_window.draw( t );

	m_window.display();
	m_window.clear();
}

//
//	Process inputs
//
void Engine::processInputs()
{
	sf::Event e;
	while( m_window.pollEvent( e ) )
	{
		switch( e.type )
		{
			case sf::Event::Closed:
			{
				m_gameState = Exiting;
				break;
			}

			case sf::Event::KeyPressed:
			{
				break;
			}
		}
	}
}