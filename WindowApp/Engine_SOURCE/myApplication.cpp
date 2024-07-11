#include "myApplication.h"

namespace MyApp
{
	void MyApp::Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);
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
		//�Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		Rectangle(mHdc, 100, 100, 200, 200);

		//�ٽ� ��� �����귯���� ����
		SelectObject(mHdc, oldBrush);

		// �Ķ� �귯�� ����
		DeleteObject(blueBrush);


		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		Ellipse(mHdc, 200, 200, 300, 300);

		SelectObject(mHdc, oldPen);
		DeleteObject(redPen);

		// �⺻���� ���ֻ�� �Ǵ� GDI������Ʈ�� �̸� DC�ȿ� �����ξ��µ�
		// �� ������Ʈ���� ���� ������Ʈ��� �Ѵ�.

		HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);
		Rectangle(mHdc, 400, 400, 500, 500);
		SelectObject(mHdc, oldBrush);

		Rectangle(mHdc, 500, 500, 600, 600);
	}
}
