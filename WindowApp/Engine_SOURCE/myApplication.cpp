#include "myApplication.h"

namespace MyApp
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
	{
	}

	Application::~Application()
	{
	}

	void MyApp::Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		mPlayer.setPosition(0, 0);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mSpeed += 0.01f;

		

		mPlayer.Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
	}
}
