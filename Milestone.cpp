//
// Created by cse310 on 2/4/22.
//

#include "Milestone.h"
#include <iostream>
#include <string>



using namespace std;

milestone::milestone()
 {
    for(int i = 0; i < NSYMBOLS; i++)
    {
        prep[i].symbol = i;
        prep[i].freq = 0;
        prep[i].parent= NULL;

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
                if (str.at(i) == prep[j].symbol)
                {
                    prep[j].freq++;
                    if(max < j)
                        max =j;
                }
            }
        }

        prep[10].freq++;
    }


    for (int j = 0; j < NSYMBOLS; j++)
    {
        if (prep[j].freq != 0)
        {
            if(j != max)
                cout << j << "\t" << prep[j].freq << "\n";
            else
                cout<<j << "\t"<< prep[j].freq;
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