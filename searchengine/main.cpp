#include <iostream>
#include "dictionary.h"
using namespace std;



int main()
{
    Dictionary * dictionary = new Dictionary(true);

    dictionary->addWord("Christina", "Chase");
    dictionary->addWord("Christina", "Chas");
    dictionary->addWord("Christina", "Chase");


    string name="";
    string uuid;

    int j=0;

    int imax=1000000-1;
    for(int i=0; i<imax; i++){
        if(i%((imax+1)/100)==0)
            cout << i << " of " << imax+1 << "\n";

        uuid=(char)((i+j%93)+33);

        dictionary->addWord(name+(char)((i%93)+33), uuid);

        if(i%93*92==0){
            j++;
            name+=(char)((i%93)+33);
        }
     }

    cout << "\n\n-------------\nUpdating FRs\n-----------\n\n";
    dictionary->calcFreq();

    return 0;
}

