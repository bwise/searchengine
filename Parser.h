#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <fstream>
#include "TinyXML.h"
#include "porter2_stemmer.h"
#include <string>

class Parser
{
	Parser(){};
	void ParserMain(char*);
	std::string checkTag(std::string);
}

#endif