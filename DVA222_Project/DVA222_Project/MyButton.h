#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "UIControl.h"

using namespace std;

class MyButton : public UIControl
{
protected:
	//Bitmap
	Bitmap *bitmap;

	//Mouse event bools
	bool hit;
	bool pressed;

public:
    //Constructor
	MyButton();

	//Destructor
	~MyButton();

    //ControlBase Override
	virtual void OnPaint();
	virtual void OnLoaded();
};