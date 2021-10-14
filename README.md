# OS_2
top, ps, lscpu 명령어와 유사한 결과 출력하는 mytop, myps, mylscpu 명령어 구현

1. 과제 목표
  * system 함수 or exec계열 함수를 사용하지 않고 직접 기능 구현하기
  * 리눅스 top, ps와 최대한 유사한 결과를 출력하는 mytop, myps 명령어 구현하기
  * CPU VendorID, CPU 모델명, CPU 속도, 캐쉬크기(L1i, L1d, L2캐쉬)를 출력하는 mylscpu명령어 구현하기
  
2. 기본 지식
  * top, ps, lscpu 명령어의 기능, 출력되는 결과가 무슨 뜻인지
  
3. 구현한 것
  * mytop
  * myps
  * mylscpu - CPU VendorID, CPU모델명, CPU 속도, 캐쉬크기(L1i,L1d,L2,L3), Address size, Flags
