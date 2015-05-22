#pragma once
#include "Panel.h"
class ElementGroup :
	public Panel
{
protected:
	//Looks
	Color border;

	//Helper
	virtual void PaintElements();

public:
	//Constructor
	ElementGroup();

	//Destructor
	~ElementGroup();

	//Looks
	virtual void SetBorderColor(Color color);

	//ControlBase Override
	virtual void OnPaint();

	
	
};

