#pragma once
#include "ControlBase.h"
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include <string>
#include <stdlib.h>
class Label :
	public ControlBase
{
private:
	std::string text;
	int r, g, b;

public:
	Label();
	Label(int locX, int locY);
	~Label();

	//Set, Get
	virtual void setText(std::string text);
	virtual void setColor(int r, int g, int b);
	virtual void setPosition(int locX, int locY);

	//The class is overriding the following Event Handlers inherited from the base class 
	virtual void OnPaint();
	virtual void OnLoaded();
};



