#include <iostream>
using namespace std;

int main() {
    bool gameRunning = true;
    string currentRoom = "Menu";

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

        else if (currentRoom == "Hallway") {
            cout << "\nYou are in the Hallway. It's quiet... too quiet.\n";
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
