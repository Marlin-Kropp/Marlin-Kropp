// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - Best buy header

#include <iostream>
#include "Player.h"
#ifndef BESTBUY_H
#define BESTBUY_H

class BestBuy{

    private:
        double priceHike;
        int currentTotal;
        Player player1;

    public:
        //Basic constructor
        BestBuy();

        //Getters/setters
        void setPriceHike(double pricePercentIncrease);

        void setPlayer(Player name);

        Player getPlayer();

        double getPriceHike();

        //other member functions
        void buy();

        void buyComputerParts();

        void buyAntivirus();

        void buyVPN();

        void buyInternet();

};

#endif