/*
 * triangle.cpp
 * Created by Zachary Ferguson
 * Source file for the triangle class, a class for creating and drawing 
 * triangles
 */

/* Include necessary header */
#include "triangle.h"

/* Constructor that takes a list of vectors for the vertices and the color */
triangle::triangle(std::list<vec3>* vertices, float red, float green, float blue) :
	polygon(vertices, red, green, blue)
{
	assert(vertices -> size() == 3);
}

triangle::~triangle()
{
	delete (this -> vertices);
	this->vertices = NULL;
}

/* Draws this polyline */
void triangle::draw(mat3 transformation) const
{
	/* Set the color */
	glColor3f((polyline::color)[0], (this->color)[1], (this->color)[2]);
	/* Draw the vertices */
	glBegin(GL_TRIANGLES);
	for (std::list<vec3>::const_iterator it = (this->vertices)->begin(); it != 
		(this->vertices)->end(); ++it)
	{
		vec3 vertex = transformation * (*it);
		glVertex2f(vertex[0], vertex[1]);
	}
	glEnd();
}

/* Sets the list of vertices to the new one */
void triangle::setVertices(std::list<vec3>* newVertices)
{
	assert(newVertices->size() == 3);
	this->vertices = newVertices;
}
