#pragma once
#include "CommonInclude.h" //목적 : CommonInclude안의 Vector를 사용하기 위해서

namespace MyApp
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Up, Down,
		End,
	};

	// key의 상태는 Stay Down Up 3가지 유형으로 나뉘어진다. 
	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;	// 눌려진 키가 무엇인지
			eKeyState state;	// 눌려진 키의 상태가 무엇인지
			bool bPressed;		// 눌려진 키가 눌려있는지
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; };
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; };
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; };
	private:
		//eKeyState mState; // 0 : Down, 1 : Pressed, 2 : Up, 3 : None
		static std::vector<Key> mKeys;	// 키들을 저장하는 배열

		// 간단 정적 변수에 대해서 설명
		// 외부 특히 main함수 밖에서 사용하는건 모든 객체가 공유하고 사용이 가능한 정적 변수이다. 
		// 근데 Class내부에서 정의한 static 변수는 외부에서 사용이 불가능하다. 
		// 한마디로 클래스 내부에서만 사용이 가능한 정적 변수이다.

		// private에서는 시작을 대문자로 하지 않는다. 
		static void updateKeys();
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Input::Key& key);
	};
}

