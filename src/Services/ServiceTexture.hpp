#ifndef DEF_SERVICETEXTURE_HPP
#define DEF_SERVICETEXTURE_HPP

#include <SFML/Graphics.hpp>

#include <hash_map>
#include <iostream>

class ServiceTexture
{
private:
	std::map<std::string, sf::Texture*> m_textures;

	struct GameObjectDeallocator
	{
		void operator()( const std::pair<std::string, sf::Texture*>& p) const
		{
			delete p.second;
		}
	};

public:	
	ServiceTexture();
	~ServiceTexture();

	void add( const std::string path );
	void remove( const std::string path );
	sf::Texture* getTexture( const std::string path ) const;
};

#endif