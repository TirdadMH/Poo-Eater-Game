#include "Trash.h"
#include "Graphics.h"

void Trash::Update()
{
	SetTrashDirection();
	ClampScreen();
}

void Trash::SetTrashDirection()
{

	if (direction == 0 || direction == 3)
		x += 1;
	else if (direction == 1 || direction == 2)
		x -= 1;

	if (direction == 0 || direction == 1)
		y -= 1;
	else if (direction == 2 || direction == 3)
		y += 1;
}

void Trash::ClampScreen()
{
	const int up_side = y;
	const int down_side = up_side + Height;
	const int left_side = x;
	const int right_side = left_side + Width;

	if (up_side <= 0)
	{
		if (direction == 0)
			direction = 3;
		if (direction == 1)
			direction = 2;
	}
	else if (down_side >= Graphics::ScreenHeight)
	{
		if (direction == 3)
			direction = 0;
		if (direction == 2)
			direction = 1;
	}

	if (left_side <= 0)
	{
		if (direction == 2)
			direction = 3;
		if (direction == 1)
			direction = 0;
	}
	else if (right_side >= Graphics::ScreenWidth)
	{
		if (direction == 3)
			direction = 2;
		if (direction == 0)
			direction = 1;
	}
}