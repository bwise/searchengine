#include "dictionary.h"

Dictionary::Dictionary()
{
    if(debug)
        cout << "Dict: New Dictionary\n";

    avlmode=true;
    if(avlmode){
        words= new AVLTree<Word>();
    }else{

    }
}

Dictionary::Dictionary(bool avl){

    if(debug)
        cout << "Dict: New Dictionary "<< (avl ? "True" : "False") <<"\n";

    avlmode=avl;
    if(avlmode){
        words= new AVLTree<Word>();
    }else{

    }
}

Dictionary::~Dictionary(){

    cout << "\n\nCLEARING ALL DOCUMENTS\n\n";

    if(debug)
        cout << "Dict: Destroy Dictionary\n";

    if(avlmode){
        delete words;
    }else{

    }
}

results * Dictionary::query(string a){
    //cout << "a";
    if(words->search(a)!=NULL){
	std::transform(a.begin(),a.end(),a.begin(), ::tolower);
	return words->search(a)->returnresults();
	}
    else{
        cout << "Word not found: " << a << ". Continuing.";
        return NULL;
    }
}

void Dictionary::addWord(string name, string uuid){
    if(debug)
        cout << "Dict: Dictionary ADD Word "<<name << " " << uuid<<"\n";

    if(avlmode){
        words->insert(name,uuid);

    }else{

    }
}

bool Dictionary::checkExists(string name){
    if(debug)
        cout << "Dict: Dictionary Check Exists Word "<<name <<"\n";

    if(avlmode){
        if(words->search(name)!=NULL)
            return true;
        else
            return false;
    }else{

    }
}

void Dictionary::update(string u){
    if(debug)
        cout << "Dict: Dictionary Update Word "<<u <<"\n";

    if(avlmode){

    }else{

    }
}

void Dictionary::insert(string n, string u){
    if(debug)
        cout << "Dict: Dictionary Insert Word "<<n <<" "<<u <<"\n";

    if(avlmode){
        if(checkExists(n)){
            words->search(n)->update(u);
        }else{
            addWord(n,u);
        }
    }else{

    }
}

void Dictionary::calcFreq(){

    if(debug)
        cout << "Dict: Dictionary CalcFreq\n";

    if(avlmode){
        words->calcFreq();
    }else{

    }
}

/*
void Dictionary::createMFI(){
    if(debug)
        cout << "Dict: Dictionary CreateMFI\n";

    if(avlmode){

    }else{

    }
}

void Dictionary::readMFI(string mfiName){

    if(debug)
        cout << "Dict: Dictionary ReadMFI\n";

    if(avlmode){

    }else{

    }
}
*/
