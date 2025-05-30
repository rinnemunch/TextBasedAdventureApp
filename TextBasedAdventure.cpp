#include <iostream>
using namespace std;

int main() {
    bool gameRunning = true;
    string currentRoom = "Menu";
    bool hasSword = false; 
    bool enemyDefeated = false; 

    while (gameRunning) {

        if (currentRoom == "Menu") {
            cout << "\n=============================\n";
            cout << "   WELCOME TO DUNGEON QUEST\n";
            cout << "=============================\n";
            cout << "1. Enter the Dungeon\n";
            cout << "2. Quit Game\n";
            cout << "Choose an option: ";

            int choice;
            cin >> choice;

            if (choice == 1) {
                currentRoom = "Entrance";
                cout << "\nYou step into the dungeon... it's dark and cold.\n";
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
    )ART" << '\n';


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
            cout << "\nYou are standing in the dungeon entrance.\n";
            cout << "1. Go left to the Armory\n";
            cout << "2. Go right to the Hallway\n";
            cout << "3. Exit to Main Menu\n";
            cout << "Choose an option: ";

            int choice;
            cin >> choice;

            if (choice == 1) {
                currentRoom = "Armory";
                cout << "\nYou enter the Armory. Rusty weapons line the walls.\n";
            }
            else if (choice == 2) {
                currentRoom = "Hallway";
                cout << "\nYou walk into a long, shadowy hallway.\n";
            }
            else if (choice == 3) {
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
                cout << "2. Return to Entrance\n";
            }
            else {
                cout << "1. Return to Entrance\n";
            } 

            cout << "Choose an option: ";

            int choice;
            cin >> choice;

            if (!hasSword && choice == 1) {
                hasSword = true;
                cout << "\nYou picked up a rusty old sword. It might still work...\n";
            }
            else if ((hasSword && choice == 1) || (!hasSword && choice == 2)) {
                currentRoom = "Entrance";
            }
            else {
                cout << "\nInvalid choice. Try again.\n";
            }
        }


        else if (currentRoom == "Hallway") {
            if (!enemyDefeated) {
                cout << "\nA goblin jumps out from the shadows!\n";

                if (hasSword) {
                    cout << "You raise your sword! The goblin shrieks and runs away.\n";
                }
                else {
                    cout << "You panic... but the goblin seems just as scared and runs off.\n";
                }

                enemyDefeated = true;
            }
            else {
                cout << "\nThe hallway is quiet. Whatever was here before is gone.\n";
            }

            cout << "1. Return to Entrance\n";
            cout << "Choose an option: ";

            int choice;
            cin >> choice;

            if (choice == 1) {
                currentRoom = "Entrance";
            }
            else {
                cout << "\nInvalid choice. Try again.\n";
            }
}

    }

    return 0;
}
