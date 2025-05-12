#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"
#include "Dude.h"

Rect::Rect() : rd(), rng(rd()), xDist(0, 770), yDist(0, 570)
{
	x = xDist(rng);
	y = yDist(rng);
}

void Rect::Draw(Graphics& gfx) const
{
	for (int i = x; i < x + width; i++)
		for (int j = y; j < y + height; j++)
			gfx.PutPixel(i, j, Colors::Magenta);
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
		IsRectCollected = true;
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
