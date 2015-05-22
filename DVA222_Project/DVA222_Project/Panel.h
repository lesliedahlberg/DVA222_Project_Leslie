#pragma once
#include "UIControl.h"
#include <stdlib.h>
#include <vector>
#include "Header.h"
#include "Graphix.h"
#include "Label.h"
#include <algorithm>

class Panel : public UIControl
{
protected:
	//Looks
	Color background;

	//Elements
	std::vector<UIControl*> controls;

	//Helper function for painting panel elements
	virtual void PaintElements();

public:
	//Contructor
	Panel();

	//Desctructor
	~Panel();

	//Comparison function for datatype
	bool compare(UIControl* c1, UIControl* c2)
	{
		return c1->GetZ() < c2->GetZ();
	}

	//Looks
	virtual void SetBackground(Color background);

	//ControlBase Overrides
	virtual void OnLoaded();
	virtual void OnPaint();
	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);

	//Custom SetZeroPointForControls
	virtual void SetZeroPointForControls();

	//Add element to panel
	virtual void Add(UIControl* element);
	
};

