#ifndef PROC_GEN_OPENGL_INPUT_PROCESSOR_HPP
#define PROC_GEN_OPENGL_INPUT_PROCESSOR_HPP


#include <SDL_events.h>

class InputProcessor
{
protected:
public:
	virtual void processInput(SDL_Event& e) = 0;
};


#endif //PROC_GEN_OPENGL_INPUT_PROCESSOR_HPP
