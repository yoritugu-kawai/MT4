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
		Quaternion rotation = MakeRotateAxisAngleQuaternion(Normalize(Vector3{ 1.0f,0.4f,-0.2f }), 0.45f);
		Vector3 pointY = { 2.1f,-0.9f,1.3f };
		Matrix4x4 rotateMatrix = MakeRotateMatrix(rotation);
		Vector3 rotateByQuaterion = RotateVector(pointY, rotation);
		Vector3 rotateByMatrix = TransformRot(pointY, rotateMatrix);

		ImGui::Begin("rotation");
		
		ImGui::Text("%.3f", rotation.x);
		ImGui::Text("%.3f", rotation.y);
		ImGui::Text("%.3f", rotation.z);
		ImGui::Text("%.3f", rotation.w);

		ImGui::End();


		ImGui::Begin("rotateMatrix");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ImGui::Text("%4.2f", rotateMatrix.m[i][j]);
			}
		}
	

		ImGui::End();




		ImGui::Begin("rotateByQuaterion");

		ImGui::Text("%.3f", rotateByQuaterion.x);
		ImGui::Text("%.3f", rotateByQuaterion.y);
		ImGui::Text("%.3f", rotateByQuaterion.z);

		ImGui::End();

		ImGui::Begin("rotateByMatrix");

		ImGui::Text("%.3f", rotateByMatrix.x);
		ImGui::Text("%.3f", rotateByMatrix.y);
		ImGui::Text("%.3f", rotateByMatrix.z);

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
