#include "stdafx.h"
#include "Panel.h"

//Contructor
Panel::Panel()
{
	SetBackground(Color(207, 216, 220));

}

//Desctructor
Panel::~Panel()
{
}

//Looks
void Panel::SetBackground(Color background)
{
	this->background = background;
}

//ControlBase Overrides
void Panel::OnLoaded()
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnLoaded();
	}
}

void Panel::OnPaint()
{
	//Set background color
	SetColor(background.R, background.G, background.B);
	
	//Paint panel
	FillRectangle(X+zeroPoint.X, Y+zeroPoint.Y, Width, Height);
	
	//Paint elements
	PaintElements();
}


void Panel::OnKeyboard(unsigned char key, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnKeyboard(key, x, y);
	}
}

void Panel::OnMouseUp(int button, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnMouseUp(button, x, y);
	}
}

void Panel::OnMouseDown(int button, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnMouseDown(button, x, y);
	}
}

void Panel::OnMouseMove(int button, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnMouseMove(button, x, y);
	}
}

void Panel::OnResize(int width, int height)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnResize(width, height);
	}
}

//Custom SetZeroPointForControls
void Panel::SetZeroPointForControls()
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		//Set Zero Point for control
		controls.at(i)->SetZeroPoint(Point(zeroPoint.X + X, zeroPoint.Y + Y));
		
		//Set Zero Point for controls children
		controls.at(i)->SetZeroPointForControls();
	}
}

//Add element to panel
void Panel::Add(UIControl* element)
{
	//Set Zero Point for new control
	element->SetZeroPoint(Point(X + zeroPoint.X, Y + zeroPoint.Y));
	
	//Add element
	controls.push_back(element);
}



//Helper function for painting panel elements
void Panel::PaintElements()
{
	//For for Z
	//std::sort(controls.begin(), controls.end(), compare);
	
	//Paint controls
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnPaint();
	}
}

