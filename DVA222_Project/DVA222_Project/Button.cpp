#include "stdafx.h"
#include "Button.h"


Button::Button()
{
	hit = pressed = false;
}

Button::Button(int locX, int locY, int width, int height)
	: ControlBase(locX, locY, width, height)
{
	hit = pressed = false;
	borderThickness = 2;
	background = Color(200, 200, 200);
	border = Color(0, 0, 0);
	buttonText.setColor(Color(0, 0, 0));
	SetLocation(X, Y);
}

Button::~Button()
{
	hit = pressed = false;
	borderThickness = 2;
}

void Button::SetButtonText(std::string text)
{
	buttonText.setText(text);
}

void Button::SetLocation(int locX, int locY)
{
	X = locX;
	Y = locY;
	buttonText.SetLocation(locX + borderThickness * 4, locY + borderThickness * 4 + 10);
}

void Button::SetSize(int Width, int Height)
{
	this->Width = Width;
	this->Height = Height;
}

void Button::OnMouseMove(int button, int x, int y)
{
	if (x>X && x < X + Width && y>Y && y < Y + Height)
		hit = true;
	else
	{
		pressed = hit = false;
	}
}

void Button::Draw()
{
	SetColor(background.R, background.G, background.B);
	FillRectangle(X, Y, Width, Height);
	SetColor(border.R, border.G, border.B);
	DrawRectangle(X, Y, Width, Height);

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