#include "filerecord.h"

string FileRecord::getName(){
    return name;
}

double FileRecord::tdidf(double idf){
    return freq*idf;
}

void FileRecord::addresult(results *r, double idf){
    r->add(this,tdidf(idf));
}

FileRecord::FileRecord()
{
    name="";
    freq=0.0;
    occur=0;

    if(debug)
        cout << "FR: Instantiating - Empty " << name << " "<< occur<< " " << freq<<"\n";
}

FileRecord::FileRecord(string fid, long occ){
    name=fid;
    occur=occ;
    freq=0.0;

    if(debug)
        cout << "FR: Instantiating " << name << " "<< occur<< " " << freq<<"\n";
}

void FileRecord::increment(){
    occur++;

    if(debug)
        cout << "FR: Incrementing " << name << " "<< occur<< " " << freq<<"\n";
}

void FileRecord::calcFreq(long total){

    freq=1.0*occur/total;

    if(debug)
        cout << "FR: Updating " << name << " "<< occur<< " / " << total << " " << freq<<"\n";
}

bool FileRecord::operator<(string n){
    if(name.compare(n)<0)
        return true;
    else
        return false;
}

bool FileRecord::operator>(string n){
    if(name.compare(n)>0)
        return true;
    else
        return false;
}

void FileRecord::insert(string u){
    if(name==""){
        name=u;
        increment();
    }else
        increment();
}

bool FileRecord::operator==(string n){
    if(name.compare(n)==0)
        return true;
    else
        return false;
}
