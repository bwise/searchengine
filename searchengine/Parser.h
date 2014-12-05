#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "dictionary.h"

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
	Parser(Dictionary*);
	private:
	void parseMain();
	int getDir(std::string dir, std::vector<std::string> &files);
	bool tokenize(std::string&,std::string&);
	std::string rm_spec_char(std::string&);

	Dictionary* dic;
};

#endif
