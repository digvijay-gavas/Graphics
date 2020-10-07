#include "Camera.h";


Camera::Camera(GLFWwindow* window): eye(0,0,10),look(0,0,0),up(0,1,0)
{
	this->window = window;

	glfwSetWindowSizeCallback  (window, Camera::resizeCallback);
	glfwSetKeyCallback         (window, Camera::keyCallback);
	glfwSetMouseButtonCallback (window, Camera::mouseClickCallback);
	glfwSetCursorPosCallback   (window, Camera::cursorPosCallback);
}

void Camera::update()
{
	gluLookAt(eye.x, eye.y, eye.z, look.x, look.y, look.z, up.i, up.j, up.k);
}
void Camera::resizeCallback(GLFWwindow* window, int w, int h)
{
	std::cout << "resizeCallback: w" << w << ", h " << h << std::endl;
}
void Camera::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout << "keyCallback: key" << key << ", scancode " << scancode << ", action " << action << ", mods " << mods << std::endl;
}
void Camera::mouseClickCallback(GLFWwindow* window, int button, int action, int mods)
{
	std::cout << "mouseClickCallback: button" << button << ", action " << action << ", mods " << mods << std::endl;
}
void Camera::cursorPosCallback(GLFWwindow* window, double x, double y)
{
	std::cout << "cursorPosCallback: x" << x << ", y " << y << std::endl;
}


void Camera::pan(GLdouble x,GLdouble y)
{
	gluLookAt(0.0f, 0.0f, 10, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void Camera::zoom(GLdouble angle)
{
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

