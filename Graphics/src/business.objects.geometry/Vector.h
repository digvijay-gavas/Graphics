#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

class Vector
{
private:
	
public:
	double i, j, k;

	Vector();
	Vector(double i, double j, double k);

	void rotate(double x, double y);
	void scale(double angle);
	double magnitude();

};