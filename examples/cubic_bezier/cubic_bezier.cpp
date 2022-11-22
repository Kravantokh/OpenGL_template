#include <stdio.h>
#include "GL/gl3w.h"
#include "GLFW/glfw3.h"
#include "bu_glw.hpp"
#include <math.h>

/* For explanations about the glfw API see minimal_triangle.cpp  */
static void glfw_error_handler(int error, const char* message);
static void glfw_key_handler(GLFWwindow*, int, int, int, int);

int main(void){
	if (!glfwInit()){
		fprintf(stderr, "Failed to initialize glfw!\n");
		exit(1);
	}
	glfwSetErrorCallback(&glfw_error_handler);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	GLFWwindow* window = glfwCreateWindow(640, 480, "Minimal Triangle", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "Failed to create glfw window!\n");
		exit(1);
	}
	glfwSetKeyCallback(window, &glfw_key_handler);
	
	glfwMakeContextCurrent(window);
	

	if(gl3wInit()){
		fprintf(stderr, "Gl3w function loading failed!\n");
	}
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	float points[] = {
	 0.0,  0.0,  0.0,
	 0.5,  0.0,  0.0,
	 0.5,  1.0,  0.0,
	 1.0,  1.0,  0.0  };
	VBO vbo(&points);	
	VAO vao;
	vao.add_attribute(3);
	vao.bind_attributes();
	
	ShaderProgram prog("./cubic_bezier_vs.glsl", "./cubic_bezier_gs.glsl", "./cubic_bezier_fs.glsl");

	prog.use();
	
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window))
	{
		/* Set background color. */
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, 4);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return EXIT_SUCCESS;
}


static void glfw_error_handler(int error, const char* message){
	fprintf(stderr, "Glfw error number %d has appeared - %s\n", error, message);
}

static void glfw_key_handler(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}
