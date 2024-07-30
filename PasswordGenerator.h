#pragma once
#include <string>

using namespace std;

class PasswordGenerator {
public:
	string GeneratePassword(int length = 12);

	void DisplayPair(string platform, string email, string password);
};
