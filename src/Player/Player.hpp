#ifndef DEF_PLAYER_HPP
#define DEF_PLAYER_HPP

#include "ConvertUtils.hpp"

#include "Map.hpp"

class Map;

class Player
{
private:
	sf::Texture m_tileset;
	sf::Sprite m_sprite;
	float m_x;
	float m_y;
	float m_velocityV;
	float m_velocityH;
	float m_maxVelocity;
	float m_acceleration;

public:
	Player( const std::string& tileset );

	void update( const Map* map, float timePerFrame );
	sf::Sprite getSprite();
	float getX() const;
	float getY() const;
	float getVelH() const;
	float getVelV() const;
};

#endif