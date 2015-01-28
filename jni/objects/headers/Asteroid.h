/*
 * Asteroid.h
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#ifndef OBJECTS_HEADERS_ASTEROID_H_
#define OBJECTS_HEADERS_ASTEROID_H_

#include "MoveableGameObject.h"

class Asteroid : public MoveableGameObject
{
private:
	float 	radius;
	char	big;

public:
	Asteroid	(float x, float y, float radius, char big);
	~Asteroid	();

	void draw	();
	void update	();
	char is_big	();
};



#endif /* OBJECTS_HEADERS_ASTEROID_H_ */
