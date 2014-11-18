#ifndef FILERECORD_H
#define FILERECORD_H

#include<string>
#include <iostream>


using namespace std;

class FileRecord
{
public:
    FileRecord();
    FileRecord(string fid, long occ);
    void increment();
    void calc(long total);
private:
    string fileID;
    double freq;
    long occur;
    bool debug=true;
};

#endif // FILERECORD_H
