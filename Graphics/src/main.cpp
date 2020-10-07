
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include <math.h> 
#include "business.objects/Camera.h"
#include "business.objects.geometry/Point.h"

static int WIDTH = 1024;
static int HEIGHT = 768;
double PI = 3.1415;
double trans = 0;
float rotatex = 0, rotatey = 0, mouseX = 0, mouseY = 0;
bool dragging = false, panning = false;
float dragX = 0;
float dragY = 0;
int keyArr[350];

float x = 100, y = 100, dt = 0.001, M = 10000, c = 0.6, g = 0, distance = 100, r = 25, g1;
float px = 400, py = 400, vx = 1.2, vy = 1.3, ax, ay;
float px1 = 400, py1 = 400, vx1 = 1.5, vy1 = 0.3, ax1, ay1;
float  distance1;


int main(int argc, char** argv) {
	GLFWwindow* window;

	glfwInit();
	window = glfwCreateWindow(WIDTH, HEIGHT, argv[0], NULL, NULL);
	glfwMakeContextCurrent(window);

	Camera camera = Camera(window,HEIGHT,WIDTH);
	camera.setAt(Point(0, 0, 10));
	camera.lookAt(Point(20, 0, 0));
	camera.zoom(45);

	glClearColor(0.0, 0.0, 0.2, 1.0);

	while (!glfwWindowShouldClose(window))
	{
		glColor3f(1.0, 0.0, 0.0); // red x
		glBegin(GL_LINES);
		// x aix

		glVertex3f(-40.0, 0.0f, 0.0f);
		glVertex3f(40.0, 0.0f, 0.0f);

		// arrow
		glVertex3f(40.0, 0.0f, 0.0f);
		glVertex3f(30.0, 10.0f, 0.0f);

		glVertex3f(40.0, 0.0f, 0.0f);
		glVertex3f(30.0, -10.0f, 0.0f);
		glEnd();
		glFlush();

		glfwSetTime(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	return 0;
}