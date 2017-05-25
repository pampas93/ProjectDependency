#include "../Bridger/bridger.h"
#include <string>
#include <thread>
#include <iostream>
#include "../Analyzer/Executive.h"

class Bridger : public IBridger
{
public:
	void start(char* path);
	void open();
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

void Bridger::open()
{
	std::string f = "file:///" + FileSystem::Path::getFullFileSpec("../VisualizationFiles/fileVisualization.html");
	std::wstring ff = std::wstring(f.begin(), f.end());
	LPCWSTR lpcff = ff.c_str();
	LPCWSTR a = L"open";
	LPCWSTR browser = L"chrome.exe";
	ShellExecute(NULL, a, browser, lpcff, NULL, SW_SHOWDEFAULT);

}

void Bridger::stop()
{
}

IBridger* ObjectFactory::createBridger()
{
	return new Bridger();
}
