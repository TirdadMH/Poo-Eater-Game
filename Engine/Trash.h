#pragma once
#include "Graphics.h"
#include "Dude.h"

class Trash 
{
public:
	void init(int in_x, int in_y, int in_direction);
	void Update();
	void SetTrashDirection();
	void ClampScreen();
	void ProcessConsumption(const Dude& dude);
	void Draw(Graphics& gfx) const;
	bool IsCollected() const;
private:
	int x;
	int y;
	bool trashIsCollected = false;
	int direction;
	static constexpr int Width = 24;
	static constexpr int Height = 24;
	bool initialized = false;
};