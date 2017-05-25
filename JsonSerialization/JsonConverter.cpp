#include "JsonConverter.h"

void JsonConverter::jsonMain(MapofDep fileDepMap, MapofDep projDepMap, Files fileListEx)
{

	fileDep = fileDepMap;
	projDep = projDepMap;
	this->fileList = fileListEx;

	buildFile2ProjectMap();

	std::string Projnodes = projectNodeString();
	pjsonString.append("{");
	pjsonString.append(Projnodes);
	std::string Projlinks = projectLinksString();
	pjsonString.append(Projlinks);
	pjsonString.append("}");

	std::string nodes = nodeString();
	jsonString.append("{");
	jsonString.append(nodes);
	std::string links = linksString();
	jsonString.append(links);
	jsonString.append("}");

	return ;
}

std::string JsonConverter::nodeString()
{
	std::string nodeMain = "\"nodes\":[";
	bool firstLine = true;

	std::string newPath = "C:/Users/Abhijit/Desktop/ProjectDependency/depOutput.txt";
	std::ofstream doc(newPath);


	int fileIndex = 0;
	for (std::string file : fileList) 
	{
		std::string fileName = FileSystem::Path::getName(file);

		std::string project = file2ProjectMap[file];
		int projIndex = projIndexMap[project];

		
		doc << file + "\n";
		doc << project + "\n";
		doc << projIndex + "\n\n\n";

		fileIndexMap[fileName] = fileIndex;
		fileIndex++;

		if (!firstLine) {
			nodeMain.append(",");
		}
		nodeMain.append("{\"name\":\"");
		nodeMain.append(fileName);
		nodeMain.append("\",\"group\" : ");
		nodeMain.append(std::to_string(projIndex));
		nodeMain.append("}");


		firstLine = false;
	}
	doc.close();

	nodeMain.append("],");

	return nodeMain;
}

std::string JsonConverter::linksString()
{
	std::string linksMain = "\"links\":[";
	bool firstLine = true;

	using FilePair = std::pair<std::string, std::vector<std::string>>;

	for (FilePair itemPair : fileDep)
	{

		int fileIndex = fileIndexMap[itemPair.first];

		for (std::string fileD : itemPair.second)
		{
			if (!firstLine) {
				linksMain.append(",");
			}

			int fileDI = fileIndexMap[fileD];

			linksMain.append("{\"source\":");
			linksMain.append(std::to_string(fileIndex));
			linksMain.append(",\"target\":");
			linksMain.append(std::to_string(fileDI));
			linksMain.append(",\"value\": 1}");

			firstLine = false;
		}

	}

	linksMain.append("]");
	return linksMain;
}

std::string JsonConverter::projectNodeString()
{
	std::string projectNodeMain = "\"nodes\":[";
	bool firstLine = true;

	int projIndex = 0;

	for (std::string pname : projectList)
	{
		if (!firstLine) {
			projectNodeMain.append(",");
		}
		projectNodeMain.append("{\"name\":\"");
		projectNodeMain.append(pname);
		projectNodeMain.append("\",\"group\" : ");
		projectNodeMain.append(std::to_string(projIndex));
		projectNodeMain.append("}");

		projIndexMap[pname] = projIndex;
		projIndex++;

		firstLine = false;
	}
	projectNodeMain.append("],");

	return projectNodeMain;
}

std::string JsonConverter::projectLinksString()
{
	std::string projectLinksMain = "\"links\":[";
	bool firstLine = true;

	using ProjPair = std::pair<std::string, std::vector<std::string>>;

	for (ProjPair itemPair : projDep)
	{

		int projIndex = projIndexMap[itemPair.first];

		for (std::string pD : itemPair.second)
		{
			if (pD == itemPair.first) {
				continue;
			}

			if (!firstLine) {
				projectLinksMain.append(",");
			}
			int projDI = projIndexMap[pD];
			projectLinksMain.append("{\"source\":");
			projectLinksMain.append(std::to_string(projIndex));
			projectLinksMain.append(",\"target\":");
			projectLinksMain.append(std::to_string(projDI));
			projectLinksMain.append(",\"value\": 1}");

			firstLine = false;
		}
	}
	projectLinksMain.append("]");
	return projectLinksMain;

}

void JsonConverter::buildFile2ProjectMap()
{
	for (std::string f : fileList)
	{
		std::string pname = delimiterFuncProjectName(f);
		file2ProjectMap[f] = pname;

		//Build project vector also here
		if (std::find(projectList.begin(), projectList.end(), pname) == projectList.end())
		{
			projectList.push_back(pname);
		}
	}

}

std::string JsonConverter::returnFileJson()
{
	return jsonString;
}

std::string JsonConverter::returnProjectJson()
{
	return pjsonString;
}

//----------Delimiter function to get Project name , Delimiter used is "//" -------
std::string JsonConverter::delimiterFuncProjectName(std::string fullPath)
{
	std::string x = FileSystem::Path::getPath(fullPath);
	x.pop_back();

	size_t temp;
	while (true)
	{
		temp = x.find("\\");
		if (temp == std::string::npos)
		{
			break;
		}
		x = x.substr(temp + 1, x.length());
	}
	return x;
}




