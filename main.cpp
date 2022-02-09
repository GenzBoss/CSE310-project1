//Project 1
// Created by Burhanuddin Barafwala on 2/5/22.
//main.cpp handles the preprocessing


#include "Milestone.h"



int main() {
    //create object of milstone
    milestone project = milestone();
    //do the preprocessing
    project.preprocessor();
    //redirect the output to text file
    project.preprocprint();
    return 0;
}
