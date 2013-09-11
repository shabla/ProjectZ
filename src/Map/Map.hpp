#ifndef DEF_MAP_HPP
#define DEF_MAP_HPP

#include "ConvertUtils.hpp"

#include "Locator.hpp"
#include "Tile.hpp"
#include "Engine.hpp"

class Map
{
private:
	const int m_firstGid;

	int m_hTileCount;
	int m_vTileCount;
	int m_tileW;
	int m_tileH;
	int m_tilesetTilesPerLine;

	float m_offsetX;
	float m_offsetY;

	std::string m_mapPath;
	std::string m_tilesetPath;
	std::vector< std::vector<Tile*> > m_layers;

	int	load();

public:
	Map( const std::string& filename );
	
	void draw( sf::RenderWindow& w );
	void update( float playerX, float playerY );
	float getOffsetX() const;
	float getOffsetY() const;
	int getTileW() const;
	int getTileH() const;
};

#endif