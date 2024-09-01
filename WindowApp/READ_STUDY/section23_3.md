# 충돌 처리 개요

## 레이어 구조를 통한 충돌 로직 개요
- 충돌의 세 가지 상태: 
  - 충돌 시작 (OnCollisionEnter)
  - 충돌 중 (OnCollisionStay)
  - 충돌 종료 (OnCollisionExit)

## 충돌체 ID 관리
- 각 충돌체에 고유 ID 부여
- 유니온을 사용한 데이터 관리

## 충돌 체크 로직
- AABB(축 정렬 경계 상자) 알고리즘 구현
- 충돌 체크 및 상태 관리

## 충돌 상태별 처리
- 충돌 시작 시 (OnCollisionEnter)
- 충돌 중 (OnCollisionStay)
- 충돌 종료 시 (OnCollisionExit)

## 실습: 충돌 로직 구현
- 코드 구현 예제
- 충돌 시 오브젝트 위치 변경 예시

## 다음 시간 예고
- 원과 원 사이의 충돌 처리 예정