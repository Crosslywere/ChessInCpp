#include "pch.h"
#include <Engine.h>
#include <Timer.h>
#include "Window.h"

void Engine::play() {
	Window window{ this };
	onCreate();
	while (window.isOpen()) {
		Timer::update();
		onUpdate();
		onRender();
	}
	window.cleanup();
}