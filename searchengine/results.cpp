#include "results.h"

results::results()
{
    frstruct.clear();
}

void results::add(FileRecord * a, double b){
    frs c;
    c.fr=a;
    c.tfidf=b;
    frstruct.push_back(c);
}

results* results::AND(results* a){
    bool inboth=false;

    for(int my=0; my<this->frstruct.size() ;my++){
        inboth=false;

        for(int their=0; their<a->frstruct.size(); their++ )
            if(this->frstruct[my].fr->getName()==a->frstruct[their].fr->getName()){
                inboth=true;
                this->frstruct[my].tfidf+=a->frstruct[their].tfidf;
                break;
            }

        if(!inboth){
            this->frstruct.erase(this->frstruct.begin()+my);
            my--;
        }
    }
    return this;
}

results * results::NOT(results* a){ // here check logic
    bool inboth=false;

    for(int my=0; my<this->frstruct.size() ;my++){
        inboth=false;

        for(int their=0; their<a->frstruct.size(); their++ )
            if(this->frstruct[my].fr->getName()==a->frstruct[their].fr->getName()){
                inboth=true;
                break;
                //this->frstruct[my].tdidf+=a->frstruct[my].tdidf;
            }

        if(inboth)
            this->frstruct.erase(this->frstruct.begin()+my);
    }
    return this;
}

results* results::OR(results* a){
    bool inboth=false;

    for(int my=0; my<this->frstruct.size() ;my++){
        inboth=false;

        for(int their=0; their<a->frstruct.size(); their++ )
            if(this->frstruct[my].fr->getName()==a->frstruct[their].fr->getName()){
                inboth=true;
                this->frstruct[my].tfidf=this->frstruct[my].tfidf+a->frstruct[their].tfidf;
                break;
            }

        if(inboth)
            a->frstruct[my].fr=NULL;
    }


    for(int their=0; their<a->frstruct.size(); their++)
        if(a->frstruct[their].fr==NULL)
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

    if(this==NULL){
        cout<< "\nNo results found!\n";
        return NULL;
    }

    int howmany=10;

    if(frstruct.size()<howmany)
        howmany=frstruct.size();


    this->sort();


    for(int i=0; i<howmany; i++)
        cout << i+1 << "\t" << frstruct[i].fr->getName()
                << "\tRank: " << setprecision (15) << frstruct[i].tfidf <<"\n";

    return this;

}
