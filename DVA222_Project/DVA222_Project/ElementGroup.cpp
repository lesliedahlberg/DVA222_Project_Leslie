#include "stdafx.h"
#include "ElementGroup.h"


ElementGroup::ElementGroup()
{
}

ElementGroup::ElementGroup(int locX, int locY, int w, int h)
:Panel(locX, locY, w, h)
{
	background = Color(20, 20, 20);
}

void ElementGroup::SetBorderColor(Color color)
{
	border = color;
}

void ElementGroup::OnPaint()
{
	SetColor(background.R, background.G, background.B);
	FillRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);
	SetColor(border.R, border.G, border.B);
	DrawRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);
	PaintElements();
}

void ElementGroup::PaintElements()
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->SetLocation(Point(15, 25 * (i + 1)));
		controls.at(i)->OnPaint();
	}
}


ElementGroup::~ElementGroup()
{
}
