#include "dictionary.h"

Dictionary::Dictionary()
{
    if(debug)
        cout << "New Dictionary\n";

    avlmode=true;
    if(avlmode){
        words= new AVLTree<Word>();
    }else{

    }
}

Dictionary::Dictionary(bool avl){

    if(debug)
        cout << "New Dictionary "<< (avl ? "True" : "False") <<"\n";

    avlmode=avl;
    if(avlmode){
        words= new AVLTree<Word>();
    }else{

    }
}

Dictionary::~Dictionary(){

    if(debug)
        cout << "Destroy Dictionary\n";

    if(avlmode){
        delete words;
    }else{

    }
}

void Dictionary::addWord(string name, string uuid){
    if(debug)
        cout << "Dictionary ADD Word "<<name << " " << uuid<<"\n";

    if(avlmode){
        words->insert(name,uuid);

    }else{

    }
}

bool Dictionary::checkExists(string name){
    if(debug)
        cout << "Dictionary Check Exists Word "<<name <<"\n";

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
        cout << "Dictionary Update Word "<<u <<"\n";

    if(avlmode){

    }else{

    }
}

void Dictionary::insert(string n, string u){
    if(debug)
        cout << "Dictionary Insert Word "<<n <<" "<<u <<"\n";

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
        cout << "Dictionary CalcFreq\n";

    if(avlmode){

    }else{

    }
}

void Dictionary::createMFI(){
    if(debug)
        cout << "Dictionary CreateMFI\n";

    if(avlmode){

    }else{

    }
}

void Dictionary::readMFI(string mfiName){

    if(debug)
        cout << "Dictionary ReadMFI\n";

    if(avlmode){

    }else{

    }
}
