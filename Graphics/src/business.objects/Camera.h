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
	float fieldOfview = 125;
	float aspectRatio = 1;
	float height;
	float width;
	void update();

public:
	Camera(float height, float width);
	Camera() {};
	void pan(GLdouble x, GLdouble y);
	void zoom(GLdouble deltaAngle);
	void zoomIn();
	void zoomOut();
	void setAt(GLdouble x, GLdouble y,GLdouble z);
	void setAt(Point eye);

	void lookAt(GLdouble x, GLdouble y,GLdouble z);
	void lookAt(Point look);

};