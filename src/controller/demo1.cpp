#include <model/square.hpp>
#include <view/vertex_shader.hpp>
#include <view/fragment_shader.hpp>
#include <view/vao.hpp>
#include <view/vbo.hpp>
#include <view/shader_program.hpp>
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
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
		};
	VertexShader vs;
	FragmentShader fs;
	ShaderProgram program;

	vs.loadCompileShaderSource("assets/shaders/vertex/default_basic.glsl");
	fs.loadCompileShaderSource("assets/shaders/fragment/default_basic.glsl");

	program.attachVertexAndFragmentShaders(vs, fs);
	program.linkProgram();

	VAO vao;
	VBO vbo;
	vao.bind();
	vbo.bind();
	vbo.loadVertices(vertices, sizeof(vertices));
	vao.setVertexAttributePointers(0, 3);
	while (window.isOpen())
	{
		processEvents();
//		currentView->draw();
		window.updateViewportAndClear();
		program.useProgram();
		vao.bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		window.render();
	}
}


