// CSCI 1300 Fall 2021
// Author: Marlin Kropp
// Recitation: 314 - Bishop
// Project 3 - Member Functions

#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include <iostream>
#include "ServerRoom.h"
#include "Hacker.h"
#include "NPC.h"

using namespace std;

Player::Player(){
    name = "";
    numCPU = 0;
    numGPU = 0;
    numPowerSupply = 0;
    numCase = 0;
    numCard = 0;
    numMouseAndKeys = 0;
    numAntivirus = 0;
    percentFilesStolen = 0;
    numHackersDefeated = 0;
    numViruses = 0;
    frustrationLvl = 0;
    numCoin = 200;
    internetLvl = 1;
    numVPN = 1;
    percentComputerMatinence = 100;
    premadeComputer = false;
}

Player::Player(string temp){
    name = temp;
    numCPU = 0;
    numGPU = 0;
    numPowerSupply = 0;
    numCase = 0;
    numCard = 0;
    numMouseAndKeys = 0;
    numAntivirus = 0;
    percentFilesStolen = 0;
    numHackersDefeated = 0;
    numViruses = 0;
    frustrationLvl = 0;
    numCoin = 200;
    internetLvl = 1;
    numVPN = 1;
    percentComputerMatinence = 100;
    premadeComputer = false;
}

string Player::getName(){
    return name;
}

void Player::setCPU(int CPUs){
    numCPU = CPUs;
}

int Player::getCPU(){
    return numCPU;
}

void Player::setGPU(int GPUs){
    numGPU = GPUs;
}

int Player::getGPU(){
    return numGPU;
}

void Player::setPower(int Power){
    numPowerSupply = Power;
}

int Player::getPower(){
    return numPowerSupply;
}

void Player::setCase(int Case){
    numCase = Case;
}

int Player::getCase(){
    return numCase;
}

void Player::setCard(int Card){
    numCard = Card;
}
        
int Player::getCard(){
    return numCard;
}

void Player::setMaK(int MaK){
    numMouseAndKeys = MaK;
}

int Player::getMaK(){
    return numMouseAndKeys;
}

void Player::setComputer(bool Computer){
    premadeComputer = Computer;
}

bool Player::getComputer(){
    return premadeComputer;
}

void Player::setAntivirus(int Antivirus){
    numAntivirus = Antivirus;
}

int Player::getAntivirus(){
    return numAntivirus;
}

void Player::setVPN(int VPN){
    numVPN = VPN;
}

int Player::getVPN(){
    return numVPN;
}

void Player::setInternet(int lvl){
    internetLvl = lvl;
}

int Player::getInternet(){
    return internetLvl;
}

void Player::setCoin(int Coin){
    numCoin = Coin;
}

int Player::getCoin(){
    return numCoin;
}

void Player::setFilesStolen(int FilesStolen){
    percentFilesStolen = FilesStolen;
}

int Player::getFilesStolen(){
    return percentFilesStolen;
}

void Player::setMatinence(int Matinence){
    percentComputerMatinence = Matinence;
}

int Player::getMatinence(){
    return percentComputerMatinence;
}

void Player::setFrustration(int Level){
    frustrationLvl = Level;
}

int Player::getFrustration(){
    return frustrationLvl;
}

void Player::setHackersDefeated(int defeated){
    numHackersDefeated = defeated;
}

int Player::getHackersDefeated(){
    return numHackersDefeated;
}

void Player::setViruses(int num){
    numViruses = num;
}

int Player::getViruses(){
    return numViruses;
}

void Player::statusUpdate(){
    cout << "Computer Matinence Level: " << percentComputerMatinence << "%" << endl;
    cout << "Number of Viruses: " << numViruses << endl;
    cout << "Number of CPUs: " << numCPU << endl;
    cout << "Number of GPUs: " << numGPU << endl;
    cout << "Number of Power Supplies: " << numPowerSupply << endl;
    cout << "Number of Computer Cases: " << numCase << endl;
    cout << "Number of Internet Cards: " << numCard << endl;
    cout << "Number of Keyboards and Mice: " << numMouseAndKeys << endl;
    if (getComputer()){
        cout << "You have an Extra Premade Computer" << endl;
    }else{
        cout << "You do not have an Extra Premade Computer" << endl;
    }
    cout << "Number of Antivirus USBs: " << numAntivirus << endl;
    cout << "Number of VPNs: " << numVPN << endl;
    cout << "Internet Provider Level: " << internetLvl << endl;
    cout << "Amount of Dogecoin: " << numCoin << endl;
    cout << "Frustration Level: " << frustrationLvl << "/100" << endl;
    cout << "Percent files stolen: " << percentFilesStolen << "%" << endl;
    cout << "Total number of hackers defeated: " << numHackersDefeated << endl;
    return;
}

