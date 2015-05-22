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
	//Title bar
	int titleBarHeight;
	Label* title;

	//Mouse event bools
	bool hit, pressed, moving;
	Point clickLocation;

	//Main panel
	Panel* panel;
	
public:
	//Constructor
	Window();

	//Destructor
	~Window();

	//ControlBase Overrides
	virtual void OnPaint();
	virtual void OnLoaded();
	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);

	//Title
	virtual void setTitle(std::string text);

	//Looks
	virtual void SetBackground(Color color);

	//Add elements
	virtual void Add(UIControl* element);

	//Custom SetZeroPointForControls
	virtual void SetZeroPointForControls();

	//Size override
	virtual void SetSize(Size size);
	
};

