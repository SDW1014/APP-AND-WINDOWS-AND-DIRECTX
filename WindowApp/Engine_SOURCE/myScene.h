#pragma once
#include "CommonInclude.h"
#include "myEntity.h"
#include "myGameObject.h"

namespace MyApp
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
	private:
		std::vector<GameObject*> mGameObjects;
	};
}

