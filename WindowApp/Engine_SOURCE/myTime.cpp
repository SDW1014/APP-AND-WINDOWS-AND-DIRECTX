#include "myTime.h"

namespace MyApp
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		// ���� CPU�� ���� �������� �����´�.
		QueryPerformanceFrequency(&CpuFrequency);
		
		// ���� �ð��� �����´�.
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		// ���� �ð��� ���� �ð��� ���̸� ���Ѵ�.
		float diffrenctFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = diffrenctFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		// fps�� ������.
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";

		swprintf_s(str, 50, L"FPS : %d", static_cast<int>(fps));

		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}


