#include <stdio.h>
#include "GL/gl3w.h"
#include "GLFW/glfw3.h"
#include "bu_glw.hpp"

/* Forward declaration of error handling functions so as to reduce the visual noise here. See them at the end of this file. */
static void glfw_error_handler(int error, const char* message);
static void glfw_key_handler(GLFWwindow*, int, int, int, int);

int main(void){
	/* Initializing glfw and registering error signaling function. */
	if (!glfwInit()){
		fprintf(stderr, "Failed to initialize glfw!\n");
		exit(1);
	}
	glfwSetErrorCallback(&glfw_error_handler);

	/* Setting OpenGL version window creation and key callback registration. */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	GLFWwindow* window = glfwCreateWindow(640, 480, "Minimal Triangle", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "Failed to create glfw window!\n");
		exit(1);
	}
	glfwSetKeyCallback(window, &glfw_key_handler);
	
	/* Make our window the active OpenGL context. */
	glfwMakeContextCurrent(window);
	

	/* Load OpenGL functions. */
	if(gl3wInit()){
		fprintf(stderr, "Gl3w function loading failed!\n");
	}
	/* Set OpenGL viewport size. */
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	/*End of context creation boilerplate. Finally time for some OpenGL examples with my library. */
	
	/* These are the vertices of the triangle. */
	float vertices[] = { 0.0,  0.5, 0.0,
					-0.5, -0.5, 0.0,
					 0.5, -0.5, 0.0 };
	/* A VBO (vertex buffer object) can be constructed directly from an array of a fixed size and optionally a draw mode.
	 * If no draw mode is specified GL_STATIC_DRAW shall be used.
	 * This is the recommended way to create VBOs of sizes known at compile time.
	 * If you wish to create a vbo (of known length) at runtime you may use an alternative constructor of the
	 * signature VBO(const float* array, GLuint Length, GLenum draw_mode)
	 * The draw mode here also defaults to GL_STATIC_DRAW if unspecified. 
	 * Also, unless you define BU_GLW_CONSTRUCTORS_BIND explicitly to false all the vaos, vbos and ebos will be left\
	 * bound after their construction. */
	VBO vbo(&vertices);	
	/* A VAO (vertex array object) may be constructed as follows:*/
	VAO vao;
	/* Let's create VAO attributes.
	 * If a single number is given it is implicitly float. We have 3 floats representing each vertex,\
	 * so that is the exact layout we want.
	 * It optionally takes:
	 * 	- field type (GLenum),
	 * 	- field size (size_t),
	 * 	- normalization (GLboolean) (whether the data is normalized)
	 * in order to be able to conform to any other requirements. */
	vao.add_attribute(3);
	/* Here some more add_attribute calls could follow if we had more attributes. */

	/* After listing all the attributes we must send them over to the gpu. This will clear them from cpu-side. 
	 * This default behaviour is generally desireable, but if for some specific reason you do not wish to 
	 * discard the attributes from the cpu you may use the bind_attributes_no_discard method.*/
	vao.bind_attributes();
	
	/* Now let's create our shader program. It takes two paths (vertex shader and fragment shader) and
	 * automatically compiles and links them. For a description of how to use uniforms see uniform_api.cpp.
	 * You can also create the two shaders manually and separately and then link them into a ShaderProgram.
	 * There may also be an example for that. */
	ShaderProgram prog("./basic_vertex_shader.glsl", "./basic_fragment_shader.glsl");

	/* Let's use the newly created program. */
	prog.use();
	

	while (!glfwWindowShouldClose(window))
	{
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
