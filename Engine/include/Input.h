#pragma once

#include <set>
#include <glm/glm.hpp>

enum class MouseButton {
	LEFT = 0,
	RIGHT,
	MIDDLE,
	FORWARD,
	BACKWARD
};

enum class Key {
	_0 = '0', _1, _2, _3, _4, _5, _6, _7, _8, _9,
	A = 'A', B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	SPACE = ' ',
	MINUS = '-',
	EQUAL = '=',
	SLASH = '/',
	BACKSLASH = '\\',
	SEMI_COLON = ';',
	APOSTROPHY = '\'',
	GRAVE = '`',
	PERIOD = '.',
	COMMA = ',',
	LEFT_SQR_BRACKET = '[',
	RIGHT_SQR_BRACKET = ']',
	F1 = 290, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
	ESC = 256,
	ENTER = 257,
	TAB = 258,
	BACKSPACE = 259,
	INSERT = 260,
	DELETE = 261,
	RIGHT_ARROW = 262,
	LEFT_ARROW = 263,
	DOWN_ARROW = 264,
	UP_ARROW = 265,
	PAGE_UP = 266,
	PAGE_DOWN = 267,
	HOME = 268,
	END = 269,
	CAPSLOCK = 280,
	SCROLL_LOCK = 281,
	PRINT_SCR = 283,
	PAUSE = 284,
	LEFT_SHIFT = 340,
	LEFT_CTRL = 341,
	LEFT_ALT = 342,
	RIGHT_SHIFT = 344,
	RIGHT_CTRL = 345,
	RIGHT_ALT = 346,
	MENU = 348,
};

class Input {
public:
	bool isButtonJustPressed(MouseButton button) const;
	bool isButtonPressed(MouseButton button) const;
	bool isButtonJustReleased(MouseButton button) const;
	bool isKeyJustPressed(Key key) const;
	bool isKeyPressed(Key key) const;
	bool isKeyJustReleased(Key key) const;
	int getScrollAmount() const;
	const glm::vec2& getMousePos() const;

	void setButtonPressed(int, bool);
	void setKeyPressed(int, bool);
	void setScrollAmount(double);
	void setMousePos(double, double);
	void update();
private:
	std::set<MouseButton> m_ButtonsLast;
	std::set<MouseButton> m_ButtonsPressed;
	std::set<Key> m_KeysLast;
	std::set<Key> m_KeysPressed;
	int m_ScrollAmount{};
	glm::vec2 m_MousePos{};
};
