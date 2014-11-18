#ifndef WORD_H
#define WORD_H

#include<string>
#include <iostream>
#include "avltree.h"
#include "filerecord.h"

class Word
{
private:
    string name;
    AVLTree<FileRecord>* filerecords;
    long totalOccurences;
    bool debug=true;
    void add(string filerec);
public:
    Word();
    ~Word();
    void update(string filerec);
    void calcfreq();
};

#endif // WORD_H
