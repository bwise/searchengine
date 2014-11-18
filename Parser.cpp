
#include "Parser.h"

void Parser::ParseMain(char* fileName)
{
string readBuffer = "";
string nextWord = "";
string nextTag = "";
string uniqueID = "";

porter2_stemmer stemmer = new porter2_stemmer();

//read words from the XML base file
 iostream readInit();
 readInit.open(fileName);
 
 while(!readInit.eof())
 {
	//check if you get a tag
	readInit >> readBuffer;
	if (readBuffer[0] == '<') //you have a tag
		nextTag = readBuffer; //TODO: clear < > 

	//either create new tag, or append word to tag
	checkTag( nextTag) //TODO: create a function that checks a tag array/ checks if we need the info

	//check if you get a word or a uniqueID
	 if(nextTag == "ID") //TODO: check XML tags for ID identifier
		 {
		 uniqueID = readBuffer; //get the unique ID associated with the word
		 }
	 else
		 {
		 nextWord = readBuffer; //TODO: check that this is a correct assumption
		 //stem the word
		nextWord = stemmer.stem(nextWord);
		 //send the word and its ID to the dictionary
		 dictonary.addWord(unqiueID, nextWord);
		 } 

	}
}

std::string Parser::checkTag(std::string tagToCheck)
{
	for(int i = 0; i < sizeOfCompArray; i //TODO: define compArray & size of compArray
		if( strncmp(tagToCheck, compArray[i]))
			return compArray[i];

}
