#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "task/Window.h"

int main()
{
	Window window(800, 600);

	window.Open();

	return 0;
}