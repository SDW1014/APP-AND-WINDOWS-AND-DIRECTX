 // Start of Selection
#include "myCollider.h"
#include "myGameObject.h"
#include "myScript.h"

namespace MyApp
{
	UINT Collider::CollisionID = 1;

	Collider::Collider()
		: Component(enums::eComponentType::Colider)
		, mID(CollisionID++)
		, mSize(Vector2::One)
	{

	}

	Collider::~Collider()
	{
	}

	void Collider::Initialize()
	{
	}

	void Collider::Update()
	{
	}

	void Collider::LateUpdate()
	{
	}

	void Collider::Render(HDC hdc)
	{
	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(other);
	}

	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionExit(other);
	}
}
