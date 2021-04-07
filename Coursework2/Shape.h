#pragma once
#include "Vector3D.h"
//Author: Aiden Stanley
//Purpose: Header file of the abstract class to represent a shape in 2D space

class Shape {
public:
	Shape();
	Shape(Vector3D position);

	Vector3D getPos() const;													//return the position of the shape
	void setPos(Vector3D position);

	void move(Vector3D displacement);											//displaces the shape by vector 'displacement'
	void move(float posX, float posY);											//displaces the shape by 'x' on the x-axis and 'y' on the y-axis

	virtual bool checkCollision(const Shape* other) const = 0;					//check if shape is colliding with another given shape

	friend std::ostream& operator<<(std::ostream& out, const Shape& shape);

protected:
	virtual std::ostream& print(std::ostream& out) const;						//helper function to allow virtualisation of ouput overload

	Vector3D position;
};

