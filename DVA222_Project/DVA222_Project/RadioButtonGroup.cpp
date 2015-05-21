#include "stdafx.h"
#include "RadioButtonGroup.h"
#include "RadioButton.h"


RadioButtonGroup::RadioButtonGroup()
{
}

RadioButtonGroup::RadioButtonGroup(int locX, int locY, int w, int h)
:ElementGroup(locX, locY, w, h)
{
}

void RadioButtonGroup::Reset()
{
	int size = controls.size();
	for (int i = 0; i < size; i++)
	{
		RadioButton* e = (RadioButton*) controls.at(i);
		e->setStatus(false);
	}
}

RadioButtonGroup::~RadioButtonGroup()
{
}
