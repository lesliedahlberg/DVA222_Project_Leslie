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
void Label::setColor(int r, int g, int b)
{
	this->r = r;
	this->b = b;
	this->g = g;
}


void Label::OnPaint()
{
	//PAINT
	SetColor(r, g, b);
	DrawString(text, X+zeroPoint.X, Y+zeroPoint.Y);
}

void Label::OnLoaded()
{

}