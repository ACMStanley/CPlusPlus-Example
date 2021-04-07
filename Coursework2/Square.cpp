#include "Square.h"
#include <stdexcept>
#include "Collision.h"

//Author: Aiden Stanley
//Purpose: implementation of the class to represent a square in 2D space

Square::Square() : Shape(), sideLength(1) {}														//default contructor initialises a square centered at the origin with side length of 1

Square::Square(float sideLength) : Shape(), sideLength(sideLength) {								//constructor that iniitialises a square of a specific side length, centered at the origin
	validSideLength(sideLength);
}

Square::Square(float sideLength, Vector3D position) : Shape(position), sideLength(sideLength) {		//constructor that iniitialises a square of a specified side length, at a specified position
	validSideLength(sideLength);
}

Square::Square(Vector3D position) : Shape(position), sideLength(1) {}								//constructor that iniitialises a square of side length 1, at a specified position

float Square::getSideLength() const{
	return sideLength;
}

void Square::validSideLength(float sideLength) {													//helper function that throws an error if an invalid side length is given
	if (sideLength <= 0) {
		throw std::runtime_error("Side length must be greater than 0!");
	}
}


bool Square::checkCollision(const Shape* other) const {												//checks whether the square is colliding with another given shape
	return Collision::checkCollision(this,other);
}

std::ostream& Square::print(std::ostream& out) const
{
	out << "Square at pos: " << this->getPos() << " (Side Length: " << this->getSideLength() << ")";
	return out;
}
