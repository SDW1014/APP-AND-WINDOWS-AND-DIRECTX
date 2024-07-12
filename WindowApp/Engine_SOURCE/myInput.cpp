#include "myInput.h"

namespace MyApp
{
	std::vector<Input::Key> Input::mKeys = {};

	void MyApp::Input::Initialize()
	{
	}

	void MyApp::Input::Update()
	{
	}

	bool MyApp::Input::GetKeyDown(eKeyCode code)
	{
		return false;
	}

	bool MyApp::Input::GetKeyUp(eKeyCode code)
	{
		return false;
	}

	bool MyApp::Input::GetKey(eKeyCode code)
	{
		return false;
	}
}
