// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - Hacker header

#include <iostream>
#ifndef HACKER_H
#define HACKER_H

using namespace std;

class Hacker{

    private:
        string name;
        int level;
        bool defeated;

    public:
        Hacker(){
            name = "";
            level = 1;
            defeated = false;
        }

        void setName(string str){
            name = str;
        }
        string getName(){
            return name;
        }

        void setLevel(int lvl){
            level = lvl;
        }
        int getLevel(){
            return level;
        }

        void setDefeated(bool test){
            defeated = test;
        }

        bool getDefeated(){
            return defeated;
        }

};

#endif