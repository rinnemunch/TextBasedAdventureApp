#include <iostream>
#include <string> 
#include <chrono>
#include <thread>
using namespace std;  

// == Color Codes == 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"


// == Type Text Function ==
void typeText(const string& text, int delayMs = 30) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}

// ==== FUNCTION: Show Dungeon Art ====
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


// Main Game Logic Begins Here
int main() {
    // === GAME STATE ===
    bool gameRunning = true;
    string currentRoom = "Menu";
    bool hasSword = false;
    bool enemyDefeated = false; 
    bool skeletonDefeated = false;
    int playerHealth = 100;
    string playerName;
    bool wizardAppeared = false;
    bool wizardHealed = false; 
    bool potionFound = false;


    while (gameRunning) {

        // === ROOM: MENU ===
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
            cout << YELLOW << "Choose an option: " << RESET;

            int choice;
            cin >> choice;

            if (choice == 1) {
                cin.ignore(); 
                cout << "\nBefore you enter... what is your name, adventurer?\n";
                getline(cin, playerName);

                currentRoom = "Entrance";
                typeText("\n" + playerName + ", you are standing in the dungeon entrance.");
                cout << GREEN << "Health: " << playerHealth << RESET << endl;
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

        // === ROOM: ENTRANCE ===
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
                if (!potionFound) {
                    typeText("\nYou examine your surroundings... you notice a loose stone near the wall.");
                    typeText("Behind it, you find a small red potion vial!");
                    cout << GREEN << "You drink the potion and recover 25 health!" << RESET << endl;

                    playerHealth += 25;
                    if (playerHealth > 100) playerHealth = 100;
                    potionFound = true;
                }
                else {
                    cout << "\nYou examine the room again, but there's nothing new.\n";
                }
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

        // === ROOM: ARMORY ===
        else if (currentRoom == "Armory") {
            cout << "\nYou are in the Armory. Old swords and cracked shields cover the walls.\n";

            if (!hasSword) {
                cout << "1. Take the sword\n";
                cout << "2. Examine the room\n";
                cout << "3. Enter the Training Room\n";
                cout << "4. Return to Entrance\n";
            }
            else {
                cout << "1. Examine the room\n";
                cout << "2. Enter the Training Room\n";
                cout << "3. Return to Entrance\n";
            }

            cout << "Choose an option: ";
            int choice;
            cin >> choice;

            if (!hasSword) {
                if (choice == 1) {
                    hasSword = true;
                    typeText("\nYou picked up a rusty old sword. It might still work...");
                }
                else if (choice == 2) {
                    cout << "\nYou examine the walls. One sword has a notch shaped like a dragon's tooth.\n";
                }
                else if (choice == 3) {
                    currentRoom = "TrainingRoom";
                }
                else if (choice == 4) {
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
                    currentRoom = "TrainingRoom";
                }
                else if (choice == 3) {
                    currentRoom = "Entrance";
                }
                else {
                    cout << "\nInvalid choice. Try again.\n";
                }
            }
        }

        // === ROOM: HALLWAY ===
        else if (currentRoom == "Hallway") { 

            // === ENCOUNTER: GOBLIN ===
            if (!enemyDefeated) {
                typeText("\nA goblin jumps out from the shadows!");

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
                    cout << RED << "You took 25 damage!" << RESET << endl;
                }

                if (playerHealth <= 0) {
                    typeText("\n" + playerName + ", you've taken too much damage and collapse...");
                    typeText("GAME OVER");
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

        // === ROOM: LIBRARY ===
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
                    typeText("\nYou read further... The page speaks of a Lich King buried beneath the dungeon,");
                    typeText("sealed away by fire and blood. His return could unmake the world.");

                    // === EVENT: Wizard Encounter (Library) ===
                    if (!wizardAppeared) {
                        wizardAppeared = true;
                        typeText("\nSuddenly, the torches flicker. A shadow steps out from behind the shelves...");
                        typeText("An old wizard in a deep purple robe appears, stroking his beard.");
                        typeText("\"Curious minds awaken old truths,\" he says. \"Be careful what you seek, " + playerName + ".\"");

                        // === Healing Interaction ===
                        if (playerHealth < 100 && !wizardHealed) {
                            typeText("\nThe wizard notices your wounds.");
                            typeText("\"You've been injured. Would you like me to heal you?\"");

                            cout << "1. Accept healing\n";
                            cout << "2. Decline\n";
                            cout << "Choose an option: ";
                            int healChoice;
                            cin >> healChoice;

                            if (healChoice == 1) {
                                playerHealth = 100;
                                wizardHealed = true;
                                typeText("The wizard lifts his staff. A warm light surrounds you...");
                                typeText(GREEN + string("You feel completely restored!") + RESET);
                            }
                            else {
                                typeText("\"Very well,\" the wizard says. \"I won’t ask again.\"");
                                wizardHealed = true;
                            }
                        }

                        typeText("The wizard fades away into sparkles of light...");
                    }
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

        // === ROOM: TRAPROOM ===
        else if (currentRoom == "TrapRoom") {
            typeText("\nYou step into a narrow tunnel. As the door shuts behind you, the floor clicks.");
            typeText("A trap is triggered! Choose fast:");
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
                cout << RED << "You took 30 damage. Health: " << playerHealth << RESET << endl;

                if (playerHealth <= 0) {
                    cout << "\n" << playerName << ", you fall to the ground... the dungeon claims another victim.\n";
                    cout << RED << "GAME OVER\n" << RESET;
                    gameRunning = false;
                }
            }

            if (playerHealth > 0) {
                cout << "\n" << playerName << ", you stumble back into the dungeon entrance, still breathing...\n";
            }

            currentRoom = "Entrance";
       } 

       // === ROOM: TRAINING ROOM ===
        else if (currentRoom == "TrainingRoom") {
            typeText("\nYou step into the Training Room. A skeleton warrior clatters to life from the corner...");

            if (!skeletonDefeated) {
                if (!hasSword) {
                    typeText("You step forward... but realize you're unarmed. The skeleton stares at you, unmoved.");
                    typeText("You decide to come back later when you're better equipped.");
                }
                else {
                    int skeletonHealth = 30;

                    while (skeletonHealth > 0 && playerHealth > 0) {
                        cout << "\nYour Health: " << GREEN << playerHealth << RESET
                            << " | Skeleton Health: " << RED << skeletonHealth << RESET << endl;

                        cout << "1. Light Attack (5-10 dmg)\n";
                        cout << "2. Heavy Attack (10-20 dmg)\n";
                        cout << YELLOW << "Choose your action: " << RESET;

                        int attackChoice;
                        cin >> attackChoice;

                        int damage = 0;
                        if (attackChoice == 1) {
                            damage = 5 + rand() % 6;
                            typeText("You strike with speed!");
                        }
                        else if (attackChoice == 2) {
                            damage = 10 + rand() % 11;
                            typeText("You commit to a heavy swing!");
                        }
                        else {
                            typeText("You hesitate... and miss your chance!");
                        }

                        skeletonHealth -= damage;
                        cout << "You dealt " << damage << " damage.\n";

                        if (skeletonHealth > 0) {
                            int enemyHit = 5 + rand() % 8;
                            typeText("The skeleton counters!");
                            cout << RED << "The skeleton hits you for " << enemyHit << " damage!" << RESET << endl;
                            playerHealth -= enemyHit;

                            if (playerHealth <= 0) {
                                typeText("\nYou collapse beside the training dummy. The dungeon claims another adventurer...");
                                typeText("GAME OVER");
                                gameRunning = false;
                                return 0;
                            }
                        }
                    }

                    typeText("The skeleton crumbles into a pile of bones.");
                    skeletonDefeated = true;
                }
            }
            else {
                typeText("The Training Room is quiet. The skeleton remains defeated.");
            }

            cout << "1. Return to Armory\n";
            int nextChoice;
            cin >> nextChoice;
            currentRoom = "Armory";
            }



    } // end of while (gameRunning)

    return 0;
}
