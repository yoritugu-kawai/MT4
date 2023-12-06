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
		Quaternion q1 = { 2.0f,3.0f,4.0f,1.0f };
		Quaternion q2 = { 1.0f,3.0f,5.0f,2.0f };
		Quaternion indentity = IdentityQuaternion();
		Quaternion conj = Conjugate(q1);
		Quaternion inv = InverseQuaternion(q1);
		Quaternion normal = NormalizeQuaternion(q1);
		Quaternion mul1 = MultiplyQuaternion(q1, q2);
		Quaternion mul2 = MultiplyQuaternion(q2, q1);
		float norm = Norm(q1);
		
		ImGui::Begin("indentity");
		
		ImGui::Text("%.2f", indentity.x);
		ImGui::Text("%.2f", indentity.y);
		ImGui::Text("%.2f", indentity.z);
		ImGui::Text("%.2f", indentity.w);

		ImGui::End();

		ImGui::Begin("Conjugate");

		ImGui::Text("%.2f", conj.x);
		ImGui::Text("%.2f", conj.y);
		ImGui::Text("%.2f", conj.z);
		ImGui::Text("%.2f", conj.w);

		ImGui::End();

		ImGui::Begin("Inverse");

		ImGui::Text("%.2f", inv.x);
		ImGui::Text("%.2f", inv.y);
		ImGui::Text("%.2f", inv.z);
		ImGui::Text("%.2f", inv.w);

		ImGui::End();

		ImGui::Begin("Normalize");

		ImGui::Text("%.2f", normal.x);
		ImGui::Text("%.2f", normal.y);
		ImGui::Text("%.2f", normal.z);
		ImGui::Text("%.2f", normal.w);

		ImGui::End();


		ImGui::Begin("MultiplyQuaternion(q1, q2)");

		ImGui::Text("%.2f", mul1.x);
		ImGui::Text("%.2f", mul1.y);
		ImGui::Text("%.2f", mul1.z);
		ImGui::Text("%.2f", mul1.w);

		ImGui::End();


		ImGui::Begin("MultiplyQuaternion(q2, q1)");

		ImGui::Text("%.2f", mul2.x);
		ImGui::Text("%.2f", mul2.y);
		ImGui::Text("%.2f", mul2.z);
		ImGui::Text("%.2f", mul2.w);

		ImGui::End();


		ImGui::Begin("Norm");

		ImGui::Text("%.2f", norm);
	

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
