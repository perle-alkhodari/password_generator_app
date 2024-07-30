#include "Input.h"
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <string>

using namespace std;

void Input::ClearScreen()
{
	std::cout << "\x1B[2J\x1B[H" << std::endl;
}

void Input::SaveFeedback()
{
	ClearScreen();
	cout << "Saved!" << endl;
	Sleep(1500);
	ClearScreen();
}

string Input::GetAns(string prompt, int low, int high, int exit)
{
	bool invalid = true;
	bool strInvalid = true;
	string userInput;
	int intUserInput;
	if (!prompt.empty()) cout << prompt << endl;
	do {
		getline(cin, userInput);
		if (!userInput.empty()) strInvalid = false;
	} while (strInvalid);


	if (low != high) {
		while (invalid) {
			try {
				intUserInput = stoi(userInput);
				if (exit == 1 && intUserInput == -1) {
					invalid = false;
				}
				if (intUserInput >= low && intUserInput <= high) {
					invalid = false;
				}
			}
			catch (...) {
				invalid = true;
			}
			if (invalid) {
				cout << "\nMust be between " << low << " and " << high << "." << endl;
				getline(cin, userInput);
			}
		}
	}

	return userInput;
}

int Input::MenuChoice(vector<string> options)
{
	for (int i = 0; i < options.size(); ++i) {
		cout << "[" << i+1 << "] " << options.at(i) << endl;
	}

	string inp = GetAns("(-1 to exit)", 1, options.size(), 1);
	int userInput = stoi(inp);
	return userInput;
}

string Input::Lower(string str)
{
	string result;
	for (int i = 0; i < str.size(); ++i) {
		result += tolower(str.at(i));
	}
	return result;
}
