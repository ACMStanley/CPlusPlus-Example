//Author: Aiden Stanley
//Purpose: A class to represent 3D Vectors and provide basic mathamatical operations on them

#include "Vector3D.h"
#include <math.h>
#include <stdexcept>
#include <iostream>

static const float DELTA = 0.000001;									//tolerance for float equality

Vector3D::Vector3D() {													//default constructor creates origin vector						
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}		//standard 3D Vector constructor

Vector3D::Vector3D(float x, float y) : x(x), y(y) {						//constructor for virtual 2D vectors
	z = 0;
}

float Vector3D::getX() const{
	return x;
}

float Vector3D::getY() const {
	return y;
}

float Vector3D::getZ() const {
	return z;
}

float Vector3D::magnitude() const {
	return sqrt((getX()* getX()) + (getY() * getY()) + (getZ() * getZ()));
}

Vector3D Vector3D::normalised() const {															//returns a unit vector in the same direction as the vector invoked on
	float mag = magnitude();

	//check for divide by 0
	if (mag != 0) {	
		return Vector3D(x / mag, y / mag, z / mag);
	}
	else {
		throw std::runtime_error("Calculating unit vector would use zero divisor (Magnitude is 0)");
	}
}

Vector3D Vector3D::orthonormal(const Vector3D& rhs) const {										//returns a unit vector orthogonal to both the vector invoked on and a given vector
	return (*this % rhs).normalised();
}

Vector3D Vector3D::operator+(const Vector3D& rhs) const {										//vector addition
	return Vector3D(getX() + rhs.getX(), getY() + rhs.getY(), getZ() + rhs.getZ());
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const {										//vector subtraction
	return Vector3D(getX() - rhs.getX(), getY() - rhs.getY(), getZ() - rhs.getZ());
}

Vector3D Vector3D::operator*(const float rhs) const {											//multiplication by a scalar
	return Vector3D(getX() * rhs, getY() * rhs, getZ() * rhs);
}

Vector3D Vector3D::operator/(const float rhs) const {											//division by a scalar
	if (rhs == 0) {
		throw std::runtime_error("Cannot divide a vector by 0 (undefined)");
	}
	return Vector3D(getX() / rhs, getY() / rhs, getZ() / rhs);
}

float Vector3D::operator*(const Vector3D& rhs) const {											//dot product/scalar product
	return (getX() * rhs.getX()) + (getY() * rhs.getY()) + (getZ() * rhs.getZ());
}

Vector3D Vector3D::operator%(const Vector3D& rhs) const {										//vector product/cross product
	return Vector3D(

		(getY() * rhs.getZ()) - (getZ() * rhs.getY()), //x
		(getZ() * rhs.getX()) - (getX() * rhs.getZ()), //y
		(getX() * rhs.getY()) - (getY() * rhs.getX())  //z
		
		);
}

bool Vector3D::operator==(const Vector3D& rhs) const {											//equality operator
	if (this == &rhs) {
		return true;
	}

	return
		vectorFloatIsEqual(x, rhs.getX()) &&
		vectorFloatIsEqual(y, rhs.getY()) &&
		vectorFloatIsEqual(z, rhs.getZ());
}

bool Vector3D::operator!=(const Vector3D& rhs) const {											//inequality operator
	return !(operator==(rhs));
}

Vector3D& Vector3D::operator=(const Vector3D& rhs) {											//assignment operator
	if (this == &rhs) {
		return *this;
	}

	this->x = rhs.getX();
	this->y = rhs.getY();
	this->z = rhs.getZ();

	return *this;
}

bool Vector3D::vectorFloatIsEqual(float a,float b) {
	return fabs(a - b) < DELTA;	//floats are considered equal if their difference is smaller than DELTA
}

//OUTPUT OVERLOAD

std::ostream& operator << (std::ostream& out, const Vector3D& vector) {
	out << '[' << vector.getX() << " , " << vector.getY() << " , " << vector.getZ() << "]";
	return out;
}
