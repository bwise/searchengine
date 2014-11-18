#include "word.h"

Word::Word(string n, string uuid){
    name=n;
    this->add(uuid);
    totalOccurences=0;
}

Word::Word(){
    filerecords=new AVLTree<FileRecord>();
    name="";
    totalOccurences=0;
}

Word::~Word(){
    delete filerecords;
}

void Word::insert(string n,string u){
    if(name!=""){
        name=n;
        add(u);
    }else
        add(u);
}

void Word::add(string filerec){
    if(filerecords->search(filerec)!=NULL)
        filerecords->insert(filerec);
    else
        update(filerec);
}

void Word::update(string filerec){
    if(filerecords->search(filerec)!=NULL)
    filerecords->search(filerec)->increment();
}

void Word::calcfreq(){

}

bool Word::operator<(string n){
    if(name.compare(n)<0)
        return true;
    else
        return false;
}

bool Word::operator>(string n){
    if(name.compare(n)>0)
        return true;
    else
        return false;
}

bool Word::operator==(string n){
    if(name.compare(n)==0)
        return true;
    else
        return false;
}
