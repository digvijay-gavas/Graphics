#include "Camera.h";


Camera::Camera(float height, float width) : eye(0, 0, 10), look(0, 0, 0), up(0, 1, 0)
{
	this->height = height;
	this->width = width;
	this->aspectRatio = this->height / this->width;
}

void Camera::update()
{
	this->aspectRatio = this->height / this->width;
	

	glLoadIdentity();
	gluPerspective(this->fieldOfview, this->aspectRatio, 0.1, 1000);
	gluLookAt(eye.x, eye.y, eye.z, look.x, look.y, look.z, up.i, up.j, up.k);
}



void Camera::pan(GLdouble x,GLdouble y)
{
	//gluPerspective(fieldOfview, aspectRatio, -1000, 1000);
	//gluPerspective(25.0f, 1, 0.1f, 1000.0f);
	//gluLookAt(0.0f, 0.0f, 10, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void Camera::zoom(GLdouble deltaAngle)
{
	
	this->fieldOfview += deltaAngle*5;
	if (this->fieldOfview > 180)
		this->fieldOfview = 180;
	else if (this->fieldOfview < 0)
		this->fieldOfview = 0;
	this->update();
	std::cout << "fieldOfview: " << fieldOfview << std::endl;
}
void Camera::zoomIn()
{
	if (this->fieldOfview > 180)
		this->fieldOfview = 180;
	this->fieldOfview += 0.1 ;
	this->update();
	std::cout << "fieldOfview: " << fieldOfview << std::endl;
}

void Camera::zoomOut()
{
	if (this->fieldOfview < 0)
		this->fieldOfview = 0;
	this->fieldOfview -= 0.1;
	this->update();
	std::cout << "fieldOfview: " << fieldOfview << std::endl;
}

void Camera::setAt(GLdouble x, GLdouble y, GLdouble z)
{
}

void Camera::setAt(Point eye)
{
	this->eye = eye;
	this->update();
}

void Camera::lookAt(GLdouble x, GLdouble y, GLdouble z)
{
}

void Camera::lookAt(Point look)
{
	this->look = look;
	this->update();
}

