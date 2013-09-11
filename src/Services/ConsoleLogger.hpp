#ifndef DEF_CONSOLELOGGER_HPP
#define DEF_CONSOLELOGGER_HPP

#include <iostream>

#include "ILogger.hpp"

class ConsoleLogger : public ILogger
{
public:
	void log( const char* str )
	{
		std::cout << "[LOG] " << str << "\n";
	}
};

#endif