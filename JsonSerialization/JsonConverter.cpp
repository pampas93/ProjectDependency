#include "JsonConverter.h"

std::string JsonConverter::jsonMain(MapofDep fileDepMap, MapofDep projDepMap, Files fileListEx)
{
	std::string jsonString;

	fileDep = fileDepMap;
	projDep = projDepMap;
	this->fileList = fileListEx;

	std::string nodes = nodeString();
	jsonString.append("{");
	jsonString.append(nodes);
	std::string links = linksString();
	jsonString.append(links);
	jsonString.append("}");

	return jsonString;
}

std::string JsonConverter::nodeString()
{
	std::string nodeMain = "\"nodes\":[";
	bool firstLine = true;

	int fileIndex = 0;
	for (std::string file : fileList) 
	{
		std::string fileName = FileSystem::Path::getName(file);

		fileIndexMap[fileName] = fileIndex;
		fileIndex++;

		if (!firstLine) {
			nodeMain.append(",");
		}
		nodeMain.append("{\"name\":\"");
		nodeMain.append(fileName);
		nodeMain.append("\",\"group\" : 1}");

		firstLine = false;
	}
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


int JsonConverter::getFileIndex(std::string file)
{
	std::unordered_map<std::string, int>::const_iterator it = fileIndexMap.find(file);

	if (it == fileIndexMap.end())
		return -1;
	else
		return it->second;

}

