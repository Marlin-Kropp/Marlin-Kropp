#include "Map.h"
#include <iostream>
#include "BestBuy.h"
#include "Hacker.h"
#include "NPC.h"
#include "Player.h"
#include "ServerRoom.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std; 

int main() {
    // create player
    string name;
    cout << "Enter your name: " << endl;
    getline(cin, name);
    Player Player1 = Player(name);

    // enter best buy
    ifstream file;
    file.open("best_buy_info.txt");
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
    cout << endl;
    BestBuy Intro = BestBuy();
    Intro.setPriceHike(0);
    Intro.setPlayer(Player1);
    Intro.buy();
    Player1 = Intro.getPlayer();
    cout << endl;

    //cout << Player1.getCPU() << endl;
    //cout << Player1.getCoin() << endl;
    Player1.statusUpdate();
    cout << endl;

    ServerRoom Room1 = ServerRoom();
    // room 1 (make this all a funciton of server room) have to pass in player, map, and best buy
    Map map1;  // create object called map of type Map
    map1.spawnBestBuy(1, 3);
    map1.spawnNPC(2, 5);
    map1.spawnNPC(3, 8);
    map1.spawnHacker(1, 1);

    char move;
    int i = 0;
    Hacker hacker1 = Hacker();
    hacker1.setName("Noob_Master_69");
    Room1.addHacker(hacker1);
    int choice = -1;
    while (!(Room1.getClear())){ //put this in server room
        i = 0; // rework this to ask to move first then check positions, possibly fine need to test
        map1.displayMap();
        if (map1.isHackerLocation() && !hacker1.getDefeated()){
            Player1.attackHacker(hacker1);
        }else if (map1.isNPCLocation()){
            cout << "Turn options:\n1. Travel the room\n2. Browse StackOverflow\n3. Use Antivirus software\n4. Repair computer" << endl;
            cout << "5. Interact with NPC\n6. Quit" << endl;
            switch (choice){
                case 1:
                    while (move != 'q' && i < 10) {
                        //This section is based on the map driver that was provided
                        map1.displayMap();

                        cout << "Valid moves are: " << endl; 
                        map1.displayMoves();
        
                        cout << "Input a move: "; 
                        cin >> move;
                        cout << endl;
                        map1.executeMove(move);

                        if (map1.isBestBuyLocation()) {
                        cout << "You're in a Best Buy!" << endl;
                        Intro.buy();
                        Player1 = Intro.getPlayer();
                        }

                        if (map1.isHackerLocation()) {
                        cout << "You've encountered a Hacker!" << endl;
                        Player1.attackHacker(hacker1);
                        }

                        if (map1.isNPCLocation()) {
                        cout << "You've encountered an NPC!" << endl;
                        Player1.speakNPC();
                        }
                        i++;
                    }
                    break;
                case 2:
                    Player1.browseStack();
                    break;
                case 3:
                    Player1.useAntivirus();
                    break;
                case 4:
                    Player1.repairComputer();
                    break;
                case 5:
                    Player1.speakNPC();
                case 6:
                    cout << "You could not defead Carmen's hackers" << endl;
                    return 0;
                    break;
                default:
                    cout << "Invalid input." << endl;
                    break;
            }
        }else if (map1.isBestBuyLocation()){
            cout << "Turn options:\n1. Travel the room\n2. Browse StackOverflow\n3. Use Antivirus software\n4. Repair computer" << endl;
            cout << "5. Enter Best Buy\n6. Quit" << endl;
            switch (choice){
                case 1:
                    while (move != 'q' && i < 10) {
                        //This section is based on the map driver that was provided
                        map1.displayMap();

                        cout << "Valid moves are: " << endl; 
                        map1.displayMoves();
        
                        cout << "Input a move: "; 
                        cin >> move;
                        cout << endl;
                        map1.executeMove(move);

                        if (map1.isBestBuyLocation()) {
                        cout << "You're in a Best Buy!" << endl;
                        Intro.buy();
                        Player1 = Intro.getPlayer();
                        }

                        if (map1.isHackerLocation()) {
                        cout << "You've encountered a Hacker!" << endl;
                        Player1.attackHacker(hacker1);
                        }

                        if (map1.isNPCLocation()) {
                        cout << "You've encountered an NPC!" << endl;
                        Player1.speakNPC();
                        }
                        i++;
                    }
                    break;
                case 2:
                    Player1.browseStack();
                    break;
                case 3:
                    Player1.useAntivirus();
                    break;
                case 4:
                    Player1.repairComputer();
                    break;
                case 5:
                    Intro.buy();
                    break;
                case 6:
                    cout << "You could not defead Carmen's hackers" << endl;
                    return 0;
                    break;
                default:
                    cout << "Invalid input." << endl;
                    break;
            }
        }else{
            cout << "Turn options:\n1. Travel the room\n2. Browse StackOverflow\n3. Use Antivirus software\n4. Repair computer\n5. Quit" << endl;
            cin >> choice;
            switch (choice){
                case 1:
                    while (move != 'q' && i < 10) {
                        //This section is based on the map driver that was provided
                        map1.displayMap();

                        cout << "Valid moves are: " << endl; 
                        map1.displayMoves();
        
                        cout << "Input a move: "; 
                        cin >> move;
                        cout << endl;
                        map1.executeMove(move);

                        if (map1.isBestBuyLocation()) {
                        cout << "You're in a Best Buy!" << endl;
                        Intro.buy();
                        Player1 = Intro.getPlayer();
                        }

                        if (map1.isHackerLocation()) {
                        cout << "You've encountered a Hacker!" << endl;
                        Player1.attackHacker(hacker1);
                        }

                        if (map1.isNPCLocation()) {
                        cout << "You've encountered an NPC!" << endl;
                        Player1.speakNPC();
                        }
                        i++;
                    }
                    break;
                case 2:
                    Player1.browseStack();
                    break;
                case 3:
                    Player1.useAntivirus();
                    break;
                case 4:
                    Player1.repairComputer();
                    break;
                case 5:
                    cout << "You could not defead Carmen's hackers" << endl;
                    return 0;
                    break;
                default:
                    cout << "Invalid input." << endl;
                    break;
            }
        }
        cout << "Status Update? (1 for yes/2 for no)" << endl;
        cin >> choice;
        if (choice == 1){
            Player1.statusUpdate();
        }else if (choice == 2){
            cout << endl;
        }else {
            cout << "Invalid input." << endl;
        }
        if (!Player1.endTurn()){
            return 0;
        }
        Player1.misfortune();
        Room1.checkClear();
        if (Room1.getClear()){
            break;
        }
    }

    return 0;
    
}
