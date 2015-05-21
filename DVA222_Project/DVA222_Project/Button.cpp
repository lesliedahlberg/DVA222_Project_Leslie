#include "stdafx.h"
#include "Button.h"


Button::Button()
{
	hit = pressed = false;
}

Button::Button(int locX, int locY, int width, int height)
	: UIControl(locX, locY, width, height)
{
	hit = pressed = false;
	background = Color(200, 200, 200);
	border = Color(0, 0, 0);
	buttonText.setColor(Color(0, 0, 0));
	buttonText.SetLocation(Point(0, 0));
	
}

Button::~Button()
{
	hit = pressed = false;
}

void Button::SetZeroPoint(Point zeroPoint)
{
	UIControl::SetZeroPoint(zeroPoint);
	SetZeroPointForControls(zeroPoint);
}

void Button::SetZeroPointForControls(Point zeroPoint)
{
	buttonText.SetZeroPoint(Point(X + zeroPoint.X, Y + zeroPoint.Y));
	
}

void Button::SetButtonText(std::string text)
{
	buttonText.setText(text);
}


void Button::SetSize(int Width, int Height)
{
	this->Width = Width;
	this->Height = Height;
}

void Button::OnMouseMove(int button, int x, int y)
{
	if (x>X + zeroPoint.X && x < X + zeroPoint.X + Width && y>Y + zeroPoint.Y && y < Y + zeroPoint.Y + Height)
		hit = true;
	else
	{
		pressed = hit = false;
	}
}

void Button::Draw()
{
	SetColor(background.R, background.G, background.B);
	FillRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);
	SetColor(border.R, border.G, border.B);
	DrawRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);

	buttonText.OnPaint();
}

void Button::OnPaint()
{
	if (pressed){
		background = Color(100, 100, 100);
		border = Color(0, 0, 0);
		buttonText.setColor(Color(0, 0, 0));
	}else if (hit){
		background = Color(150, 150, 150);
		border = Color(0, 0, 0);
		buttonText.setColor(Color(0, 0, 0));
	}else{
		background = Color(200, 200, 200);
		border = Color(0, 0, 0);
		buttonText.setColor(Color(0, 0, 0));
	}
	Draw();
}

void Button::OnLoaded()
{

}

void Button::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
		pressed = true;
}

void Button::OnMouseUp(int button, int x, int y)
{
	pressed = false;
}