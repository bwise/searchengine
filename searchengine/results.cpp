#include "results.h"

results::results()
{
    //cout << "Results enstant";
    frstruct.clear();
}

void results::add(FileRecord * a, double b){
    frs c;
    c.fr=a;
    c.tfidf=b;
    frstruct.push_back(c);
}

results* results::AND(results* a){
    //cout << "z";

    if(a==NULL)
        return NULL;
    if(this==NULL)
        return NULL;

    bool inboth=false;

    for(int my=0; my<this->frstruct.size() ;my++){
        inboth=false;

        //cout << "a";

        for(int their=0; their<a->frstruct.size(); their++ )
            if(this->frstruct[my].fr->getName()==a->frstruct[their].fr->getName()){
                inboth=true;
                this->frstruct[my].tfidf+=a->frstruct[their].tfidf;
                break;
            }

        if(!inboth){
            this->frstruct.erase(this->frstruct.begin()+my);
            my--;

            //cout << "here";
        }
    }
    return this;
}

results * results::NOT(results* a){
    if(a==NULL)
        return this;
    if(this==NULL)
        return NULL;

    bool inboth=false;

    for(int my=0; my<this->frstruct.size() ;my++){
        inboth=false;

        for(int their=0; their<a->frstruct.size(); their++ )
            if(this->frstruct[my].fr->getName()==a->frstruct[their].fr->getName()){
                inboth=true;
                break;
                //this->frstruct[my].tdidf+=a->frstruct[my].tdidf;
            }

        if(inboth){
            this->frstruct.erase(this->frstruct.begin()+my);
            my--;
        }
    }
    return this;
}

results* results::OR(results* a){


    if(a==NULL)
        return this;
    if(this==NULL)
        return a;


    bool inboth=false;


    for(int my=0; my<this->frstruct.size() ;my++){
        inboth=false;

        for(int their=0; their<a->frstruct.size(); their++ ){
            if(this->frstruct[my].fr->getName()==a->frstruct[their].fr->getName()){
                inboth=true;
                this->frstruct[my].tfidf=this->frstruct[my].tfidf+a->frstruct[their].tfidf;
            }

            if(inboth){
                //cout << "Erasing" << a->name << a->frstruct[their].fr->getName();
                a->frstruct.erase(a->frstruct.begin()+their);
                my--;
            }
        }
    }

    //cout << "Here";

    for(int their=0; their<a->frstruct.size(); their++)
        if(a->frstruct[their].fr!=NULL)
            this->frstruct.push_back(a->frstruct[their]);

    return this;
}

bool results::frs::operator<(frs j) const{
    return tfidf > j.tfidf;
}

void results::sort(){

    std::sort(frstruct.begin(), frstruct.end());

}

results* results::display(){
    int choice =-1;
    cout << "------------------\n";
    cout << "\n\nResults:\n";

    if(this==NULL||frstruct.size()==0){
        cout<< "\nNo results found!\n";
        return NULL;
    }

    int howmany=10;

    if(frstruct.size()<howmany)
        howmany=frstruct.size();

    //cout << howmany << frstruct[1].fr;


    this->sort();


    for(int i=0; i<howmany; i++)
        cout << i+1 << "\t" << frstruct[i].fr->getName()
                << "\tRank: " << setprecision (15) << frstruct[i].tfidf <<"\n";

    cout << "\nWould you like to open one of these results?\n";
    cout << "Pick the number of the result you would like to see: ";
    cin >> choice;

    choice-=1;

    if(choice<0 || choice > howmany)
        cout << "Invalid choice : " << choice << "\n";
    else
        this->openresult(choice);



    return this;

}

void results::openresult(int c){

    ifstream ifile(frstruct[c].fr->getName());

    string line;

    if(ifile.is_open()){
        while(getline(ifile,line))
            cout << line << '\n';
        ifile.close();
    }
    else
        cout << "Unable to open File.\n";

}
