#include "myInput.h"

namespace MyApp
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
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
			// 키가 눌렸는지 아닌지
			// 키가 눌렸다
			if(GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;
				mKeys[i].bPressed = true;
			}
			else // 키가 눌리지 않았다
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;
				mKeys[i].bPressed = false;
			}
		}
	}
}
