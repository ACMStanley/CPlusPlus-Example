#pragma once
#include "Shape.h"
#include <iostream>

//Author: Aiden Stanley
//Purpose: Header file of the class to represent a circle in 2D space

class Circle: public Shape {
public:

	Circle();															//default contructor initialises a cirlce centred on the origin with radius 0.5 (diameter of 1)
	Circle(float radius);												//constructor that initialises a circle centred on the origin with a specificed radius
	Circle(Vector3D position);											//contructor that initialises a cirlce centred on a speicifed position with radius 0.5 (diameter of 1)
	Circle(float radius, Vector3D position);							//contructor that initialises a cirlce centred on a speicifed position with a sepcified radius

	float getRadius() const;

	bool checkCollision(const Shape* other) const override;				//checks if the circle is colliding with a given shape

	friend std::ostream& operator<<(std::ostream& out, const Circle& circle);

private:
	std::ostream& print(std::ostream& out) const override;

	static void validRadius(float radius);								//helper function that throws an error if the length of given radius is not valid

	float radius;


	
};


