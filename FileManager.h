#pragma once
#include <fstream>
#include <map>
#include <string>

using namespace std;

class FileManager {
public:
	void SavePair(map<string, map<string, string>> pairs);

	map<string, map<string, string>> MappedPairs();
};