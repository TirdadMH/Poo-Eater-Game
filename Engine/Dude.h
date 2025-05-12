#pragma once
#include "Graphics.h"
#include "MainWindow.h"

class Dude
{
public:
	void Update(const MainWindow& wnd);
	void ClampScreen();
	void Draw(Graphics& gfx) const;
	int getDudeX() const;
	int getDudeY() const;
	int getHeight() const;
	int getWidth() const;
private:
	int x = 237;
	int y = 412;
	static constexpr int speed = 2;
	static constexpr int height = 20;
	static constexpr int width = 20;
};

