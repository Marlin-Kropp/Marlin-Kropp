// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - driver

#include "Player.h"
#include "BestBuy.h"
#include "ServerRoom.h"
#include "NPC.h"
#include <iostream>

int main(){
    
    //THINK ABOUT USING A LOOPED SWITCH STATEMENT FOR CHOICES

    /*
    Start of turn after status update print the map and the choices (if NPC position then have display the speak to NPC option)
    Only move if they select a move option
    */

    //Player Class
    //testing Player getters / setters
    Player RalphieVI = Player("RalphieVI"); // creating a player
    cout << RalphieVI.getName() << endl; // getting the name
    RalphieVI.setCPU(0); // setting the cpu to zero
    cout << RalphieVI.getCPU() << endl; // zero
    RalphieVI.setGPU(0);
    cout << RalphieVI.getGPU() << endl; // zero
    RalphieVI.setPower(0);
    cout << RalphieVI.getPower() << endl; // zero
    RalphieVI.setCase(0);
    cout << RalphieVI.getCase() << endl; // zero
    RalphieVI.setCard(0);
    cout << RalphieVI.getCard() << endl; // zero
    RalphieVI.setMaK(0);
    cout << RalphieVI.getMaK() << endl; // zero
    RalphieVI.setComputer(false);
    cout << RalphieVI.getComputer() << endl; // zero
    RalphieVI.setAntivirus(0);
    cout << RalphieVI.getAntivirus() << endl; // zero
    RalphieVI.setVPN(0);
    cout << RalphieVI.getVPN() << endl; // zero
    RalphieVI.setInternet(0);
    cout << RalphieVI.getInternet() << endl; // zero
    RalphieVI.setCoin(0);
    cout << RalphieVI.getCoin() << endl; // zero
    RalphieVI.setFilesStolen(0);
    cout << RalphieVI.getFilesStolen() << endl; // zero
    RalphieVI.setMatinence(0);
    cout << RalphieVI.getMatinence() << endl; // zero
    RalphieVI.setFrustration(0);
    cout << RalphieVI.getFrustration() << endl; // zero
    RalphieVI.setHackersDefeated(0);
    cout << RalphieVI.getHackersDefeated() << endl; // zero
    //Other member functions
    RalphieVI.statusUpdate(); // testing status update (should all be zero)
    
    int test;
    test = RalphieVI.quit(); // running the quit function
    if (test == -1){ // quitting 
        //return 0; // end game
    }
    
    cout << endl;



    //testing getters and setters for Best Buy
    BestBuy RalphiesCorral = BestBuy(); // creating a best buy
    RalphiesCorral.setPriceHike(.1); // setting the price hike
    cout << RalphiesCorral.getPriceHike() << endl; // should be 1.1
    cout << endl;

    //testing getters and setters for Server Room
    ServerRoom Room1 = ServerRoom(); // creating a server room
    cout << Room1.getNumHackersDefeated() << endl; // zero
    cout << Room1.getClear() << endl; // zero
    Room1.clearRoom(); // clearing the room
    cout << Room1.getClear() << endl; // one
    cout << endl;

    //testing getters and setters for NPC
    NPC ChipsMom = NPC(); // creating an NPC
    ChipsMom.setName("Chip's Mom"); // setting the name
    cout << ChipsMom.getName() << endl; // displaying the name
    cout << ChipsMom.getFriendStatus() << endl; // should be zero

    return 0; // end

}

