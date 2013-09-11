#include "ServiceTexture.hpp"

ServiceTexture::ServiceTexture()
{	
}

ServiceTexture::~ServiceTexture()
{
	std::for_each( m_textures.begin(), m_textures.end(), GameObjectDeallocator() );
}

void ServiceTexture::add( const std::string path )
{
	sf::Texture* t = new sf::Texture();
	if( !t->loadFromFile( path ) )
	{
		std::cout << "Failed to load texture from file " << path << "\n";
		delete t;
	}
	else
	{
		m_textures.insert( std::pair<std::string, sf::Texture*>( path, t ) );
	}
}

void ServiceTexture::remove( const std::string path )
{
	std::map<std::string, sf::Texture*>::iterator results = m_textures.find( path );
	if( results != m_textures.end() )
	{
		delete results->second;
		m_textures.erase( results );
	}
}

sf::Texture* ServiceTexture::getTexture( const std::string path ) const
{
	std::map<std::string, sf::Texture*>::const_iterator results = m_textures.find( path );
	if( results == m_textures.end() )
		return NULL;
	return results->second;
}