#pragma once
#include "Graphics.h"
#include "Dude.h"

class Trash 
{
public:
	void Update();
	void SetTrashDirection();
	void ClampScreen();
	void ProcessConsumption(const Dude& dude);
	void Draw(Graphics& gfx) const;

	int x;
	int y;
	bool trashIsCollected = false;
	int direction;
	static constexpr int Width = 24;
	static constexpr int Height = 24;

	Trash() = default;
};