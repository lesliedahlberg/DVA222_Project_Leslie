#include "stdafx.h"
#include "Window.h"


Window::Window()
{
	xOff = 0;
	yOff = 20;
}

Window::Window(int locX, int locY, int width, int height) : UIControl(locX, locY, width, height)
{
	xOff = 0;
	yOff = 20;
	pressed = hit = moving = false;
	panel = new Panel(0, 0, width, height);
	SetLocation(Point(locX, locY));
}

Window::~Window()
{

}

void Window::Add(UIControl* element)
{
	panel->Add(element);
}

void Window::SetLocation(Point location)
{
	UIControl::SetLocation(location);
	panel->SetZeroPoint(Point(X + xOff, Y + yOff));
	panel->SetZeroPointForControls();
}

void Window::OnLoaded()
{
	panel->OnLoaded();
	SetLocation(Point(X, Y));
}

void Window::OnPaint()
{
	SetColor(180, 180, 180);
	FillRectangle(X, Y, Width, yOff);
	panel->OnPaint();
}

void Window::OnKeyboard(unsigned char key, int x, int y)
{
	panel->OnKeyboard(key, x, y);
}

void Window::OnMouseUp(int button, int x, int y)
{
	if (moving)
	{
		SetLocation(Point(X - (clickLocation.X - x), Y - clickLocation.Y + y));
	}
	pressed = moving = false;
	panel->OnMouseUp(button, x, y);
}

void Window::OnMouseDown(int button, int x, int y)
{
	if (hit)
	{
		pressed = true;
	}
	panel->OnMouseDown(button, x, y);
}

void Window::OnMouseMove(int button, int x, int y)
{
	if (x>X && x < X + Width && y>Y && y < Y + yOff)
		hit = true;
	else
	{
		pressed = hit = false;
	}
	if (pressed)
	{
		moving = true;
		clickLocation = Point(x, y);
	}
	panel->OnMouseMove(button, x, y);
}

void Window::OnResize(int width, int height)
{
	panel->OnResize(width, height);
}