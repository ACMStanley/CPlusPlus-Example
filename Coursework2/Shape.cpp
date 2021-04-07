#include "Shape.h"
#include <stdexcept>

//Author: Aiden Stanley
//Purpose: Implementation of the abstract class to represent a shape in 2D space

Shape::Shape() {
	position = Vector3D(0, 0);								//default constructor Instantiates shape at the origin
}

Shape::Shape(Vector3D position) : position(position) {}

void Shape::move(Vector3D displacement) {					//displaces the shape by vector 'displacement'
	position = position + displacement;	
}

void Shape::move(float x, float y) {						//move shape in the x-axis by 'x' and in the y-axis by 'y'
	move(Vector3D(x, y));
}

Vector3D Shape::getPos() const{
	return position;
}

void Shape::setPos(Vector3D position)
{
	this->position = position;
}

std::ostream& Shape::print(std::ostream& out) const{		//helper function to allow virtualisation of ouput overload
	return out;
}

std::ostream& operator<<(std::ostream& out, const Shape& shape)
{
	return shape.print(out);
}
