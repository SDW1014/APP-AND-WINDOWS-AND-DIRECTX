#include "myInput.h"
#include <algorithm>

namespace MyApp
{
	// Input 클래스의 정적 멤버 변수로 모든 키의 상태를 저장합니다.
	std::vector<Input::Key> Input::mKeys = {};

	// ASCII 코드와 키 코드의 매핑을 정의합니다.
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP
	};

	// Input 클래스의 초기화 함수입니다.
	void MyApp::Input::Initialize()
	{
		// 모든 키의 상태를 초기화합니다.
		for(size_t i = 0; i < (size_t)eKeyCode::End; i++)
		{
			Key key = {};

			key.keyCode = (eKeyCode)i; // 키 코드를 설정합니다.
			key.state = eKeyState::None; // 초기 상태를 None으로 설정합니다.
			key.bPressed = false; // 누름 상태를 초기화합니다.

			mKeys.push_back(key); // 키 상태 벡터에 추가합니다.
		}
	}

	// 입력 상태를 업데이트하는 함수입니다.
	void MyApp::Input::Update()
	{
		// 모든 키에 대한 입력 상태를 업데이트합니다.
		for(size_t i = 0; i < mKeys.size(); i++)
		{
			// 키가 누름 상태인지 확인합니다.
			if(GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// 키가 누름 상태이면 상태를 업데이트합니다.
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;
				mKeys[i].bPressed = true; // 누름 상태를 true로 설정합니다.
			}
			else // 키가 누름 상태가 아니면
			{
				// 키가 누름 상태에서 해제된 경우 상태를 업데이트합니다.
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;
				mKeys[i].bPressed = false; // 누름 상태를 false로 설정합니다.
			}
		}
	}
	// 모든 키의 상태를 업데이트하는 함수입니다.
	void Input::updateKeys()
	{
		// 모든 키에 대한 상태 업데이트를 수행합니다.
		std::for_each(mKeys.begin(), mKeys.end(), [](Key& key)-> void {
			updateKey(key);
		});
	}
	// 단일 키의 상태를 업데이트하는 함수입니다.
	void Input::updateKey(Input::Key& key)
	{
		// 키가 누름 상태인지 확인합니다.
		if(isKeyDown(key.keyCode))
		{
			// 키가 누름 상태이면 누름 상태 업데이트를 수행합니다.
			updateKeyDown(key);
		}
		else
		{
			// 키가 누름 상태가 아니면 해제 상태 업데이트를 수행합니다.
			updateKeyUp(key);
		}
	}
	// 키가 누름 상태인지 확인하는 함수입니다.
	bool Input::isKeyDown(eKeyCode code)
	{
		// 키의 누름 상태를 확인합니다.
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}
	// 키가 누름 상태일 때 상태를 업데이트하는 함수입니다.
	void Input::updateKeyDown(Input::Key& key)
	{
		// 키가 이미 누름 상태이면 누름 상태로 유지합니다.
		if (key.bPressed == true)
		{
			key.state = eKeyState::Pressed;
		}
		else
		{
			// 키가 처음 누름 상태가 되면 Down 상태로 설정합니다.
			key.state = eKeyState::Down;
		}
		key.bPressed = true; // 누름 상태를 true로 설정합니다.
	}
	// 키가 해제 상태일 때 상태를 업데이트하는 함수입니다.
	void Input::updateKeyUp(Input::Key& key)
	{
		// 키가 누름 상태에서 해제된 경우 Up 상태로 설정합니다.
		if (key.bPressed == true)
		{
			key.state = eKeyState::Up;
		}
		else
		{
			// 키가 해제 상태이면 None 상태로 설정합니다.
			key.state = eKeyState::None;
		}
		key.bPressed = false; // 누름 상태를 false로 설정합니다.
	}
}
