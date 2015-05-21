#include "stdafx.h"
#include "UIControl.h"


UIControl::UIControl()
{
	zeroPoint = Point(0, 0);
}

UIControl::UIControl(int locX, int locY, int width, int height)
	: ControlBase(locX, locY, width, height)
{
	zeroPoint = Point(0, 0);
}


UIControl::~UIControl()
{
}

Point UIControl::GetLocation()
{
	return Point(X, Y);
}

void UIControl::SetZeroPointForControls(Point zeroPoint)
{
	
}

void UIControl::SetZeroPoint(Point zeroPoint)
{
	this->zeroPoint.X = zeroPoint.X;
	this->zeroPoint.Y = zeroPoint.Y;
	SetZeroPointForControls(zeroPoint);
}

void UIControl::SetLocation(Point location)
{
	X = location.X;
	Y = location.Y;
}

void UIControl::OnLoaded()
{
	//SetZeroPoint(zeroPoint);
}