#include "pch.h"
#include <Engine.h>
#include <Timer.h>
#include "Window.h"

void Engine::play() {
	Input input{};
	Window window{ this, &input };
	onCreate();
	while (window.isOpen() && m_Running) {
		onUpdate(input);
		onRender();
		input.update();
		Timer::update();
	}
	window.cleanup();
}