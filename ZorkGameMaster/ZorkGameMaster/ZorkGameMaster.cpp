// ZorkGameMaster.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


int main()
{
	char key;
	string player_input;
	cout << "Welcome to my Zork Game\n";
	cout << "--------------\n";
	

	while (1) {
		if (_kbhit() != 0) {
			key = _getch();
			if (key == '\b') {
				if (player_input.length() > 0) {
					player_input.pop_back();
					cout << '\b';
					cout << " ";
					cout << '\b';
				}
			}
			else if (key != '\r') {
				player_input += key;
				cout << key;
				
			}
			else {
				cout << "Tokenize";
				cout << endl;
			}

			//Interpretate instructions
		}
	}

	cout << "\nThanks for playing,Bye\n";
    return 0;
}

