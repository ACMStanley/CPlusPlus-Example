#include "Circle.h"
#include <stdexcept>
#include "Collision.h"

//Author: Aiden Stanley
//Purpose: implementation of the class to represent a circle in 2D space

Circle::Circle() : Shape(), radius(0.5) {}												//default contructor initialises a cirlce centred on the origin with radius 0.5 (diameter of 1)

Circle::Circle(float radius) : Shape(), radius(radius) {								//constructor that initialises a circle centred on the origin with a specificed radius
	validRadius(radius);
}

Circle::Circle(Vector3D position) : Shape(position), radius(0.5) {}						//contructor that initialises a cirlce centred on a speicifed position with radius 0.5 (diameter of 1)


Circle::Circle(float radius, Vector3D position) : Shape(position), radius(radius) {		//contructor that initialises a cirlce centred on a speicifed position with a sepcified radius
	validRadius(radius);
}


float Circle::getRadius() const {
	return radius;
}

void Circle::validRadius(float radius) {												//helper function that throws an error if given an invalid radius
	if (radius <= 0) {
		throw std::runtime_error("Radius must be greater than 0!");
	}
}

bool Circle::checkCollision(const Shape* other) const {									//checks if the circle is colliding with a given shape
	return Collision::checkCollision(this,other);
}

std::ostream& Circle::print(std::ostream& out) const									
{
	out << "Circle at pos: " << this->getPos() << " (Radius: " << this->getRadius() << ")";
	return out;
}