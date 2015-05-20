#pragma once
#include "ControlBase.h"
#include <stdlib.h>
#include <vector>
#include "Header.h"
#include "Graphix.h"
#include "Label.h"
class Container : public ControlBase
{
private:
	Label titleLabel;
	Color background;
	Color border;
	std::string title;
	std::vector<ControlBase*> controls;
public:
	Container();
	Container(int locX, int locY, int width, int height);
	~Container();

	virtual void Add(ControlBase* element);
	virtual void SetTitle(std::string title);
	virtual void SetBackground(Color background);
	virtual void SetBorder(Color border);

	virtual void OnPaint();
	virtual void OnLoaded();

	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);
};

