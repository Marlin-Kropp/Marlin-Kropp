// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - Server Room header

#include <iostream>
#include <vector>
#include "NPC.h"
#include "Hacker.h"
#ifndef SERVERROOM_H
#define SERVERROOM_H

using namespace std;

class ServerRoom{

    private:
        int numHackersDefeated;
        bool cleared;
        int level;
        vector<Hacker> hackers; // use to store hackers
        NPC npc;
    
    public:
        //constructors
        ServerRoom();

        ServerRoom(int lvl);

        //getters/setters
        int getNumHackersDefeated();

        int getLvl();

        void clearRoom();

        bool getClear();

        void addHacker(Hacker name);


        //other member functions
        void playRoom();
        
        void defeatHacker();

        void checkClear();
    
};

#endif