#pragma once
#include "Panel.h"
#include "CheckBox.h"
#include "ElementGroup.h"
using namespace std;
class CheckBoxGroup :
	public ElementGroup
{

public:

	CheckBoxGroup();
	CheckBoxGroup(int locX, int locY, int w, int h);
	
	~CheckBoxGroup();
};

