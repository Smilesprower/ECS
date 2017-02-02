#pragma once
#include "SDL.h"
//
//typedef int* TypeID;
//
//template <class T>
//class Component {
//public:
//	static TypeID type;
//	TypeID getType() const { return T::type; }
//};
//template <typename T> 
//TypeID Component<T>::type((TypeID)&T::type);
//
//class HealthComponent : public Component<HealthComponent> {
//public:
//	HealthComponent()
//		: m_health(100)
//	{
//	};
//	virtual ~HealthComponent() {};
//	void setHalth(int health) { m_health = health; }
//	int getHealth(){ return m_health; };
//private:
//	int m_health;
//};
//




class Component
{
public:
	Component(int id)
		: m_id(id)
	{
	};
	~Component() {};
	int getId() { return m_id; }
private: 
	int m_id;
};

class HealthComponent : public Component
{
public:
	HealthComponent(int id)
		: Component(id)
		, m_health(100){}
	~HealthComponent() {};

	int getHealth() { return m_health; }
	void setHealth(int health) { m_health = health; }

private:
	int m_health;
};

class PositionComponent : public Component
{
public:
	PositionComponent(int id)
		: Component(id)
		, m_position(SDL_Point{ 0,0 }){}
	~PositionComponent() {};
	SDL_Point getPosition() { return m_position; }
	void setPosition(SDL_Point position) { m_position = position; }

private:
	SDL_Point m_position;
};
class ControlComponent : public Component
{
public:
	ControlComponent(int id)
		: Component(id)
		, m_direction(0) {}
	~ControlComponent() {};
	int getPosition() { return m_direction; }
	void setPosition(int direction) { m_direction = direction; }

private:
	int m_direction;
};
