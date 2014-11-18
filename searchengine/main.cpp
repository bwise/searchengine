#include <iostream>
#include "dictionary.h"
using namespace std;



int main()
{
    Dictionary * dictionary = new Dictionary(true);

    dictionary->addWord("Christina", "Chase");

    dictionary->calcFreq();






    //AVLTree <int>*  avl = new AVLTree<int>();
    //avl->menu();
    return 0;
}

