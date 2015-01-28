/*
 * MoveableGameObject.cpp
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#include "headers/MoveableGameObject.h"

MoveableGameObject::MoveableGameObject(float x, float y, float width, float height, float speed, float dir_x, float dir_y) : GameObject(x, y, width, height)
{
	this->speed 	= speed;
	this->dir_x		= dir_x;
	this->dir_y 	= dir_y;
}

MoveableGameObject::MoveableGameObject(float width, float height, float speed, float dir_x, float dir_y) : GameObject(width, height)
{
	this->speed 	= speed;
	this->dir_x		= dir_x;
	this->dir_y 	= dir_y;
}

MoveableGameObject::MoveableGameObject(float width, float height) : GameObject(width, height)
{
	this->speed 	= 0;
	this->dir_x		= 0;
	this->dir_y 	= 1.0f;
}

float MoveableGameObject::get_speed()
{
	return speed;
}

float MoveableGameObject::get_dir_x()
{
	return dir_x;
}

float MoveableGameObject::get_dir_y()
{
	return dir_y;
}

void MoveableGameObject::set_speed(float speed)
{
	this->speed = speed;
}

void MoveableGameObject::set_dir_x(float dir_x)
{
	this->dir_x = dir_x;
}

void MoveableGameObject::set_dir_y(float dir_y)
{
	this->dir_y = dir_y;
}
