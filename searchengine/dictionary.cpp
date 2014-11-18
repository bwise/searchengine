#include "dictionary.h"

Dictionary::Dictionary()
{
    avlmode=true;
    if(avlmode){
        words= new AVLTree<Word>();
    }else{

    }
}

Dictionary::Dictionary(bool avl){
    avlmode=avl;
    if(avlmode){
        words= new AVLTree<Word>();
    }else{

    }
}

Dictionary::~Dictionary(){
    if(avlmode){
        delete words;
    }else{

    }
}

void Dictionary::addWord(string name, string uuid){
    if(avlmode){
        words->insert(name,uuid);

    }else{

    }
}

bool Dictionary::checkExists(string name){
    if(avlmode){
        if(words->search(name)!=NULL)
            return true;
        else
            return false;
    }else{

    }
}

void Dictionary::update(string u){
    if(avlmode){

    }else{

    }
}

void Dictionary::insert(string n, string u){
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
    if(avlmode){

    }else{

    }
}

void Dictionary::createMFI(){
    if(avlmode){

    }else{

    }
}

void Dictionary::readMFI(string mfiName){
    if(avlmode){

    }else{

    }
}
