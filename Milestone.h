//Project 1
// Created by Burhanuddin Barafwala on 2/5/22.
//milestone.h has the header file for milestone class

#ifndef PROJECT1_MILESTONE_H
#define PROJECT1_MILESTONE_H
#include "defns.h"
#include <string>
using namespace std;

class milestone {
    //our data is private we use it to execute our project

    int N_alpha;   //for encode
    int N_nonalpha; //for encode
    symbol Symbols[NSYMBOLS]; //for both
    tree *alpha; // our dynamic array for alphabets
    tree *nonalpha; // our dynamic array for non alphabets
    symbol *ROOT; // the top of the binary tree
    symbol * node_t; // our new nodes in binary tree
    int total;    // total symbols



  public:
    //constructor
    milestone();
    //take the input values and complete the preprocessing
    void preprocessor();
    //print the output to text for preprocessing
    void preprocprint();
    //start encoding by taking the preprocessed text file
    void Encode1(string prefile);
    //helper function for sorting arryas
    void insertionsort(tree array[], int size);
    //creates heap allocated nodes
    symbol* createNode();
    //create the entire binary tree
    void binarytree();
    //create the encoding for symbols
    void encoding();
    //reverse the bitstring
    void reverseBit();
    //output (redirect) the encoding to text file
    void printencode();

};


#endif //PROJECT1_MILESTONE_H
