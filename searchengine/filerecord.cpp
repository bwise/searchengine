#include "filerecord.h"

FileRecord::FileRecord()
{
    fileID="";
    freq=0.0;
    occur=0;

    if(debug)
        cout << "Instantiating - Empty " << fileID << " "<< occur<< " " << freq<<"\n";
}

FileRecord::FileRecord(string fid, long occ){
    fileID=fid;
    occur=occ;
    freq=0.0;

    if(debug)
        cout << "Instantiating " << fileID << " "<< occur<< " " << freq<<"\n";
}

void FileRecord::increment(){
    occur++;

    if(debug)
        cout << "Incrementing " << fileID << " "<< occur<< " " << freq<<"\n";
}

void FileRecord::calc(long total){

    freq=1.0*occur/total;

    if(debug)
        cout << "Updating " << fileID << " "<< occur<< " / " << total << " " << freq<<"\n";
}
