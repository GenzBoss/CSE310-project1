//
// Created by cse310 on 2/5/22.
//

#include "Milestone.h"
#include "iostream"
using namespace std;

int main(int argc, char* argv[])
 {
    milestone encoder = milestone();
    encoder.Encode1(argv[1]);
    encoder.binarytree();
    encoder.encoding();
    encoder.reverseBit();
    encoder.printencode();
   /*
     int extra = 0;

     while(N_alpha != 1)
     {

         tree t;
         symbol tee;
         t.root = &tee;
         for(int i = 0; i < E_LEN; i++)
             tee.encoding[i] = 0;
         tee.parent = NULL;
         tee.left = alpha[0].root;
         tee.right = alpha[1].root;
         alpha[0].root->parent = &tee;
         alpha[1].root->parent = &tee;
         t.freq = alpha[0].freq + alpha[1].freq;
         tee.freq = t.freq;
         t.index = 129 + extra;
         extra++;

         for (int i = 0; i < N_alpha - 1; i++) {
             alpha[i] = alpha[i + 1];
         }

         N_alpha--;
         alpha[0] = t;
         insertionsort(alpha, N_alpha);
         }

    while(N_nonalpha != 1)
    {
        tree t;
        symbol tee;
        t.root = &tee;
        tee.parent = NULL;
        for(int i = 0; i < E_LEN; i++)
            tee.encoding[i] = 0;
        tee.left = nonalpha[0].root;
        tee.right = nonalpha[1].root;
        nonalpha[0].root->parent = &tee;
        nonalpha[1].root->parent = &tee;
        t.freq = nonalpha[0].freq + nonalpha[1].freq;
       // cout<<t.freq<< "\t" << nonalpha[0].freq << nonalpha[1].freq<<endl;
        tee.freq = t.freq;
        t.index = 129 + extra;
        extra++;

        for (int i = 0; i < N_nonalpha - 1; i++) {
            nonalpha[i] = nonalpha[i + 1];
        }
        N_nonalpha--;
        nonalpha[0] = t;
        insertionsort(nonalpha, N_nonalpha);
    }

    ROOT.parent = NULL;
    for(int i = 0; i < E_LEN; i++)
        ROOT.encoding[i] = 0;
    ROOT.freq = alpha[0].freq + nonalpha[0].freq;
    ROOT.left = alpha[0].root;
    ROOT.right= nonalpha[0].root;
    alpha[0].root->parent = &ROOT;
    nonalpha[0].root->parent = &ROOT;

            */

/* if(root->left == NULL && root->right == NULL){
        root->encoding[level] = '\0';
        return;
    }



    encoding(root->left, true, false, level);

    encoding(root->right, false, true, level);

    if(L == true)
        root->encoding[level] = '0';
    if(R == true)
        root->encoding[level] = '1';

    level++;

*/

     }