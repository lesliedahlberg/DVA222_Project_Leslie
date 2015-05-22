#include "StdAfx.h"
#include "MyButton.h"
#include "Graphix.h"
#include "glut.h"

using namespace std;

//Constructor
MyButton::MyButton()
{

}

//Destructor
MyButton::~MyButton()
{
    delete bitmap;
}

//ControlBase Override
void MyButton::OnPaint()
{
        DrawBitmap(*bitmap, X+zeroPoint.X,Y+zeroPoint.Y,Width, Height);
    
}

void MyButton::OnLoaded()
{		
	bitmap = new Bitmap("image.bmp");	
}	

