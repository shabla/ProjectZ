#pragma once

#include "stdafx.hpp"

const int WINDOW_HEIGHT = 768;
const int WINDOW_WIDTH	= 1024;

// Convert string to int
inline int stringToInt( const std::string &s )
{
	std::istringstream i( s );
	int x;
	i >> x;
	return x;
}

template <typename T>
std::string toString( T value )
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}