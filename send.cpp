/*
 * send.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: Louis
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <windows.h>
#include "send.h"

using namespace std;

string alpha[41] = {"a", "b", "c", "d", "e", "f",
                    "g", "h", "i", "j", "k", "l",
                    "m", "n", "o", "p", "q", "r",
                    "s", "t", "u", "v", "w", "x",
                    "y", "z", " ", ".", "'", ",",
                    "?", "!", "1", "2", "3", "4",
                    "5", "6", "7", "8", "9"};

string order = "";
string output = "";

/* Private Functions -------------------------------------------------------*/

string convert(string input){
    string output;
    string newInput;

    //binaryish array which says whether a letter has been used already... see below
    int used[41] = {0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0};
    string newAlpha[41] = {};

    for(int n=0; n<41;){
        int num = rand() % 42 + 1;
        num = num - 1;

        //This if checks to see if we have used this letter before and if so it won't iterate the for loop
        //and will make it generate a new random letter until it gets one that hasn't been used before(could this be
        //improved because currently that can use a lot of resources...
        if(used[num] == 0){
            order.append(alpha[num]);
            newAlpha[num] = alpha[num];
            n++;
            //Sleep(1); //Sleep for 5 ms or else the random function gets pissed
            used[num] = 1;
        }
        else{
            //Sleep(1); //Sleep for 5 ms or else the random function gets pissed
        }
    }

    for(int n=0; n<41; n++){
        string newVal(1, order[n]);
        newAlpha[n] = newVal;
    }

    for(unsigned int x=0; x<input.length(); x++){
        string letter(1, input[x]);
        for(int n=0; n<41; n++){
            if(alpha[n] == letter){
                newInput.append(newAlpha[n]);
            }
        }
    }

    output = order;
    output.append(newInput);

    return output;
}

void runEncode(string originalInput){
    srand((int) time(0));
    output = convert(originalInput);
    order = "";
}

/* Public Functions -------------------------------------------------------*/

string getSendOutput(string origInput){
    output = "";
    runEncode(origInput);
    return output;
}
