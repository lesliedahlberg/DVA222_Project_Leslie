#include "StdAfx.h"
#include "MyButton.h"
#include "Graphix.h"
#include "glut.h"

using namespace std;

// This is just a sample code to show you how you can use different Event Handlers in your code


MyButton::MyButton()
{

}

MyButton::MyButton(int locX, int locY, int width, int height)
    : UIControl(locX, locY, width, height)
{
	
}

MyButton::~MyButton()
{
    delete normal;
}



//This is called whenever the application wants to redraw its contents. We have already set it to 30 fps. You cannot change that
void MyButton::OnPaint()
{
        DrawBitmap(*normal, X+zeroPoint.X,Y+zeroPoint.Y,Width, Height);
    
}

//Is called once, when the object is being loaded
void MyButton::OnLoaded()
{		
	normal = new Bitmap("image.bmp");
	//Only 24bit bmp files are supported
	//Edit your bitmaps in MSPaint also remember that the width of the image MUST be a factor of 4 (be dividable by 4)

			
		
}	

