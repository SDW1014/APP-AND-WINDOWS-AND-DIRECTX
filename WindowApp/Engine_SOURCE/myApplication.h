#pragma once
#include "CommonInclude.h"

namespace MyApp
{
	class Application
	{
	public:
		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
	};
}


