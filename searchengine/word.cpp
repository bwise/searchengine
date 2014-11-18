#include "word.h"

Word::Word(string n, string uuid){
    if(debug)
        cout << "New Word Object "<< n << " "<< uuid <<"\n";

    name=n;
    this->add(uuid);
    totalOccurences=0;
}

Word::Word(){
    if(debug)
        cout << "New Word Object\n";

    filerecords=new AVLTree<FileRecord>();
    name="";
    totalOccurences=0;
}

Word::~Word(){
    if(debug)
        cout << "Delete Word "<< this->name <<"\n";

    delete filerecords;
}

void Word::insert(string n,string u){
    if(debug)
        cout << "Insert FileRecord"<< n << " "<< u <<"\n";

    if(name!=""){
        name=n;
        add(u);
    }else
        add(u);
}

void Word::add(string filerec){
    if(debug)
        cout << "Add FileRecord "<< filerec <<"\n";

    if(filerecords->search(filerec)!=NULL)
        filerecords->insert(filerec);
    else
        update(filerec);
}

void Word::update(string filerec){
    if(debug)
        cout << "Update FileRecord "<< filerec <<"\n";

    if(filerecords->search(filerec)!=NULL)
    filerecords->search(filerec)->increment();
}

void Word::calcfreq(){
    if(debug)
        cout << "CalcFreq\n";

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
