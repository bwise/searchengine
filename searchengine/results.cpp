#include "results.h"

results::results()
{
}

results::AND(results* a){
    bool inboth=false;

    for(int my=0; my<this->fr.size() ;my++){
        inboth=false;

        for(int their=0; their<a->fr.size(); their++ )
            if(this->fr[my]->getName()==a->fr[their]->getName()){
                inboth=true;
                break;
            }

        if(!inboth)
            this->fr.erase(this->fr.begin()+my);
    }
}

results::NOT(results a){ // here check logic
    bool inboth=false;

    for(int my=0; my<this->fr.size() ;my++){
        inboth=false;

        for(int their=0; their<a->fr.size(); their++ )
            if(this->fr[my]->getName()==a->fr[their]->getName()){
                inboth=true;
                break;
            }

        if(inboth)
            this->fr.erase(this->fr.begin()+my);
    }
}
}

results::OR(results a){

}
