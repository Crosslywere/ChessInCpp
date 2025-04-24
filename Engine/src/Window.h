#pragma once

#include <Engine.h>
#include <glfw/glfw3.h>

class Window {
public:
	Window(Engine* engine);
	bool isOpen() const;
	void cleanup();
private:
	GLFWwindow* m_Window;
};