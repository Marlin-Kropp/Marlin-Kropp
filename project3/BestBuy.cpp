// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - best buy member funcitons

#include "BestBuy.h"
#include <iostream>
#include "Player.h"
#include <iomanip>

using namespace std;

BestBuy::BestBuy(){
    player1 = Player();
    priceHike = 1.0;
    currentTotal = 0;
}

void BestBuy::setPriceHike(double pricePercentIncrease){
    priceHike = priceHike + priceHike * pricePercentIncrease;
    return;
}

double BestBuy::getPriceHike(){
    return priceHike;
}

void BestBuy::setPlayer(Player name){
    player1 = name;
}

Player BestBuy::getPlayer(){
    return player1;
}

void BestBuy::buy(){
    int choice = -1;
    cout << "Welcome to Best Buy, how may we help you?" << endl;
    while (choice != 5){
        cout << "You have " << player1.getCoin() << " Dogecoins" << endl; // fix the number
        cout << "1. Buy Computer Parts\n2. Buy Antivirus Software\n3. Buy a VPN\n4. Upgrade your Internet Provider\n5. Exit\nEnter a choice (1-5)" << endl;
        cin >> choice;
        switch (choice){
            case 1:
                buyComputerParts();
                break;
            case 2:
                buyAntivirus();
                break;
            case 3:
                buyVPN();
                break;
            case 4:
                buyInternet();
                break;
            case 5:
                cout << "Thank you for shopping at Best Buy" << endl;
                break;
            default:
                cout << "Invalid input." << endl;
        }
    }
}

