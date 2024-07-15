#include "myInput.h"
#include <algorithm>

namespace MyApp
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP
	};

	void MyApp::Input::Initialize()
	{
		//mKeys.resize((size_t)eKeyCode::End);

		for(size_t i = 0; i < (size_t)eKeyCode::End; i++)
		{
			Key key = {};

			key.keyCode = (eKeyCode)i;
			key.state = eKeyState::None;
			key.bPressed = false;

			mKeys.push_back(key);
		}
	}

	void MyApp::Input::Update()
	{
		for(size_t i = 0; i < mKeys.size(); i++)
		{
			// Ű�� ���ȴ��� �ƴ���
			// Ű�� ���ȴ�
			if(GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;
				mKeys[i].bPressed = true;
			}
			else // Ű�� ������ �ʾҴ�
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;
				mKeys[i].bPressed = false;
			}
		}
	}
	void Input::updateKeys()
	{
		std::for_each(mKeys.begin(), mKeys.end(), [](Key& key)-> void {
			updateKey(key);
		});
	}
	void Input::updateKey(Input::Key& key)
	{
		if(isKeyDown(key.keyCode))
		{
			updateKeyDown(key);
		}
		else
		{
			updateKeyUp(key);
		}
	}
	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}
	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Pressed;
		}
		else
		{
			key.state = eKeyState::Down;
		}
		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Up;
		}
		else
		{
			key.state = eKeyState::None;
		}
		key.bPressed = false;
	}
}
