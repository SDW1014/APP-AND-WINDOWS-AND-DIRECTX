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

		// ÇÃ·¹ÀÌ¾î
		//GameObject mPlayer;
		//
		BulletPlayerGameObject* mPlayer;

		// ÃÑ¾Ë Test
		//BulletGameObject mBullet;
		//std::vector<BulletGameObject> mBullets;
		
		// ÃÑ¾Ë 10°³
		BulletGameObject mBullets[10];
	};
}


