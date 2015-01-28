/*
 * GameObject.h
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#ifndef HEADERS_GAMEOBJECT_H_
#define HEADERS_GAMEOBJECT_H_

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

	virtual ~GameObject() = 0;

	float get_x			();
	float get_y			();
	float get_width		();
	float get_height	();

	void set_x			(float x);
	void set_y			(float x);
	void set_width		(float x);
	void set_height		(float x);

	virtual void draw() = 0;
};



#endif /* HEADERS_GAMEOBJECT_H_ */