void Player::attackHacker(Hacker name){
    if (percentComputerMatinence <= 0){
        cout << "Repair your computer to fight the hacker!" << endl;
        return;
    }
    if (name.getDefeated()){
        cout << "You have already beaten this hacker!" << endl;
        return;
    }
    srand(time(NULL));
    int rand1 = rand() % 6 + 1;
    int rand2 = rand() % 6 + 1;
    int result;
    result = (rand1 * internetLvl) - (rand2 * name.getLevel() * (1 / numVPN));
    if (result > 0){
        cout << "You defeated " << name.getName() << "!" << endl;
        numCoin += 50;
        if (numCPU > 0){
            numCPU--;
        }else if (numGPU > 0){
            numGPU--;
        }else if (numPowerSupply > 0 ){
            numPowerSupply--;
        }else if (numCase > 0){
            numCase--;
        }else if (numCard > 0){
            numCard--;
        }else if (numMouseAndKeys > 0){
            numMouseAndKeys--;
        }else if (premadeComputer){
            premadeComputer = false;
        }
        name.setDefeated(true);
        numHackersDefeated++;
    }else {
        cout << "You were defeated by " << name.getName() << ". :(" << endl;
        percentComputerMatinence -= 20;
        percentFilesStolen += 25;
        if ((rand() % 10) == 0){
            numViruses++;
        }
        if (numCPU > 0){
            numCPU--;
        }else if (numGPU > 0){
            numGPU--;
        }else if (numPowerSupply > 0 ){
            numPowerSupply--;
        }else if (numCase > 0){
            numCase--;
        }else if (numCard > 0){
            numCard--;
        }else if (numMouseAndKeys > 0){
            numMouseAndKeys--;
        }else if (premadeComputer){
            premadeComputer = false;
        }
    }
    int rand3 = rand() % 10;
    if (0 <= rand3 && rand3 <= 2){
            percentComputerMatinence -= 30;
        }
    return;
}

void Player::speakNPC(){
    cout << "Do you want to play a game or see if the NPC is friendly? (1 for game/2 for check)" << endl;
    int choice;
    cin >> choice;
    int guess = -1;
    if (choice == 1){
        int rand1 = rand() % 3 + 1;
        int rand2 = rand() % 10 + 1;
        cout << "What is " << rand1 << " + " << rand2 << "?" << endl;
        cin >> guess;
        if (guess == rand1 + rand2){
            cout << "You have chosen wisely and gained a computer part" << endl;
            if (numCPU < 3){
                numCPU++;
            }else if (numGPU < 3){
                numGPU++;
            }else if (numPowerSupply < 3 ){
                numPowerSupply++;
            }else if (numCase < 3){
                numCase++;
            }else if (numCard < 3){
                numCard++;
            }else if (numMouseAndKeys < 3){
                numMouseAndKeys++;
            }else if (!premadeComputer){
                premadeComputer = true;
            }
        }else {
            cout << "You have chosen poorly" << endl;
        }
    }else if (choice == 2){ // make the friendliness part of the NPC class
        //NPC test;
        //test.getFriendStatus();
        int friendliness = rand() % 3;
        if (friendliness == 0){
            cout << "The NPC is friendly and gives you a free computer part" << endl;
            if (numCPU < 3){
                numCPU++;
            }else if (numGPU < 3){
                numGPU++;
            }else if (numPowerSupply < 3 ){
                numPowerSupply++;
            }else if (numCase < 3){
                numCase++;
            }else if (numCard < 3){
                numCard++;
            }else if (numMouseAndKeys < 3){
                numMouseAndKeys++;
            }else if (!premadeComputer){
                premadeComputer = true;
            }
        }else if (friendliness == 1){
            cout << "The NPC is neutral and you go on your merry way" << endl;
        }else{
            cout << "The NPC is unfriendly and they steal a computer part" << endl;
            if (numCPU > 0){
                numCPU--;
            }else if (numGPU > 0){
                numGPU--;
            }else if (numPowerSupply > 0 ){
                numPowerSupply--;
            }else if (numCase > 0){
                numCase--;
            }else if (numCard > 0){
                numCard--;
            }else if (numMouseAndKeys > 0){
                numMouseAndKeys--;
            }else if (premadeComputer){
                premadeComputer = false;
            }
        }
    }else {
        cout << "Invalid input." << endl;
    }
    return;
}

