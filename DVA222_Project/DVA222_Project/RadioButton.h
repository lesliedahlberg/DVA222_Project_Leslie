#pragma once
#include "ControlBase.h"
#include "Label.h"
#include "Header.h"
class RadioButton :
	public ControlBase
{
private:
	std::string text;
	int r, g, b;
	bool hit;
	bool fillButton;
	Color button;
	Color textColor;
	Label buttonText;

public:

	RadioButton();
	RadioButton(int x, int y);
	~RadioButton();
	
	virtual void OnLoaded();
	virtual void OnPaint(void);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);

	virtual void setText(std::string text);
	virtual void setTextColor(int r, int g, int b);
	virtual void setColor(int r, int g, int b);
	virtual void setPosition(int locX, int locY);
	virtual void setStatus(bool checked);
	virtual bool getStatus();
	
};

