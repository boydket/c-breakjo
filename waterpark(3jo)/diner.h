#pragma once
#include <iostream>
using namespace std;

class Diner
{
private:
	int Diner_time;	// 식당 이용시간
	int Diner_cost;	// 식당 이용금액

public:
	Diner();
	int GetDiner_time();
	void DinerMenu();
	void Drink();
	void DinerTime();
	int GetDiner_Time();
	int GetDiner_Cost();
};

