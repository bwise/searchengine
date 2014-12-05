#include <iostream>
#include "dictionary.h"
#include "Parser.h"
using namespace std;



int main(int argc, char* argv[])
{
    bool exit=false;
    bool advancedmenu=false;
    bool avlmode=true;
    int response=0;
    char keepparsing=' ';
    char exitLoop = ' ';
    char exitLoop2 = ' ';
    char clearDocs= ' ';
    char clearDocs2=' ';
    string searchterms="";
    string notterms="";
    string trash="";
    bool andflag=false;
    bool orflag=false;
    bool notflag=false;
    std::size_t notpos;
    std::size_t iter;

    cout << "----------------------------\n"
         << " Data Structures - CSE 2341\n"
         << "         Fall 2014\n"
         << "    Search Engine Project\n\n"
         << "Ben Wise and Kristofor Horst\n"
         << "----------------------------\n";

    cout << "\n* Would you like to use AVL tree or Hash Table Implementation.\n"
         << "* Response: ";

    Dictionary * dictionary = new Dictionary(avlmode);

    cout << "\n\n*-*-*Hash Table Mode Disabled. Implementation not complete.*-*-*\n\n";


    //Test Section
    dictionary->addWord("Christina", "Chase");
    dictionary->addWord("Christina", "Chas");
    dictionary->addWord("Christina", "Chase");
    dictionary->addWord("Isaiah", "Chase");
    dictionary->addWord("Isaiah", "Chase");
    dictionary->addWord("Kris", "Chase");
    dictionary->addWord("Ana", "Chas");
    dictionary->addWord("Ana", "Chase");
    dictionary->addWord("Ana", "Chase");
    dictionary->addWord("Kris", "Chase");

    dictionary->calcFreq();
    /*
    cout << "\n";
    dictionary->query("Christina")->display();
    cout << "\n";
    dictionary->query("Ana")->display();
    cout << "\n";
    dictionary->query("Kris")->display();
    cout << "\n";
    dictionary->query("Isaiah")->display();
    cout << "\n";
    dictionary->query("Christina")->AND(dictionary->query("Isaiah"))->display();
    cout << "\n";
    dictionary->query("Andrew")->display();
    cout << "\n";
    dictionary->query("Christina")->OR(dictionary->query("Isaiah"))->display();//->display();
    cout << "\n";
    //End Test Section
    */

    while(!exit){
        string mode = avlmode?"AVL Mode\n":"Hash Table Mode\n";


        if(!advancedmenu){
            cout << "\n\n--------------------------------------------------------\n"
                << "Menu:\n"
                << "1 Search\n"
                << "2 Parse Document\n"
                << "3 Toggle Advanced Menu\n"
                << "9 Exit\n"
                << "--------------------------------------------------------\n"
                << "Selection: ";
        }else{
            cout << "\n\n********************************************************\n"
                << "Advanced Menu:\n"
                << "1 Search\n"
                << "2 Parse Document\n"
                << "3 Toggle Advanced Menu\n"
                << "4 Toggle AVL/Hash Table Mode. Currently in: " << mode
                << "5 Stress Test Mode\n"
                << "6 Clear All Documents\n"
                << "9 Exit\n"
                << "********************************************************\n"
                << "Selection: ";
        }

        cin >> response;

        switch(response){
        case 0:
            break;
        case 1://Search
            try{
                cout << "*****\nSearch:\n"
                     << "Please format search in the following 3 ways:\n"
                     << "\n\t<space separated search terms> : Defaults to AND Search\n"
                     << "\tAND <space separated search terms> : AND Search\n"
                     << "\tOR <space separated search terms> : OR Search\n"
                     << "\nOptional: NOT <space separated exclude terms> : Excludes NOT Terms\n"
                     << "\n\nSearch: ";

                getline(std::cin, trash);
                getline(std::cin,searchterms);

                notpos=searchterms.find("NOT");
                if(notpos!=std::string::npos){
                    notterms=searchterms.substr(notpos+4,string::npos);
                    searchterms.erase(notpos-1,string::npos);
                    notflag=true;
                }

                searchterms.append(" ");

                notpos=searchterms.find("AND");
                if(notpos!=std::string::npos){
                    searchterms.erase(searchterms.begin(),searchterms.begin()+4);
                    andflag=true;
                }

                notpos=searchterms.find("OR");
                if(notpos!=std::string::npos){
                    searchterms.erase(searchterms.begin(),searchterms.begin()+3);
                    orflag=true;
                }

                cout << "\nSearching for " <<searchterms << "and NOT " << notterms << ".\n";
                //cout << andflag<<orflag<< notflag <<"\n";

                if(!andflag && !orflag)
                    orflag=true;

                //cout << andflag<<orflag<< notflag <<"\n";


                //Do Search
                if(!(andflag==true&&orflag==true)){

                    if(andflag){
                        //cout << "AND:";
                        results * res=NULL;

                        iter=searchterms.find(' ');

                        //cout<< "AND" << searchterms.substr(0,iter) << ".\n";
                        res=dictionary->query(searchterms.substr(0, iter));
                        searchterms.erase(0, iter+1);
                        iter=searchterms.find(' ');

                        //cout << searchterms;

                        //cout << "here";

                        while(iter!=string::npos){
                            //cout<< "AND" << searchterms.substr(0,iter) << ".\n";
                            res=res->AND(dictionary->query(searchterms.substr(0, iter)));
                            searchterms.erase(0, iter+1);
                            iter=searchterms.find(' ');
                        }

                        res->display();

                    }else if(orflag){ //logic error, OR appears to put only intersection in list
                        cout << "OR";
                        results * res=NULL;

                        iter=searchterms.find(' ');

                        cout<< "OR" << searchterms.substr(0,iter) << ".\n";
                        res=dictionary->query(searchterms.substr(0, iter));
                        searchterms.erase(0, iter+1);
                        iter=searchterms.find(' ');

                        while(iter!=string::npos){
                            cout<< "OR" << searchterms.substr(0,iter) << ".\n";
                            res=res->OR(dictionary->query(searchterms.substr(0, iter)));
                            searchterms.erase(0, iter+1);
                            iter=searchterms.find(' ');
                        }

                        res->display();
                    }

                    if(notflag){
                        cout << "NOT";
                    }


                }else{
                    cout << "Error: Compound Binary Search Not Supported.\n";
                }

                searchterms="";
                notterms="";
                andflag=false;
                orflag=false;
                notflag=false;
            }catch( exception& e){
                cout<< "Error Thrown: \n";
                cout << e.what();
                cout << "\n";
            }
            break;
        case 2://Parse
            do{
		//update dictionary that parser uses
		cout<<"Would you like to enter a new document, or parse the WikiBooks?\n 1. WikiBooks\n 2. New File \n" << endl;
		cin<< keepparsing; //reutilization of variable, maybe changed if conflict
		if(keepparsing == '1')
		Parser entry(dictionary);
		else if (keepparsing =='2')
		{
		cout << "Please enter the filename to be parsed: ";
		cin keepparsing;
		Parser entry(dictionary, keepparsing);
		}
		else{
		cout << "Invalid input, please enter 1 for Wikibooks or 2 for New File: ";	
		cin keepparsing;
		//todo: turn this into a function to allow recalling
		}
		//WikiDumps or other file
		//Parse -> dic.addWord( key/word , filename )
		
                /*Code to actually parse a doc
                 *
                 *
                 */
                keepparsing=' ';
                cout << "Do you want to continue parsing? (y/n) Response: ";
                cin >>keepparsing;
            }while(keepparsing=='y');
            keepparsing=' ';
            cout << "\n\nRecalculating document statistics. Please Wait.\n";
            dictionary->calcFreq();
            cout << "Done.\n";
            break;

        case 3://Toggle Advanced Menu - Done!
            advancedmenu=!advancedmenu;
            break;

        case 4://Toggle AVL/Hash Table Mode. - Done! (Unless we get Hash Tables)
            if(advancedmenu){
                cout << "\n\n\n\n______________________________________________________________\n";
                cout << "\n\n*-*-*Hash Table Mode Disabled. Implementation not complete.*-*-*\n\n";
                cout << "\n______________________________________________________________\n";
            }
            break;

        case 5://Stress Test Mode
            if(advancedmenu){

            }
            break;
        case 6://Clear All Documents -Done
            if(advancedmenu){
                cout <<"            .-\"\"\"\"\"-.\n           /         \\\n  .-.      |  _   _  |      .-.\n (_. '._   | |_\ /_| |   _.' ._)\n    '-._'-.(_   A   _).-'_.-'\n        '-._| _____ |_.-'\n       _.-\'_\`\"\"\"\"\"`/_\'-._\n  .-.-\'_.-\'  `-----\'  \'-._\'-.-.\n (,_.\'`                   `\'._,)\n";
                cout <<"\n\nAre you sure you want to clear the index? (Y/n) \nResponse: ";
                cin >> clearDocs;
                if(clearDocs=='Y'){
                    cout << "\n\n\n---------------------------------------\n";
                    cout << "This is IRREVERSIBLE and will DUMP THE INDEX!\n\n\nAre you absolutely sure? (y/N) ";
                    cin >> clearDocs2;
                    if(clearDocs2=='y')
                        delete dictionary;
                        dictionary = new Dictionary(avlmode);

                }
                clearDocs=' ';
                clearDocs2=' ';
            }
            break;

        case 9://Exit - Done!
            cout << "Are you sure you want to exit? (Y/n)\nResponse: ";
            cin >> exitLoop;
            if(exitLoop=='Y'){
                cout << "\n\n\n---------------------------------------\n";
                cout << "This is IRREVERSIBLE and will DUMP THE INDEX!\n\n\nAre you absolutely sure? (y/N) ";
                cin >> exitLoop2;
                if(exitLoop2=='y')
                    exit=true;
            }
            exitLoop=' ';
            exitLoop2=' ';
            break;
        }

        response=0;

    }



    /*
    cout << argv[1] <<endl;

    Parser parseEntry(argv[1]);//create a parser object; should be argv[0]?

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
    */
    return 0;
}

