#include "controller/demo1.hpp"
#include <iostream>

#ifdef _WIN32
#include <minwindef.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR pCmdLine, int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
	Demo1 application(DEFAULT_WINDOW_TITLE, DEFAULT_WINDOW_HEIGHT, DEFAULT_WINDOW_WIDTH);
	application.run();
	return 0;
}
