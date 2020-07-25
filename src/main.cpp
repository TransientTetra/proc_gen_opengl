#include "controller/application.hpp"
#include <iostream>

#ifdef _WIN32
#include <minwindef.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR pCmdLine, int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
	std::cout << "elo" << std::endl;
	Application application(DEFAULT_WINDOW_TITLE);
	application.run();
	return 0;
}
