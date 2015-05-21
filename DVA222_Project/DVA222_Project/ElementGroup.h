#pragma once
#include "Panel.h"
class ElementGroup :
	public Panel
{
protected:
	Color border;

public:
	ElementGroup();
	ElementGroup(int locX, int locY, int w, int h);
	virtual void SetBorderColor(Color color);
	virtual void OnPaint();
	virtual void PaintElements();
	~ElementGroup();
};

