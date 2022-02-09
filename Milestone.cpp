//
// Created by cse310 on 2/4/22.
//

#include "Milestone.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

milestone::milestone()
 {
    N_alpha = 0;
    N_nonalpha = 0;
    for(int i = 0; i < NSYMBOLS; i++)
    {
        Symbols[i].symbol = i;
        Symbols[i].freq = 0;
        Symbols[i].parent= NULL;
        Symbols[i].left= NULL;
        Symbols[i].right = NULL;
        for(int j = 0; j < E_LEN; j++)
        Symbols[i].encoding[j] = 0;

    }


 }

void milestone::preprocessor()
 {
    string str;
    int max = -1;


    while (getline(cin, str))
    {
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = 0; j < NSYMBOLS; j++)
            {
                if (str.at(i) == Symbols[j].symbol)
                {
                    Symbols[j].freq++;
                    if(max < j)
                        max = j;
                }
            }
        }

        Symbols[10].freq++;
    }


     rewind(stdin);

   /* for (int j = 0; j < NSYMBOLS; j++)
    {
        if (prep[j].freq != 0)
        {
            //if(j != max)
                cout << j << "\t" << prep[j].freq << "\n";
            //else
              //  cout<<j << "\t"<< prep[j].freq;
        }


    }


   /* freopen("/dev/tty", "a", stdout);
    for (int j = 0; j < NSYMBOLS; j++)
    {
        if (prep[j].freq != 0)
        {
            cout << j << "\t" << prep[j].freq << "\n";


        }

    }
   */
 }

 void  milestone::preprocprint()
 {
     for (int j = 0; j < NSYMBOLS; j++)
     {
         if (Symbols[j].freq != 0)
         {
             //if(j != max)
             cout << j << "\t" << Symbols[j].freq << "\n";
             //else
             //  cout<<j << "\t"<< prep[j].freq;
         }


     }
 }

 void  milestone:: Encode1(string prefile)
 {
    ifstream fin(prefile);

    int ascii;
    int no = 1;
    while(fin>>ascii)
    {
      if(no%2 == 0)
      {}
      else
        {
          if((ascii > 64 && ascii < 91 || ascii > 96 && ascii < 123))
                N_alpha++;
          else
                N_nonalpha++;
        }
      no++;
    }
     fin.clear();
     fin.seekg(0);
     int i = 0;
     int j = 0;
     alpha = new tree[N_alpha];
     nonalpha = new tree[N_nonalpha];
     while(fin>>ascii)
     {
         if((ascii > 64 && ascii < 91 || ascii > 96 && ascii < 123))
         {
             alpha[i].index = ascii;
             alpha[i].symbol = ascii;
             alpha[i].root = &Symbols[ascii];
             fin>>ascii;
             Symbols[alpha[i].index].freq = ascii;
             alpha[i].freq = ascii;
             i++;
         }
         else
         {
             nonalpha[j].index = ascii;
             nonalpha[j].symbol = ascii;
             nonalpha[j].root = &Symbols[ascii];
             fin>>ascii;
             Symbols[alpha[i].index].freq = ascii;
             nonalpha[j].freq = ascii;
             j++;

         }
     }

     total = N_alpha + N_nonalpha;

 }

void milestone::insertionsort( tree array[], int size)

