#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <business.objects.geometry/Point.h>
#include <business.objects.geometry/Vector.h>

class Camera
{
private:
	Point eye, look;
	Vector up;
	float fieldOfview = 45;
	float aspectRatio = 1;
	float height;
	float width;
	void update();

public:
	Camera(float width, float height);
	Camera() {};
	void resize(float width, float height);
	void pan(GLdouble x, GLdouble y);
	void rotate(GLdouble x, GLdouble y);
	void zoom(GLdouble deltaAngle);
	void setAt(GLdouble x, GLdouble y,GLdouble z);
	void setAt(Point eye);

	void lookAt(GLdouble x, GLdouble y,GLdouble z);
	void lookAt(Point look);

};