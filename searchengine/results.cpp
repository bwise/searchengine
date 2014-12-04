#include "results.h"

results::results()
{
    frstruct.clear();
}

void results::add(FileRecord * a, double b){
    frs c;
    c.fr=a;
    c.tdidf=b;
    frstruct.push_back(c);
}

void results::AND(results* a){
    bool inboth=false;

    for(int my=0; my<this->frstruct.size() ;my++){
        inboth=false;

        for(int their=0; their<a->frstruct.size(); their++ )
            if(this->frstruct[my].fr->getName()==a->frstruct[their].fr->getName()){
                inboth=true;
                break;
                this->frstruct[my].tdidf+=a->frstruct[my].tdidf;
            }

        if(!inboth)
            this->frstruct.erase(this->frstruct.begin()+my);
    }
}

void results::NOT(results* a){ // here check logic
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
}

void results::OR(results* a){
    bool inboth=false;

    for(int my=0; my<this->frstruct.size() ;my++){
        inboth=false;

        for(int their=0; their<a->frstruct.size(); their++ )
            if(this->frstruct[my].fr->getName()==a->frstruct[their].fr->getName()){
                inboth=true;
                break;
                this->frstruct[my].tdidf+=a->frstruct[my].tdidf;
            }

        if(inboth)
            a->frstruct.erase(this->frstruct.begin()+my);
    }

    for(int their=0; their<a->frstruct.size(); their++)
        this->frstruct.push_back(a->frstruct[their]);

}

bool results::frs::operator<(frs j) const{
    return tdidf > j.tdidf;
}

void results::sort(){

    std::sort(frstruct.begin(), frstruct.end());

}

void results::display(){

    int howmany=10;

    if(frstruct.size()<howmany)
        howmany=frstruct.size();


    this->sort();


    for(int i=0; i<howmany; i++)
        cout << i+1 << "\t" << frstruct[i].fr->getName()
                << "\tRank: " << setprecision (15) << frstruct[i].tdidf <<"\n";

}
