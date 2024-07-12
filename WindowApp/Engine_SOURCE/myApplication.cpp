#include "myApplication.h"
#include "myInput.h"
#include "myTime.h"

namespace MyApp
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
	{
	}

	Application::~Application()
	{
	}

	void MyApp::Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);

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
