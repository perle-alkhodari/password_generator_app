#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include "PasswordGenerator.h"
#include "Input.h"
#include "FileManager.h"

using namespace std;



int main() {
	PasswordGenerator pg;
	Input input;
	FileManager fm;

	vector<string> options = { "See Passwords", "Make New", "Delete" };
	string saveStatement;

	string application;
	int passwordLength;
	int menuChoice = 0;
	string email;
	string password;
	string deletePlatform;
	string deleteUser;
	bool on = true;
	bool isSave;
	bool stillDeleting = true;

	map<string, map<string, string>> m;
	map<string, string> emailPass;

	srand(time(NULL));

	while (menuChoice != -1) {
		m = fm.MappedPairs();
		input.ClearScreen();
		menuChoice = input.MenuChoice(options);

		switch (menuChoice) {
		case -1:
			break;
		case 1:
			// SEE PAIRS
			input.ClearScreen();
			for (auto iter = m.begin(); iter != m.end(); ++iter) {
				
				for (auto it = (iter->second).begin(); it != (iter->second).end(); ++it) {
					cout << setw(10) << left << iter->first << "     " << setw(10) << left << it->first << "     " << it->second << endl;
				}
			}
			cout << "\nEnter any key to continue..." << endl;
			cin.get();
			// SEE PAIRS
			break;
		case 2:
			// ADD PAIR
			input.ClearScreen();
			application = input.GetAns("For which platform? (-1 to exit)", 0, 0, 1);
			if (application == "-1") break;
			cout << endl;
			email = input.GetAns("Username or Email? (-1 to exit)", 0, 0, 1);
			if (email == "-1") break;
			cout << endl;
			passwordLength = stoi(input.GetAns("How long would you like the password to be? (-1 for default).", 7, 20, 1));
			if (passwordLength == -1) password = pg.GeneratePassword(); else password = pg.GeneratePassword(passwordLength);
			input.ClearScreen();

			pg.DisplayPair(application, email, password);
			cout << endl;

			application = input.Lower(application);
			email = input.Lower(email);

			saveStatement = (m[application].find(email) == m[application].end()) ? "Save this group? (1 - yes, 0 - no)." : "Are you sure you want to overwrite your existing password for " + application + "? (1 - yes, 0 - no).";

			isSave = stoi(input.GetAns(saveStatement, 0, 1));

			if (isSave) {
				m[application].insert(make_pair(email, password));
				fm.SavePair(m);
				input.SaveFeedback();
			}
			break;
			// END ADD PAIR
		case 3:
			while (stillDeleting) {
				input.ClearScreen();
				for (auto iter = m.begin(); iter != m.end(); ++iter) {

					for (auto it = (iter->second).begin(); it != (iter->second).end(); ++it) {
						cout << setw(15) << left << iter->first << setw(15) << left << it->first << it->second << endl;
					}
				}
				cout << endl;
				cout << "Type the platform / user pair to delete. (-1 to exit).\n" << endl;
				deletePlatform = input.GetAns("platform: ", 0, 0, 1);
				if (deletePlatform == "-1") break;
				deletePlatform = input.Lower(deletePlatform);
				cout << endl;
				deleteUser = input.GetAns("user: ", 0, 0, 1);
				if (deleteUser == "-1") break;
				deleteUser = input.Lower(deleteUser);
				cout << endl;

				if (m.find(deletePlatform) != m.end()) {
					auto isFind = m[deletePlatform].find(deleteUser);
					if (isFind != m[deletePlatform].end()) m[deletePlatform].erase(deleteUser);
					fm.SavePair(m);
				}
			}

		}
	}

}