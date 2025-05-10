#include "Dude.h"
#include "Graphics.h"

void Dude::Update()
{
	ClampScreen();
}

void Dude::ClampScreen()
{
	const int up_side = y;
	const int down_side = up_side + height;
	const int left_side = x;
	const int right_side = left_side + width;

	if (left_side < 0)
		x = 0;
	else if (right_side >= Graphics::ScreenWidth)
		x = (Graphics::ScreenWidth - 1) - width;

	if (up_side < 0)
		y = 0;
	else if (down_side >= Graphics::ScreenHeight)
		y = (Graphics::ScreenHeight - 1) - height;
}
