#include "pch.h"
#include <Timer.h>
#include <glfw/glfw3.h>

static float s_TotalTime{};
static float s_DeltaTime{};

void Timer::update() {
	float now = static_cast<float>(glfwGetTime());
	s_DeltaTime = now - s_TotalTime;
	s_TotalTime = now;
}

float Timer::getDeltaTime() {
	return s_DeltaTime;
}

float Timer::getTotalTime() {
	return s_TotalTime;
}