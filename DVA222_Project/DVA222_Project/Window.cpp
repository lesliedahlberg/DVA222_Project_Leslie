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
	clickLocation = Point(0, 0);
	panel = new Panel(0, 0, width, height);
	title = new Label(0, 0);
	title->setColor(Color(50, 50, 50));
	SetLocation(Point(locX, locY));
}

Window::~Window()
{

}

void Window::setTitle(std::string text)
{
	title->setText(text);
}

void Window::SetBackground(Color color)
{
	this->background = color;
	panel->SetBackground(background);
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
	title->SetZeroPoint(Point(X+5, Y+5));
	title->SetZeroPointForControls();
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
	title->OnPaint();
	panel->OnPaint();
}

void Window::OnKeyboard(unsigned char key, int x, int y)
{
	panel->OnKeyboard(key, x, y);
}

void Window::OnMouseUp(int button, int x, int y)
{
	/*if (moving)
	{
		SetLocation(Point(X - (clickLocation.X - x), Y - clickLocation.Y + y));
	}*/
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
		if (moving)
		{

		}
		else{
			moving = true;
			clickLocation = Point(x, y);
		}
		
	}
	if (moving)
	{
		SetLocation(Point(X+x-clickLocation.X, Y+y-clickLocation.Y));
		clickLocation = Point(x, y);
	}
	panel->OnMouseMove(button, x, y);
}

void Window::OnResize(int width, int height)
{
	panel->OnResize(width, height);
}