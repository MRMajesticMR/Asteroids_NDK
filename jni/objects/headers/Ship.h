/*
 * Ship.h
 *
 *  Created on: 28 ���. 2015 �.
 *      Author: azakharov
 */

#ifndef HEADERS_SHIP_H_
#define HEADERS_SHIP_H_

#include "MoveableGameObject.h"

class Ship : public MoveableGameObject
{
private:


public:
	Ship		();
	~Ship		();

	void fire	();

	void draw	();
	void update	();
};


#endif /* HEADERS_SHIP_H_ */
