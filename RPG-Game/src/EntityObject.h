#pragma once
#include "Player.h"
#include "Skeleton.h"
#include "BulletManagment.h"
#include <SFML/Graphics.hpp>

#include <list>

class EntityObject {
public:

	static int playerQuanity;
	static int skeletonQuanity;

	static std::list<Player> player;
	static std::list<Skeleton> skeleton;

	static void addPlayer();
	static void addSkeleton();
	static void updateEnity(float, BulletManagment&, sf::RenderWindow&);
	static void removePlayer();
	static void removeSkeleton();
	static void drawEntity(sf::RenderWindow&);
	static void deleteAllEntity();};

