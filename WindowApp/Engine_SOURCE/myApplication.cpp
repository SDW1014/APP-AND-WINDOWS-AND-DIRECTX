#include "myApplication.h"

namespace MyApp
{
	void MyApp::Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
	}
}
