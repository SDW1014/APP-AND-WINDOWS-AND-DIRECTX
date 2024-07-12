#pragma once
#include "CommonInclude.h"

// 시간의 정의 : 세슘 133 원자의 9,192,631,770번의 진동을 1초로 정의한다.
// 그렇다면 컴퓨터에서는 어떻게 시간을 측정할까? 
// Ghz : 10억번의 진동을 1초로 정의한다.

namespace MyApp
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTime;
	};
}



