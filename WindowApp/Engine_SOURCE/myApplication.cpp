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
		, mBackHdc(nullptr)
		, mBackBitmap(nullptr)
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

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼에 그림을 그리기 위한 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

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
		Rectangle(mBackHdc, 0, 0, 1600, 900); // 이렇게 하면 문제가 생긴다. 
		// 이유는 무엇일까? 
		// 이유는 더블 버퍼링이 없기 때문이다.

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		// Back에 미리 그려주는것 그리고 원본에 출력을 해야한다.
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
