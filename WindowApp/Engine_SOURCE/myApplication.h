#pragma once
#include "CommonInclude.h"
#include "myGameObject.h"
#include "myBulletPlayerGameObject.h"
#include "myBulletGameObject.h"

namespace MyApp
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		// �÷��̾�
		//GameObject mPlayer;
		//
		BulletPlayerGameObject* mPlayer;

		// �Ѿ� Test
		//BulletGameObject mBullet;
		//std::vector<BulletGameObject> mBullets;
		
		// �Ѿ� 10��
		BulletGameObject mBullets[10];
	};
}


