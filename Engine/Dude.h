#pragma once
#include "Graphics.h"
class Dude
{
public:
	void Update();
	void ClampScreen();
	void Draw(Graphics& gfx) const;

	int x = 237;
	int y = 412;
	static constexpr int height = 20;
	static constexpr int width = 20;
};

