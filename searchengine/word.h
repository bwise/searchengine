#ifndef WORD_H
#define WORD_H

#include<string>
#include <iostream>
#include "avltree.h"
#include "filerecord.h"
#include "math.h"
#include "results.h"


class Word
{
friend class AVLTree<Word>;
private:
    string name;
    AVLTree <FileRecord>* filerecords;
    long totalOccurences;
    bool debug=false;
    void add(string filerec);
    long numFR;
    double idf;
public:
    Word();
    Word(string n, string u);
    ~Word();
    string getName();
    void update(string filerec);
    void calcFreq();
    void insert(string, string);
    bool operator<(string n);
    bool operator>(string n);
    bool operator==(string n);
    results* returnresults();

};

#endif // WORD_H
