#include "myTime.h"

namespace MyApp
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTime = 0.0f;

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

		DeltaTime = diffrenctFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
}


