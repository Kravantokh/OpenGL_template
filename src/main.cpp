#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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


int main(){
	//Initialization of glfw.
	if (!glfwInit()){
		printf("Error. Could not initialize glfw.");
		return -1;
	}

	//Set an error callback so that GLFW can report any erros it runs into.
	glfwSetErrorCallback(error_callback);

	//Set minimum OpenGL version.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, k_MinMajorOpenGLVersion);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, k_MinMinorOpenGLVersion);

	//Create windows
	GLFWwindow* window = glfwCreateWindow(640, 480, "A window", NULL, NULL);

	//Error-checking
	if (!window)
	{
	    printf("Error. Could not create OpenGL context. Perhaps the minimum requiered version is not supported.");
		return -1;
	}

	//Set the current context to the previously created window.
	glfwMakeContextCurrent(window);
	//Enable keypress handling.
	glfwSetKeyCallback(window, key_callback);

	//Initialize GLEW + some error checking.
	GLenum err = glewInit();
	if(err != GLEW_OK){
		printf("Failed to initialize GLEW");
		return -1;
	}

	//Main loop
	while (!glfwWindowShouldClose(window))
    {
		//Write you openGL code here.
		glfwPollEvents();
    }

	//Terminate glfw before returning.
	glfwTerminate();
}
