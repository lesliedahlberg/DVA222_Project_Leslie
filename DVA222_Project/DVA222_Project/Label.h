#pragma once
#include "UIControl.h"
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include <string>
#include <stdlib.h>
class Label :
	public UIControl
{
private:
	std::string text;
	int r, g, b;

public:
	Label();
	Label(int locX, int locY);
	~Label();

	virtual void SetLocation(Point location);
	virtual void SetZeroPoint(Point zeroPoint);
	virtual void SetZeroPointForControls(Point zeroPoint);

	//Set, Get
	virtual void setText(std::string text);
	virtual void setColor(int r, int g, int b);

	//The class is overriding the following Event Handlers inherited from the base class 
	virtual void OnPaint();
	virtual void OnLoaded();
};



