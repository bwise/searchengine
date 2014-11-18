#include "filerecord.h"

FileRecord::FileRecord()
{
    name="";
    freq=0.0;
    occur=0;

    if(debug)
        cout << "Instantiating - Empty " << name << " "<< occur<< " " << freq<<"\n";
}

FileRecord::FileRecord(string fid, long occ){
    name=fid;
    occur=occ;
    freq=0.0;

    if(debug)
        cout << "Instantiating " << name << " "<< occur<< " " << freq<<"\n";
}

void FileRecord::increment(){
    occur++;

    if(debug)
        cout << "Incrementing " << name << " "<< occur<< " " << freq<<"\n";
}

void FileRecord::calc(long total){

    freq=1.0*occur/total;

    if(debug)
        cout << "Updating " << name << " "<< occur<< " / " << total << " " << freq<<"\n";
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
    if(name!=""){
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
