#pragma once
#include "Panel.h"
#include <stdlib.h>
#include <vector>
#include "Header.h"
#include "Graphix.h"
#include "Label.h"
#include "UIControl.h"
class Window : public UIControl
{
protected:
	int xOff, yOff;
	bool hit, pressed, moving;
	Color background;
	Point clickLocation;
	Point difference;
	Panel* panel;
	Label* title;
public:
	Window();
	Window(int locX, int locY, int width, int height);
	~Window();
	virtual void setTitle(std::string text);
	virtual void Add(UIControl* element);
	virtual void SetLocation(Point location);
	virtual void SetBackground(Color colro);
	virtual void OnPaint();
	virtual void OnLoaded();
	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);
};

