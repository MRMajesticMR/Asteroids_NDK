/*
 * Bullet.h
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#ifndef OBJECTS_HEADERS_BULLET_H_
#define OBJECTS_HEADERS_BULLET_H_

#include "MoveableGameObject.h"

class Bullet : public MoveableGameObject
{
private:

public:
	Bullet		();
	~Bullet		();

	void update		();
	void draw		();

};



#endif /* OBJECTS_HEADERS_BULLET_H_ */
