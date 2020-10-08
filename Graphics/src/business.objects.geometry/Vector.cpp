#include "Vector.h";


Vector::Vector() 
{
	this->i = 0;
	this->j = 0;
	this->k = 0;
}

Vector::Vector(double i, double j, double k)
{
	this->i = i;
	this->j = j;
	this->k = k;
}
Vector::Vector(Point p1, Point p2)
{
	this->i = p2.x - p1.x;
	this->j = p2.y - p1.y;
	this->k = p2.z - p1.z;
}

void Vector::rotate(double x, double y)
{
}

void Vector::scale(double scale)
{
}

double Vector::magnitude()
{
	return sqrt(this->i * this->i + this->j * this->j + this->k * this->k);
}