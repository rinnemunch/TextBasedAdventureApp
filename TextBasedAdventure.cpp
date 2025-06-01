#include <iostream>
#include <string>
using namespace std;

void showDungeonArt() {
    cout << R"ART(

                  .7
                .'/ 
               / /  
              / /   
             / /    
            / /     
           / /      
          / /       
         / /         
        / /          
      __|/           
    ,-\__\           
    |f-"Y\|          
    \()7L/           
     cgD                            __ _
     |\(                          .'  Y '>,
      \ \                        / _   _   \
       \\\                       )(_) (_)(|}
        \\\                      {  4A   } /
         \\\                      \uLuJJ/\l
          \\\                     |3    p)/
           \\\___ __________      /nnm_n//
           c7___-__,__-)\,__)(".  \_>-<_/D
                      //V     \_"-._.__G G_c__.-__<"/ ( \
                             <"-._>__-,G_.___)\   \7\
                            ("-.__.| \"<.__.-" )   \ \
                            |"-.__"\  |"-.__.-".\   \ \
                            ("-.__"". \"-.__.-".|    \_\
                            \"-.__""|!|"-.__.-".)     \ \
                             "-.__""\_|"-.__.-"./      \ l
                              ".__""">G>-.__.-">       .--,_
    )ART";
}

