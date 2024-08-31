#pragma once
#include "myEntity.h"
#include "CommonInclude.h"
#include "myGameObject.h"

namespace MyApp
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);

	private:
		void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		void deleteGameObjects(std::vector<GameObject*> gameObjs);
		void eraseGameObject();

	private:
		std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}
