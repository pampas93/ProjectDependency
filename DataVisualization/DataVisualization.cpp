#include "DataVisualization.h"
/////////////////////////////////////////////////////////////////////
//  DataVisualization.cpp									       //
//																   //
//  Language:      Visual C++ 2015                                 //
//  Platform:      Dell Inspiron, Windows 8.1			           //
//  Application:   ProjectDependency- PempPassionProjects	       //
//  Author:        Abhijit Srikanth SUID:864888072			       //
/////////////////////////////////////////////////////////////////////

std::string Visualization::visualizationMain(std::string json, std::string pjson)
{

	visualizationPath = "../VisualizationFiles/fileVisualization.html";

	cssPage();
	javascriptFilePage(json);
	javascriptProjectPage(pjson);

	return visualizationPath;
}


void Visualization::cssPage()
{
	std::string cssCode = ".node {\n stroke: #fff ;	stroke - width: 1.5px; }\n .link{\n stroke: #999; stroke - opacity: .6;\n}";
	
	std::string cssPath = "../VisualizationFiles/d3cascading.css";

	try {
		std::ofstream doc(cssPath);
		doc << cssCode;
		doc.close();

	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}

	return;
}

void Visualization::javascriptFilePage(std::string json)
{
	std::string jsCode;
	jsCode.append("window.onload=function(){\nvar graph = \n");
	jsCode.append(json);
	jsCode.append(";\n");

	std::string jsPath = "../VisualizationFiles/FileGraph.js";
	try {

		std::ifstream document1("../VisualizationFiles/partialFileJS.js");
		std::string graphCode;

		std::string str;
		while (getline(document1, str))
		{
			graphCode.append(str);
			graphCode.append("\n");
		}
		document1.close();
		
		jsCode.append(graphCode);
		jsCode.append("\n}");

		std::ofstream doc(jsPath);
		doc << jsCode;
		doc.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	return;
}

void Visualization::javascriptProjectPage(std::string pjson)
{
	std::string jsCode;
	jsCode.append("window.onload=function(){\nvar graph = \n");
	jsCode.append(pjson);
	jsCode.append(";\n");

	std::string jsPath = "../VisualizationFiles/ProjectGraph.js";
	try {

		std::ifstream document1("../VisualizationFiles/partialProjectJS.js");
		std::string graphCode;

		std::string str;
		while (getline(document1, str))
		{
			graphCode.append(str);
			graphCode.append("\n");
		}
		document1.close();

		jsCode.append(graphCode);
		jsCode.append("\n}");

		std::ofstream doc(jsPath);
		doc << jsCode;
		doc.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	return;
}
