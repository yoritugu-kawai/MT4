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

		Vector3 from0 = Normalize(Vector3{ 1.0f,0.7f,0.5f });
		Vector3 to0;
		to0.x= -from0.x;
		to0.y = -from0.y;
		to0.z = -from0.z;

		Vector3 from1 = Normalize(Vector3{ -0.6f,0.9f,0.2f });
		Vector3 to1 = Normalize(Vector3{ 0.4f,0.7f,-0.5f });
		
		Matrix4x4 rotateMatrix0 = DirectionToDirection(
			Normalize(Vector3{ 1.0f,0.0f,0.0f }), Normalize(Vector3{ -1.0f,0.0f,0.0f })
		);
		Matrix4x4 rotateMatrix1 = DirectionToDirection(from0, to0);
		Matrix4x4 rotateMatrix2 = DirectionToDirection(from1, to1);
		ImGui::Begin("rotateMatrix0");
		for (int i = 0; i < 4; i++) {
			for (int t = 0; t < 4; t++) {
				ImGui::Text("%.3f", rotateMatrix0.m[i][t]);
			}
		}
		ImGui::End();

		ImGui::Begin("rotateMatrix1");
		for (int i = 0; i < 4; i++) {
			for (int t = 0; t < 4; t++) {
				ImGui::Text("%.3f", rotateMatrix1.m[i][t]);
			}
		}
		
		ImGui::End();

		ImGui::Begin("rotateMatrix2");
		for (int i = 0; i < 4; i++) {
			for (int t = 0; t < 4; t++) {
				ImGui::Text("%.3f", rotateMatrix2.m[i][t]);
			}
		}

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
