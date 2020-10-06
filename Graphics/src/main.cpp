
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include <math.h> 

static int WIDTH = 640;
static int HEIGHT = 480;
double PI = 3.1415;
double trans = 0;
float rotatex = 0, rotatey = 0, mousex = 0, mousey = 0;
bool dragging = false;
int keyArr[350];

float x=100, y=100, dt = 0.1, M = 10000, c = 0.6, g = 0, distance = 100, r = 25, g1;
float px = 400, py = 400, vx = 1.2, vy = 1.3, ax, ay;
float px1 = 400, py1 = 400, vx1 = 1.5, vy1 = 0.3, ax1, ay1;
float  distance1;

static void Resize(GLFWwindow* window, int w, int h) {
	if (h < 1)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w / (float)h, 0.1f, 1000.0f);
	gluLookAt(0.0f, 0.0f, 30, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
}

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	std::cout << "action:" << action << std::endl;
	keyArr[key] = action;
}

static void MouseClickCallback(GLFWwindow* window, int button, int action, int mods) {
	std::cout << "button:" << button << std::endl;
	switch (button) {
	case GLFW_MOUSE_BUTTON_1:
		dragging = action;
		break;
	}
}

static void MouseMotionCallback(GLFWwindow* window, double x, double y) {
	std::cout << "dragging:" << dragging << std::endl;
	if (dragging) {
		mousex += x;
		mousey += y;
	}
}

int main(int argc, char** argv) {
	GLFWwindow* window;

	glfwInit();
	window = glfwCreateWindow(WIDTH, HEIGHT, argv[0], NULL, NULL);
	glfwMakeContextCurrent(window);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	//gluLookAt(0.0f, 0.0f, 30, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

//	glfwSetWindowSizeCallback(window, Resize);
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetMouseButtonCallback(window, MouseClickCallback);
	glfwSetCursorPosCallback(window, MouseMotionCallback);
	while (!glfwWindowShouldClose(window)) {
		float delta = glfwGetTime();

		distance = sqrt((x - px)*(x - px) + (y - py)*(y - py));
		distance1 = sqrt((x - px1)*(x - px1) + (y - py1)*(y - py1));
		g = M / (distance);
		g1 = M / (distance);

		ax = 0;
		ay = 0;

		if (px < 2 * r)
		{
			//ax=c*(2*r-px);
			vx = c * abs(vx);
		}
		else if (px > 500 - 2 * r)
		{
			//ax=c*(( displayWidth-2*r)-px);
			vx = -c * abs(vx);
		}
		if (py < 2 * r)
		{
			//ay=c*(2*r-py);
			vy = c * abs(vy);
		}
		else if (py > 500 - 2 * r)
		{
			//ay=c*((displayHeight-2*r)-py);
			vy = -c * abs(vy);
		}

		ax = ax + g * (x - px) / distance;
		ay = ay + g * (y - py) / distance;

		vx = vx + ax * dt;
		px = px + vx * dt;

		vy = vy + ay * dt;
		py = py + vy * dt;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 1, 1);

		glBegin(GL_LINE_LOOP);
		glVertex2f(x/100, y/100);
		glVertex2f(px/100, py/100);
		glVertex2f(x, y);
		glEnd();
		glFlush();

		glBegin(GL_LINE_LOOP);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.75, 0.0);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.0, 0.75);
		glVertex2f(0.75, 0.0);
		glEnd();
		glFlush();

		std::cout << "x,y :" << x <<","<<y<<"----------";
		std::cout << "px,py :" << px << "," << py << std::endl;

		
		/*if (keyArr[GLFW_KEY_ESCAPE])
			glfwSetWindowShouldClose(window, 1);
		rotatex += keyArr[GLFW_KEY_LEFT] - keyArr[GLFW_KEY_RIGHT];
		rotatey += keyArr[GLFW_KEY_UP] - keyArr[GLFW_KEY_DOWN];

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 1, 1);

		glBegin(GL_LINE_LOOP);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.75, 0.0);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.0, 0.75);
		glVertex2f(0.75, 0.0);
		glEnd();
		glFlush();*/



		glfwSetTime(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	return 0;
}