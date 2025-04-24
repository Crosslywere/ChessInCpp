#pragma once

#include <string>
#include <cstdint>

class Engine {
	friend class Window;
public:
	void play();

	inline uint32_t getWidth() const { return m_Width; }
	inline void setWidth(uint32_t width) { m_Width = width; }

	inline uint32_t getHeight() const { return m_Height; }
	inline void setHeight(uint32_t height) { m_Height = height; }

	inline const std::string& getTitle() const { return m_Title; }
	inline void setTitle(const std::string& title) { m_Title = title; }

	inline bool isResizable() const { return m_Resizable; }

protected:
	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onRender() = 0;

	inline virtual void onResize() {}
	inline virtual void onExit() {}

	inline void close() { m_Running = false; }
private:
	uint32_t m_Width{};
	int32_t m_MinWidth{ -1 };
	uint32_t m_Height{};
	int32_t m_MinHeight{ -1 };
	std::string m_Title{};
	bool m_Resizable{ true };
	bool m_Running{ true };
};
