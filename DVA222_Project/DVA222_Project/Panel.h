#pragma once
#include "UIControl.h"
#include <stdlib.h>
#include <vector>
#include "Header.h"
#include "Graphix.h"
#include "Label.h"

class Panel : public UIControl
{
protected:
	Color background;
	std::vector<UIControl*> controls;
public:
	Panel();
	Panel(int locX, int locY, int width, int height);
	~Panel();

	virtual void PaintElements();

	virtual void SetLocation(Point location);
	virtual void SetZeroPoint(Point zeroPoint);
	virtual void SetZeroPointForControls(Point zeroPoint);

	virtual void Add(UIControl* element);
	virtual void SetBackground(Color background);
	
	virtual void OnLoaded();
	virtual void OnPaint();

	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);
};

