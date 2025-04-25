#include <Engine.h>
#include <Framebuffer.h>
#include <Timer.h>

class Chess : public Engine {
public:
	Chess() {
		setTitle("Chess In C++");
		setWidth(1280);
		setHeight(720);
		setMinWidth(800);
		setMinHeight(600);
	}
	void onCreate() override {
	}
	void onUpdate(const Input& input) override {
		Framebuffer::setClearColor(abs(sinf(Timer::getTotalTime())), abs(sinf(Timer::getTotalTime() + 0.5f)), 0);
		if (input.isKeyJustPressed(Key::ESC))
			forceClose();
	}
	void onRender() override {
		Framebuffer::clearScreen();
	}
	void onResize() override {
	}
	void onExit() override {
	}
};

#if defined (DEBUG) || !defined (PLATFORM_WINDOWS) // None windows systems and windows debug
int main() {
	Chess().play();
}
#else // Windows release
#include <windows.h>
int WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmd, int showCmd) {
	Chess().play();
}
#endif