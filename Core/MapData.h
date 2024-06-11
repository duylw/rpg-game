#pragma once
#include <string>
#include "SFML/Graphics.hpp"

struct MapData {
    const int version{ 1 };

    std::string tilesheet = "D:/GameVersion/rpg-game/RPG-Game/Assets/World/prison/tilesheet.png";
    std::string name = "";

    int tileWidth{};
    int tileHeight{};

    int mapWidth{};
    int mapHeight{};

    int scaleX{};
    int scaleY{};

    int dataLength{};
    const int* data = NULL;;

    MapData(
        const std::string& ini_name, const sf::Vector2f& ini_tileSize, const sf::Vector2i& ini_mapSize,
        const sf::Vector2f& ini_scale,int ini_dataLength,const int* ini_data)
    {
        name = ini_name;

        tileWidth = ini_tileSize.x;
        tileHeight = ini_tileSize.y;

        mapWidth = ini_mapSize.x;
        mapHeight = ini_mapSize.y;
    
        scaleX = ini_scale.x;
        scaleY = ini_scale.y;
        
        dataLength = ini_dataLength;
        data = ini_data;
    }

    inline const int getVersion() const { return version; }
    inline const std::string getTileSheet() const { return tilesheet; }
    inline const std::string getName() const { return name; }
    inline const int getTileWidth() const { return tileWidth; }
    inline const int getTileHeight() const { return tileHeight; }
    inline const int getMapWidth() const { return mapWidth; }
    inline const int getMapHeight() const { return mapHeight; }
    inline const int getScaleX() const { return scaleX; }
    inline const int getScaleY() const { return scaleY; }
    inline const int getDataLength() const { return dataLength; }
    inline const int* getMapArray() const { return data; }
};
