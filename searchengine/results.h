#ifndef RESULTS_H
#define RESULTS_H
#include <string>
#include <vector>
#include "filerecord.h"

class results
{
public:
    results();
    void AND(results);
    void OR(results);
    void NOT(results);
private:
    string name;
    vector<FileRecord *> fr;
};

#endif // RESULTS_H
