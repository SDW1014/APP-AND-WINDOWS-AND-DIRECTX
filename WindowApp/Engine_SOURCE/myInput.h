#pragma once
#include "CommonInclude.h" //���� : CommonInclude���� Vector�� ����ϱ� ���ؼ�

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
		End,
	};

	// key�� ���´� Stay Down Up 3���� �������� ����������. 
	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;	// ������ Ű�� ��������
			eKeyState state;	// ������ Ű�� ���°� ��������
			bool bPressed;		// ������ Ű�� �����ִ���
		};

	private:
		//eKeyState mState; // 0 : Down, 1 : Pressed, 2 : Up, 3 : None
		static std::vector<Key> mKeys;	// Ű���� �����ϴ� �迭

		// ���� ���� ������ ���ؼ� ����
		// �ܺ� Ư�� main�Լ� �ۿ��� ����ϴ°� ��� ��ü�� �����ϰ� ����� ������ ���� �����̴�. 
		// �ٵ� Class���ο��� ������ static ������ �ܺο��� ����� �Ұ����ϴ�. 
		// �Ѹ���� Ŭ���� ���ο����� ����� ������ ���� �����̴�.
	};
}

