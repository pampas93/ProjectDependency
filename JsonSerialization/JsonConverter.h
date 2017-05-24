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
	std::string linksString();

	std::string projectNodeString();
	std::string projectLinksString();
	void buildFile2ProjectMap();

	std::string delimiterFuncProjectName(std::string fullPath);

private:
	MapofDep fileDep;
	MapofDep projDep;
	std::unordered_map<std::string, std::string> file2ProjectMap;
	Files fileList;
	Files projectList;
	FileMap fileIndexMap;
	FileMap projIndexMap;
};

