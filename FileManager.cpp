#include "FileManager.h"
#include <string>
#include <vector>
#include <iostream>



void FileManager::SavePair(map<string, map<string, string>> pairs)
{
	ofstream file("Passwords.txt");
	for (auto iter = pairs.begin(); iter != pairs.end(); ++iter) {
		
		for (auto it = (iter->second).begin(); it != (iter->second).end(); ++it) {
			file << iter->first << "9999-" << it->first << "8888-" << it->second << endl;
		}
	}
	file.close();
}

map<string, map<string, string>> FileManager::MappedPairs()
{
	string locator;
	string loc = "9999-";
	int index;
	int index1; // since you feel like it fine XD

	string platform = "";
	string password = "";
	string email = "";
	string contents;

	map<string, string> emailPass;
	map<string, map<string, string>> result; // XDDDD // my stream has music u can join if u want bro

	ifstream file("Passwords.txt");

	while (getline(file, contents)) {
		index = contents.find("9999-");          
		index1 = contents.find("8888-"); 
		platform = contents.substr(0, index);
		int i = contents.substr(index + 5, index1).find("8888-");
		email = contents.substr(index + 5, index1).substr(0, i);
		password = contents.substr(index1 + 5);			
		result[platform].insert(make_pair(email, password));
	}
	file.close();
	return result;
}
