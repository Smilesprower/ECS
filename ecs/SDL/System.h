#pragma once
#include "Entity.h"
#include "Identifiers.h"
#include "Component.h"
#include <iostream>


//Phil's EC pattern lab needs following:
//Components: Health, position, control
//	Entities :
//Player - health, position, control components
//Alien - health, position
//Cat - health, position
//Dog - health, position
//Systems :
//Control system - Deals with position & control components
//Render system - position
//AI system - health, position


class AISystem
{
public:
	AISystem() {}
	~AISystem() {}

	void addEntity(Entity e) { m_entities.emplace_back(new Entity(e)); };
	void removeEntity(Entity e) { }
	void update()
	{
		std::cout << "---------------------\n" << std::endl;
		std::cout << "   AISystem Update   \n" << std::endl;
		std::cout << "---------------------\n";
		for (size_t i = 0; i < m_entities.size(); i++)
		{
			std::string name = m_entities[i]->getID();

			HealthComponent* hc = static_cast<HealthComponent*>(m_entities.at(i)->getComponent(ComponentID::Health));
			if (hc != NULL){
				std::cout << name.c_str() << ": Updating Health" << std::endl;
			}
			PositionComponent* pc = static_cast<PositionComponent*>(m_entities.at(i)->getComponent(ComponentID::Position));
			if (pc != NULL) {
				std::cout << name.c_str() << ": Updating Position" << std::endl;
			}
		}
	}
private:
	std::vector<Entity*> m_entities;
};

class RenderSystem
{
public:
	RenderSystem() {}

	~RenderSystem() {}

	void addEntity(Entity e) { m_entities.emplace_back(new Entity(e)); };
	void removeEntity(Entity e) { }
	void update()
	{
		std::cout << "---------------------\n" << std::endl;
		std::cout << " RenderSystem Update \n" << std::endl;
		std::cout << "---------------------\n";
		for (size_t i = 0; i < m_entities.size(); i++)
		{
			std::string name = m_entities[i]->getID();
			PositionComponent* pc = static_cast<PositionComponent*>(m_entities.at(i)->getComponent(ComponentID::Position));
			if (pc != NULL) {
				std::cout << name.c_str() << ": Rendering " << std::endl;
			}
		}
	}
private:
	std::vector<Entity*> m_entities;
};
class ControlSystem
{
public:
	ControlSystem() {}
	~ControlSystem() {}

	void addEntity(Entity e) { m_entities.emplace_back(new Entity(e)); };
	void removeEntity(Entity e) { }
	void update()
	{
		std::cout << "----------------------\n" << std::endl;
		std::cout << " ControlSystem Update \n" << std::endl;
		std::cout << "----------------------\n";
		for (size_t i = 0; i < m_entities.size(); i++)
		{
			std::string name = m_entities[i]->getID();
			ControlComponent* cc = static_cast<ControlComponent*>(m_entities.at(i)->getComponent(ComponentID::Health));
			if (cc != NULL) {
				std::cout << name.c_str() << ": Updating Input" << std::endl;
			}
			PositionComponent* pc = static_cast<PositionComponent*>(m_entities.at(i)->getComponent(ComponentID::Position));
			if (pc != NULL) {
				std::cout << name.c_str() << ": Updating Position" << std::endl;
			}
		}
	}
private:
	std::vector<Entity*> m_entities;
};
