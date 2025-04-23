#include <Engine.h>

class Chess : public Engine {
public:
	Chess() {
		setTitle("Chess In C++");
		setWidth(1280);
		setHeight(720);
	}
	void onCreate() override {
	}
	void onUpdate() override {
	}
	void onRender() override {
	}
};

int main() {
	Chess().play();
}