#pragma once
#include "ControlBase.h"
#include <stdlib.h>
#include <vector>
#include "Header.h"
#include "Graphix.h"
class Container : public ControlBase
{
private:
	Color background;
	std::vector<ControlBase*> controls;
public:
	Container();
	Container(int locX, int locY, int width, int height);
	~Container();

	virtual void Add(ControlBase* element);

	virtual void OnPaint();
	virtual void OnLoaded();

	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);
};

