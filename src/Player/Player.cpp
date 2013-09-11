#include "stdafx.hpp"
#include "Player.hpp"

Player::Player( const std::string& tileset )
{
	m_tileset.loadFromFile( tileset );
	m_sprite.setTexture( m_tileset );
	m_sprite.setTextureRect( sf::IntRect( 32, 0, 32, 48 ) );
	m_x = m_y = 25;
	m_velocityV = m_velocityH = 0;
	m_maxVelocity = 3.f;
	m_acceleration = 10.f;

}

void Player::update( const Map* map, float timePerFrame )
{
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		m_velocityH += 1 + m_acceleration * timePerFrame / map->getTileW();
		m_x -= m_velocityH;
		m_sprite.move( -m_velocityH, 0 );
	}
	else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		m_velocityH += 1 + m_acceleration * timePerFrame / map->getTileW();
		m_x += m_velocityH;
		m_sprite.move( m_velocityH, 0 );
	}
	
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
	{
		m_velocityV += 1 + m_acceleration * timePerFrame / map->getTileH();
		m_y -= m_velocityV;
		m_sprite.move( 0, -m_velocityV );
	}
	else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
	{
		m_velocityV += 1 + m_acceleration * timePerFrame / map->getTileH();
		m_y += m_velocityV;
		m_sprite.move( 0, m_velocityV );
	}

	if( m_velocityH > m_maxVelocity )
		m_velocityH = m_maxVelocity;

	if( m_velocityV > m_maxVelocity )
		m_velocityV = m_maxVelocity;

}

sf::Sprite Player::getSprite()
{
	return m_sprite;
}

float Player::getX() const
{
	return m_x;
}

float Player::getY() const
{
	return m_y;
}

float Player::getVelH() const
{
	return m_velocityH;
}

float Player::getVelV() const
{
	return m_velocityV;
}