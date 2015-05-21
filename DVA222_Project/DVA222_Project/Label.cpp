 #include "stdafx.h"
#include "Label.h"
#include "Graphix.h"
#include "glut.h"


Label::Label()
{
	
}

Label::Label(int locX, int locY)
	: UIControl(locY, locX, 0, 0)
{
	
}

Label::~Label()
{
}

void Label::SetZeroPointForControls()
{

}

void Label::SetLocation(Point location)
{
	UIControl::SetLocation(Point(location.Y, location.X));

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
	DrawString(text, Y+zeroPoint.Y+10, X+zeroPoint.X);
}

void Label::OnLoaded()
{

}