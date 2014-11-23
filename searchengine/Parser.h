#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <fstream>
#include <string>

#include "porter2_stemmer.h"

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

class Parser
{	public:
	Parser(char*);
	private:
	void parseMain(char*);
	int getdir(std::string dir, std::vector<std::string> &files);
};

#endif
