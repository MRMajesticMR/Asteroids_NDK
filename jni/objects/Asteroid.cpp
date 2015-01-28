/*
 * Asteroid.cpp
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#include "headers/Asteroid.h"

Asteroid::Asteroid(float x, float y, float radius, char big) : MoveableGameObject(x, y, radius * 2, radius * 2, 3, 0, 1)
{
	this->radius 	= radius;
	this->big		= big;
}

Asteroid::~Asteroid()
{

}

void Asteroid::draw()
{

}

void Asteroid::update()
{

}

char Asteroid::is_big()
{
	return big;
}



