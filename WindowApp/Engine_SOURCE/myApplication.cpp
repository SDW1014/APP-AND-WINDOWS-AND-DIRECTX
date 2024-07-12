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
		//�Ͼ�� ����� ũ�⿡ ���缭 �ϳ� �����
		Rectangle(mHdc, 0, 0, 1600, 900); // �̷��� �ϸ� ������ �����. 
		// ������ �����ϱ�? 
		// ������ ���� ���۸��� ���� �����̴�.

		Time::Render(mHdc);
		mPlayer.Render(mHdc);
	}
}
