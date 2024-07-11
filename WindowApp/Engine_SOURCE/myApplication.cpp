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

		// ���� ������ Ű�� �Է¹����� x��ǥ�� �÷���
		// ���� ���� Ű�� �Է¹����� x��ǥ�� ���̳ʽ�
		// ���� ���� Ű�� �Է¹����� y��ǥ�� ���̳ʽ�
		// ���� �Ʒ��� Ű�� �Է¹����� y��ǥ�� �÷���
		
		float x = mPlayer.GetpositionX();
		float y = mPlayer.GetpositionY();

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			x -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			x += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			y += 0.01f;
		}

		mPlayer.setPosition(x, y);
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		//�Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);
		SelectObject(mHdc, oldPen);

		int x = mPlayer.GetpositionX();
		int y = mPlayer.GetpositionY();

		Rectangle(mHdc, 100 + x, 100 + y, 200 + x, 200 + y);

		SelectObject(mHdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
