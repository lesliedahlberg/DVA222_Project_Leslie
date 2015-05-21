#include "stdafx.h"
#include "Window.h"


Window::Window()
{

}

Window::Window(int locX, int locY, int width, int height) : UIControl(locX, locY, width, height)
{
	windowPanel = new Panel(0, 0, width, height);
	windowPanel->SetBackground(Color(23, 23, 23));
	windowPanel->SetZeroPoint(Point(locX, locY+20));
}

Window::~Window()
{
}

void Window::OnPaint()
{
	SetColor(56, 3, 98);
	FillRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, 20);
	windowPanel->OnPaint();
}

void Window::Add(UIControl* element)
{
	windowPanel->Add(element);
}