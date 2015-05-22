#include "stdafx.h"
#include "RadioButton.h"
#include "Graphix.h"
#include "glut.h"

//Constructor
RadioButton::RadioButton()
{
	hit = fillButton = false;
	inGroup = false;
	SetSize(Size(16, 16));
}

RadioButton::RadioButton(RadioButtonGroup* group)
{
	hit = fillButton = false;
	buttonText.SetLocation(Point(16 + 8, 8 - 5));
	parent = group;
	inGroup = true;
	SetSize(Size(16, 16));
}

//Desctructor
RadioButton::~RadioButton()
{
}

//ControlBase Override
void RadioButton::OnLoaded()
{
	buttonText.OnLoaded();
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
		if (inGroup)
		{
			parent->Reset();
		}
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

//Custom SetZeroPointForControls
void RadioButton::SetZeroPointForControls()
{
	buttonText.SetZeroPoint(Point(X + zeroPoint.X, Y + zeroPoint.Y));

	//Set label location
	buttonText.SetLocation(Point(Width + 8, Height / 2 - 5));
}

//Label
void RadioButton::setText(std::string text)
{
	buttonText.setText(text);
}

void RadioButton::setTextColor(Color color)
{
	buttonText.setColor(color);
}

//Looks
void RadioButton::setColor(Color color)
{
	button = color;
}

//Status
void RadioButton::setStatus(bool checked)
{
	fillButton = checked;
}

bool RadioButton::getStatus()
{
	return fillButton;
}
