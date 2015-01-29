/*
 * Ship.cpp
 *
 *  Created on: 28 џэт. 2015 у.
 *      Author: azakharov
 */

#include "headers/Ship.h"

GLfloat triangle_vertices[6];
GLfloat rotate_matrix[9];

Ship::Ship(float x, float y) : MoveableGameObject(x, y, 0.5f, 0.5f, 3, 0, -1)
{
	triangle_vertices[0] = x; 						triangle_vertices[1] = y + (get_height() / 2);
	triangle_vertices[2] = x + (get_width() / 2); 	triangle_vertices[3] = y - (get_height() / 2);
	triangle_vertices[4] = x - (get_width() / 2);	triangle_vertices[5] = y - (get_height() / 2);

	rotate_matrix[0] = 1.0f; rotate_matrix[1] = 0.0f; rotate_matrix[2] = 0.0f;
	rotate_matrix[3] = 0.0f; rotate_matrix[4] = 1.0f; rotate_matrix[5] = 0.0f;
	rotate_matrix[6] = 0.0f; rotate_matrix[7] = 0.0f; rotate_matrix[8] = 1.0f;
}

Ship::~Ship()
{

}

void Ship::fire()
{

}

void Ship::draw(GLuint program)
{
	GLuint position_handle 	= glGetAttribLocation(program, "vPosition");

	glVertexAttribPointer(position_handle, 2, GL_FLOAT, GL_FALSE, 0, triangle_vertices);
	glEnableVertexAttribArray(position_handle);
	glDrawArrays(GL_LINE_LOOP, 0, 3);

}

void Ship::update()
{

}

void Ship::check_collision(GameObject* game_object)
{

}
