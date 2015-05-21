#include "stdafx.h"
#include "CheckBoxGroup.h"
#include "RadioButton.h"


CheckBoxGroup::CheckBoxGroup()
{
}

CheckBoxGroup::CheckBoxGroup(int x, int y, int w, int h)
:Panel(x, y, w, h)
{
}

void CheckBoxGroup::AddCheckBox(std::string text)
{
	CheckBox *box = new CheckBox(X + zeroPoint.X + 15, Y + zeroPoint.Y 
		+ controls.size() + 1 * 15);
	box->setText(text);
	Panel::Add(box);
	Panel::SetBackground(Color(40, 80, 60));
}


CheckBoxGroup::~CheckBoxGroup()
{
}
