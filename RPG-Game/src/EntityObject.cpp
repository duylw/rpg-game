#include "EntityObject.h"

int EntityObject::playerQuanity = 0;
int EntityObject::skeletonQuanity = 0;
std::list<Player> EntityObject::player;
std::list<Skeleton> EntityObject::skeleton;

void EntityObject::addPlayer()
{

	player.push_back(Player());
	(player.back()).Initialize();
	(player.back()).Load();
	playerQuanity++;
}

void EntityObject::addSkeleton()
{
	skeleton.emplace_back();
	(skeleton.back()).Initialize();
	(skeleton.back()).Load();
	skeletonQuanity++;
}

void EntityObject::removePlayer()
{
}



void EntityObject::removeSkeleton()
{
}


void EntityObject::drawEntity(sf::RenderWindow &window)
{
	for (auto& i : player)
	{
		i.Draw(window);
	}
	for (auto& i : skeleton)
	{
		i.Draw(window);
	}
}

void EntityObject::deleteAllEntity()
{
	for (auto i = player.begin(); i != player.end(); )
	{
		i = player.erase(i);
	}
	for (auto i = skeleton.begin(); i != skeleton.end();)
	{
		i = skeleton.erase(i);
	}

}

void EntityObject::updateEnity(float deltaTime, BulletManagment& BulletManage, sf::RenderWindow&window)
{
	for (auto i = player.begin(); i != player.end(); i++)
	{
		i->Update(deltaTime, BulletManage, window);
	}
	for (auto i = skeleton.begin(); i != skeleton.end();)
	{
		if (i->isDead())
		{
			i = skeleton.erase(i);
		}
		else
		{
			i->Update(deltaTime);
			++i;
		}
	}
}

