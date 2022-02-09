//Project 1
// Created by Burhanuddin Barafwala on 2/5/22.
//main2.cpp handles the encoding

#include "Milestone.h"
#include "iostream"
using namespace std;

int main(int argc, char* argv[])
 {
    //simple main file just create object of milestone class and call the required functions in right order

    milestone encoder = milestone();
    encoder.Encode1(argv[1]); //get the arrays
    encoder.binarytree();  // build the tree
    encoder.encoding();  // encode the symbols
    encoder.reverseBit(); //reverse the encoding bits
    encoder.printencode(); // print to text file


     }