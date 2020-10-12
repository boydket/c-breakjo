#pragma once

#include <iostream>
using namespace std;

class borrow {
private: // 변수
	int height;			//키
	int weight;			//몸무게
	int state;			//아무것도 없으면 0, 구명조끼 착용상태는 1, 튜브 착용은 2, 둘 다 착용은 3			
	int vest_price;		//구명조끼 가격
	int tube_price;		//튜브 가격
	int v_borrow_time;	//구명조끼 대여시간
	int t_borrow_time;	//튜브 대여시간
	int b_cost;			//총 대여비용

public: // 함수
	borrow();
	borrow(int height, int weight);
	int GetVest_price();
	int GetTube_price();
	int GetV_borrow_time();
	int GetT_borrow_time();
	int GetState();
	int GetB_cost();
	void Fixborrow(int height, int weight);
	void AddState(int value);	//구명조끼나 튜브 착용시 상태(state) 변화시키는 함수
	void SubState(int value);	//구명조끼나 튜브 해제시 상태(state) 변화시키는 함수
	void AddV_borrow_time(int time);	//시간 흐를시 구명조끼 대여시간을 추가시킬 때 쓰는 함수
	void AddT_borrow_time(int time);	//시간 흐를시 튜브 대여시간을 추가시킬 때 쓰는 함수
	void AddB_cost(int cost);	//반납시 총 대여비용에 대여비용을 추가시켜주는 함수
	void borrow_system();		//대여기능 구현한 함수
};