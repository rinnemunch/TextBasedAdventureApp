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

// Random Entrance Atmosphere 
string entranceAtmosphere[] = {
    "A cold draft sweeps through the hall...",
    "The torches flicker for a moment.",
    "You hear dripping water echoing in the dark.",
    "Dust floats in the air like falling snow.",
    "The ground vibrates slightly beneath your feet.",
    "A low rumble echoes from deep below.",
    "You catch a faint smell of smoke in the air.",
    "A whisper of wind brushes past your neck."
}; 


// Main Game Logic Begins Here
int main() { 
    srand(time(0));

    // === GAME STATE ===
    bool gameRunning = true;
    string currentRoom = "Menu";
    bool hasSword = false; 
    // Sword Level:
    // 1 = Basic sword (default from Armory)
    // 2 = Enchanted sword (earned from Boss Room)
    // Future fights should scale damage based on swordLevel
    int swordLevel = 1;
    bool enemyDefeated = false; 
    bool skeletonDefeated = false;
    int playerHealth = 100;
    string playerName;
    bool wizardAppeared = false; 
    int gold = 0;
    bool wizardHealed = false;
    bool potionFound = false;
    bool bossDefeated = false;  
    bool goblinReturned = false;
    bool goblinSpared = false;


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


                // Monsters defeated
                int totalDefeated = 0;
                if (enemyDefeated) totalDefeated++;
                if (skeletonDefeated) totalDefeated++;

                cout << YELLOW << "Monsters defeated: " << totalDefeated << "/2" << RESET << endl; 

                int messageIndex = rand() % 8;
                typeText(entranceAtmosphere[messageIndex]);


                if (!bossDefeated) {
                    typeText("You notice a large door covered in runes. It looks important, but it won't budge.");
                }
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
            if (skeletonDefeated && enemyDefeated && !bossDefeated) {
                cout << "7. Enter the final door with strange markings\n";
            }

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

                    if (playerHealth == 100) {
                        cout << YELLOW << "Your health is full. Drink the potion anyway?\n" << RESET;
                        cout << "1. Drink it now\n";
                        cout << "2. Save it for later\n";
                        cout << "Choose an option: ";

                        int potionChoice;
                        cin >> potionChoice;

                        if (potionChoice == 1) {
                            typeText("You drink the potion even though you're at full health. Wasteful... but refreshing.");
                            potionFound = true;
                        }
                        else {
                            typeText("You decide to leave it for later.");
                        }
                    }
                    else {
                        typeText("You drink the potion and feel your wounds healing.");
                        playerHealth += 25;
                        if (playerHealth > 100) playerHealth = 100;
                        potionFound = true;
                        cout << GREEN << "Health restored to " << playerHealth << RESET << endl;
                    }
                }
                else {
                    cout << "\nYou already found the potion here. Nothing else of interest.\n";
                }
            }


            else if (choice == 5) {
                currentRoom = "TrapRoom";
            }
            else if (choice == 6) {
                currentRoom = "Menu";
            } 
            else if (choice == 7 && skeletonDefeated && enemyDefeated && !bossDefeated) {
                currentRoom = "BossRoom";
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

            // The goblin returns
            if (enemyDefeated && !goblinReturned && !bossDefeated) {
                typeText("You hear a familiar snarl behind you...");
                typeText("It's the goblin you spared and he's back for revenge!");

                goblinReturned = true;

                int goblinHealth = 20;

                while (goblinHealth > 0 && playerHealth > 0) {
                    cout << "\nYour Health: " << GREEN << playerHealth << RESET
                        << " | Goblin Health: " << RED << goblinHealth << RESET << endl;

                    cout << "1. Light Attack (5-10 dmg)\n";
                    cout << "2. Heavy Attack (10-20 dmg)\n";
                    cout << "Choose your action: ";

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
                        typeText("You hesitate… and miss your chance!");
                    }

                    goblinHealth -= damage;
                    cout << "You dealt " << damage << " damage.\n";

                    if (goblinHealth > 0) {
                        int enemyHit = 4 + rand() % 6;
                        typeText("The goblin lunges at you!");
                        cout << RED << "The goblin hits you for " << enemyHit << " damage!" << RESET << endl;
                        playerHealth -= enemyHit;
                    }

                    if (playerHealth <= 0) {
                        typeText("\nYou collapse at the entrance. The dungeon claims another adventurer...");
                        typeText("GAME OVER");
                        gameRunning = false;
                        return 0;
                    }
                }

                typeText("The goblin slumps over. Mercy doesn't always pay.");
                cout << R"ASCII(
                                             ..........                                              
                                   ..:-=+**##%%%####%%%##**+=-:..                                    
                                .:*%@%####@@+**+*******+@@#*##%@%*:.                                 
                              .-%@%******#@+%+********+%+@%******%@%-.                               
                             .+@%********#@**************@%********%@+.                              
                            .+@@@%%@@#***#@**#%%****%%#**@#***#@@%%@@@+.                             
                           .+@%**###*#@%**%%*+********+*%%**%@%*###**%@*.                            
                          .+@%******+*#@@%*+#+********+#++%@@#*+******#@+.                           
                         .=@@#**#@%***+*@%+%=**********+%+%@*+***%@#**#@@=.                          
         ..=*####*-..    :%%+*##*+@@#***#@*#************#*%#***#@@+*##*+#%:     .-*####*=....        
   .*#+*#+=+++++++*@#:  .*#*****+%*@@#**#@******#%%#******@#***@@*%+****+#*.  .*@*+++++++=+#*+#*..   
   ..%@@@@@@@@%*****#@+.-%******+=#*@@***%**%%********%%*+%***@@##++******%=.+@#*****#%@@@@@@@@..    
     .@#########%%****@#+#*******=%*@@%*#@%+************+%@#*%@@#%+*******#*#@****%%#########@:      
      =%#####%%%##%#*+*@@*+******+#*@@@*@%+**************+#@*@@@*#*******+*@@*+*#%##%%%#####%+.      
      :@########%@%%#+*%@++*********@@@@@#+**************+*@@@@@*********++%%*+#%%@%########@:       
      .%%#########@@@*+#@*+*******+*@@@@@++**************++%@@@@*+*******+*@%++@@@#########%%:       
      .%%#########%@@*+%@%++******+#@@@@@++**************++%@@@@%+*******+%@%+*@@%#########%%:       
      .*%######%###@@+*@@%#*#@@@@@@@@@@@@*#**************#*@@@@@@@@@@@@#+#%@@*+@@###%######%*.       
      .-%%######@##%@+*@%*@@#===+@#*#@@@@%****************%@@@@#*#%*===#@@*%@*+@@##@#######%-.       
       .=%######%@%%#**@#%%+*******++***%@%*#+*********#*%@%***++*******=%%*@#+#@%@#######%=.        
        ..*@%#####@@%+#%*%****##@@@@@@%##%@@*#********#*@@%##%@@@@@@#*****%*%#+#@@%####%%*:..        
          ..+@%####@@*#%*%%**%@@@@@@@@@%@@@@@%#******#%@@@@@%@@@@@@@@@%**%%*%#*@@####%@+..           
           ..+######@@##*#***@@@@@@##*%@@@@@@@@@@**@@@@@@@@@@%*##@@@@@@***#*##@@####*#+..            
            .:#*#####@@###++#@@@@@%*@@@*@@@@%@@%*++*%@@%@@@@*@@@*#@@@@@%+**##@@#####*#:.             
            ..*#*#####@%#*++%@@@@*%%%*@%%@@%@#%#****#%#@%@@%%@+%%%*@@@@%+**#%@#####*#*..             
             .:%*#%###@%#***+@@@@@+@@@%+@@%@#%#*+**+*#%#@%@@*%@@@+@@@@@+***#%@###%#*%-..             
              .+%*%%##%@#***++@@@@@@@@@@%%##%%#@#==#@#%%##%%@@@@@@@@@@*+***#@%##%%*%*...             
               .#%#%%%@@%**+**++*######****#@*@@@@@@@@*%#****#######++**+**%@@%%%#%#..                
                .*%#%@@@@***+************#%@*%@@@@@@@@%*@%#************+***@@@@%#%*..                 
                 .=%#%@@@@**%#===##**#%%%%@**@@@@@@@@@@**@%%%%%**##===*%**@@@@%#%=.                   
                  ..+@%%@@@#=****++@@@@******@@@@#*@@@@**#***@@@@++****=#@@@%%@*..                    
                     ..%@%%@@@@@@@##@@@*+*##+#@@%==%@@#+%#*+*@@@##@@@@@%@%%@%:....                    
                       ..+@@%#%#****#@%+==+**#++#**#++#**+==+%@#****#%#%@@*..                         
                         .:@@##*#***#%*=+***+**********+***+=*%#***%*##@@:.                          
                          .-@@##******+*+++*=**********=*+++*+*#***+##@@=                            
                           .%@##+***+*+#+++*=***+**++**=*+++#+*+***+##@%.                            
                           .-@###+*#*##%+**#%++#+==+#*+%##*+%##*#*+##*@=                             
                            .%@**%+*+=-+=+-#:=#:-#*-:#=-%-+=*-=+#+%*+@%:                             
                            .=@%%+#**%@=-=-*:=#::##::*=:#-=-=@%**#+%%@=.                             
                            .-@%#@****@@@#=#:-+::##::=-:%=#@@@****%#%@-.                             
                             .*@*#%#**@%@@@@@@@%#@@#%@@@@@@@%@***%#*@*..                             
                            ..:%%*##++*%%@@@@@@@@@@@@@@@@@@%%*++##*@%-.                              
                              .:*@%%++**#%@@@@@@@@@@@@@@@@%#**++%%@*:.                               
                                ..=@#+=****#@@@@%@@%@@@@%****=+#@=...                                
                                  .=@@*+=++***###**###***++=+#@@=.                                   
                                    .=@@#++==++++++++++==++#@@+.                                     
                                      .=%@#+==++++++++==+#@%=.                                       
                                       ..-#@%%%%****%%%%@#=..                                        
                                          ................                                           
)ASCII";

            }

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
                        goblinSpared = true;
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
                int messageIndex = rand() % 8;
                typeText(entranceAtmosphere[messageIndex]);
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
            int messageIndex = rand() % 8;
            typeText(entranceAtmosphere[messageIndex]);

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
            typeText("You step into a narrow tunnel...");
            int messageIndex = rand() % 8;
            typeText(entranceAtmosphere[messageIndex]);
            typeText("As the door shuts behind you, the floor clicks.");

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
        // == BOSS ROOM ==  
        else if (currentRoom == "BossRoom") {
                typeText("\nYou enter the boss chamber. A shadow rises... it's the Dungeon Beast!");

                int bossHealth = 60;
                int phase = 1;

                while (bossHealth > 0 && playerHealth > 0) {
                    cout << "\nYour Health: " << GREEN << playerHealth << RESET
                        << " | Boss Health: " << RED << bossHealth << RESET << endl;

                    cout << "1. Strike\n";
                    cout << "2. Defend\n";
                    cout << "Choose your action: ";

                    int action;
                    cin >> action;

                    int damage = 0;
                    if (action == 1) {
                        damage = 10 + rand() % 6;
                        typeText("You attack the beast!");
                        bossHealth -= damage;
                        cout << "You dealt " << damage << " damage.\n";
                    }
                    else if (action == 2) {
                        typeText("You brace yourself for the attack...");
                    }
                    else {
                        typeText("You hesitate... and lose momentum!");
                    }

                    if (bossHealth > 0) {
                        int bossDmg = (phase == 1) ? (8 + rand() % 6) : (12 + rand() % 6);
                        if (action == 2) bossDmg /= 2;

                        typeText("The Dungeon Beast lashes out!");
                        cout << RED << "You take " << bossDmg << " damage!" << RESET << endl;
                        playerHealth -= bossDmg;
                    }

                    if (bossHealth <= 30 && phase == 1) {
                        phase = 2;
                        typeText("\nThe Beast roars and grows more furious! Phase 2 begins!");
                    }

                    if (playerHealth <= 0) {
                        typeText("\nYou fall... the beast stands victorious.");
                        typeText("GAME OVER");
                        gameRunning = false;
                        return 0;
                    }
                }

                typeText("\nThe Dungeon Beast collapses with a ground-shaking thud...");
                typeText("You walk up to its altar and claim a gleaming enchanted sword!");
                hasSword = true; 
                swordLevel = 2; // This is for the enchanted sword's power
                bossDefeated = true;
                currentRoom = "Entrance";
                }




    } // end of while (gameRunning)

    return 0;
}
