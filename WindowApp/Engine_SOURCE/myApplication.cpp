#include "myApplication.h"
#include "myInput.h"
#include "myTime.h"

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

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		//하얀색 배경을 크기에 맞춰서 하나 만든다
		Rectangle(mHdc, 0, 0, 1600, 900); // 이렇게 하면 문제가 생긴다. 
		// 이유는 무엇일까? 
		// 이유는 더블 버퍼링이 없기 때문이다.

		Time::Render(mHdc);
		mPlayer.Render(mHdc);
	}
}
