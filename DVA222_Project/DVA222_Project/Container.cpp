#include "stdafx.h"
#include "Container.h"


Container::Container()
{
}

Container::Container(int locX, int locY, int width, int height) : ControlBase(locX, locY, width, height)
{
	background = Color(34, 21, 67);
}

Container::~Container()
{

}

void Container::Add(ControlBase* element)
{
	controls.push_back(element);
}

void Container::OnPaint()
{
	SetColor(background.R, background.G, background.B);
	FillRectangle(X, Y, Width, Height);

	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnPaint();
	}
}

void Container::OnLoaded()
{

}

void Container::OnKeyboard(unsigned char key, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnKeyboard(key, x, y);
	}
}

void Container::OnMouseUp(int button, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnMouseUp(button, x, y);
	}
}

void Container::OnMouseDown(int button, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnMouseDown(button, x, y);
	}
}

void Container::OnMouseMove(int button, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnMouseMove(button, x, y);
	}
}

void Container::OnResize(int width, int height)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnResize(width, height);
	}
}