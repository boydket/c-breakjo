#pragma once
#include<iostream>
using namespace std;

class play
{
private:

	int play_time;      //놀이기구 이용시간
	int play_cost;      //놀이기구 이용금액

public:
	play();
	void List();			//놀이시설 리스트
	int PlayPool(int state);		//파도풀 이용
	int PlayRiver();		//유수풀 이용
	int PlaySlide(int height);	//워터슬라이드 이용
	int GetPlay_Time();
	int GetPlay_Cost();
	void AddPlay_time(int time);
};
