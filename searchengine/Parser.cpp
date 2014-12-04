
#include "porter2_stemmer.h"
#include "Parser.h"
#include <vector>

using namespace rapidxml;


int main()
{	
	std::cout << "Entered main" << std::endl;

//	Parser parseEntry();//create a parser object; 
	Parser* parseEntry = new Parser();
//	parseEntry->parseMain();
	return 0;
}


Parser::Parser()
{	std::cout << "created object" << std::endl;
	parseMain();
}


 int Parser::getDir(std::string dir, std::vector<std::string> &files)
{
	DIR *dp;
	struct dirent *dirp;
	struct stat filestat;
	std::string filepath;

	if((dp = opendir(dir.c_str())) == NULL) {
	std::cout << "Error(" << errno << ") opening " << dir << std::endl;
	return errno;
	}
	while ((dirp = readdir(dp)) != NULL) {

	filepath = dir + "/" + dirp->d_name;
		if (stat(filepath.c_str(),&filestat)) continue;
		if(S_ISDIR(filestat.st_mode)) continue;
	
		
	std::cout << "Directory opened, reading files" << std::endl;
	std::cout << std::string(dirp->d_name) << std::endl;
	files.push_back(std::string(dirp->d_name));
	}
	closedir(dp);
	std::cout << "leaving getdir" << std::endl;
	return 0;
}


void Parser::parseMain()
{
 std::cout<<"Parsing main" <<std::endl;
//read buffers and necessary variables to stemming etc
std::string readBuffer = "";
std::string nextWord = "";
std::string nextTag = "";
std::string uniqueID = ""; 

//file<> xmlFile(fileName); //denotes an XML file; potentially unnecessary?
std::cout << "Declaring variables" << std::endl;
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

std::ifstream theFile;

std::string filepath = " ";
//getDir creates a vector of XML document names

std::cout << "entering getdir" << std::endl;
getDir(dir, files);

//Creation of empty nodes to keep in scope
xml_node<> *mediaWikiNode = NULL;
xml_node<> *pageNode = NULL;
xml_node<> *titleNode = NULL;
xml_node<> *idNode = NULL;
xml_node<> *revisorNode = NULL;
xml_node<> *contributorNode = NULL;
xml_node<> *usernameNode = NULL;
xml_node<> *textNode = NULL;

std::cout << files.size() << std::endl;
for(unsigned int x = 0; x < files.size(); x++)
{
	std::cout << "Entered for file.size() loop" << std::endl;
	filepath = dir + "/" + files[x];

if  (files[x].compare(oneDot) == 0)
{//do nothing
}
else if  (files[x].compare(twoDot) == 0)
{//do nothing
}
else
{

//read words from the XML base file

 theFile.open(filepath.c_str());
 
 std::vector<char>buffer((std::istreambuf_iterator<char>(theFile)),std::istreambuf_iterator<char>()); //grabs the file names from getDir
 buffer.push_back('\0');

 doc.parse<0>(&buffer[0]);//The doc object should now contain the contents of the XML.

//We begin to read through the doc object to find information we want
 
 mediaWikiNode = doc.first_node(); //every file starts with wikimedia
 
 //now find a page
 pageNode = mediaWikiNode->first_node();//this line segfaults, I think
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
	std::cout << "check inside pageNode is: " << check << std::endl;

	while (title.compare(check) != 0)
	{
	titleNode = titleNode->next_sibling();
	check = titleNode->name();
	std::cout << "check inside title is: " << check << std::endl;
	}
	std::cout << "after while" << std::endl;
//get the ID associated with the page


	idNode = pageNode->next_sibling();
	std::cout << "made it here";
	check = idNode->name();
	
	std::cout << "check after idNode assignment is " << check << std::endl;

	while(id.compare(check) == 0)
	{
	idNode = idNode->next_sibling();
	check = idNode->name();
	std::cout << "check idNode is: " << check << std::endl;
	}
//get who last worked on the page (revised)
	revisorNode = idNode->next_sibling();
	check = revisorNode->name();
	int squirtle = 0;
	while (revision.compare(check) != 0)
	{
std::cout << "this it?" << std::endl;	
		revisorNode = revisorNode->next_sibling();
		check = revisorNode->name();
			
	std::cout << "revisor node: " << check << squirtle++ <<  std::endl;
	}

	//get the text of the revision
	std::cout << "made it hrtr"<<std::endl;
	textNode = revisorNode->first_node();
	check = textNode->name();
	while(text.compare(check) != 0)
	{
	textNode = textNode->next_sibling();
	check = textNode->name();
	}

//somewhere here, we capture the text and send it to the stemmer
	if(textNode != NULL) //text node has data
	{
	text = textNode->value();
	//I belive this is where the stemmer goes
	//stem(text);?
	}

//We have the text back, stemmed, we move down the page
//get who last worked on the page (contributed)
//	contributorNode = revisorNode->first_node();
//	check = contributorNode->name();
//	while(contributor.compare(check) != 0)
//	{
//	contributorNode = contributorNode->next_sibling();
//	check = contributorNode->name();
//	}
//get original author of the page
//	usernameNode = contributorNode->first_node();
//	check = usernameNode->name();
//	while( username.compare(check) != 0 && usernameNode != NULL)
//	{
//	usernameNode = usernameNode->next_sibling();
//	check = usernameNode->name();
//	}
//advance to the next page
	pageNode = pageNode->next_sibling();
}
}
theFile.close();
theFile.clear();
 }
}
