/*
 * GameObject.cpp
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#include "headers/GameObject.h"

GameObject::GameObject(float x, float y, float width, float height)
{
	this->x 		= x;
	this->y 		= y;

	this->width 	= width;
	this->height 	= height;
}

GameObject::GameObject(float width, float height)
{
	this->x 		= 0;
	this->y 		= 0;

	this->width 	= width;
	this->height 	= height;
}

float GameObject::get_x()
{
	return x;
}

float GameObject::get_y()
{
	return y;
}

float GameObject::get_width()
{
	return width;
}

float GameObject::get_height()
{
	return height;
}


void GameObject::set_x(float x)
{
	this->x = x;
}


void GameObject::set_y(float y)
{
	this->y = y;
}

void GameObject::set_width(float width)
{
	this->width = width;
}

void GameObject::set_height(float height)
{
	this->height = height;
}
