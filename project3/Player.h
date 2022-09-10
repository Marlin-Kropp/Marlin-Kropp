// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - Player Class Header

#include <iostream>
#include <string>
#include "Hacker.h"
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {

    private:
        string name;
        int numCPU;
        int numGPU;
        int numPowerSupply;
        int numCase;
        int numCard;
        int numMouseAndKeys;
        bool premadeComputer;
        int numAntivirus;
        int numVPN;
        int internetLvl;
        int numCoin;
        int percentFilesStolen;
        int percentComputerMatinence;
        int frustrationLvl;
        int numHackersDefeated;
        int numViruses;

    public:

        // getters/setters
        Player();

        Player(string temp);

        string getName();

        void setCPU(int CPUs);

        int getCPU();

        void setGPU(int GPUs);

        int getGPU();

        void setPower(int Power);

        int getPower();

        void setCase(int Case);

        int getCase();

        void setCard(int Card);
        
        int getCard();

        void setMaK(int MaK);

        int getMaK();

        void setComputer(bool Computer);

        bool getComputer();

        void setAntivirus(int Antivirus);

        int getAntivirus();

        void setVPN(int VPN);

        int getVPN();

        void setInternet(int lvl);

        int getInternet();

        void setCoin(int Coin);

        int getCoin();

        void setFilesStolen(int FilesStolen);

        int getFilesStolen();

        void setMatinence(int Matinence);

        int getMatinence();

        void setFrustration(int Level);

        int getFrustration();

        void setHackersDefeated(int defeated);

        int getHackersDefeated();

        void setViruses(int num);

        int getViruses();

        // other member functions:

        void statusUpdate();

        void attackHacker(Hacker name);

        void speakNPC();

        void repairComputer();

        void useAntivirus();

        void travelRoom();

        void browseStack();

        int quit();

        void misfortune();

        bool endTurn();

};

#endif