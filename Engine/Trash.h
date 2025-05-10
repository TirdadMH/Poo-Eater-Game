#pragma once

class Trash 
{
public:
	void Update();
	void SetTrashDirection();
	void ClampScreen();

	int x;
	int y;
	bool trashIsCollected = false;
	int direction;
	static constexpr int Width = 24;
	static constexpr int Height = 24;

	Trash() = default;
};