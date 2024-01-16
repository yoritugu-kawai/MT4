#include"DKJEN/Base/DxCommon.h"
#include"DKJEN/Base/WinApp.h"
#include"DKJEN/Base/ImageLoading.h"

#include"DKJEN/Math/Math.h"
#include"DKJEN/Imgui/imguiManager.h"

#include"DKJEN/Type/Polygon.h"
#include"DKJEN/Type/Sprite.h"
#include"DKJEN/Type/Texture.h"
#include"DKJEN/Type/Sphere.h"
#include"DKJEN/Type/Obj3D.h"
#include"DKJEN/Utilipy/rektyk.h"
#include"DKJEN/Utilipy/Input.h"

#include"DKJEN/Management/PSOCopileManagement.h"
const wchar_t Title[] = { L"ド根性エンジン" };


struct Transfrom4
{
	Vector4 lefe;
	Vector4  top;
	Vector4 right;
	Vector4 color;

};

static D3DResourceLeaker leaker;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	WinApp::Initialize(Title);
	DxCommon::Initialize();
	ImguiManager::Initialize();
	Input::Initialize();
	
	PSOCopileManagement::Set();
	
	

	//　メインループ
	MSG msg{};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		DxCommon::BeginFrame();
		ImguiManager::BeginFrame();
		Input::BeginFlame();

		//　ゲーム処理
		//////
		Quaternion rotaion0 = MakeRotateAxisAngleQuaternion({0.71f,0.71f,0.0f},0.3f);
		Quaternion rotaion1 = MakeRotateAxisAngleQuaternion({0.71f,0.0f,0.71f},0.3141592f);

		Quaternion interpolate0 = Slerp(rotaion0, rotaion1, 0.0f);
		Quaternion interpolate1 = Slerp(rotaion0, rotaion1, 0.3f);
		Quaternion interpolate2 = Slerp(rotaion0, rotaion1, 0.5f);
		Quaternion interpolate3 = Slerp(rotaion0, rotaion1, 0.7f);
		Quaternion interpolate4 = Slerp(rotaion0, rotaion1, 1.0f);

		ImGui::Begin("interpolate0");
		
		ImGui::Text("%4.2f", interpolate0.x);
		ImGui::Text("%4.2f", interpolate0.y);
		ImGui::Text("%4.2f", interpolate0.z);
		ImGui::Text("%4.2f", interpolate0.w);
		ImGui::Text("Slerp(rotaion0, rotaion1, 0.0f)");

		ImGui::End();

		ImGui::Begin("interpolate1");

		ImGui::Text("%4.2f", interpolate1.x);
		ImGui::Text("%4.2f", interpolate1.y);
		ImGui::Text("%4.2f", interpolate1.z);
		ImGui::Text("%4.2f", interpolate1.w);
		ImGui::Text("Slerp(rotaion0, rotaion1, 0.3f);");

		ImGui::End();

		ImGui::Begin("interpolate2");

		ImGui::Text("%4.2f", interpolate2.x);
		ImGui::Text("%4.2f", interpolate2.y);
		ImGui::Text("%4.2f", interpolate2.z);
		ImGui::Text("%4.2f", interpolate2.w);
		ImGui::Text("Slerp(rotaion0, rotaion1, 0.5f)");

		ImGui::End();
		ImGui::Begin("interpolate3");
	   
		ImGui::Text("%4.2f", interpolate3.x);
		ImGui::Text("%4.2f", interpolate3.y);
		ImGui::Text("%4.2f", interpolate3.z);
		ImGui::Text("%4.2f", interpolate3.w);
		ImGui::Text("Slerp(rotaion0, rotaion1, 0.7f)");

		ImGui::End();
		ImGui::Begin("interpolate4");

		ImGui::Text("%4.2f", interpolate4.x);
		ImGui::Text("%4.2f", interpolate4.y);
		ImGui::Text("%4.2f", interpolate4.z);
		ImGui::Text("%4.2f", interpolate4.w);
		ImGui::Text("Slerp(rotaion0, rotaion1, 1.0f)");

		ImGui::End();

		// 
		//////
		//　ゲーム処理


		ImguiManager::EndFrame();
		DxCommon::EndFrame();

	}

	/*
	*************************
	*********   解放  *******
	*************************
	*/
	

	
	
	PSOCopileManagement::Release();

	ImguiManager::Release();
	DxCommon::Release();


	return 0;
}
