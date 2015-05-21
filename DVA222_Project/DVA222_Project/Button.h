#pragma once
#include "UIControl.h
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "Label.h"
#include "Header.h"
#include <string>
#include <stdlib.h>

class Button :
	public UIControl
{
private:
	Label buttonText;
	Color background;
	Color border;
	int borderThickness;
	bool hit;
	bool pressed;

	virtual void Draw();

public:
	Button();
	Button(int locX, int locY, int width, int height);
	~Button();

	virtual void SetButtonText(std::string text);
	virtual void SetSize(int Width, int Height);
	
	//The class is overriding the following Event Handlers inherited from the base class 
	virtual void OnPaint();
	virtual void OnLoaded();
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
};

