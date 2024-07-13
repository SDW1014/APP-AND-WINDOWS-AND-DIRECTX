#include "myApplication.h"
#include "myInput.h"
#include "myTime.h"
#include "myBulletPlayerGameObject.h"
#include "myBulletGameObject.h"

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

		// ������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ����ۿ� �׸��� �׸��� ���� DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer = new BulletPlayerGameObject();
		mPlayer->setPosition(0,0);

		//mPlayer�� �Լ� �ֱ� 
		// Gameobject�� ��ӹ��� BulletpalyerGameObject�� �Լ��� �־��ش�. ���ٷ� �ִ´�.
		// BUlletplayerGameObject�� �Լ��� ����������ֳ�? 
		//void SetShotFunction(voidFUnction funcPtr) { mShotFunction = funcPtr; }
		mPlayer->SetShotFunction([this]()
		{
			for (int i = 0; i < 10; ++i)
			{
				if (!mBullets[i].IsShow())
				{
					mBullets[i].OnShow(mPlayer->GetpositionX(), mPlayer->GetpositionY());
					break;
				}
			}
		});
		//SetSHowFunction�� ���ٴµ� ����������? 




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

		mPlayer->Update();

		for (int i = 0; i < 10; i++)
		{
			mBullets[i].Update();
		}
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		//�Ͼ�� ����� ũ�⿡ ���缭 �ϳ� �����
		Rectangle(mBackHdc, 0, 0, 1600, 900); // �̷��� �ϸ� ������ �����. 
		// ������ �����ϱ�? 
		// ������ ���� ���۸��� ���� �����̴�.

		Time::Render(mBackHdc);
		mPlayer->Render(mBackHdc);
		for(int i = 0; i < 10; ++i)
		{
			mBullets[i].Render(mBackHdc);
		}

		// Back�� �̸� �׷��ִ°� �׸��� ������ ����� �ؾ��Ѵ�.
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
