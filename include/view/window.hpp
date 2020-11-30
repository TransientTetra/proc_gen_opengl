#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_sdl.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

class Window
{
private:
protected:
	bool open;
	SDL_Window* sdlWindow;
	SDL_GLContext glContext;
	ImGuiIO* io;
	std::string title;
public:
	Window(std::string title, int posX, int posY, int height, int width);
	~Window();

	void setupImGui();
	void closeImGui();

	void updateViewportAndClear();
	void render();
	bool isOpen();
	void setClose();
	SDL_Window* getSDLWindow();

	void setFullScreenWindowed();
	void setFullScreenBorderless();
	void setFullScreen();

	void maximize();
	void minimize();

	int getHeight() const;

	int getWidth() const;
};


#endif //WINDOW_HPP
