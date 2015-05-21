// DVA222_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graphix.h"
#include "glut.h"
#include "Button.h"
#include "Label.h"
#include "Container.h"
#include "Panel.h"

using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------
    
	//ControlBase* button = new MyButton(10,10,190,60);
	Label* label1 = new Label(0, 0);
	label1->setText("AJ AJ");
	label1->setColor(256, 256, 256);

	Button* button = new Button(0, 0, 200, 50);
	button->SetButtonText("Click Here!");

	Panel* smallPanel = new Panel(0, 0, 100, 100);
	smallPanel->SetBackground(Color(256, 0, 0));

	Panel* smallPanel2 = new Panel(10, 10, 50, 50);
	smallPanel2->SetBackground(Color(0, 0, 256));

	smallPanel->Add(smallPanel2);

	Panel* panel = new Panel(100, 100, 200, 200);
	panel->Add(smallPanel);
	panel->SetBackground(Color(0, 256, 0));

	ControlBase* base = panel;
	InitOGL(argc, argv, base);

    delete base;
	return 0;
}

