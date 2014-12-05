#include "word.h"

Word::Word(string n, string uuid){
    if(debug)
        cout << "Word: New Word Object "<< n << " "<< uuid <<"\n";

    name=n;
    this->add(uuid);
    totalOccurences=0;
}

string Word::getName(){
    return name;
}


results * Word::returnresults(){
    results* r = new results();

    filerecords->calcFreq();

    filerecords->returnresults(r, idf);

    return r;

}

Word::Word(){
    if(debug)
        cout << "Word: New Word Object\n";

    filerecords=new AVLTree<FileRecord>();
    name="";
    totalOccurences=0;
    numFR=0;
    idf=0.0;
}

Word::~Word(){
    if(debug)
        cout << "Word: Delete Word "<< this->name <<"\n";

    delete filerecords;
}

void Word::insert(string n,string u){
    if(debug)
        cout << "Word: Insert FileRecord "<< n << " "<< u <<"\n";

    if(name==""){
        name=n;
        add(u);
    }else
        add(u);
}

void Word::add(string filerec){
    if(debug)
        cout << "Word: Add FileRecord "<< filerec <<"\n";

    if(filerecords->search(filerec)==NULL){
        filerecords->insert(filerec);
        numFR++;
    }
    else
        update(filerec);

    totalOccurences++;
}

void Word::update(string filerec){
    if(debug)
        cout << "Word: Update FileRecord "<< filerec <<"\n";

    FileRecord * fr=filerecords->search(filerec);

    if(fr!=NULL)
        fr->increment();
    else
        cout << "Something Bad Happened, Word.add(u) should have caught this.\n";
}

void Word::calcFreq(){
    if(debug)
        cout << "Word: CalcFreq: "<< name <<"\n";
    filerecords->calcFreq(totalOccurences);
    idf=log(200000.0/(numFR*1.0));
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
