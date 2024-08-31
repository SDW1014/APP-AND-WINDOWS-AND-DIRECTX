#include "myDestroy.h"
#include "myGameObject.h" // GameObject의 정의가 포함되어야 합니다.

namespace MyApp::object
{
	void Destroy(GameObject* obj)
	{
		obj->Death(); // 이제 obj가 완전한 타입이므로 호출 가능
	}
}