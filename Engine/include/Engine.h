#pragma once

#include <string>
#include <cstdint>

class Engine {
public:
	void play();
	
	inline uint32_t getWidth() const { return m_Width; }
	inline void setWidth(uint32_t width) { m_Width = width; }
	
	inline uint32_t getHeight() const { return m_Height; }
	inline void setHeight(uint32_t height) { m_Height = height; }

	inline std::string getTitle() const { return m_Title; }
	inline void setTitle(const std::string& title) { m_Title = title; }

protected:
	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onRender() = 0;
	
	void onExit();
	void onResize();
private:
	uint32_t m_Width{};
	uint32_t m_MinWidth{ -1 };
	uint32_t m_Height{};
	uint32_t m_MinHeight{ -1 };
	std::string m_Title{};
};
