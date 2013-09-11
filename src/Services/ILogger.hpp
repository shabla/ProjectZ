#ifndef DEF_ILOGGER_HPP
#define DEF_ILOGGER_HPP

class ILogger
{
public:
	virtual void log( const char* str ) = 0;
};

#endif