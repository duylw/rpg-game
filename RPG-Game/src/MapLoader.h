#pragma once
#include <iostream>

#include "MapData.h"

class MapLoader
{
public:
public:
	void Load(const std::string& filename, MapData&);
	~MapLoader();
};

