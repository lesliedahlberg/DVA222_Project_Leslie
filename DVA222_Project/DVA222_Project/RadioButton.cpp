#include "stdafx.h"
#include "RadioButton.h"
#include "Graphix.h"
#include "glut.h"


RadioButton::RadioButton()
{
}

RadioButton::RadioButton(int x, int y)
: ControlBase(x, y, 16, 16)
{
	hit = fillButton = false;
	buttonText.setColor(textColor);
}

RadioButton::~RadioButton()
{
}

void RadioButton::OnLoaded()
{

}

void RadioButton::setText(std::string text)
{
	buttonText.setText(text);
}
void RadioButton::setColor(Color color)
{
	button = color;
}

void RadioButton::setTextColor(Color color)
{
	buttonText.setColor(color);
}

void RadioButton::setPosition(int locX, int locY)
{
	X = locX;
	Y = locY;
}

void RadioButton::OnPaint(void)
{
	buttonText.SetLocation(Point(X+12, Y+5));
	buttonText.OnPaint();
	SetColor(button.R, button.G, button.B);
	DrawCircle(X, Y, Width / 2);
	if (fillButton)
	{
		int currentRadius = Width / 4;
		for (int i = 1; currentRadius > 0; i++)
		{
			DrawCircle(X, Y, currentRadius);
			currentRadius -= i/2;
		}
	}
}

void RadioButton::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
	{
		fillButton = true;
	}
}

void RadioButton::OnMouseUp(int button, int x, int y)
{
	
}

void RadioButton::OnMouseMove(int button, int x, int y)
{
	if (x<=X+(Width/2) && x >= X - (Width/2) && y<=Y + (Width/2) && y >= Y - (Width/2))
		hit = true;
	else
	{
		hit = false;
	}
}

void RadioButton::setStatus(bool checked)
{
	fillButton = checked;
}

bool RadioButton::getStatus()
{
	return fillButton;
}
