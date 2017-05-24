#pragma once

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "../FileSystem/FileSystem.h"

class JsonConverter {

public:
	using MapofDep = std::unordered_map<std::string, std::vector<std::string>>;
	using FileMap = std::unordered_map<std::string, int>;
	using Files = std::vector<std::string>;

	std::string jsonMain(MapofDep fileDepMap, MapofDep projDepMap, Files fileListEx);
	std::string nodeString();
	int getFileIndex(std::string file);
	std::string linksString();

private:
	MapofDep fileDep;
	MapofDep projDep;
	Files fileList;
	FileMap fileIndexMap;
};

