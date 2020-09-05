#include <model/square.hpp>
#include <view/opengl_interfacing/vertex_shader.hpp>
#include <view/opengl_interfacing/fragment_shader.hpp>
#include <view/opengl_interfacing/vao.hpp>
#include <view/opengl_interfacing/vbo.hpp>
#include <view/opengl_interfacing/shader_program.hpp>
#include <view/opengl_interfacing/ebo.hpp>
#include <view/opengl_interfacing/rendered_model.hpp>
#include "controller/demo1.hpp"

Demo1::Demo1(const std::string &title, int height, int width)
: Application(title, height, width)
{
	world.addEntity(std::shared_ptr<Square>(new Square(Point(0, 0, 0), 10, 10)));
}

void Demo1::processEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		bool quit = (event.type == SDL_QUIT);
		quit |= (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE
			 && event.window.windowID == SDL_GetWindowID(window.getSDLWindow()));
		if (quit)
		{
			window.setClose();
		}
	}
}

void Demo1::run()
{
	float vertices[] =
		{
			-0.25f,  0.5f, 0.0f, // top right
			-0.25f, 0.25f, 0.0f, // bottom right
			-0.5f, 0.25f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f  // top left
		};

	float vertices2[] =
		{
			0.25f,  0.5f, 0.0f, // top right
			0.25f, 0.25f, 0.0f, // bottom right
			0.5f, 0.25f, 0.0f, // bottom left
			0.5f,  0.5f, 0.0f  // top left
		};
	unsigned int indices[] =
		{
			0, 1, 3,
			1, 2, 3
		};
	VertexShader vs;
	FragmentShader fs;
	ShaderProgram program;

	vs.loadCompileShaderSource("assets/shaders/vertex/default_basic.glsl");
	fs.loadCompileShaderSource("assets/shaders/fragment/default_basic.glsl");

	program.attachVertexAndFragmentShaders(vs, fs);
	program.linkProgram();

	RenderedModel model(vertices, sizeof(vertices), indices, sizeof(indices), GL_STATIC_DRAW);
	RenderedModel model2(vertices2, sizeof(vertices2), indices, sizeof(indices), GL_STATIC_DRAW);
	while (window.isOpen())
	{
		processEvents();
//		currentView->draw();
		window.updateViewportAndClear();
		program.useProgram();
		model.draw();
		model2.draw();
		window.render();
	}
}