string toUpper(string str){ // declaring a string function
    for(int i = 0; i < str.length(); i++){ // iterating over the string
        if ((int) str.at(0) < 91){ // checking if the character is lowercase
        str.at(0) = (char)((int)str.at(0) + 32); // capitalizing the character
        }
    } 
    return str; // returning the capitalized string
}

void Player::repairComputer(){
    cout << "Inventory: " << endl;
    cout << "Computer Matinence Level: " << percentComputerMatinence << "%" << endl;
    cout << "CPU: " << numCPU << endl;
    cout << "GPU: " << numGPU << endl;
    cout << "Power Supply Unit: " << numPowerSupply << endl;
    cout << "Computer Case: " << numCase << endl;
    cout << "Internet Card: " << numCard << endl;
    cout << "Keyboard and Mouse: " << numMouseAndKeys << endl;
    string input;
    for (int i = 0; i < 5; i++){
        cout << "Enter the name of the part you wish to use (enter 'Quit' to stop):" << endl;
        getline(cin, input);
        input = toUpper(input);
        if (input == "CPU" && numCPU > 0){
            percentComputerMatinence += 20;
            numCPU--;
        }else if (input == "GPU" && numGPU > 0){
            percentComputerMatinence += 20;
            numGPU--;
        }else if (input == "POWER SUPPLY UNIT" && numPowerSupply > 0){
            percentComputerMatinence += 20;
            numPowerSupply--;
        }else if (input == "COMPUTER CASE" && numCase > 0){
            percentComputerMatinence += 20;
            numCase--;
        }else if (input == "INTERNET CARD" && numCard > 0){
            percentComputerMatinence += 20;
            numCard--;
        }else if (input == "KEYBOARD AND MOUSE" && numMouseAndKeys > 0){
            percentComputerMatinence += 20;
            numMouseAndKeys--;
        }else {
            cout << "Invalid input or you own none of the selected part" << endl;
        }
    }
    return;
}

void Player::useAntivirus(){
    if (numAntivirus > 0){
        cout << "You have successfully wiped your computer of all viruses" << endl;
        numViruses = 0;
    }else{
        cout << "You need a USB stick of antivirus software" << endl;
    }
    return;
}

void Player::travelRoom(){
    //TODO: travel the given map class
    //This is in the main game
    return;
}

void Player::browseStack(){
    int guess;
    int rand1 = rand() % 5 + 1;
    int rand2 = rand() % 7 + 1;
    cout << "What is " << rand1 << " - " << rand2 << "?" << endl;
    cin >> guess;
    if (guess == rand1 - rand2){
        cout << "You have subtracted correctly" << endl;
        if (frustrationLvl > 5){
            frustrationLvl -= 5;
        }
    }else {
        cout << "You have subtracted incorrectly" << endl;
    }
    return;
}

int Player::quit(){
    cout << "Thanks for playing!" << endl;
    return -1;
}

void Player::misfortune(){
    int x = rand() % 3;
    if (x == 0){
        cout << "OH NO! Your team was robbed by Carmen’s dastardly\nhackers!\nYou have no computer parts/antivirus software\nleft!" << endl;
        numCPU = 0;
        numGPU = 0;
        numPowerSupply = 0;
        numCase = 0;
        numCard = 0;
        numMouseAndKeys = 0;
        premadeComputer = false;
        numAntivirus = 0;
    }else if (x == 1){
        cout << "OH NO! Your computer was damaged!" << endl;
        if (percentComputerMatinence > 10){
            percentComputerMatinence = 10;
        }else{
            percentComputerMatinence = 0;
        }
    }else{
        cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
        frustrationLvl += 10;
    }
    return;
}

bool Player::endTurn(){
    //TODO: implement all of the end of turn processes
    numCoin += 5 + 5 * numGPU;
    percentFilesStolen += 5;
    //check numViruses and all game ending variables
    bool conditionCheck = true;
    if (percentFilesStolen >= 100){
        cout << "Carmen's Hackers stole all of the files" << endl;
        conditionCheck = false;
        return false;
    }
    if (percentComputerMatinence <= 0 && !premadeComputer){
        cout << "Your computer is destroyed and you do not have a backup" << endl;
        conditionCheck = false;
        return false;
    }if (percentComputerMatinence < 0 && premadeComputer){
        cout << "Your computer is destroyed but you have a backup!" << endl;
        percentComputerMatinence = 100;
        premadeComputer = false;
        conditionCheck = true;
    }
    if (frustrationLvl >= 100){
        cout << "You rage quit" << endl;
        return false;
    }

    return conditionCheck;
}