//Author: Aiden Stanley
//Purpose: Header file for a class to represent 3D Vectors and provide basica mathamatical operations on them

#pragma once
#include <iostream>

class Vector3D {
public:
	//CONSTRUCTORS

	Vector3D();									//default constructor creates origin vector
	Vector3D(float x, float y);					//constructor for virtual 2D vectors
	Vector3D(float x, float y, float z);		//standard 3D Vector constructor


	//MEMBER FUNCTIONS

	float getX() const;
	float getY() const;
	float getZ() const;

	float magnitude() const;					

	Vector3D normalised() const;						//returns a unit vector in the same direction as the vector invoked on

	Vector3D orthonormal(const Vector3D& rhs) const;	//returns a unit vector orthogonal to both the vector invoked on and a given vector

	static bool vectorFloatIsEqual(float a, float b);   //equality for floats used in the context of Vector3D class


	//OPERATOR OVERLOADS 

	Vector3D operator+(const Vector3D& rhs) const;		//vector addition
	Vector3D operator-(const Vector3D& rhs) const;		//vector subtraction

	Vector3D operator*(const float rhs) const;			//multiplication by a scalar
	Vector3D operator/(const float rhs) const;			//division by a scalar

	float operator*(const Vector3D& rhs) const;			//dot product/scalar product
	Vector3D operator%(const Vector3D& rhs) const;		//vector product/cross product

	bool operator==(const Vector3D& rhs) const;			//equality operator
	bool operator!=(const Vector3D& rhs) const;			//inequality operator

	Vector3D& operator=(const Vector3D& rhs);			//assignment operator

	

private:
	float x;
	float y;
	float z;
};


//OUTPUT OVERLOAD

std::ostream& operator<<(std::ostream& out, const Vector3D& vector);