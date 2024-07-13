#include "mySceneManager.h"

namespace MyApp
{
	SceneManager::SceneManager()
	{
	}
	SceneManager::~SceneManager()
	{
	}
	void SceneManager::Initialize()
	{
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
	}
	void SceneManager::Render(HDC hdc)
	{
	}
}