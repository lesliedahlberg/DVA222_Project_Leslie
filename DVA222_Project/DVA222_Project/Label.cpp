 #include "stdafx.h"
#include "Label.h"
#include "Graphix.h"
#include "glut.h"

//Constructor
Label::Label()
{
	
}

//Destructor
Label::~Label()
{
}


//Text
void Label::setText(std::string text)
{
	this->text = text;
}

//Looks
void Label::setColor(Color color)
{
	this->color = color;
}

//ControlBase Overrides
void Label::OnPaint()
{
	//Set Color
	SetColor(color.R, color.B, color.G);

	//Draw text
	DrawString(text, Y+zeroPoint.Y+10, X+zeroPoint.X);
	
}
