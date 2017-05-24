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
	std::string visualizationMain(std::string json);
	void cssPage();
	void javascriptPage(std::string json);

private:
	std::string jsonString;
	std::string visualizationPath;
};
