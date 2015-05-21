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

	virtual Point GetLocation();
	virtual void SetLocation(Point location);
	virtual void SetZeroPoint(Point zeroPoint);
	virtual void SetZeroPointForControls(Point zeroPoint);
};

