#include "stdafx.h"
#include "RadioButton.h"
#include "Graphix.h"
#include "glut.h"


RadioButton::RadioButton()
{
}

RadioButton::RadioButton(int x, int y)
: UIControl(x, y, 16, 16)
{
	hit = fillButton = false;

	
	buttonText.SetLocation(Point(8+5, 16+5));
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

void RadioButton::SetZeroPoint(Point zeroPoint)
{
	UIControl::SetZeroPoint(zeroPoint);
	SetZeroPointForControls(zeroPoint);
}

void RadioButton::SetZeroPointForControls(Point zeroPoint)
{
	buttonText.SetZeroPoint(Point(X + zeroPoint.X, Y + zeroPoint.Y));
}


void RadioButton::OnPaint(void)
{
	
	SetColor(button.R, button.G, button.B);
	DrawCircle(X+zeroPoint.X+8, Y+zeroPoint.Y+8, Width / 2);
	if (fillButton)
	{
		int currentRadius = Width / 4;
		for (int i = 1; currentRadius > 0; i++)
		{
			DrawCircle(X+zeroPoint.X+8, Y+zeroPoint.Y+8, currentRadius);
			currentRadius -= i/2;
		}
	}
	
	buttonText.OnPaint();
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
	if (x > X + zeroPoint.X && x < X + zeroPoint.X + 16 && y>Y + zeroPoint.Y && y < Y + zeroPoint.Y + 16)
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
