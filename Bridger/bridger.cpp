#include "../Bridger/bridger.h"
#include <string>
#include <thread>
#include <iostream>
#include "../Analyzer/Executive.h"

class Bridger : public IBridger
{
public:
	void start(char* path);
	void stop();
private:
};

void Bridger::start(char* path)
{
	char * argvArray[7];
	std::string temp = "simbly";

	argvArray[0] = _strdup(temp.c_str());
	argvArray[1] = path;

	std::string x[] = { "simbly","pathActually","*.h","*.cpp","/m","/f","/r" };
	for (int i = 2; i < 7; i++) {
		const char* xx = x[i].c_str();
		argvArray[i] = _strdup(xx);
	}

	CodeAnalysis::CodeAnalysisExecutive exexec;
	exexec.ProcessCommandLine(7, argvArray);
	std::unordered_map<std::string, std::vector<std::string>> xx = exexec.ExecutiveMain4GUI();
	
	return;
	//std::cout << "Tester";
}

void Bridger::stop()
{
}

IBridger* ObjectFactory::createBridger()
{
	return new Bridger();
}
