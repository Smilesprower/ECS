// SDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>

#pragma comment(lib,"SDL2.lib") 


#include "Component.h"
#include "Entity.h"
#include "System.h"
#include "Identifiers.h"


int main(int argc, char** argv) 
{
	Entity player(EntityID::Player);
	Entity alien(EntityID::Alien);
	Entity cat(EntityID::Cat);
	Entity dog(EntityID::Dog);

	HealthComponent hc(ComponentID::Health);
	PositionComponent pc(ComponentID::Position);
	ControlComponent cc(ComponentID::Control);

	player.addComponent(hc);
	player.addComponent(pc);
	player.addComponent(cc);
	alien.addComponent(hc);
	alien.addComponent(pc);
	cat.addComponent(hc);
	cat.addComponent(pc);
	dog.addComponent(hc);
	dog.addComponent(pc);

	AISystem as;
	RenderSystem rs;
	ControlSystem cs;

	rs.addEntity(player);
	cs.addEntity(player);

	as.addEntity(alien);
	rs.addEntity(alien);

	as.addEntity(cat);
	rs.addEntity(cat);

	as.addEntity(dog);
	rs.addEntity(dog);

	cs.update();
	as.update();
	rs.update();
	system("pause");
	return 0;
}
