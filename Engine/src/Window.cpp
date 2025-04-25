#include "pch.h"
#include <glad/glad.h>
#include "Window.h"

static Engine* s_Engine = nullptr;
static Input* s_Input = nullptr;

Window::Window(Engine* engine, Input* input) {
	if (!glfwInit()) {
		std::cerr << "Failed to initalize glfw\n";
		std::exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!engine->isResizable())
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_Window = glfwCreateWindow(engine->getWidth(), engine->getHeight(), engine->getTitle().c_str(), nullptr, nullptr);
	if (!m_Window) {
		std::cerr << "Failed to create window\n";
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(1);
	if (!gladLoadGL()) {
		std::cerr << "Failed to load OpenGL\n";
		cleanup();
		std::exit(EXIT_FAILURE);
	}
	if (engine->m_MinWidth > 0 || engine->m_MinHeight > 0);
	glfwSetWindowSizeLimits(m_Window, engine->m_MinWidth, engine->m_MinHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBlendEquation(GL_FUNC_ADD);
	s_Engine = engine;
	s_Input = input;
	glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
		s_Engine->setWidth(width);
		s_Engine->setHeight(height);
		s_Engine->onResize();
		glViewport(0, 0, width, height);
		});
	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
		s_Input->setButtonPressed(button, action >= GLFW_PRESS);
		});
	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
		s_Input->setMousePos(xpos, ypos);
	});
	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		s_Input->setKeyPressed(key, action >= GLFW_PRESS);
	});
	glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
		s_Input->setScrollAmount(yoffset);
	});
}

bool Window::isOpen() const {
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
	return !glfwWindowShouldClose(m_Window);
}

void Window::cleanup() {
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}