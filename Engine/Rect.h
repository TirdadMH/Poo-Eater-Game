#pragma once

#include "Graphics.h"
#include "Dude.h"
#include <random>

class Rect
{
public:
	Rect();
	void Draw(Graphics& gfx) const;
	void ProcessConsumption(const Dude& dude);
	void Update(const Dude& dude);
private:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	int x = 0;
	int y = 0;
	static int constexpr width = 25;
	static int constexpr height = 25;
	bool IsRectCollected = false;
};

