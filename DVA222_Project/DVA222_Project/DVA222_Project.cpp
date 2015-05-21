// DVA222_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graphix.h"
#include "glut.h"
#include "Button.h"
#include "Label.h"
#include "Panel.h"
#include "RadioButton.h"

using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------
    
	//ControlBase* button = new MyButton(10,10,190,60);
<<<<<<< HEAD
	/*Label* label1 = new Label(0, 0);
	label1->setText("Label");
	label1->setColor(256, 256, 0);
=======
	Container *container = new Container();
	Label* label1 = new Label(0, 0);
	label1->setText("AJ AJ");
	label1->setColor(256, 256, 256);
>>>>>>> origin/master

	Button* button = new Button(0, 0, 200, 50);
	button->SetButtonText("Click Here!");*/

<<<<<<< HEAD
	Panel* panel_1 = new Panel(100, 100, 500, 500);
	Panel* panel_2 = new Panel(100, 100, 300, 300);
	Panel* panel_3 = new Panel(100, 100, 100, 100);
=======
	RadioButton *radio = new RadioButton(400, 400);
	radio->setText("Radio");

	Panel* smallPanel = new Panel(0, 0, 100, 100);
	smallPanel->SetBackground(Color(256, 0, 0));
>>>>>>> origin/master

	panel_1->SetBackground(Color(200, 0, 0));
	panel_2->SetBackground(Color(0, 200, 0));
	panel_3->SetBackground(Color(0, 0, 200));

	panel_1->Add(panel_2);
	panel_2->Add(panel_3);

<<<<<<< HEAD
	panel_1->SetLocation(Point(10, 10));
	panel_2->SetLocation(Point(10, 10));

	ControlBase* base = panel_1;
	InitOGL(argc, argv, base);
=======
	Panel* panel = new Panel(100, 100, 200, 200);
	panel->Add(smallPanel);
	panel->SetBackground(Color(0, 256, 0));
	container->Add(panel);
	container->Add(button);
	container->Add(radio);
	

	ControlBase* base = panel;
	InitOGL(argc, argv, container);
>>>>>>> origin/master

    delete base;
	return 0;
}

