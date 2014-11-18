#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<string>
#include<iostream>
#include "avltree.h"
#include "word.h"

using namespace std;

class Dictionary
{
private:
    bool avlmode;
    void addWord(string name, string uuid);
    bool checkExists(string name);
    void update(string u);
    AVLTree<Word>* words;
public:
    Dictionary(bool avl);
    Dictionary();
    ~Dictionary();
    void insert(string n, string u);
    void calcFreq();
    void createMFI();
    void readMFI(string mfiName);
};

#endif // DICTIONARY_H
