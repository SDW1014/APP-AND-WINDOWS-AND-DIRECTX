#pragma once

namespace MyApp
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void setPosition(float x, float y);
		float GetpositionX();
		float GetpositionY();


	private:
		// ���� ������Ʈ�� ��ǥ
		float mX;
		float mY;
	};
}


