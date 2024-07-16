#pragma once
// 1. 운영체제 및 하드웨어 관련
#include <Windows.h>
#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib");
#pragma comment(lib, "winmm.lib");

// 2. 그래픽스 및 멀티미디어
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib");

// 3. 수학 및 알고리즘
#include "myMath.h"

// 4. STL 라이브러리
#include <vector>
#include <algorithm>
#include <string>
#include <map>

// 5. 사용자 정의 열거형
#include "myEnums.h"