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
#include "CheckBox.h"
#include "Window.h"
#include "ImageBox.h"
#include "CheckBoxGroup.h"
#include "RadioButtonGroup.h"
#include "MyButton.h"

using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------
    
	Window* window_1 = new Window(20, 20, 550, 450);
	window_1->SetBackground(Color(235, 235, 235));
	window_1->setTitle("I am the window!");

	Label* label_top = new Label(20, 20);
	label_top->setText("I am Label. Actually all the text you see inside those 2 panels ...");
	label_top->setColor(Color(50, 50, 50));

	CheckBoxGroup* checkBoxGroup_1 = new CheckBoxGroup(10, 50, 250, 150);
	checkBoxGroup_1->SetBackground(Color(210, 210, 210));
	CheckBox* checkBox_1 = new CheckBox(0, 0);
	CheckBox* checkBox_2 = new CheckBox(0, 20);
	CheckBox* checkBox_3 = new CheckBox(0, 40);
	CheckBox* checkBox_4 = new CheckBox(0, 60);
	checkBox_1->setText("I am a CheckBox");
	checkBox_2->setText("I am another CheckBox");
	checkBox_3->setText("I am a selected CheckBox");
	checkBox_4->setText("I am another selected CheckBox");
	checkBox_3->setStatus(true);
	checkBox_4->setStatus(true);
	checkBoxGroup_1->Add(checkBox_1);
	checkBoxGroup_1->Add(checkBox_2);
	checkBoxGroup_1->Add(checkBox_3);
	checkBoxGroup_1->Add(checkBox_4);

	RadioButtonGroup* radioButtonGroup_1 = new RadioButtonGroup(10 + 250 + 20, 50, 250, 150);
	radioButtonGroup_1->SetBackground(Color(210, 210, 210));
	RadioButton* radioButton_1 = new RadioButton(0, 0, radioButtonGroup_1);
	RadioButton* radioButton_2 = new RadioButton(0, 20, radioButtonGroup_1);
	RadioButton* radioButton_3 = new RadioButton(0, 40, radioButtonGroup_1);
	RadioButton* radioButton_4 = new RadioButton(0, 60, radioButtonGroup_1);
	radioButton_1->setText("I am a RadioButton");
	radioButton_2->setText("I am another RadioButton");
	radioButton_3->setText("I am THE selected RadioButton. The Only.");
	radioButton_4->setText("I am just another RadioButton");
	radioButton_3->setStatus(true);
	radioButtonGroup_1->Add(radioButton_1);
	radioButtonGroup_1->Add(radioButton_2);
	radioButtonGroup_1->Add(radioButton_3);
	radioButtonGroup_1->Add(radioButton_4);

	RadioButton* freeRadioButton_1 = new RadioButton(20, 50 + 150 + 20);
	freeRadioButton_1->setText("I am a free RadioButton");

	CheckBox* freeCheckBox_1 = new CheckBox(20, 50 + 150 + 20 + 20);
	freeCheckBox_1->setText("And I am a free CheckBox");

	MyButton* image_1 = new MyButton(20, 50 + 150 + 20 + 20 + 40, 100, 100);
	
	Panel* panel_1 = new Panel(10 + 250 + 20, 50 + 150 + 20, 250, 150);
	panel_1->SetBackground(Color(250, 120, 120));

	Label* label_panel_1 = new Label(20, 20);
	label_panel_1->setText("I am a panel.");
	label_panel_1->setColor(Color(50, 50, 50));

	panel_1->Add(label_panel_1);

	Panel* panel_2 = new Panel(10 + 250 + 20 - 100, 50 + 150 + 20 + 50, 250, 150);
	panel_2->SetBackground(Color(120, 250, 120));

	Label* label_panel_2 = new Label(20, 20);
	label_panel_2->setText("I am also a panel.");
	label_panel_2->setColor(Color(50, 50, 50));

	panel_2->Add(label_panel_2);

	Button* button = new Button(20, 40, 75, 20);
	button->SetButtonText("Button");

	panel_2->Add(button);
	
	

	window_1->Add(label_top);
	window_1->Add(checkBoxGroup_1);
	window_1->Add(radioButtonGroup_1);
	window_1->Add(freeRadioButton_1);
	window_1->Add(freeCheckBox_1);
	window_1->Add(image_1);
	window_1->Add(panel_1);
	window_1->Add(panel_2);
	
	ControlBase* base = window_1;

	InitOGL(argc, argv, base);

	delete base;
	return 0;
}

