#pragma once
#include "CommonInclude.h"

// �ð��� ���� : ���� 133 ������ 9,192,631,770���� ������ 1�ʷ� �����Ѵ�.
// �׷��ٸ� ��ǻ�Ϳ����� ��� �ð��� �����ұ�? 
// Ghz : 10����� ������ 1�ʷ� �����Ѵ�.

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



