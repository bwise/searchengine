#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <fstream>
#include "tinyxml.h"
#include "tinystr.h"
#include "porter2_stemmer.h"
#include <string>

class Parser
{
	Parser(){};
	void parseMain(char*);
	std::string checkTag(std::string);
};

#endif