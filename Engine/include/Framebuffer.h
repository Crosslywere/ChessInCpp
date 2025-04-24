#pragma once

#include <glm/glm.hpp>

class Framebuffer {
public:
	virtual ~Framebuffer() = 0;
	static void clearScreen();
	static const glm::vec4& getClearColor();
	static void setClearColor(const glm::vec3& color);
	static void setClearColor(float x, float y, float z);
};