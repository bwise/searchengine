#ifndef FILERECORD_H
#define FILERECORD_H

#include<string>
#include <iostream>
#include "avltree.h"
#include "results.h"


using namespace std;

class FileRecord
{
friend class AVLTree<FileRecord>;
public:
    FileRecord();
    FileRecord(string fid, long occ);
    void increment();
    void calcFreq(){}
    void calcFreq(long total);
    void insert(string u);
    bool operator<(string n);
    bool operator>(string n);
    bool operator==(string n);
    string getName();
    double tdidf(double idf);
    void addresult(results*r, double idf);
private:
    string name; //fileID
    double freq;
    long occur;
    bool debug=false;

};

#endif // FILERECORD_H
