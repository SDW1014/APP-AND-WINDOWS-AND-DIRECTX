# DC란 무엇인가?

디바이스 컨텍스트(DC)는 화면에 그리기 위한 정보를 가지고 있으며, 도형, 텍스트, 이미지를 렌더링하는 작업을 통해 복잡한 그래픽 작업을 쉽게 처리할 수 있게 해줍니다.

## 중요한 포인트
1. 가장 중요한 건, 자신이 필요한 부분만 캐치하는 것이다.
2. MyRegisterClass 부분에서 설정을 어찌 하냐를 기억하고 있는 것.

## DC 관련 요소
- **Rectangle**: 사각형 그리기
- **Ellipse**: 타원 그리기
- **HBRUSH**: 브러시 핸들
- **oldBrush**: 이전 브러시 핸들
- **DeleteObject**: 객체 삭제
- **hpen**: 펜 핸들
- **oldpen**: 이전 펜 핸들

## 생성 및 삭제 개념
- 생성 -> 삭제의 개념이 중요하다.
