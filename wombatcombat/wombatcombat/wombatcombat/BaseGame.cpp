//
//  GameLoop.cpp
//  movement_cpp
//
//  Created by Simon Jentsch on 05.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "BaseGame.h"
#include <iostream>

BaseGame::BaseGame(GameContainer* gc)
{
	this->gc = gc;

	float windowRatio = (float)gc->getWindow()->getSize().y / (float)gc->getWindow()->getSize().x;
	this->player = new Player(gc, 60, 10, 0.4f, 1.8f);
	this->camera = new Camera(gc, this->player, sf::Vector2f(4, -3), sf::Vector2f(30, 30*windowRatio));

	this->terrain = new Terrain(gc, 7, 0, 0);
		this->terrain->addPoint(0, 40, 50);
		this->terrain->addPoint(1, 50, 0);
		this->terrain->addPoint(2, 90, 5);
		this->terrain->addPoint(3, 110, 10);
		this->terrain->addPoint(4, 120, 50);
		this->terrain->addPoint(5, 200, 45);
		this->terrain->addPoint(6, 250, 55);

  	this->rock1 = new DynBox(gc, 4, 62,20);
  		this->rock1->addPoint(0,3,-1);
  		this->rock1->addPoint(1,0,0);
  		this->rock1->addPoint(2,0,-6);
  		this->rock1->addPoint(3,4,-6);

  	this->rock2 = new DynBox(gc, 3, 55, 40);
  		this->rock2->addPoint(0,0,0);
  		this->rock2->addPoint(1,-2,-3);
  		this->rock2->addPoint(2,2,-3);


  	this->terrain->generate();
  	this->rock1->generate();
  	this->rock2->generate();
}

// Update everything
void BaseGame::update()
{

  this->player->update(gc);
  this->rock1->update(gc);
  this->rock2->update(gc);
  this->camera->update();

}

// Render everything
void BaseGame::render()
{

  /*
  for(int i = 0 ; i < this->platforms.size() ; i++)
    this->platforms.at(i)->render(this->gc->getWindow());
  */
  this->player->render(this->gc);
  this->rock1->render(this->gc);
  this->rock2->render(this->gc);
  this->terrain->render(this->gc);
}
