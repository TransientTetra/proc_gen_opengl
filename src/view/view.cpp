#include "view/view.hpp"

View::View()
{
    cameraPos = new glm::vec3(1.0f, .0f, 4.0f);

    cameraFront = new glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
}

void View::draw()
{
	for (Frame frame : frames)
	{
		frame.draw();
	}
}

void View::render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

Camera* View::getCamera()
{
    return this->camera;
}

glm::vec3* View::getCameraFront()
{
    return cameraFront;
}


glm::vec3 View::getCameraUp()
{
    return cameraUp;
}

void View::changeCameraPos(const glm::vec3 &changeVector)
{
    *cameraPos += changeVector;
}
