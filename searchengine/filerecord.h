#ifndef FILERECORD_H
#define FILERECORD_H

#include<string>
#include <iostream>
#include "avltree.h"


using namespace std;

class FileRecord
{
friend class AVLTree<FileRecord>;
public:
    FileRecord();
    FileRecord(string fid, long occ);
    void increment();
    void calcFreq(long total);
    void insert(string u);
    bool operator<(string n);
    bool operator>(string n);
    bool operator==(string n);
private:
    string name; //fileID
    double freq;
    long occur;
    bool debug=false;

};

#endif // FILERECORD_H
