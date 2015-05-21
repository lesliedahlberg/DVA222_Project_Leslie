 #include "stdafx.h"
#include "Label.h"
#include "Graphix.h"
#include "glut.h"


Label::Label()
{
	
}

Label::Label(int locX, int locY)
	: UIControl(locX, locY, 0, 0)
{
	
}

Label::~Label()
{
}

void UIControl::SetZeroPointForControls(Point zeroPoint)
{
	
}

void UIControl::SetZeroPoint(Point zeroPoint)
{
	UIControl::SetZeroPoint(zeroPoint);
}

void UIControl::SetLocation(Point location)
{
	UIControl::SetLocation(location);
}

//Set, Get
void Label::setText(std::string text)
{
	this->text = text;
}
void Label::setColor(Color color)
{
	this->color = color;
}


void Label::OnPaint()
{
	//PAINT
	SetColor(color.R, color.B, color.G);
	DrawString(text, X+zeroPoint.X, Y+zeroPoint.Y+12);
}

void Label::OnLoaded()
{

}