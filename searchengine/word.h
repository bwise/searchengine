#ifndef WORD_H
#define WORD_H

#include<string>
#include <iostream>
#include "avltree.h"
#include "filerecord.h"

class Word
{
friend class AVLTree<Word>;
private:
    string name;
    AVLTree <FileRecord>* filerecords;
    long totalOccurences;
    bool debug=true;
    void add(string filerec);
public:
    Word();
    Word(string n, string u);
    ~Word();
    void update(string filerec);
    void calcfreq();
    void insert(string, string);
    bool operator<(string n);
    bool operator>(string n);
    bool operator==(string n);

};

#endif // WORD_H
