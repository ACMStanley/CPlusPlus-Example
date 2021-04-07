#pragma once
#include "Shape.h"

//Author: Aiden Stanley
//Purpose: Header file of the class to represent a square in 2D space

class Square : public Shape {
public:

	Square();										//default contructor initialises a square centered at the origin with side length of 1
	Square(float sideLength);						//constructor that iniitialises a square of a specific side length, centered at the origin
	Square(float sideLength, Vector3D position);	//constructor that iniitialises a square of a specified side length, at a specified position
	Square(Vector3D position);						//constructor that iniitialises a square of side length 1, at a specified position

	float getSideLength() const;							

	bool checkCollision(const Shape* other) const override;			//checks whether the square is colliding with another given shape

private:
	std::ostream& print(std::ostream& out) const override;

	static void validSideLength(float sideLength);					//helper function that throws an error if an invalid side length is given

	float sideLength;
};

