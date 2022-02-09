//Project 1
// Created by Burhanuddin Barafwala on 2/4/22.
//implements the headerfile has all of the required functions for both preprocessing ans encoding

#include "Milestone.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

//initialise all the pointers to null and encoding can be set to '\0' or 0 I have chosen the latter cuz of preference and understanding
//this is the constructor

milestone::milestone()
 {
    N_alpha = 0;    //size of alpha array
    N_nonalpha = 0; //size of nonalpha array
    for(int i = 0; i < NSYMBOLS; i++)
    {
        Symbols[i].symbol = i;   //symbol is the index itslef
        Symbols[i].freq = 0;     //freq
        Symbols[i].parent= NULL; //parent
        Symbols[i].left= NULL;   // left
        Symbols[i].right = NULL; // right
        for(int j = 0; j < E_LEN; j++)
        Symbols[i].encoding[j] = 0; // encoding

    }


 }

void milestone::preprocessor()
 {
    string str;  //str to store our line from file
    int max = -1; //this max does not do anything i used this to find the max index which has freq!= 0


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

        Symbols[10].freq++;  //getline removes new line but while loop means there is a new line so we can do this
    }

//my attempt to rewind stdin failed

    //rewind(stdin);

  //if you want to print in console just for fun

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
    //print the output for preprocessing and redirect to pre.txt file
     for (int j = 0; j < NSYMBOLS; j++)
     {
         if (Symbols[j].freq != 0)
         {
             cout << j << "\t" << Symbols[j].freq << "\n";

         }


     }
 }

 void  milestone:: Encode1(string prefile)
 {
    //i create a file object and then read numbers in it to make my symbols array, alpha array and nonalpha array
    //we take argument from the command line
    ifstream fin(prefile);

    int ascii;
    int no = 1;
    while(fin>>ascii)
    {
        //we wanna count alpha and nonalpha size only for 1st number in line second number is the freq
      if(no%2 != 0)
        {
          if((ascii > 64 && ascii < 91 || ascii > 96 && ascii < 123))
                N_alpha++;
          else
                N_nonalpha++;
        }
      no++;
    }
    //I clear my file object and then reset it to start of the text file using seekg(0);
     fin.clear();
     fin.seekg(0);
     int i = 0;
     int j = 0;
     alpha = new tree[N_alpha];
     nonalpha = new tree[N_nonalpha];
     //now i am using this to make the actual alpha array and nonalpha array after taking their size and also i am making my SYMBOLS array
     //hitting two stone with one
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
//my total variable know total symbols
     total = N_alpha + N_nonalpha;

 }

void milestone::insertionsort( tree array[], int size)

{

//i use this to sort my arrays
        for (int step = 1; step < size; step++)
        {
            tree key = array[step];
            int j = step - 1;

            // Compare key with each element on the left of it until an element with frequency smaller than
            // it is found.If both have same frequency sort with index
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
    //this is a helper function to help me create nodes of type symbol which are allocated in heap so they dont get destroyed on their own and end up with garbage values
    symbol *node = (struct symbol*) malloc(sizeof (struct symbol));   //malloc is used for heap allocation
    node->freq = 0;
    node->symbol= 0;
    node->parent = nullptr;
    node->left = nullptr;    //doing the same old as constructor
    node->right = nullptr;
    for(int i = 0; i < E_LEN; i++)
       node->encoding[0] = 0;    //I do this cuz of my preference and understanding

    return node;
}

void milestone::binarytree() {
    //this code needs to be upgraded for if you have only 1 symbol

    //first sort the arrays
    insertionsort(alpha, N_alpha);
    insertionsort(nonalpha, N_nonalpha);

    int l = 0;
    if (N_alpha == 1) { //needs upgrade this is beyond the scope of milestone and is not required

    } else {
        while (N_alpha > 1) {
            //create data tree to put in alpha or nonalpha arrays will have Symbol Node
            tree t;
            node_t = createNode();  //heap allocate
            alpha[0].root->parent = node_t;   //create the correct connections between the nodes to form binary tree
            alpha[1].root->parent = node_t;
            node_t->left = alpha[0].root;
            node_t->right = alpha[1].root;
            node_t->freq = alpha[0].freq + alpha[1].freq;  //freq = 1st plus 2nd element

            //make array smaller by two
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < N_alpha - 1; i++) {
                    alpha[i] = alpha[i + 1];
                }

            }
            t.root = node_t;
            t.symbol = 0;
            N_alpha--;
            //add the new node
            alpha[N_alpha - 1] = t;
            alpha[N_alpha - 1].root = node_t;
            alpha[N_alpha - 1].freq = node_t->freq;
            alpha[N_alpha - 1].index = 129 + l;
            l++;
            insertionsort(alpha, N_alpha);
            //sort and repeat till we have only 1 element in array
        }

        //do the same thing as above for nonaplha array exactly the same things
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


        } //repeat till 1 index

        //create a ROOT NODE which will combine the nonalpha tree and alpha tree
        ROOT = createNode();
        ROOT->left = alpha[0].root;
        ROOT->right = nonalpha[0].root;   //create the correct connections for pointers
        alpha[0].root->parent = ROOT;
        nonalpha[0].root->parent = ROOT;
        ROOT->freq = alpha[0].freq + nonalpha[0].freq;  //total frequency


    }
}

void milestone::encoding() {

   //now we move to assigning the encoding to symbols based on symbol and position in binary tree
    symbol *node = createNode();
    symbol *currNode = createNode();
    for (int i = 0; i < NSYMBOLS; i++) {


        int level = 0;
        node = Symbols[i].parent;  //start from bottom(leaf nodes) go to top of tree
        currNode = &Symbols[i];  //our current position
        if (node != nullptr) {
            while (node != NULL) {         //till we reach top keep going *condition*
                if (node->left == currNode) {   //if parent left leads to leaf node we add 0 to our encoding
                    Symbols[i].encoding[level] = '0';
                    level++;
                } else if (node->right == currNode) {  //if right then we put 1 and keep moving for both cases
                    Symbols[i].encoding[level] = '1';
                    level++;
                }

                currNode = node;   //update the nodes
                node = node->parent;  //update the parent meaning we moved up
            }

            Symbols[i].encoding[level] = '\0';  // after we are done terminate the char array so we can print like string
        }
    }



 }

 void milestone::reverseBit()
 {
    //reverse my char array because we moved bottom to up our bits are in reversed order
     for (int i = 0; i < NSYMBOLS; i++)
         if (Symbols[i].parent != NULL) {
             string bit = Symbols[i].encoding;   //put in string
             int s=0;    //start index
             int f = bit.size() - 1;  //final index   size() give lenght
             while(s < f){
                 char temp = Symbols[i].encoding[f];
                 Symbols[i].encoding[f] = Symbols[i].encoding[s];    //create temp and swap the indexes
                 Symbols[i].encoding[s] = temp;
                 s++;  //s moves forward
                 f--; //f move backward

             }
         }
 }
    void milestone::printencode() {

    //FINAL STEP YAY
    //PRINT THE REQUIRED OUTPUT
    //we use input redirection to get our endcoded textfile
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
     //we are done thank you