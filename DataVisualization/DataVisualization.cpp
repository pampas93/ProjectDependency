#include "DataVisualization.h"

std::string Visualization::visualizationMain(std::string json)
{
	try {

		visualizationPath = "../VisualizationFiles/visualization.html";

		std::string openHtmlTags = "<html>\n<head>\n";
		std::string cssLink = "<link rel = \"stylesheet\" type = \"text/css\" href = \"../VisualizationFiles/d3cascading.css\" />\n";
		std::string jsLink = "\n<script type=\"text/javascript\" src=\"../VisualizationFiles/Graph.js\"></script> \n\n <script src = \"http://d3js.org/d3.v2.min.js?2.9.6\"></script>";
		std::string pageTitle = "\n<title>Dependency Visualization</title>\n\n</head>\n<body>";
		std::string closeHtmlTags = "\n</body>\n</html>";

		std::ofstream doc(visualizationPath);
		doc << openHtmlTags;
		doc << cssLink;
		doc << jsLink;
		doc << pageTitle;
		doc << closeHtmlTags;
		doc.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}

	cssPage();
	javascriptPage(json);

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

void Visualization::javascriptPage(std::string json)
{
	std::string jsCode;
	jsCode.append("window.onload=function(){\nvar graph = \n");
	jsCode.append(json);
	jsCode.append(";\n");

	std::string jsPath = "../VisualizationFiles/Graph.js";
	try {

		std::ifstream document1("../VisualizationFiles/partialJS.js");
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
