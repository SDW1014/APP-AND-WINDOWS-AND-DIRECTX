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
		//파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		Rectangle(mHdc, 100, 100, 200, 200);

		//다시 흰색 원본브러쉬로 선택
		SelectObject(mHdc, oldBrush);

		// 파랑 브러쉬 삭제
		DeleteObject(blueBrush);


		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		Ellipse(mHdc, 200, 200, 300, 300);

		SelectObject(mHdc, oldPen);
		DeleteObject(redPen);

		// 기본으로 자주사용 되는 GDI오브젝트를 미리 DC안에 만들어두었는데
		// 그 오브젝트들을 스톡 오브젝트라고 한다.

		HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);
		Rectangle(mHdc, 400, 400, 500, 500);
		SelectObject(mHdc, oldBrush);

		Rectangle(mHdc, 500, 500, 600, 600);
	}
}
