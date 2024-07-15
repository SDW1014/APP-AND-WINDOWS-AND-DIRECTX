#pragma once

// Windows API
#include <Windows.h>  // Windows API를 사용하기 위한 헤더 파일

// Standard Template Library (STL)
#include <vector>     // 동적 배열을 사용하기 위한 STL 컨테이너
#include <algorithm>  // STL 알고리즘 함수를 사용하기 위한 헤더 파일
#include <string>     // 문자열 처리를 위한 STL 문자열 클래스
#include <map>        // 키-값 쌍의 연관 컨테이너인 맵을 사용하기 위한 STL 컨테이너

// User-defined Libraries
#include "myMath.h"   // 사용자 정의 수학 라이브러리 헤더 파일

// Multimedia
#include <mmsystem.h> // 멀티미디어 타이머와 오디오 재생을 위한 헤더 파일
#pragma comment(lib, "winmm.lib")    // 멀티미디어 함수를 사용하기 위한 Windows 라이브러리

// Input Handling
#include <dinput.h>   // DirectInput을 사용하여 입력 장치를 처리하기 위한 헤더 파일

// Graphics
#include <gdiplus.h>  // GDI+를 사용하여 2D 그래픽을 그리기 위한 헤더 파일
#pragma comment(lib, "gdiplus.lib")  // GDI+ 라이브러리를 링크하기 위한 pragma 지시문
#pragma comment(lib, "Msimg32.lib")  // 이미지 처리를 위한 Windows 라이브러리

// GDI+는 Windows에서 2D 그래픽을 그리기 위한 API입니다.
// GDI+를 사용하면 선, 도형, 텍스트, 이미지 등을 쉽게 그릴 수 있습니다.
// 또한 그라데이션, 투명도, 안티앨리어싱 등의 효과도 적용할 수 있습니다.
// Windows 프로그래밍에서 그래픽 처리를 위해 널리 사용되는 라이브러리입니다.
