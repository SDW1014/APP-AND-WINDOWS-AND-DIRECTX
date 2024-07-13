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
		, mGameObjects{}
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		GameObject* gameObj = new GameObject();
		mGameObjects.push_back(gameObj);
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

		for(size_t i = 0; i < mGameObjects.size(); ++i)
		{
			mGameObjects[i]->Update();
		}
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		
		for (size_t i = 0; i < mGameObjects.size(); ++i)
		{
			mGameObjects[i]->Render(mBackHdc);
		}

		copyRenderTarget(mBackHdc, mHdc);
	}
	void Application::clearRenderTarget()
	{
		// -1 -1 1601 901을 하는 이유는 조금의 더 커진 도화지가 필요하기 때문이다.
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		// Back에 미리 그려주는것 그리고 원본에 출력을 해야한다.
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(hwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		//윈도우 해상도에 맞는 백버퍼(도화지)생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}
