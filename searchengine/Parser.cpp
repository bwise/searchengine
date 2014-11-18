#include "porter2_stemmer.h"
#include "Parser.h"

void Parser::parseMain(char* fileName)
{
std::string readBuffer = "";
std::string nextWord = "";
std::string nextTag = "";
std::string uniqueID = ""; 



//read words from the XML base file
 
	TiXmlDocument doc( fileName ); //Use TinyXML to parse file? FIGURE OUT HOW THIS WORKS
	doc.LoadFile();
}
 
 iostream readInit(fileName); //Basic read logic
 readInit.open(fileName);
 
 while(!readInit.eof())
 {
	//check if you get a tag
	readInit >> readBuffer;
	if (readBuffer[0] == '<') //you have a tag
		nextTag = checkTag( readBuffer); //TODO: clear < > 

	//either create new tag, or append word to tag
	 //TODO: create a function that checks a tag array/ checks if we need the info

	//check if you get a word or a uniqueID
	 if(nextTag == "Sha1") //TODO: check XML tags for ID identifier
		 {
		 uniqueID = readBuffer; //get the unique ID associated with the word
		 }
	 else
		 {
		 nextWord = readBuffer; //TODO: check that this is a correct assumption
		 //stem the word
		nextWord = porter2_stemmer stemmer::stem(nextWord);
		 //send the word and its ID to the dictionary
		 dictonary.addWord(unqiueID, nextWord);
		 } 

	}
	
}

std::string Parser::checkTag(std::string tagToCheck)
{
int  sizeOfCompArray = 3;
string compArray[] = {"Sha1" , "Title", "text"} //increase useful tags
	for(int i = 0; i < sizeOfCompArray; i //TODO: define compArray & size of compArray
		if( strncmp(tagToCheck, compArray[i]))
			return compArray[i];

}
