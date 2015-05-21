#include "stdafx.h"
#include "CheckBox.h"
#include "Graphix.h"


CheckBox::CheckBox()
{
}

CheckBox::CheckBox(int x, int y)
	:UIControl(x, y, 16, 16)
{
	hit = checked = false;
	buttonText.setColor(Color(0, 0, 0));
}

CheckBox::~CheckBox()
{
}

void CheckBox::OnLoaded()
{
	
}

void CheckBox::OnPaint(void)
{
	buttonText.SetLocation(Point(X + 25, Y + 12));
	buttonText.OnPaint();
	SetColor(buttonColor.R, buttonColor.G, buttonColor.B);
	DrawRectangle(X+zeroPoint.X, Y+zeroPoint.Y, Width, Height);
	if (checked)
	{
		DrawLine(X + zeroPoint.X + 2, Y + zeroPoint.Y + 10, X + zeroPoint.X + 8, Y + zeroPoint.Y + 15);
	}
}

void CheckBox::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
	{
		if (!checked)
			checked = true;
		else
			checked = false;
	}
}

void CheckBox::OnMouseUp(int button, int x, int y)
{

}

void CheckBox::OnMouseMove(int button, int x, int y)
{
	if (x > X+zeroPoint.X && x < X+zeroPoint.X + Width && y > Y+zeroPoint.Y && y < Y+zeroPoint.Y + Height)
		hit = true;
	else
	{
		hit = false;
	}
}

void CheckBox::setText(std::string text)
{
	buttonText.setText(text);
}

void CheckBox::setTextColor(int r, int g, int b)
{
	textColor.R = r;
	textColor.G = g;
	textColor.B = b;
}

void CheckBox::setColor(int r, int g, int b)
{
	buttonColor.R = r;
	buttonColor.G = g;
	buttonColor.B = b;
}

void CheckBox::setPosition(int locX, int locY)
{
	X = locX;
	Y = locY;
}

void CheckBox::setStatus(bool checked)
{
	this->checked = checked;
}

bool CheckBox::getStatus()
{
	return checked;
}