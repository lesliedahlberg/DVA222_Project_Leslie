#pragma once
#include "ElementGroup.h"
class RadioButtonGroup :
	public ElementGroup
{
public:
	RadioButtonGroup();
	RadioButtonGroup(int locX, int locY, int w, int h);
	void Reset();
	~RadioButtonGroup();
};

