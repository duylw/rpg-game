#include "MapSaver.h"
#include <fstream>
#include <iostream>


void MapSaver::Save(const std::string& filename, const MapData& mapData)
{
	std::ofstream file;
	file.open(filename);
	if (file.is_open())
	{	
		file << "[Map]" << std::endl;
		file << "version=" << mapData.getVersion() << std::endl;
		file << "tilesheet=" << mapData.getTileSheet() << std::endl;
		file << "name=" << mapData.getName() << std::endl;
		file << "map-width=" << mapData.getMapWidth() << std::endl;
		file << "map-height=" << mapData.getMapHeight() << std::endl;
		file << "tile-width=" << mapData.getTileWidth() << std::endl;
		file << "tile-height=" << mapData.getTileHeight() << std::endl;
		file << "scale-x=" << mapData.getScaleX() << std::endl;
		file << "scale-y=" << mapData.getScaleY() << std::endl;
		file << "dataLength=" << mapData.getDataLength() << std::endl;

		const int* data = mapData.getMapArray();
		file << "data=";
		int i = 0;
		for (i; i < mapData.getDataLength() - 1; i++)
		{
			file << data[i] << ", ";
		}
		if(i < mapData.getDataLength()) file << data[i];


	}
	else
	{

	}
	file.close();

}
