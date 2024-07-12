#include "myTime.h"

namespace MyApp
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTime = 0.0f;

	void Time::Initialize()
	{
		// 나의 CPU의 고유 진동수를 가져온다.
		QueryPerformanceFrequency(&CpuFrequency);
		
		// 이전 시간을 가져온다.
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		// 이전 시간과 현재 시간의 차이를 구한다.
		float diffrenctFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTime = diffrenctFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTime;

		wchar_t str[50] = L"";

		swprintf_s(str, 50,  L"Time : %f", time);

		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}


