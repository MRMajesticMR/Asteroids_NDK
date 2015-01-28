/*
 * MoveableGameObject.h
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#ifndef HEADERS_MOVEABLEGAMEOBJECT_H_
#define HEADERS_MOVEABLEGAMEOBJECT_H_

#include "GameObject.h"

class MoveableGameObject : public GameObject
{
protected:
	float speed;
	float dir_x;
	float dir_y;

public:
	MoveableGameObject(float x, float y, float width, float height, float speed, float dir_x, float dir_y);
	MoveableGameObject(float width, float height, float speed, float dir_x, float dir_y);					//x = 0, y = 0;
	MoveableGameObject(float width, float height);															//x = 0, y = 0, speed = 0, dir_x = 0, dir_y = 0

	float get_speed		();
	float get_dir_x		();
	float get_dir_y		();

	void set_speed		(float speed);
	void set_dir_x		(float dir_x);
	void set_dir_y		(float dir_y);
};



#endif /* HEADERS_MOVEABLEGAMEOBJECT_H_ */
