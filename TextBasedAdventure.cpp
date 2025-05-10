#include <iostream> 
using namespace std; 

int main() {
	bool gameRunning = true; 

	while (gameRunning) {
		cout << "\n============================= \n"; 
		cout << "   WELCOME TO DUNGEON QUEST\n"; 
		cout << "=============================\n"; 
		cout << "1. Enter the Dungeon\n"; 
		cout << "2. Quit Game \n"; 
		cout << "Choose an option: "; 

		int choice; 
		cin >> choice; 

		if (choice == 1) {
			cout << "\nYou step into the dungeon... it's dark and cold.\n"; 
		}
		else if (choice == 2) {
			cout << "\nThanks  for playing!\n"; 
			gameRunning = false; 
		}
		else {
			cout << "\nInvalid choice. Try again.\n"; 
		}
	}

	return 0;
}