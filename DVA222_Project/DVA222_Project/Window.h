#pragma once
#include "Panel.h"
#include <stdlib.h>
#include <vector>
#include "Header.h"
#include "Graphix.h"
#include "Label.h"
class Window : public Panel
{
protected:
	
public:
	Window();
	Window(int locX, int locY, int width, int height);
	~Window();
	
};

