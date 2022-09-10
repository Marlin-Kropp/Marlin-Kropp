// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - NPC member functions

#include <iostream>
#include "NPC.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

NPC::NPC(){
    name = "";
    srand(time(NULL));
    friendStatus = rand() % 3; // set to random integer between 0 and 2
}

NPC::NPC(string temp){
    name = temp;
    srand(time(NULL));
    friendStatus = rand() % 3;
}

void NPC::setName(string temp){
    name = temp;
    return;
}

string NPC::getName(){
    return name;
}

int NPC::getFriendStatus(){
    return friendStatus;
}

void NPC::puzzle(){
    //TODO: Give a puzzle to the user and determine the output
    return;
}

void NPC::noPuzzle(){
    //TODO: based on friend status give out or take away computer parts
    return;
}