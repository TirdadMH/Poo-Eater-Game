#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"
#include "Dude.h"

Rect::Rect() : rd(), rng(rd()), xDist(0, 770), yDist(0, 570)
{
	x = xDist(rng);
	y = yDist(rng);
}

void Rect::Draw(Graphics& gfx)
{
	DrawScore(gfx);
	MakeColors();
	for (int i = x; i < x + width; i++)
		for (int j = y; j < y + height; j++)
			gfx.PutPixel(i, j, r, 255, 255);
}

void Rect::ProcessConsumption(const Dude& dude)
{
	const int right0 = dude.getDudeX() + dude.getWidth();
	const int bottom0 = dude.getDudeY() + dude.getHeight();

	const int right1 = x + width;
	const int bottom1 = y + height;

	if (right0 >= x &&
		dude.getDudeX() <= right1 &&
		bottom0 >= y &&
		dude.getDudeY() <= bottom1)
	{
		IsRectCollected = true;
		score++;
	}
}

void Rect::Update(const Dude& dude)
{
	ProcessConsumption(dude);
	if (IsRectCollected)
	{
		x = xDist(rng);
		y = yDist(rng);
		IsRectCollected = false;
	}
}

void Rect::MakeColors()
{
	if (r <= 255)
		r += 2;
	else
		r = 0;
}

void Rect::DrawScore(Graphics& gfx)
{
	for (int i = score_x; i < (score_width + score_x) * score; i++)
		for (int j = score_y; j < (score_height + score_y); j++)
			gfx.PutPixel(i, j, 255, 255, 0);
}
