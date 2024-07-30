#include "PasswordGenerator.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

string PasswordGenerator::GeneratePassword(int length)
{
	string result;

	char x;

	vector<char> chars;

	for (int i = 48; i < 58; ++i) {
		x = tolower(i);
		chars.push_back(x);
	}

	for (int i = 65; i < 91; ++i) {
		x = tolower(i);
		chars.push_back(x);
	}

	for (int i = 65; i < 91; ++i) {
		x = toupper(i);
		chars.push_back(x);
	}

	chars.push_back('!');
	chars.push_back('#');
	chars.push_back('?');
	chars.push_back('-');
	chars.push_back('_');
	chars.push_back('+');
	chars.push_back('?');
	chars.push_back('@');

	for (int i = 0; i < length; ++i) {
		result += chars.at(rand() % chars.size());
	}

	return result;
}

void PasswordGenerator::DisplayPair(string platform, string email, string password)
{
	cout << "Platform: " << platform << "      User/Email: " << email << "      Password: " << password << endl;
}

