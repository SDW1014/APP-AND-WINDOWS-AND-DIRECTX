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

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
	private:
		std::vector<GameObject*> mGameObjects;
	};
}