{


        for (int step = 1; step < size; step++)
        {
            tree key = array[step];
            int j = step - 1;

            // Compare key with each element on the left of it until an element smaller than
            // it is found.
            // For descending order, change key<array[j] to key>array[j].
            while (key.freq < array[j].freq && j >= 0 || key.freq == array[j].freq && key.index < array[j].index && j>=0)
            {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = key;

        }

}

symbol* milestone:: createNode()
{
    symbol *node = (struct symbol*) malloc(sizeof (struct symbol));
    node->freq = 0;
    node->symbol= 0;
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    for(int i = 0; i < E_LEN; i++)
       node->encoding[0] = 0;

    return node;
}

void milestone::binarytree() {
    //make condition for 1 symbol only

    insertionsort(alpha, N_alpha);
    insertionsort(nonalpha, N_nonalpha);

    int l = 0;
    if (N_alpha == 1) {

    } else {
        while (N_alpha > 1) {
            tree t;
            node_t = createNode();
            alpha[0].root->parent = node_t;
            alpha[1].root->parent = node_t;
            node_t->left = alpha[0].root;
            node_t->right = alpha[1].root;
            node_t->freq = alpha[0].freq + alpha[1].freq;

            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < N_alpha - 1; i++) {
                    alpha[i] = alpha[i + 1];
                }

            }
            t.root = node_t;
            t.symbol = 0;
            N_alpha--;

            alpha[N_alpha - 1] = t;
            alpha[N_alpha - 1].root = node_t;
            alpha[N_alpha - 1].freq = node_t->freq;
            alpha[N_alpha - 1].index = 129 + l;
            l++;
            insertionsort(alpha, N_alpha);

        }

        while (N_nonalpha > 1) {
            tree t;
            node_t = createNode();
            node_t->left = nonalpha[0].root;
            node_t->right = nonalpha[1].root;
            nonalpha[0].root->parent = node_t;
            nonalpha[1].root->parent = node_t;
            node_t->freq = nonalpha[0].freq + nonalpha[1].freq;
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < N_nonalpha - 1; i++) {
                    nonalpha[i] = nonalpha[i + 1];
                }

            }
            t.root = node_t;
            t.symbol = 0;
            N_nonalpha--;

            nonalpha[N_nonalpha - 1] = t;
            nonalpha[N_nonalpha - 1].root = node_t;
            nonalpha[N_nonalpha - 1].freq = node_t->freq;
            nonalpha[N_nonalpha - 1].index = 129 + l;
            l++;
            insertionsort(nonalpha, N_nonalpha);


        }

        ROOT = createNode();
        ROOT->left = alpha[0].root;
        ROOT->right = nonalpha[0].root;
        alpha[0].root->parent = ROOT;
        nonalpha[0].root->parent = ROOT;
        ROOT->freq = alpha[0].freq + nonalpha[0].freq;


    }
}

void milestone::encoding() {


    symbol *node = createNode();
    symbol *currNode = createNode();
    for (int i = 0; i < NSYMBOLS; i++) {


        int level = 0;
        node = Symbols[i].parent;
        currNode = &Symbols[i];
        if (node != nullptr) {
            while (node != NULL) {
                if (node->left == currNode) {
                    Symbols[i].encoding[level] = '0';
                    level++;
                } else if (node->right == currNode) {
                    Symbols[i].encoding[level] = '1';
                    level++;
                }

                currNode = node;
                node = node->parent;
            }

            Symbols[i].encoding[level] = '\0';
        }
    }



 }

 void milestone::reverseBit()
 {
     for (int i = 0; i < NSYMBOLS; i++)
         if (Symbols[i].parent != NULL) {
             string bit = Symbols[i].encoding;
             int s=0;
             int f = bit.size() - 1;
             while(s < f){
                 char temp = Symbols[i].encoding[f];
                 Symbols[i].encoding[f] = Symbols[i].encoding[s];
                 Symbols[i].encoding[s] = temp;
                 s++;
                 f--;

             }
         }
 }
    void milestone::printencode() {

        cout<<total<<endl;
        for(int i = 0; i < NSYMBOLS; i++)
        {
            if(Symbols[i].parent != NULL)
            {
                cout<<i<< "\t" << Symbols[i].symbol<<"\t"<<Symbols[i].encoding<<"\n";
            }
        }
        cout<<endl;
        string str;
        while(getline(cin,str))
        {
            for (int i = 0; i < str.length(); i++) {
                for (int j = 0; j < NSYMBOLS; j++) {
                    if (str.at(i) == Symbols[j].symbol) {
                        cout<<Symbols[j].encoding;
                    }
                }
            }
                        cout<<Symbols[10].encoding;
        }


    }
