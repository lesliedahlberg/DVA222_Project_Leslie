#include "stdafx.h"
#include "Window.h"


Window::Window()
{

}

Window::Window(int locX, int locY, int width, int height) : UIControl(locX, locY, width, height)
{
	xOff = 0;
	yOff = 20;
	panel = new Panel(0, 0, width, height);
	
}

Window::~Window()
{

}

void Window::Add(UIControl* element)
{
	panel->Add(element);
}

void Window::OnPaint()
{
	SetColor(180, 180, 180);
	FillRectangle(X, Y, Width, yOff);
	panel->SetZeroPoint(Point(X+xOff, Y+yOff));
	//panel->SetZeroPoint(Point(0, 0));
	panel->OnPaint();
}

void Window::OnKeyboard(unsigned char key, int x, int y)
{
	panel->OnKeyboard(key, x, y);
}

void Window::OnMouseUp(int button, int x, int y)
{
	panel->OnMouseUp(button, x, y);
}

void Window::OnMouseDown(int button, int x, int y)
{
	panel->OnMouseDown(button, x, y);
}

void Window::OnMouseMove(int button, int x, int y)
{
	panel->OnMouseMove(button, x, y);
}

void Window::OnResize(int width, int height)
{
	panel->OnResize(width, height);
}