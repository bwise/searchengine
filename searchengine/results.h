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
        double tdidf;
        bool operator<(frs) const;
    };
    string name;
    void sort();
    vector<frs> frstruct;
public:
    results();
    void add(FileRecord*,double);
    void AND(results*);
    void OR(results*);
    void NOT(results*);
    void display();

};

#endif // RESULTS_H
