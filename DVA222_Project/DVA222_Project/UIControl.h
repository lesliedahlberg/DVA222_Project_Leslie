#pragma once
#include "ControlBase.h"
#include "Graphix.h"
class UIControl :
	public ControlBase
{
protected:
	Point zeroPoint;
public:
	UIControl();
	UIControl(int locX, int locY, int width, int height);
	~UIControl();

	virtual void SetZeroPoint(Point zeroPoint);
};

