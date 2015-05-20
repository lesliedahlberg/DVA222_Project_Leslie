// DVA222_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graphix.h"
#include "glut.h"
#include "Button.h"
#include "Label.h"
#include "Container.h"

using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------
    
	//ControlBase* button = new MyButton(10,10,190,60);
	Label* label1 = new Label(300, 300);
	label1->setText("AJ AJ");
	label1->setColor(256, 256, 256);

	Button* button = new Button(60, 60, 200, 50);
	button->SetButtonText("Click Here!");

	Container* container = new Container(50, 50, 400, 400);
	container->Add(label1);
	container->Add(button);
	container->SetTitle("Title");
	container->SetBackground(Color(34, 87, 245));
	container->SetBorder(Color(200, 0, 100));
	


	ControlBase* base = container;
	InitOGL(argc, argv, base);

    delete base;
	return 0;
}

