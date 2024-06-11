#include "MapLoader.h"
#include <fstream>
#include <string>

MapLoader::~MapLoader()
{}

void MapLoader::Load(const std::string& filename, MapData& mapData)
{

	std::string line;
	std::ifstream file(filename);
	
	bool isMapValid = false;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (isMapValid)
			{

				int pos = line.find_first_of('=');
				std::string title = line.substr(0, pos);
				std::string value = line.substr(pos + 1, line.size() - pos - 1);

				try
				{
					if (title == "tilesheet") mapData.tilesheet = value;
					else if (title == "name") mapData.name = value;
					else if (title == "version") mapData.version = std::stoi(value);
					else if (title == "map-width") mapData.mapWidth = std::stoi(value);
					else if (title == "map-height") mapData.mapHeight = std::stoi(value);
					else if (title == "tile-width") mapData.tileWidth = std::stoi(value);
					else if (title == "tile-height") mapData.tileHeight = std::stoi(value);
					else if (title == "scale-x") mapData.scaleX = std::stoi(value);
					else if (title == "scale-y") mapData.scaleY = std::stoi(value);
					else if (title == "dataLength") mapData.dataLength = std::stoi(value);
					else if (title == "data")
					{
						mapData.data = new int[mapData.dataLength];
						int ind = 0;
						int begin = 0;
						int end = value.find(", ");
						while (end >= 0)
						{
							mapData.data[ind] = std::stoi(value.substr(begin, end - begin));
							int i = mapData.data[ind];
							begin = end + 2;
							end = value.find(", ", begin);
							ind++;
						}
						mapData.data[ind] = std::stoi(value.substr(begin, end - begin));
						
					}
				}
				catch (const std::exception&)
				{
					std::cout << "Some thing can be loaded from " << filename << std::endl;
				}
			}
			else
			{
				if (line == "[Map]")
				{
					isMapValid = true;
					std::cout << "Map valid\n";
				}
				else
				{
					std::cout << "Map not valid\n";
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "unable to open map file!\n";
	}
	file.close();
}

