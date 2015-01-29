/*
 * GameObject.h
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#ifndef HEADERS_GAMEOBJECT_H_
#define HEADERS_GAMEOBJECT_H_

#include <GLES2/gl2.h>

class GameObject
{

protected:
	float 	x;
	float 	y;
	float 	width;
	float 	height;

public:
	GameObject(float x, float y, float width, float height);
	GameObject(float width, float height); 						//x = 0; y = 0;

	virtual ~GameObject();

	float get_x			();
	float get_y			();
	float get_width		();
	float get_height	();

	void set_x			(float x);
	void set_y			(float x);
	void set_width		(float x);
	void set_height		(float x);

	virtual void draw				(GLuint program) = 0;
	virtual void check_collision	(GameObject* game_object) = 0;
};



#endif /* HEADERS_GAMEOBJECT_H_ */
