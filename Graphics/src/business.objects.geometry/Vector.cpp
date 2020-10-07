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