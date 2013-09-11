#include "stdafx.hpp"
#include "Tile.hpp"

Tile::Tile( int sid, int id ) : m_sid( sid ),
								m_id( id )
{
}

int Tile::getSid() const
{
	return m_sid;
}

int Tile::getId() const
{
	return m_id;
}