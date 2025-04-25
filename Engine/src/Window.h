#pragma once

#include <Engine.h>
#include <Input.h>
#include <glfw/glfw3.h>

class Window {
public:
	Window(Engine* engine, Input* input);
	bool isOpen() const;
	void cleanup();
private:
	GLFWwindow* m_Window;
};