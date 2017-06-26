#pragma once
/////////////////////////////////////////////////////////////////////
//  DataVisualization.h										       //
//																   //
//  Language:      Visual C++ 2015                                 //
//  Platform:      Dell Inspiron, Windows 8.1			           //
//  Application:   ProjectDependency- PempPassionProjects	       //
//  Author:        Abhijit Srikanth SUID:864888072			       //
////////////////////////////////////////////////////////////////////
/*
Module Operations :
== == == == == == == == ==

This module defines a Visualization class
* -The functions defined in this class are used for,
> Calls the JsonSerialization class to build the JSON
> Builds the HTML and Javascript files

*/

#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>
#include <direct.h>

#include "../FileSystem/FileSystem.h"

class Visualization {
public:
	std::string visualizationMain(std::string json, std::string pjson);
	void cssPage();
	void javascriptFilePage(std::string json);
	void javascriptProjectPage(std::string pjson);

private:
	std::string jsonString;
	std::string visualizationPath;
};
