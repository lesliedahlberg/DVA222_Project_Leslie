#pragma once
#include "UIControl.h"
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include <string>
#include <stdlib.h>
#include "Header.h"
class Label :
	public UIControl
{
private:
	std::string text;
	Color color;

public:
	Label();
	Label(int locX, int locY);
	~Label();

	

	//Set, Get
	virtual void setText(std::string text);
	virtual void setColor(Color color);

	//The class is overriding the following Event Handlers inherited from the base class 
	virtual void OnPaint();
	virtual void OnLoaded();
};



