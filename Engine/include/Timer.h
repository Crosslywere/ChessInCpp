#pragma once

class Timer {
	friend class Engine;
public:
	static float getDeltaTime();
	static float getTotalTime();
private:
	static void update();
};
