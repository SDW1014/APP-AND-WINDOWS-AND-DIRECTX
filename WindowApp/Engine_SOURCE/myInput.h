#pragma once
#include "CommonInclude.h" //목적 : CommonInclude안의 Vector를 사용하기 위해서

namespace MyApp
{
	enum eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	// key의 상태는 Stay Down Up 3가지 유형으로 나뉘어진다. 
	class Input
	{
	public:
	private:
		//eKeyState mState; // 0 : Down, 1 : Pressed, 2 : Up, 3 : None
	};
}

