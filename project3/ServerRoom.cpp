// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - Server Room Member Functions

#include <iostream>
#include "ServerRoom.h"

using namespace std;

ServerRoom::ServerRoom(){
    numHackersDefeated = 0;
    level = 1;
    cleared = false;
    npc = NPC();
}

ServerRoom::ServerRoom(int lvl){
    numHackersDefeated = 0;
    level = lvl;
    cleared = false;
    npc = NPC();
}

int ServerRoom::getNumHackersDefeated(){
    return numHackersDefeated;
}

int ServerRoom::getLvl(){
    return level;
}

void ServerRoom::clearRoom(){
    cleared = true;
    return;
}


//check at the end of each turn
void ServerRoom::checkClear(){
    if (hackers.size() == 0){
        clearRoom();
    }
    return;
}

bool ServerRoom::getClear(){
    return cleared;
}

void ServerRoom::defeatHacker(){
    hackers.pop_back(); // fix this with the attack function in the player class
    numHackersDefeated++;
    return;
}

void ServerRoom::addHacker(Hacker name){
    hackers.push_back(name);
}
