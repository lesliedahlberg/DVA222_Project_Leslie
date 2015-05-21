#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "UIControl.h"

using namespace std;

class MyButton : public UIControl
{
public:
    //Bitmap objects that hold different images for different states of the Button
    //Remember that the images MUST be in 24bit BMP format (use paint if you have images in other format)
    //Also remember that the image with MUST be dividable by 4
    //Also remember that the images must be stored in the same location as your source files
	Bitmap *normal;

	bool hit;
    bool pressed;
    
    MyButton();
	MyButton(int locX, int locY, int width, int height);

    ~MyButton();

    //The class is overriding the following Event Handlres inherited from the base class 
	virtual void OnPaint();
	virtual void OnLoaded();
};