void BestBuy::buyComputerParts(){
    int coin = player1.getCoin();
    int choice = -1;
    int quantity;
    while (choice != 8){
        cout << "You have " << coin << " Dogecoins" << endl;
        cout << fixed << setprecision(0) << "1: CPU, cost " << 10 * priceHike << " Dogecoins" << endl;
        cout << "2: GPU, cost " << 20 * priceHike << " Dogecoins" << endl;
        cout << "3: Power Supply Unit, cost " << 5 * priceHike << " Dogecoins" << endl;
        cout << "4: Computer Case, cost " << 15 * priceHike << " Dogecoins" << endl;
        cout << "5: Internet Card, cost " << 5 * priceHike << " Dogecoins" << endl;
        cout << "6: Keyboard and Mouse, cost " << 10 * priceHike << " Dogecoins" << endl;
        cout << "7: Premade Computer, cost " << 100 * priceHike << " Dogecoins" << endl;
        cout << "8: Back to Best Buy main menu" << endl;
        cout << "Enter a choice (1-7): " << endl;
        cin >> choice;
        switch (choice){
            case 1:
                if (coin >= 10 * priceHike && player1.getCPU() < 3){
                    player1.setCPU(player1.getCPU() + 1);
                    currentTotal += 10 * priceHike;
                    cout << "Purchase successful\nCurrent Total: " << currentTotal << endl;
                    coin -= 10 * priceHike;
                    player1.setCoin(coin);
                }else if (coin < 10 * priceHike){
                    cout << "You don't have enough Dogecoins" << endl;
                }else{
                    cout << "You already have 3 CPUs" << endl;
                }
                break;
            case 2:
                if (coin >= 20 * priceHike && player1.getGPU() < 3){
                    player1.setGPU(player1.getGPU() + 1);
                    currentTotal += 20 * priceHike;
                    cout << "Purchase successful\nCurrent Total: " << currentTotal << endl;
                    coin -= 20 * priceHike;
                    player1.setCoin(coin);
                }else if (coin < 20 * priceHike){
                    cout << "You don't have enough Dogecoins" << endl;
                }else{
                    cout << "You already have 3 GPUs" << endl;
                }
                break;
            case 3:
                if (coin >= 5 * priceHike && player1.getPower() < 3){
                    player1.setPower(player1.getPower() + 1);
                    currentTotal += 5 * priceHike;
                    cout << "Purchase successful\nCurrent Total: " << currentTotal << endl;
                    coin -= 5 * priceHike;
                    player1.setCoin(coin);
                }else if (coin < 5 * priceHike){
                    cout << "You don't have enough Dogecoins" << endl;
                }else{
                    cout << "You already have 3 Power Supply Units" << endl;
                }
                break;
            case 4:
                if (coin >= 15 * priceHike && player1.getCase() < 3){
                    player1.setCase(player1.getCase() + 1);
                    currentTotal += 15 * priceHike;
                    cout << "Purchase successful\nCurrent Total: " << currentTotal << endl;
                    coin -= 15 * priceHike;
                    player1.setCoin(coin);
                }else if (coin < 15 * priceHike){
                    cout << "You don't have enough Dogecoins" << endl;
                }else{
                    cout << "You already have 3 Computer Cases" << endl;
                }
                break;
            case 5:
                if (coin >= 5 * priceHike && player1.getCard() < 3){
                    player1.setCard(player1.getCard() + 1);
                    currentTotal += 5 * priceHike;
                    cout << "Purchase successful\nCurrent Total: " << currentTotal << endl;
                    coin -= 5 * priceHike;
                    player1.setCoin(coin);
                }else if (coin < 5 * priceHike){
                    cout << "You don't have enough Dogecoins" << endl;
                }else{
                    cout << "You already have 3 Internet Card" << endl;
                }
                break;
            case 6:
                if (coin >= 10 * priceHike && player1.getMaK() < 3){
                    player1.setMaK(player1.getMaK() + 1);
                    currentTotal += 10 * priceHike;
                    cout << "Purchase successful\nCurrent Total: " << currentTotal << endl;
                    coin -= 10 * priceHike;
                    player1.setCoin(coin);
                }else if (coin < 10 * priceHike){
                    cout << "You don't have enough Dogecoins" << endl;
                }else{
                    cout << "You already have 3 Keyboards and Mice" << endl;
                }
                break;
            case 7:
                if (coin >= 100 * priceHike && !(player1.getComputer())){
                    player1.setComputer(true);
                    currentTotal += 100 * priceHike;
                    cout << "Purchase successful\nCurrent Total: " << currentTotal << endl;
                    coin -= 100 * priceHike;
                    player1.setCoin(coin);
                }else if (coin < 100 * priceHike){
                    cout << "You don't have enough Dogecoins" << endl;
                }else{
                    cout << "You already have a Premade Computer" << endl;
                }
                break;
            case 8:
                cout << "Back to main menu" << endl;
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
    player1.setCoin(coin);
    return;
}

void BestBuy::buyAntivirus(){
    cout << fixed << setprecision(0) << "You have " << player1.getCoin() << " Dogecoins" << endl;
    cout << "USB stick of antivirus software, cost " << 10 * priceHike << " Dogecoins" << endl;
    int choice = -1;
    while (choice != 2){
        cout << "1. Buy Antivirus Software\n2. Return to Best Buy main menu\nEnter a choice (1-2)" << endl;
        cin >> choice;
        switch (choice){
            case 1:
                if (player1.getCoin() >= 10 * priceHike){
                    player1.setAntivirus(player1.getAntivirus() +1);
                    currentTotal += 10 * priceHike;
                    cout << "Purchase successful\nCurrent Total: " << currentTotal << endl;
                    player1.setCoin(player1.getCoin() - 10 * priceHike);
                }else {
                    cout << "You don't have enough Dogecoins" << endl;
                }
                break;
            case 2:
                cout << "Back to main menu" << endl;
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
    return;
}

void BestBuy::buyVPN(){
    cout << fixed << setprecision(0) << "You have " << player1.getCoin() << " Dogecoins" << endl;
    cout << "Virtual Private Network (VPN), cost " << 20 * priceHike << " Dogecoins\nBenefit maxes out at 2 VPNs" << endl;
    int choice = -1;
    while (choice != 2){
        cout << "1. Buy VPN\n2. Return to Best Buy main menu\nEnter a choice (1-2)" << endl;
        cin >> choice;
        switch (choice){
            case 1:
                if (player1.getCoin() >= 20 * priceHike){
                    player1.setVPN(player1.getVPN() +1);
                    currentTotal += 20 * priceHike;
                    cout << "Purchase successful\nCurrent Total: " << currentTotal << endl;
                    player1.setCoin(player1.getCoin() - 20 * priceHike);
                }else {
                    cout << "You don't have enough Dogecoins" << endl;
                }
                break;
            case 2:
                cout << "Back to main menu" << endl;
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
    return;
}

void BestBuy::buyInternet(){
    cout << fixed << setprecision(0) << "You have " << player1.getCoin() << " Dogecoins" << endl;
    int choice = -1;
    int choice2= -1;
    if (player1.getInternet() == 1){
        cout << fixed << setprecision(0) << "Internet Level 2, cost " << 10 * priceHike << endl;
        cout << "Would you like to upgrade (1 for yes/2 for no)?" << endl;
        cin >> choice;
        if (choice == 1 && player1.getCoin() >= 10 * priceHike){
            currentTotal += 10 * priceHike;
            player1.setInternet(2);
            cout << "Purchase successful" << endl;
            cout << "Current total: " << currentTotal << endl;
            player1.setCoin(player1.getCoin() - 10 * priceHike);
        }else if  (choice == 2){
            return;
        }else if (player1.getCoin() < 10 * priceHike){
            cout << "You don't have enough Dogecoin" << endl;
        }else{
            cout << "Invalid input." << endl;
        }
    }else if (player1.getInternet() == 2){
        cout << fixed << setprecision(0) << "Internet Level 3, cost " << 25 * priceHike << endl;
        cout << "Would you like to upgrade (1 for yes/2 for no)?" << endl;
        cin >> choice;
        if (choice == 1 && player1.getCoin() >= 25 * priceHike){
            currentTotal += 25 * priceHike;
            player1.setInternet(3);
            cout << "Purchase successful" << endl;
            cout << "Current total: " << currentTotal << endl;
            player1.setCoin(player1.getCoin() - 25 * priceHike);
        }else if  (choice == 2){
            return;
        }else if (player1.getCoin() < 25 * priceHike){
            cout << "You don't have enough Dogecoin" << endl;
        }else{
            cout << "Invalid input." << endl;
        }
    }else if (player1.getInternet() == 3){
        cout << fixed << setprecision(0) << "Internet Level 4, cost " << 40 * priceHike << endl;
        cout << "Would you like to upgrade (1 for yes/2 for no)?" << endl;
        cin >> choice;
        if (choice == 1 && player1.getCoin() >= 40 * priceHike){
            currentTotal += 40 * priceHike;
            player1.setInternet(4);
            cout << "Purchase successful" << endl;
            cout << "Current total: " << currentTotal << endl;
            player1.setCoin(player1.getCoin() - 40 * priceHike);
        }else if  (choice == 2){
            return;
        }else if (player1.getCoin() < 40 * priceHike){
            cout << "You don't have enough Dogecoin" << endl;
        }else{
            cout << "Invalid input." << endl;
        }
    }else if (player1.getInternet() == 4){
        cout << fixed << setprecision(0) << "Internet Level 5, cost " << 50 * priceHike << endl;
        cout << "Would you like to upgrade (1 for yes/2 for no)?" << endl;
        cin >> choice;
        if (choice == 1 && player1.getCoin() >= 50 * priceHike){
            currentTotal += 50 * priceHike;
            player1.setInternet(5);
            cout << "Purchase successful" << endl;
            cout << "Current total: " << currentTotal << endl;
            player1.setCoin(player1.getCoin() - 50 * priceHike);
        }else if  (choice == 2){
            return;
        }else if (player1.getCoin() < 50 * priceHike){
            cout << "You don't have enough Dogecoin" << endl;
        }else{
            cout << "Invalid input." << endl;
        }
    }else{
        cout << "You have maxed out your Internet Provider Level" << endl;
    }
    return;
}
