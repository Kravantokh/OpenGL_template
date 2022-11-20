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

	/* For more explanations about the library API see minimal_traingle.cpp. It has comments explaining every call. */

	float vertices[] = { 0.0,  0.5, 0.0,
					-0.5, -0.5, 0.0,
					 0.5, -0.5, 0.0 };
	VBO vbo(&vertices);	
	VAO vao;
	vao.add_attribute(3);
	vao.bind_attributes();
	
	ShaderProgram prog("./uniform_vertex_shader.glsl", "./uniform_fragment_shader.glsl");

	prog.use();
	/* You may use the registerUniform function to register uniforms by name.
	 * Their IDs are guaranteed to be in the order in which you register them,
	 * beginning from 0.
	 * ATTENTION! The default maximum name length for uniforms is 32 characters.
	 * If you use more the uniform will fail to register unless you define 
	 * BU_GLW_MAX_UNIFORM_NAME_LENGTH to a higher value.
	 * Exceptions are thrown if the unifrom can not be located.*/
	prog.registerUniform("Color"); /* Color will have ID 0.*/
	prog.registerUniform("VerticalOffset"); /* VerticalOffset will have ID 1.*/
	/* We have finised the process of registering uniforms, thus the memory
	 * should shrink to the minimum required. If you wish to register more
	 * uniforms later you can, but remember to call this function again after it
	 * to shrink the memory usage to the minimum required
	 * (if you care about memory).
	 * The return value gives you the ID.*/
	prog.finishUniformRegistration();

	/* The setUniform function has a bunch of overloads, thus it detects
	 * automatically which version should be called based only on the number
	 * and type of arguments at no runtime cost.
	 * It first takes an ID, the one returned by prog.registerUniform,
	 * and then the arguments.
	 * Beware! This has no type checking. If you give it bad arguments it will
	 * call a bad function and OpenGL will refuse to work as it should.
	 * So please respect the types mentioned in the shader with the number
	 * and type of arguments. */
	prog.setUniform(0, 0.1f, 0.1f, 0.1f, 1.0f); /* ID 0 is the Color variable. The f post-fix must also be used, because otherwise the compiler can't deduce which function we wish to call.*/
	prog.setUniform(1, 0.0f); /* ID 1 is VerticalOffset. Same goes for the post-fix.*/
	
	/* For elegance we may also use an enum class (with typecast to int) or
	 * enum (without typecast but with mess in the global namespace - 
	 * not recommended) for these IDs, because we know them at compile time. */
	enum class Uniforms{ Color = 0, Voffset = 1 };

	/* Enable Vsync*/
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window))
	{
		double t = glfwGetTime();
		float color_value = sin(2*t)/2 + 0.5;
		float voffset = sin(0.5*t)/2;
		prog.setUniform((int)Uniforms::Color, color_value, color_value, color_value, 1.0f);
		prog.setUniform((int)Uniforms::Voffset, voffset); 
		
		

		/* Set background color. */
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);

		/* Draw the triangle. */		
		glDrawArrays(GL_TRIANGLES, 0, 3);

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
