#include "stdafx.hpp"
#include "SplashScreen.hpp"

void SplashScreen::show( sf::RenderWindow& window )
{
	// this texture doesn't need to be managed by the texture manger since this is the only place it will ever be used
	sf::Texture texture;
	if( !texture.loadFromFile( "data/images/1150410660256.jpg" ) )
		return;

	m_alpha = 100.f;

	sf::Sprite sprite( texture );
	sprite.setOrigin( texture.getSize().x/2.f, texture.getSize().y/2.f );
	sprite.setPosition( window.getSize().x/2.f, window.getSize().y/2.f );
	
	window.draw( sprite );
	window.display();

	sf::Event event;
	while( true )
	{
		while( window.pollEvent( event ) )
		{
			if( event.type == sf::Event::KeyPressed ||
				event.type == sf::Event::MouseButtonPressed || 
				event.type == sf::Event::Closed )
			{
				return;
			}
		}
	}
}