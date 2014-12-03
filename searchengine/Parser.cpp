
#include "porter2_stemmer.h"
#include "Parser.h"
#include <vector>

using namespace rapidxml;
/*
int main(int argc, char* argv[])
{	
	if(argc < 2)
{	
	std::cout << "argc: " << argc << std::endl;
	std::cout << "Enter an arguement" << std::endl;
}
else
{
	Parser parseEntry(argv[1]);//create a parser object; should be argv[0]?
}	
	return 0;
}
*/

Parser::Parser(char* fileName)
{
	parseMain(fileName);
}


 int Parser::getDir(std::string dir, std::vector<std::string> &files)
{
	DIR *dp;
	struct dirent *dirp;
	if((dp = opendir(dir.c_str())) == NULL) {
	std::cout << "Error(" << errno << ") opening " << dir << std::endl;
	return errno;
	}
	while ((dirp = readdir(dp)) != NULL) {
		if (std::string(dirp->d_name) == "." || std::string(dirp->d_name) == "..")
			break;
	std::cout << "Directory opened, reading files" << std::endl;
	std::cout << std::string(dirp->d_name) << std::endl;
	files.push_back(std::string(dirp->d_name));
	}
	closedir(dp);
	return 0;
}


void Parser::parseMain(char* fileName)
{
//read buffers and necessary variables to stemming etc
std::string readBuffer = "";
std::string nextWord = "";
std::string nextTag = "";
std::string uniqueID = ""; 

//file<> xmlFile(fileName); //denotes an XML file; potentially unnecessary?

xml_document<> doc;

std::string dir = std::string("WikiDump");
std::vector<std::string> files = std::vector<std::string>();
std::string line = "";
//declaration of strings to compare: XML tags expected values
std::string oneDot = ".";
std::string twoDot = "..";
std::string check = " ";
std::string page = "page";
std::string title = "title";
std::string id = "id";
std::string revision = "revision";
std::string contributor = "contributor";
std::string username = "username";
std::string ip = "ip";
std::string text = "text";

std::string filepath = " ";
//getDir creates a vector of XML document names
getDir(dir, files);
//Creation of empty nodes to keep in scope
xml_node<> *medianWikiNode = NULL;
xml_node<> *pageNode = NULL;
xml_node<> *titleNode = NULL;
xml_node<> *idNode = NULL;
xml_node<> *revisorNode = NULL;
xml_node<> *contributorNode = NULL;
xml_node<> *usernameNode = NULL;
xml_node<> *textNode = NULL;

std::cout << "Declarations finished" << std::endl;

for(unsigned int x = 0; x < files.size(); x++)
{
	std::cout << "Entered for file.size() loop" << std::endl;
	filepath = dir + "/" + files[x];

if  (files[x].compare(oneDot) == 0)
{}
else if  (files[x].compare(twoDot) == 0)
{}
else
{

//read words from the XML base file

 std::ifstream readInit(fileName); //Basic read logic
 readInit.open(fileName);
 
 std::vector<char>buffer((std::istreambuf_iterator<char>(readInit)),std::istreambuf_iterator<char>()); //grabs the file names from getDir
 buffer.push_back('\0');
 
std::cout << "Preparse" << std::endl;

 doc.parse<0>(&buffer[0]);//The doc object should now contain the contents of the XML.

std::cout << "Postparse" << std::endl;
//We begin to read through the doc object to find information we want
 
 xml_node<> *mediaWikiNode = doc.first_node(); //every file starts with wikimedia

std::cout << "mediaWikiNode declared"<< std::endl; //this cout prints
 
 //now find a page
 xml_node<> *pageNode = mediaWikiNode->first_node();//this line segfaults, I think
std::cout << "I segfaulted here." << std::endl; //this cout doesn't print
 std::string check = pageNode->name();
std::cout << "check is " << check << std::endl;
 while(page.compare(check) != 0)
 {
	pageNode = pageNode->next_sibling();
	check = pageNode->name();
	std::cout << " check inside while is " <<  check << std::endl; 
}
 
 while(pageNode != NULL)
 {
 //get the title of the page
	titleNode = pageNode->first_node();
	check = titleNode->name();
	while (title.compare(check) != 0)
	{
	titleNode = titleNode->next_sibling();
	check = titleNode->name();
	}
//get the ID associated with the page
	idNode = idNode->next_sibling();
	check = idNode->name();
	
	while(id.compare(check) == 0)
	{
	idNode = idNode->next_sibling();
	check = idNode->name();
	}
//get who last worked on the page (revised)
	revisorNode = idNode->next_sibling();
	check = revisorNode->name();
	while (revision.compare(check) != 0)
	{
	revisorNode = revisorNode->next_sibling();
	check = revisorNode->name();
	}
//get who last worked on the page (contributed)
	contributorNode = revisorNode->first_node();
	check = contributorNode->name();
	while(contributor.compare(check) != 0)
	{
	contributorNode = contributorNode->next_sibling();
	check = contributorNode->name();
	}
//get original author of the page
	usernameNode = contributorNode->first_node();
	check = usernameNode->name();
	while( username.compare(check) != 0 && usernameNode != NULL)
	{
	usernameNode = usernameNode->next_sibling();
	check = usernameNode->name();
	}
//advance to the next page
	pageNode = pageNode->next_sibling();
}
readInit.close();
readInit.clear();

//std::ofstream write("defaultXMLout.txt");
//print(std::cout, doc, 0);
//write.close();
//write.clear();
 }
 }
}
