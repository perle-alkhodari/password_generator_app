#pragma once
#include <string>
#include <vector>

using namespace std;

class Input {
public:
	void ClearScreen();

	void SaveFeedback();

	string GetAns(string prompt = "", int low = 0, int high = 0, int exit = 0);

	int MenuChoice(vector<string> options);

	string Lower(string str);
};