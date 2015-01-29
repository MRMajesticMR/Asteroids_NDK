/*
 * Ship.h
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#ifndef HEADERS_SHIP_H_
#define HEADERS_SHIP_H_

#include <GLES2/gl2.h>

#include "MoveableGameObject.h"

class Ship : public MoveableGameObject
{
private:


public:
	Ship					(float x, float y);
	~Ship					();

	void fire				();

	void draw				(GLuint program);
	void update				();
	void check_collision	(GameObject* game_object);
};


#endif /* HEADERS_SHIP_H_ */
