//
// Created by cse310 on 2/4/22.
//

#ifndef PROJECT1_MILESTONE_H
#define PROJECT1_MILESTONE_H
#include "defns.h"
#include <string>
using namespace std;

class milestone {
    int N_alpha;
    int N_nonalpha;
    symbol Symbols[NSYMBOLS];
    tree *alpha;
    tree *nonalpha;
    symbol *ROOT;
    symbol * node_t;
    int total;



  public:
    milestone();
    void preprocessor();
    void preprocprint();
    void Encode1(string prefile);
    void insertionsort(tree array[], int size);
    symbol* createNode();
    void binarytree();
    void encoding();
    void reverseBit();
    void printencode();

};


#endif //PROJECT1_MILESTONE_H
