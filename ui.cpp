/*
 * ui.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: Louis
 */
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <locale>
#include <algorithm>

#include "ui.h"
#include "send.h"
#include "receive.h"
using namespace std;

string input;
string mode;

void getUserInput(){
    string text;
    cout << "Send or Receive?: ";
    getline(cin, text);

    if(text[0] == 's' || text[0] == 'S'){
        mode = "send";
        cout << "Input your text: ";
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
    }
    else if(text[0] == 'r' || text[0] == 'R'){
        mode = "receive";
        cout << "Input coded text: ";
        getline(cin, input);
    }
    else{
        mode = "error";
    }
}

string getInputString(){
    return input;
}

void writeToScreen(){
    string output;

    if(mode == "send"){
        output = getSendOutput(input);
    }
    if(mode == "receive"){
        output = getReceiveOutput(input);
    }

    cout << endl << output;
}
