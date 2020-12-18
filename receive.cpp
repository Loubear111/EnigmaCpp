/*
 * receive.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: Louis
 */

#include <string>

#include "receive.h"
using namespace std;

string ualpha[41] = {"a", "b", "c", "d", "e", "f",
                    "g", "h", "i", "j", "k", "l",
                    "m", "n", "o", "p", "q", "r",
                    "s", "t", "u", "v", "w", "x",
                    "y", "z", " ", ".", "'", ",",
                    "?", "!", "1", "2", "3", "4",
                    "5", "6", "7", "8", "9"};

string diffAlpha[41] = {};

void populateAlpha(string input){
    for(int n=0; n<41; n++){
        string letter(1, input[n]);
        //diffAlpha[n] = ((char*)&input[n]);
        diffAlpha[n] = letter;
    }
}

string rconvert(string input){
    string retval;

    populateAlpha(input);
    for(unsigned int n=41; n<input.length(); n++){
        string letter(1, input[n]);
        for(int x=0; x<41; x++){
            if(letter == diffAlpha[x]){
                retval.append(ualpha[x]);
            }
        }
    }

    return retval;
}

string getReceiveOutput(string input){
    string output = rconvert(input);
    return output;
}
