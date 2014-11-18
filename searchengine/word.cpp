#include "word.h"

Word::Word(){
    filerecords=new AVLTree<FileRecord>();
}

Word::~Word(){
    delete filerecords;
}

void Word::add(string filerec){

}

void Word::update(string filerec){

}

void Word::calcfreq(){

}
