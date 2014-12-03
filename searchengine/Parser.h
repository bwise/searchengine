#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "porter2_stemmer.h"

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>

class Parser
{	public:
	Parser();
	private:
	void parseMain();
	int getdir(std::string dir, std::vector<std::string> &files);
};

#endif
