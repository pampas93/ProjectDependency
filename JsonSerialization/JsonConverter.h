#pragma once
/////////////////////////////////////////////////////////////////////
//  JsonConvertor.h											       //
//																   //
//  Language:      Visual C++ 2015                                 //
//  Platform:      Dell Inspiron, Windows 8.1			           //
//  Application:   ProjectDependency- PempPassionProjects	       //
//  Author:        Abhijit Srikanth SUID:864888072			       //
/////////////////////////////////////////////////////////////////////
/*
Module Operations :
== == == == == == == == ==

This module defines a JsonConverter class
* -The functions defined in this class are used for,
> Builds a JSON string for project nodes based on the dependencies(unordered_map)
> Builds a JSON string for project links based on the dependencies(unordered_map)
> Returns the final Json string

*/

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

	void jsonMain(MapofDep fileDepMap, MapofDep projDepMap, Files fileListEx);
	std::string nodeString();
	std::string linksString();

	std::string projectNodeString();
	std::string projectLinksString();
	void buildFile2ProjectMap();

	std::string returnFileJson();
	std::string returnProjectJson();

	std::string delimiterFuncProjectName(std::string fullPath);

private:
	std::string jsonString;
	std::string pjsonString;

	MapofDep fileDep;
	MapofDep projDep;
	std::unordered_map<std::string, std::string> file2ProjectMap;
	Files fileList;
	Files projectList;
	FileMap fileIndexMap;
	FileMap projIndexMap;
};

