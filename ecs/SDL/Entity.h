#pragma once
#include <vector>
#include "Component.h"
#include "Identifiers.h"


class Entity
{
public:
	Entity(int id)
		: m_id(id)
	{
	}
	~Entity() {};
	std::string getID() 
	{
		if (m_id == EntityID::Alien)
			return std::string("Alien");
		else if (m_id == EntityID::Cat)
			return std::string("Cat");
		else if (m_id == EntityID::Dog)
			return std::string("Dog");
		else if (m_id == EntityID::Player)
			return std::string("Player");
		return "";
	}
	void addComponent(Component c) { m_components.emplace_back(new Component(c)); }
	void removeComponent(Component c) { }
	Component* getComponent(int id) 
	{ 
		for (int i = 0; i < m_components.size(); i++)
		{
			if (id == m_components[i]->getId())
			{
				return m_components[i];
			}
		}
		return NULL; 
	}
	int m_id;
private:
	std::vector<Component*> m_components;
};

