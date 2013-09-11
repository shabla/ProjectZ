#include "stdafx.hpp"
#include "Map.hpp"

Map::Map( const std::string& filename ) :	m_firstGid( 1 ),
											m_hTileCount( -1 ),
											m_vTileCount( -1 ),
											m_tileW( -1 ),
											m_tileH( -1 ),
											m_offsetX( 0.f ),
											m_offsetY( 0.f )
{
	m_mapPath = "data/maps/" + filename;
	load();
}

int Map::load()
{
	// assumptions:
	// 1. the map and its associated tileset uses the same tile width and tile height
	// 2. there is only one tileset per map
	// 3. the fileformat for the tileset is png with transparency
	// useful informations in the map file:
	//
	//	<map width="#" height="#" tilewidth="#" tileheight="#">
	//		<tileset firstgid="1" name="ZeldaTileset1">
	//			<image source="str" trans="str"/>
	//		</tileset>
	//		<layer name="str"> (multiple)
	//			<data>
	//				<tile gid="#"/> (multiple)
	//			</data>
	//		</layer>
	//	</map>

	rapidxml::file<> f( m_mapPath.c_str() );
	
	// Parse the map file
	rapidxml::xml_document<> doc;
	doc.parse<0>( f.data() );

	rapidxml::xml_node<>* map = doc.first_node("map");

	//
	// <map> attributes
	//
	m_hTileCount	= stringToInt( map->first_attribute( "width" )->value() );
	m_vTileCount	= stringToInt( map->first_attribute( "height" )->value() );
	m_tileW			= stringToInt( map->first_attribute( "tilewidth" )->value() );
	m_tileH			= stringToInt( map->first_attribute( "tileheight" )->value() );

	std::cout << m_hTileCount << " " << m_vTileCount << " "  << m_tileW << " " << m_tileH << "\n";

	//
	// <tileset> attributes (only supports 1 tileset)
	// there should only be one <image> node per tileset
	//
	m_tilesetPath = map->first_node( "tileset" )->first_node( "image" )->first_attribute( "source" )->value();
	m_tilesetPath = "data/tilesets/" + m_tilesetPath;

	std::cout << m_tilesetPath << "\n";

	//
	// iterate through all the layers
	//
	for( rapidxml::xml_node<>* layer = map->first_node( "layer" ); layer; layer = layer->next_sibling( "layer" ) )
	{
		//
		// <layer> attributes
		//
		std::string layerName = layer->first_attribute( "name" )->value();		//not used yet ==============

		std::cout << layerName << "\n";

		//
		// <layer> <data> read all tiles
		//
		std::vector<Tile*> tileLayer;
		int tileId = -1;
		for( rapidxml::xml_node<>* tile = layer->first_node( "data" )->first_node( "tile" ); tile; tile = tile->next_sibling( "tile" ) )
		{
			tileId++;
			int tileSid = stringToInt( (std::string)tile->first_attribute( "gid" )->value() );
			tileLayer.push_back( new Tile( tileSid, tileId ) );
		}

		m_layers.push_back( tileLayer );

		std::cout << tileId << " " << tileLayer.size() << "\n";
	}

	std::cout << "success" << "\n";
	return 1;
}

void Map::draw( sf::RenderWindow& w )
{
	sf::Texture* tileset = Locator::getTextureManager()->getTexture( m_tilesetPath );

	int hScreenTiles = w.getSize().x / m_tileW;
	int vScreenTiles = w.getSize().y / m_tileH;

	m_tilesetTilesPerLine = tileset->getSize().x / m_tileW;

	if( m_hTileCount < hScreenTiles )
		hScreenTiles = m_hTileCount;
	if( m_vTileCount < vScreenTiles )
		vScreenTiles = m_vTileCount;

	for( int row=0; row<vScreenTiles; row++ )
	{
		for( int col=0; col<hScreenTiles; col++ )
		{
			int tileId = m_hTileCount * ( floor(m_offsetY/m_tileH) + row) + floor(m_offsetX/m_tileW) + col;
			Tile* tile = m_layers.at(0).at( tileId );
	
			// -1 because sid's starts at 1 instead of 0
			int left = (tile->getSid() - 1) % m_tilesetTilesPerLine;
			int top = (tile->getSid() -1) / m_tilesetTilesPerLine;

			sf::Sprite sprite;
			sprite.setTexture( *tileset );
			sprite.setTextureRect( sf::IntRect( left * m_tileW, top * m_tileH, m_tileW, m_tileH ) );
			sprite.setPosition( col * m_tileW, row * m_tileH );

			w.draw( sprite );
		}
	}
	std::cout << m_offsetX << "," << m_offsetY << "\n";
}

void Map::update( float playerX, float playerY )
{
	m_offsetX = playerX - WINDOW_WIDTH / 2;
	m_offsetY = playerY - WINDOW_HEIGHT / 2;

	if( m_offsetX > m_hTileCount * m_tileW - WINDOW_WIDTH )
		m_offsetX = m_hTileCount * m_tileW - WINDOW_WIDTH;

	if( m_offsetY > m_vTileCount * m_tileH - WINDOW_HEIGHT )
		m_offsetY = m_vTileCount * m_tileH - WINDOW_HEIGHT;

	if( m_offsetY < 0 )
		m_offsetY = 0;

	if( m_offsetX < 0 )
		m_offsetX = 0;
}

float Map::getOffsetX() const
{
	return m_offsetX;
}

float Map::getOffsetY() const
{
	return m_offsetY;
}

int Map::getTileW() const
{
	return m_tileW;
}

int Map::getTileH() const
{
	return m_tileH;
}