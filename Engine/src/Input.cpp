#include "pch.h"
#include <Input.h>

bool Input::isButtonJustPressed(MouseButton button) const {
	return m_ButtonsPressed.contains(button) && !m_ButtonsLast.contains(button);
}

bool Input::isButtonPressed(MouseButton button) const {
	return m_ButtonsPressed.contains(button);
}

bool Input::isButtonJustReleased(MouseButton button) const {
	return !m_ButtonsPressed.contains(button) && m_ButtonsLast.contains(button);
}

bool Input::isKeyJustPressed(Key key) const {
	return m_KeysPressed.contains(key) && !m_KeysLast.contains(key);
}

bool Input::isKeyPressed(Key key) const {
	return m_KeysPressed.contains(key);
}

bool Input::isKeyJustReleased(Key key) const {
	return !m_KeysPressed.contains(key) && m_KeysLast.contains(key);
}

int Input::getScrollAmount() const {
	return m_ScrollAmount;
}

const glm::vec2& Input::getMousePos() const {
	return m_MousePos;
}

void Input::setButtonPressed(int code, bool pressed) {
	if (code > static_cast<int>(MouseButton::BACKWARD))
		return;
	MouseButton button = static_cast<MouseButton>(code);
	if (pressed)
		m_ButtonsPressed.emplace(button);
	else
		m_ButtonsPressed.erase(button);
}

void Input::setKeyPressed(int code, bool pressed) {
	Key key = static_cast<Key>(code);
	if (pressed)
		m_KeysPressed.emplace(key);
	else
		m_KeysPressed.erase(key);
}

void Input::setScrollAmount(double offset) {
	m_ScrollAmount = static_cast<int>(offset);
}

void Input::setMousePos(double xpos, double ypos) {
	m_MousePos.x = static_cast<float>(xpos);
	m_MousePos.y = static_cast<float>(ypos);
}

void Input::update() {
	m_ButtonsLast.clear();
	m_ButtonsLast.insert(m_ButtonsPressed.begin(), m_ButtonsPressed.end());

	m_KeysLast.clear();
	m_KeysLast.insert(m_KeysPressed.begin(), m_KeysPressed.end());

	m_ScrollAmount = 0;
}