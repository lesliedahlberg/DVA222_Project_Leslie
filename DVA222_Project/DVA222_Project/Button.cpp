#include "stdafx.h"
#include "Button.h"

//Constructor
Button::Button()
{
	//Mouse event bools
	hit = pressed = false;

	//Looks
	background = Color(200, 200, 200);
	border = Color(0, 0, 0);
	buttonText.setColor(Color(0, 0, 0));

}

//Destructor
Button::~Button()
{

}

//ControlBase Override
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
	buttonText.OnLoaded();
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

void Button::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
		pressed = true;
}

void Button::OnMouseUp(int button, int x, int y)
{
	pressed = false;
}

//Custom SetZeroPointForControls
void Button::SetZeroPointForControls()
{
	//Set Zero Points
	buttonText.SetZeroPoint(Point(X + zeroPoint.X, Y + zeroPoint.Y));
	buttonText.SetZeroPointForControls();

	//Center label
	buttonText.SetLocation(Point(8, Height / 2 - 5));
}

//Label
void Button::SetButtonText(std::string text)
{
	buttonText.setText(text);
}

//Helper functions
void Button::Draw()
{
	//Draw Button
	SetColor(background.R, background.G, background.B);
	FillRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);
	SetColor(border.R, border.G, border.B);
	DrawRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);

	//Draw Label
	buttonText.OnPaint();
}