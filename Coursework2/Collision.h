#pragma once
#include "Shape.h"

//Author: Aiden Stanley
//Purpose: header file for a class to handle collision checking between shapes in various combinations

class Collision {
public:
	static bool checkCollision(const Shape* s1,const Shape* s2);		//checks if two given shapes are colliding
};