#pragma once
#include "CommonInclude.h"
#include "myGameObject.h"

namespace MyApp
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;

		// �÷��̾�
		GameObject mPlayer;
	};
}


