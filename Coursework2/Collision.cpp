#include "Collision.h"
#include "Square.h"
#include "Circle.h"

//Author: Aiden Stanley
//Purpose: implementation of a class to handle collision checking between shapes in various combinations

void shapeTypeNotResolved() {																							//helper function to be called when an error needs to be thrown in regards to not being 
	throw std::runtime_error("Something went wrong when trying to cast shape: 'other', during collison detection.");	//able to resolve which derivation of 'Shape' a shape is
}

bool checkCollisionOnShape(const Square* s1, const Square* s2) {			//overrride of 'checkCollisionOnShape' for the collison of two squares

	/*#####################
	The position of squares and circles is measured from the centre
	#####################*/

	float s1X = s1->getPos().getX();										//get coordinates of first square
	float s1Y = s1->getPos().getY();
	float s1Length = s1->getSideLength();									//get sidelength of first square
	float s1Offset = s1Length/2;											//get distance from the centre of the square to any of its edges

	float s2X = s2->getPos().getX();										//get coordinates of second square
	float s2Y = s2->getPos().getY();
	float s2Length = s2->getSideLength();									//get sidelength of second square
	float s2Offset = s2Length / 2;											//get distance from the centre of the square to any of its edges

	bool colliding = true;													//start by assuming the squares are colliding; if any of the following statements are false, the saures are not colliding


																			//IF
	colliding &= s1X - s1Offset <= s2X + s2Offset;							//the left side of s1 is further left than the right side of s2
	colliding &= s1X + s1Offset >= s2X - s2Offset;							//AND the right side of s1 is further right than the left side of s2
	colliding &= s1Y - s1Offset <= s2Y + s2Offset;							//AND the bottom side of s1 is further down than the top side of s2
	colliding &= s1Y + s1Offset >= s2Y - s2Offset;							//AND the top side of s1 is further up thn the bottom side of s2
																			//THEN the shapes are colliding
	return colliding;						
}

bool checkCollisionOnShape(const Circle* s1, const Circle* s2) {			//overrride of 'checkCollisionOnShape' for the collison of two circles
	float distance = (s1->getPos() - s2->getPos()).magnitude();				//get the distance between the two circles
	return distance <= (s1->getRadius() + s2->getRadius());					//if the distance between the two circles is less than the sum of their radii then they are colliding
}

bool checkCollisionOnShape(const Square* squ, const Circle* circ) {			//overrride of 'checkCollisionOnShape' for the collison of a square and a circle
	float circPosX = circ->getPos().getX();									//get the coordinates of the circle
	float circPosY = circ->getPos().getY();

	float squPosX = squ->getPos().getX();									//get the coordinates of the square
	float squPosY = squ->getPos().getY();
	float squOffset = squ->getSideLength() / 2;								//get the distance from the centre of the square to any of its edges

	float testPosX = circPosX;												//initialise the point to test for collision at the position of the circles
	float testPosY = circPosY;

	if (circPosX < squPosX - squOffset) {									//if the circle is to the left of the square then test from the left edge of the square
		testPosX = squPosX - squOffset;
	}

	if (circPosX > squPosX + squOffset) {									//if the circle is to the right of the square then test from the right edge of the square
		testPosX = squPosX + squOffset;
	}

	if (circPosY < squPosY - squOffset) {									//if the circle is above the square then test form the top edge of the square
		testPosY = squPosY - squOffset;
	}
	
	if (circPosY > squPosY + squOffset) {									//if the circle is below the square test from the bottom edge of the square
		testPosY = squPosY + squOffset;
	}

	Vector3D testPos = Vector3D(testPosX, testPosY);						

	float distance = (circ->getPos() - testPos).magnitude();				//get the diatnce between the circle at the point to be tested

	return distance <= circ->getRadius();									//if the point to be tested is within the radius if the circle then the circle and the square are colliding
}

bool checkCollisionOnShape(const Circle* s1, const Square* s2) {			//overrride of 'checkCollisionOnShape' for the collison of a square and a circle. (Swaps around and recalls the function to avoid code duplication)
	return checkCollisionOnShape(s2, s1);
}

bool Collision::checkCollision(const Shape* s1, const Shape* s2){			//deciphers which derivation of shape the given shapes are, and calls the respective overload to cehck whether two shapes are colliding
	if (typeid(*s1) == typeid(Square)) {
		if (typeid(*s2) == typeid(Square)) {
			return checkCollisionOnShape((Square*)s1, (Square*)s2);
		}
		else if (typeid(*s2) == typeid(Circle)) {
			return checkCollisionOnShape((Square*)s1, (Circle*)s2);
		}
		else {
			shapeTypeNotResolved();
		} 
	}
	else if (typeid(*s1) == typeid(Circle)) {
		if (typeid(*s2) == typeid(Circle)) {
			return checkCollisionOnShape((Circle*)s1, (Circle*)s2);
		}
		else if (typeid(*s2) == typeid(Square)) {
			return checkCollisionOnShape((Circle*)s1, (Square*)s2);
		}
		else {
			shapeTypeNotResolved();
		}
	}
	else {
		shapeTypeNotResolved();
	}
}