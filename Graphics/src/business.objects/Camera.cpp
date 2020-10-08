#include "Camera.h";


Camera::Camera(float width, float height) : eye(0, 0, 10), look(0, 0, 0), up(0, 1, 0)
{
	this->height = height;
	this->width = width;
	this->aspectRatio = this->width  / this->height;
}

void Camera::update()
{
	this->aspectRatio = this->width / this->height;
	glLoadIdentity();
	gluPerspective(this->fieldOfview, this->aspectRatio, 0, 1000);
	gluLookAt(eye.x, eye.y, eye.z, look.x, look.y, look.z, up.i, up.j, up.k);
}

void Camera::resize(float width, float height)
{
	this->height = height;
	this->width = width;
	glViewport(0, 0, this->width,this->height);
	this->update();
}

void Camera::pan(GLdouble x,GLdouble y)
{
	eye.x += x / 10;
	eye.y += y / 10;
	look.x += x / 10;
	look.y += y / 10;
	this->update();
}

void Camera::rotate(GLdouble x, GLdouble y)
{
	x /= 10;
	eye.z -= x * sin(x/(eye.z-look.z));
	eye.x += x;

	y /= 10;
	eye.z -= y * sin(y / (eye.z - look.z));
	eye.y += y;
	this->update();

	Vector cameraVector = Vector(eye, look);
	std::cout << "cameraVector:" << cameraVector.magnitude() << std::endl;
}

void Camera::zoom(GLdouble deltaAngle)
{
	
	this->fieldOfview += deltaAngle*5;
	if (this->fieldOfview > 180)
		this->fieldOfview = 180;
	else if (this->fieldOfview < 0)
		this->fieldOfview = 0;
	//eye.z += deltaAngle;
	//look.z += deltaAngle;
	this->update();
	//std::cout << "fieldOfview: " << fieldOfview << std::endl;
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