int main() {
    bool gameRunning = true;
    string currentRoom = "Menu";
    bool hasSword = false;
    bool enemyDefeated = false;
    int playerHealth = 100;
    string playerName;

    while (gameRunning) {

        if (currentRoom == "Menu") {
            cout << R"(

|\                      /) /)
| /\_\\__               (_//
|   `>\-`     _._       //`)
 \ /` \\  _.-`:::`-._  //
  `    \|`    :::    `|/
        |   DUNGEON   |
        |    QUEST    |
        |.....:::.....|
        |:::::::::::::|
        |     :::     |
        \     :::     /
         \    :::    /
          `-. ::: .-'
           //`:::`\\
          //   '   \\
         |/         \|

)";
            cout << "1. Enter the Dungeon\n";
            cout << "2. Quit Game\n";
            cout << "Choose an option: ";

            int choice;
            cin >> choice;

            if (choice == 1) {
                cin.ignore(); // clear input buffer
                cout << "\nBefore you enter... what is your name, adventurer?\n";
                getline(cin, playerName);

                currentRoom = "Entrance";
                cout << "\nWelcome, " << playerName << ". You step into the dungeon... it's dark and cold.\n";
                cout << "Health: " << playerHealth << endl;
                showDungeonArt();
                cout << "Current Room: " << currentRoom << endl;
            }
            else if (choice == 2) {
                cout << "\nThanks for playing!\n";
                gameRunning = false;
            }
            else {
                cout << "\nInvalid choice. Try again.\n";
            }
        }

        else if (currentRoom == "Entrance") {
            cout << "\n" << playerName << ", you are standing in the dungeon entrance.\n";
            cout << "1. Go left to the Armory\n";
            cout << "2. Go right to the Hallway\n";
            cout << "3. Go forward to the Library\n"; 
            cout << "4. Examine the room\n";
            cout << "5. Enter the strange tunnel on the left\n";
            cout << "6. Return to Menu\n";
            cout << "Choose an option: ";

            int choice;
            cin >> choice;

            if (choice == 1) {
                currentRoom = "Armory";
            }
            else if (choice == 2) {
                currentRoom = "Hallway";
            }
            else if (choice == 3) {
                currentRoom = "Library";
            }
            else if (choice == 4) {
                cout << "\nYou examine your surroundings. The air is thick. A carving on the wall shows a battle from long ago.\n";
            }
            else if (choice == 5) {
                currentRoom = "TrapRoom";
            }
            else if (choice == 6) {
                currentRoom = "Menu";
            }
            else {
                cout << "\nInvalid choice. Try again.\n";
            }
        }

        else if (currentRoom == "Armory") {
            cout << "\nYou are in the Armory. Old swords and cracked shields cover the walls.\n";

            if (!hasSword) {
                cout << "1. Take the sword\n";
                cout << "2. Examine the room\n";
                cout << "3. Return to Entrance\n";
            }
            else {
                cout << "1. Examine the room\n";
                cout << "2. Return to Entrance\n";
            }

            cout << "Choose an option: ";
            int choice;
            cin >> choice;

            if (!hasSword) {
                if (choice == 1) {
                    hasSword = true;
                    cout << "\nYou picked up a rusty old sword. It might still work...\n";
                }
                else if (choice == 2) {
                    cout << "\nYou examine the walls. One sword has a notch shaped like a dragon's tooth.\n";
                }
                else if (choice == 3) {
                    currentRoom = "Entrance";
                }
                else {
                    cout << "\nInvalid choice. Try again.\n";
                }
            }
            else {
                if (choice == 1) {
                    cout << "\nYou examine the walls. One sword has a notch shaped like a dragon’s tooth.\n";
                }
                else if (choice == 2) {
                    currentRoom = "Entrance";
                }
                else {
                    cout << "\nInvalid choice. Try again.\n";
                }
            }
        }

        else if (currentRoom == "Hallway") {
            if (!enemyDefeated) {
                cout << "\nA goblin jumps out from the shadows!\n";

                if (hasSword) {
                    cout << "You raise your sword. The goblin hesitates...\n";
                    cout << "1. Attack the goblin\n";
                    cout << "2. Let it run\n";
                    cout << "Choose an option: ";

                    int fightChoice;
                    cin >> fightChoice;

                    if (fightChoice == 1) {
                        cout << "\nYou slash the goblin! It lets out a final screech.\n";
                        enemyDefeated = true;
                    }
                    else if (fightChoice == 2) {
                        cout << "\nYou let the goblin flee. It vanishes into the dark.\n";
                        enemyDefeated = true;
                    }
                    else {
                        cout << "\nInvalid choice. The goblin escapes while you hesitate.\n";
                        enemyDefeated = true;
                    }
                }
                else {
                    cout << playerName << ", you panic... the goblin scratches you before fleeing!\n";
                    cout << R"ASCII(
                         ,      ,
                        /(.-""-.)\
                    |\  \/      \/  /|
                    | \ / =.  .= \ / |
                    \( \   o\/o   / )/
                     \_, '-/  \-' ,_/
                       /   \__/   \
                       \ \__/\__/ /  
                     ___\ \|--|/ /___
                    /`    \      /    `\
                    )ASCII";

                    playerHealth -= 25;
                    cout << "You took 25 damage. Health: " << playerHealth << endl;
                }

                if (playerHealth <= 0) {
                    cout << "\n" << playerName << ", you've taken too much damage and collapse...\n";
                    cout << "GAME OVER\n";
                    gameRunning = false;
                }

                enemyDefeated = true;
            }
            else {
                cout << "\nThe hallway is quiet. Whatever was here before is gone.\n";
            }

            cout << "1. Examine the hallway\n";
            cout << "2. Return to Entrance\n";
            cout << "Choose an option: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "\nYou find strange claw marks on the walls... something else might be down here.\n";
            }
            else if (choice == 2) {
                currentRoom = "Entrance";
            }
            else {
                cout << "\nInvalid choice. Try again.\n";
            }
        }

        else if (currentRoom == "Library") {
            cout << "\nYou are in the Library. Dusty books cover every wall.\n";
            cout << "1. Examine the books\n";
            cout << "2. Return to Entrance\n";
            cout << "Choose an option: ";

            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "\nYou find a torn page... it mentions a creature sealed deep below.\n";
                cout << "Keep reading? (1 = Yes, 2 = No): ";

                int readChoice;
                cin >> readChoice;

                if (readChoice == 1) {
                    cout << "\nYou read further... The page speaks of a Lich King buried beneath the dungeon,\n";
                    cout << "sealed away by fire and blood. His return could unmake the world.\n";
                }
                else {
                    cout << "\nYou put the book back.\n";
                }
            }
            else if (choice == 2) {
                currentRoom = "Entrance";
            }
            else {
                cout << "\nInvalid choice. Try again.\n";
            }
        } 
        else if (currentRoom == "TrapRoom") {
            cout << "\nYou step into a narrow tunnel. As the door shuts behind you, the floor clicks.\n";
            cout << "A trap is triggered! Choose fast:\n";
            cout << "1. Jump backward\n";
            cout << "2. Duck\n";
            cout << "3. Roll forward\n";
            cout << "Choose quickly: ";

            int trapChoice;
            cin >> trapChoice;

            if (trapChoice == 3) {
                cout << "\nYou roll just in time! Blades slice through where your head was.\n";
            }
            else {
                cout << "\nWrong move! A hidden dart hits you.\n";
                playerHealth -= 30;
                cout << "You took 30 damage. Health: " << playerHealth << endl;

                if (playerHealth <= 0) {
                    cout << "\n" << playerName << ", you fall to the ground... the dungeon claims another victim.\n";
                    cout << "GAME OVER\n";
                    gameRunning = false;
                }
            }

            if (playerHealth > 0) {
                cout << "\n" << playerName << ", you stumble back into the dungeon entrance, still breathing...\n";
            }

            currentRoom = "Entrance";
       }

    }

    return 0;
}
