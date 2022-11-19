#include <stdio.h>
#include <iostream>
#include <GL/gl3w.h>
#include "bu_glw.hpp"
#include <GLFW/glfw3.h>
#include "bu_glw_except.hpp"

const int k_MinMajorOpenGLVersion = 4;
const int k_MinMinorOpenGLVersion = 0;

//Error callback function for GLFW to report errors.
void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

//Keyboard input handling.
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{

	//throw(GLNullPointerReturned() );
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (gl3wInit() )
    {
        std::cout << "Failed to initialize GL3W" << std::endl;
        return -1;
    }

	ShaderProgram prog("./vs.glsl", "./fs.glsl");
	prog.registerUniform("Color");
	prog.registerUniform("Color2");
	prog.registerUniform("Color3");
	prog.registerUniform("Color4");
	prog.registerUniform("Color5");
	prog.finishUniformRegistration();

    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
	
	VAO vao = VAO();

	VBO vbo(&vertices);
	EBO ebo(&indices);
	
	vao.add_attribute(3);
	vao.bind_attributes();
	
	prog.use();
	prog.setUniform(0, 0.20f, 0.20f, 0.20f, 1.0f);
	prog.setUniform(1, 0.20f, 0.20f, 0.20f, 1.0f);
	prog.setUniform(2, 0.20f, 0.20f, 0.20f, 1.0f);
	prog.setUniform(3, 0.20f, 0.20f, 0.20f, 1.0f);
	prog.setUniform(4, 0.20f, 0.20f, 0.20f, 1.0f);

	vao.bind();

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

