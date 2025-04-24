#include "pch.h"
#include <glad/glad.h>
#include <Framebuffer.h>

static glm::vec4 s_ClearColor{ 0, 0, 0, 1 };

static void resetClearColor() {
	glClearColor(s_ClearColor.r, s_ClearColor.g, s_ClearColor.b, s_ClearColor.a);
}

void Framebuffer::clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

const glm::vec4& Framebuffer::getClearColor() {
	return s_ClearColor;
}

void Framebuffer::setClearColor(const glm::vec3& color) {
	s_ClearColor = glm::vec4(color, 1);
	resetClearColor();
}

void Framebuffer::setClearColor(float x, float y, float z) {
	s_ClearColor = glm::vec4(x, y, z, 1);
	resetClearColor();
}