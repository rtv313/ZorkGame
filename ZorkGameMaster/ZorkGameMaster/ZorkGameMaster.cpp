// ZorkGameMaster.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "Helpers.h"
#include "World.h"

using namespace std;


int main()
{
	char key;
	string player_input;
	vector<string> args;
	args.reserve(10);
	World MyWorld;
	bool ExitFlag = false;
	
	cout << "\n--------------";
	
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
				Tokenize(player_input, args); // separate each word assign each word to a vector cell , next interpretate instrucctions 
				if (CompareStrings(args[0],"Quit")) { 
					break; 
				}

				if (args.size() > 0 && args[0]!="") {
					MyWorld.SendInstrucction(args,ExitFlag);
					if (ExitFlag) {
						break; 
					}
				}

				args.clear();
				player_input.clear();
				cout << "\n\n";
			}
		}
	}

	cout << "\nThanks for playing,Bye\n";
	system("pause"); //this pauses the program until you press any key 
    return 0;
}

