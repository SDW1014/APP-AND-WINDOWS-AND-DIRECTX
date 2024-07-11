#include "myGameObject.h"

namespace MyApp
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::setPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}
	float GameObject::GetpositionX()
	{
		return mX;
	}
	float GameObject::GetpositionY()
	{
		return mY;
	}
}