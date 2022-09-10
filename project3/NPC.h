// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - NPC header

#include <iostream>
#ifndef NPC_H
#define NPC_H

using namespace std;

class NPC{
    private:
        string name;
        int friendStatus;

    public:
        NPC();

        NPC(string temp);

        void setName(string temp);

        string getName();
        
        int getFriendStatus();

        void puzzle();

        void noPuzzle();

};

#endif