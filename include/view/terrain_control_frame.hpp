#ifndef PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP
#define PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP


#include "frame.hpp"

class TerrainControlFrame : public Frame
{
private:
protected:
public:
	TerrainControlFrame(View *view, const std::string &name);

protected:
	void mainDraw() override;
};


#endif //PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP
