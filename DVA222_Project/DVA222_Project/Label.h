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
protected:
	//Text
	std::string text;

	//Looks
	Color color;

public:
	//Constructor
	Label();

	//Destructor
	~Label();

	//Text
	virtual void setText(std::string text);

	//Looks
	virtual void setColor(Color color);

	//ControlBase Overrides
	virtual void OnPaint();

};



