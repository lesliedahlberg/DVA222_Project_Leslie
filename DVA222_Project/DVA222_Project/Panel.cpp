#include "stdafx.h"
#include "Panel.h"


Panel::Panel()
{

}

Panel::Panel(int locX, int locY, int width, int height) : UIControl(locX, locY, width, height)
{
	
}

Panel::~Panel()
{
}

void Panel::SetLocation(Point location)
{
	UIControl::SetLocation(location);
	SetZeroPointForControls(Point(location.X+zeroPoint.X, location.Y+zeroPoint.Y));
}

void Panel::SetZeroPoint(Point zeroPoint)
{
	UIControl::SetZeroPoint(zeroPoint);
	SetZeroPointForControls(zeroPoint);
}

void Panel::SetZeroPointForControls(Point zeroPoint)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->SetZeroPoint(zeroPoint);
		Point location = controls.at(i)->GetLocation();
		controls.at(i)->SetZeroPointForControls(Point(location.X+zeroPoint.X, location.Y+zeroPoint.Y));
	}
}

void Panel::Add(UIControl* element)
{
	element->SetZeroPoint(Point(X+zeroPoint.X, Y+zeroPoint.Y));
	controls.push_back(element);
	
}

void Panel::SetBackground(Color background)
{
	this->background = background;
}

void Panel::PaintElements()
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnPaint();
	}
}

void Panel::OnLoaded()
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnLoaded();
	}
	//SetZeroPoint(zeroPoint);
}

void Panel::OnPaint()
{
	
	SetColor(background.R, background.G, background.B);
	FillRectangle(X+zeroPoint.X, Y+zeroPoint.Y, Width, Height);
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