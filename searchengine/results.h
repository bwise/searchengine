#ifndef RESULTS_H
#define RESULTS_H
#include <string>
#include <vector>
#include "filerecord.h"
#include <iomanip>
#include <algorithm>

class FileRecord;

class results
{

private:
    struct frs{
        FileRecord * fr;
        double tfidf;
        bool operator<(frs) const;
    };
    string name;
    void sort();
    vector<frs> frstruct;
public:
    results();
    void add(FileRecord*,double);
    results *AND(results*);
    results *OR(results*);
    results *NOT(results*);
    results *display();
    void openresult(int);

};

#endif // RESULTS_H
