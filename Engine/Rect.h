#pragma once

#include "Graphics.h"
#include "Dude.h"
#include <random>

class Rect
{
public:
	Rect();
	void Draw(Graphics& gfx);
	void Update(const Dude& dude);
private:
	void ProcessConsumption(const Dude& dude);
	void MakeColors();
	void DrawScore(Graphics& gfx);
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	int x = 0;
	int y = 0;
	int score_x = 20;
	int score_y = 20;
	int r = 0;
	int score = 0;
	static int constexpr width = 25;
	static int constexpr height = 25;
	int score_width = 10;
	int score_height = 20;
	bool IsRectCollected = false;
};

