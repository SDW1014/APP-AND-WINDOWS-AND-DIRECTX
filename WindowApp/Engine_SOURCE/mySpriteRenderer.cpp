#include "mySpriteRenderer.h"
#include "myGameObject.h"
#include "myTransform.h"
#include "myTexture.h"
namespace MyApp
{
	SpriteRenderer::SpriteRenderer()
		: Component()
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{


	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		// 텍스처가 없으면 오류를 발생시킵니다.
		if (mTexture == nullptr)
			assert(false);

		// 현재 게임 오브젝트의 Transform 컴포넌트를 가져옵니다.
		Transform* tr = GetOwner()->GetComponent<Transform>();
		// Transform에서 위치를 가져옵니다.
		Vector2 pos = tr->GetPosition();

		// 텍스처의 종류에 따라 다르게 렌더링합니다.
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			// 비트맵 텍스처를 렌더링합니다.
			TransparentBlt(hdc, pos.x, pos.y,
				mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y,
				mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(),
				RGB(255, 0, 255)); // 투명 색상 설정
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			// PNG 텍스처를 렌더링합니다.
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y,
					mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Jpg)
		{
			// JPG 텍스처를 렌더링합니다.
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y,
					mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}
		else
		{
			// 지원하지 않는 텍스처 타입입니다.
			assert(false);
		}
	}
}