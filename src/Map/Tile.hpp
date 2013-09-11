#ifndef DEF_TILE_HPP
#define DEF_TILE_HPP

class Tile
{
private:
	int m_sid;
	int m_id;

public:
	Tile( int sid, int id );

	int getSid() const;
	int getId() const;
};

#endif