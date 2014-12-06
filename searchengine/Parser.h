/*
Author: Kristofor Horst
Date: Fall 2014, Nov 15 - Dec 8
File: Parser.h
Pair with Parser.cpp

This is intended to be an XML parser utilizing the RapidXML parser
in conjunction with the Porter2Stemmer platform.
*/

#ifndef PARSER_H
#define PARSER_H

//STD includes
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
//hand written includes
#include "dictionary.h"
//stemmer includes
#include "porter2_stemmer.h"
//rapid XML includes
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"



class Parser
{	
public:
	Parser(Dictionary*&);
	
private:
	//functions
	//void parseMain();
	void parseMain(std::string);
	int getDir(std::string dir, std::vector<std::string> &files);
	bool tokenize(std::string&,std::string&);
	std::string rm_spec_char(std::string&);
	void parseMenu();


	//variables
	Dictionary* dic;
};

#endif
