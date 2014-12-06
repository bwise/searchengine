/* 
Author: Kristofor Horst
  Date: Fall 2014, Nov 15 - Dec 8
  File: Parser.cpp
  Pair with Parser.h

  This is intended to be an XML parser utilizing the RapidXML parser
  in conjunction with the Porter2Stemmer platform.  
*/


#include "porter2_stemmer.h"
#include "Parser.h"


using namespace rapidxml;



Parser::Parser(Dictionary* dicP)
{	
	dic = dicP;
	parseMenu();

}


int Parser::getDir(std::string dir, std::vector<std::string> &files)
{
	DIR *dp;
	struct dirent *dirp;
	struct stat filestat;
	std::string filepath;

	if ((dp = opendir(dir.c_str())) == NULL) {
		std::cout << "Error(" << errno << ") opening " << dir << std::endl;
		return errno;
	}
	while ((dirp = readdir(dp)) != NULL) {

		filepath = dir + "/" + dirp->d_name;
		if (stat(filepath.c_str(), &filestat)) continue;
		if (S_ISDIR(filestat.st_mode)) continue;


		std::cout << "Directory opened, reading files" << std::endl;
		std::cout << std::string(dirp->d_name) << std::endl;
		files.push_back(std::string(dirp->d_name));
	}
	closedir(dp);
	std::cout << "leaving getdir" << std::endl;
	return 0;
}


void Parser::parseMain(std::string passIn)
{
	std::cout << "Parsing main" << std::endl;
	//file<> xmlFile(fileName); //denotes an XML file; potentially unnecessary?
	std::cout << "Declaring variables" << std::endl;
	xml_document<> doc;

	std::string dir = std::string(passIn);//std::string dir = std::string("WikiDump");
	std::vector<std::string> files = std::vector<std::string>();
	std::string line = "";
	//declaration of strings to compare: XML tags expected values


	
	std::string page = "page";
	std::string title = "title";
	std::string id = "id";
	std::string text = "text";
	std::string author = "author";
	std::ifstream theFile;

	std::string filepath = " ";
	//getDir creates a vector of XML document names

	getDir(dir, files);

	//Creation of empty nodes to keep in scope
	xml_node<> *mediaWikiNode = NULL;
	xml_node<> *pageNode = NULL;
	
	for (unsigned int x = 0; x < files.size(); x++)
	{
		std::cout << "Entered for file.size() loop" << std::endl;
		filepath = dir + "/" + files[x];

			//read words from the XML base file
			std::stringstream contents;
			theFile.open(filepath.c_str());
			if(!theFile.is_open()){
				std::cout << "ERROR OPENING FILE BRUH" << std::endl;
			}
			contents << theFile.rdbuf();
			std::string xml_contents = contents.str();
			std::vector<char> buffer(xml_contents.begin(),xml_contents.end()); //grabs the file names from getDir
			buffer.push_back('\0');	
			for(int x = 0; x < buffer.size(); x++)
				std::cout << buffer[x];
			std::cout << std::endl;

			doc.parse<parse_declaration_node | parse_no_data_nodes>(&buffer[0]);//The doc object should now contain the contents of the XML.

			//We begin to read through the doc object to find information we want

			mediaWikiNode = doc.first_node("mediawiki");
			std::cout << "Mediawiki" <<std::endl;
			//now find a page
			pageNode = mediaWikiNode->first_node("page");
			std::cout << "Page" << std::endl;

			xml_node<>* element;
			while (pageNode != NULL)
			{
				//get the title of the page
				element = pageNode->first_node("title");
				std::cout<< "title" << std::endl;
				title = element->value();
				std::cout << "\t" << title << std:: endl;
				//std::cout << "check inside pageNode is: " << check << std::endl;

				id = element->next_sibling("revision")->first_node("contributor")->first_node("id")->value();
				std::cout << "revision/id" << std::endl;

				author = element->next_sibling("revision")->first_node("contributor")->first_node("username")->value();
				text = element->next_sibling("revision")->first_node("text")->value();				
			
				//tokenize
				tokenize(text, id);
				
				pageNode = pageNode->next_sibling("page");
			}
			
		theFile.close();
		theFile.clear();
	}
}

bool Parser::tokenize(std::string& text,std::string& id)
{
text = rm_spec_char(text);
//std::vector<std::string> token;
Porter2Stemmer::stem(text);
dic->addWord(text,id);

}

std::string Parser::rm_spec_char(std::string& text)
{
char chars[]=".,!()123456890{}'<>:/{}_|=+;-`~";
for(unsigned int i=0; i<33; i++)
	text.erase(std::remove(text.begin(),text.end(),chars[i]),text.end());
return text;
}


void Parser::parseMenu()
{
	std::string userIn ="";
	std::cout << "Would you like to enter a new document, or parse the WikiBooks?\n 1. WikiBooks\n 2. New File \n" << std::endl;
	std::cin >> userIn;
	
		if (userIn == "1")
		{
			parseMain("WikiDump");
			return;
		}
		else if (userIn == "2")
		{
			std::cout << "Please enter the filename to be parsed: ";
			std::cin >> userIn;
			parseMain(userIn);
			return;
		}
		else{
			std::cout << "Invalid input, please enter 1 for Wikibooks or 2 for New File.\n";
			parseMenu();
		}
	}
