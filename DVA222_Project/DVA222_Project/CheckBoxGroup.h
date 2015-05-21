#pragma once
#include "Panel.h"
#include "CheckBox.h"
using namespace std;
class CheckBoxGroup :
	public Panel
{
protected:
	vector <CheckBox> boxes;
public:

	CheckBoxGroup();
	CheckBoxGroup(int locX, int locY, int w, int h);
	void AddCheckBox(std::string text);
	~CheckBoxGroup();
};

