#include "Circle.h"
#include "Square.h"
#include "Vector3D.h"
#include <iostream>
#include <vector>

//Author: Aiden Stanley
//Purpose: A script that spawns shapes and then moves them randomly until they collide. once they collide they are removed form the game. the game ends when there are 1 or no shapes left

using namespace std;

const int SQUARE_COUNT = 10;							//number of squares to spawn
const int CIRCLE_COUNT = 10;							//number of circles to spawn
const float GRID_LENGTH = 5;							//side lenght of the grid to spawn th shapes on (grid bounds shape centre position)
const float maxComponentMove = 0.5f;					//the maximum distance a shape can move in the x or y axis during a round of movement
const float maxShapeSize = 2;							//the maximum radius of a circle or side length of a square

vector<Shape*> round(vector<Shape*> shapes);			//list to hold the spawned shapes

int main() {
	int listLength = SQUARE_COUNT + CIRCLE_COUNT;
	vector<Shape*> shapes = vector<Shape*>();

	for (int i = 0; i < SQUARE_COUNT; i++) {																																			//spawn the squares
		shapes.push_back(new Square(((float)rand() / RAND_MAX) * maxShapeSize, Vector3D(((float)rand() / RAND_MAX) * GRID_LENGTH, ((float)rand() / RAND_MAX) * GRID_LENGTH)));			//initialised at a random position within the grid with a random side length
	}

	for (int i = SQUARE_COUNT; i < listLength; i++) {																																	//spawn the circles
		shapes.push_back(new Circle(((float)rand() / RAND_MAX) * maxShapeSize, Vector3D(((float)rand() / RAND_MAX) * GRID_LENGTH, ((float)rand() / RAND_MAX) * GRID_LENGTH)));			//initialised at a random position within the grid with a random side length
	}

	while (shapes.size() > 1)							//reapeat until there are no more shapes to collide
	{
		shapes = round(shapes);							//start a new round of movement
	}
}

vector<Shape*> round(vector<Shape*> shapes) {			//given a list of shapes, 'round' moves the shapes randomly, once each, and then removes any shapes form the game that subsequently collide
	for (int i = 0; i < shapes.size(); i++) {
		
		shapes.at(i)->move(Vector3D((rand() / RAND_MAX) * maxComponentMove, (rand() / RAND_MAX) * maxComponentMove));			//move each shape a random distance

		bool edgeFlagX = abs(shapes.at(i)->getPos().getX()) > GRID_LENGTH;														//check if the shape has been moved off the grid in the x-axis
		bool edgeFlagY = abs(shapes.at(i)->getPos().getY()) > GRID_LENGTH;;														//check if the shape has been moved off the grid in the x-axis

		if (edgeFlagX || edgeFlagY) {																							//if the shape has gone off of either axis, return it back to the edge of the axis that it crossed over
			float posX = edgeFlagX ? GRID_LENGTH * signbit(shapes.at(i)->getPos().getX()) : shapes.at(i)->getPos().getX();
			float posY = edgeFlagY ? GRID_LENGTH * signbit(shapes.at(i)->getPos().getY()) : shapes.at(i)->getPos().getY();
			shapes.at(i)->setPos(Vector3D(posX, posY));
		}
	}

	for (int i = 0; i < shapes.size(); i++) {
		for (int j = i + 1; j < shapes.size(); j++) {														//check if any of the remaining shapes have collided

			if (shapes.at(i)->checkCollision(shapes.at(j))) {												
				cout << "{" << *shapes.at(i) << "} collided with {" << *shapes.at(j) << "}\n" << endl;		

				shapes.erase(shapes.begin() + j);															//remove any shapes that have collided
				shapes.erase(shapes.begin() + i);
			}
		}
	}

	return shapes;																							//exit the round by updating the list of remaining shapes
}

