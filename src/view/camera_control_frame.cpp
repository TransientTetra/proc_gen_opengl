#include <sstream>
#include "view/camera_control_frame.hpp"

CameraControlFrame::CameraControlFrame(CameraView *view, const std::string &name)
: Frame(view, name)
{
	flags = ImGuiWindowFlags_NoResize;
	width = 400;
	height = 350;

	cameraType = STATIC_CAMERA;
	renderingMode = FILLED_WITH_LIGHTING;

	fov = 45;
	mouseSensitivity = .5f;
	speed = 5.f;
	drawDistance = 100;

	xpos = 0;
	ypos = 1;
	zpos = 10;

	//init view
	dynamic_cast<CameraView*>(view)->setCameraController(cameraType);
	dynamic_cast<CameraView*>(view)->setRenderingMode(renderingMode);
	dynamic_cast<CameraView*>(view)->setCameraSpeed(speed);
	dynamic_cast<CameraView*>(view)->setCameraSensitivity(mouseSensitivity);
	dynamic_cast<CameraView*>(view)->setCameraDrawDistance(drawDistance);
	dynamic_cast<CameraView*>(view)->setCameraPosition(glm::vec3(xpos, ypos, zpos));
}

void CameraControlFrame::mainDraw()
{
	ImGui::SetWindowSize(ImVec2(width, height));
	ImGui::Columns(2);

	ImGui::Text("Camera type");
	CameraControllerType tempC = cameraType;
	if (ImGui::RadioButton("Static", cameraType == STATIC_CAMERA)) cameraType = STATIC_CAMERA;
	if (ImGui::RadioButton("Flying FPS camera", cameraType == FPS_CAMERA)) cameraType = FPS_CAMERA;
	if (ImGui::RadioButton("Above camera", cameraType == ABOVE_CAMERA)) cameraType = ABOVE_CAMERA;
//	if (ImGui::RadioButton("Grounded FPS camera", cameraType == GROUNDED_FPS_CAMERA)) cameraType = GROUNDED_FPS_CAMERA;
	if (tempC != cameraType)
	{
		dynamic_cast<CameraView *>(view)->setCameraController(cameraType);
		dynamic_cast<CameraView *>(view)->setCameraSensitivity(mouseSensitivity);
		dynamic_cast<CameraView *>(view)->setCameraSpeed(speed);
	}

	ImGui::NewLine();
	ImGui::Text("Render mode");
	RenderingMode tempR = renderingMode;
	if (ImGui::RadioButton("Filled with lighting", renderingMode == FILLED_WITH_LIGHTING)) renderingMode = FILLED_WITH_LIGHTING;
	if (ImGui::RadioButton("Wireframe", renderingMode == WIREFRAME)) renderingMode = WIREFRAME;
	if (tempR != renderingMode)
		dynamic_cast<CameraView*>(view)->setRenderingMode(renderingMode);

	ImGui::NextColumn();

	ImGui::NewLine();
	glm::vec3 tempP = dynamic_cast<CameraView*>(view)->getCameraPosition();
	std::ostringstream str;
	str << "X: " << tempP.x << "\nY: " << tempP.y << "\nZ: " << tempP.z;
	ImGui::Text("Current position");
	ImGui::Text(str.str().c_str());

	ImGui::NewLine();
	ImGui::Text("Change position");
	ImGui::InputFloat("Xpos", &xpos);
	ImGui::InputFloat("Ypos", &ypos);
	ImGui::InputFloat("Zpos", &zpos);
	if (ImGui::Button("Teleport"))
	{
		dynamic_cast<CameraView*>(view)->setCameraPosition(glm::vec3(xpos, ypos, zpos));
	}

	ImGui::Columns(1);
	ImGui::NewLine();
	float tempF = mouseSensitivity;
	ImGui::SliderFloat("Mouse sensitivity", &mouseSensitivity, .1f, 1.f);
	if (tempF != mouseSensitivity)
		dynamic_cast<CameraView*>(view)->setCameraSensitivity(mouseSensitivity);

	tempF = fov;
	ImGui::SliderFloat("Field of view", &fov, 10, 180);
	if (tempF != fov)
		dynamic_cast<CameraView*>(view)->setCameraFOV(glm::radians<float>(fov));

	tempF = drawDistance;
	ImGui::SliderFloat("Draw distance", &drawDistance, 1, 500);
	if (tempF != drawDistance)
		dynamic_cast<CameraView*>(view)->setCameraDrawDistance(drawDistance);

	tempF = speed;
	ImGui::SliderFloat("Movement speed", &speed, 1.f, 10.f);
	if (tempF != speed)
		dynamic_cast<CameraView*>(view)->setCameraSpeed(speed);
}
