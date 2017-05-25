#pragma once

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
