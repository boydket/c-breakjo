#pragma once
#include <iostream>
using namespace std;

class Diner
{
private:
	int Diner_time;	// �Ĵ� �̿�ð�
	int Diner_cost;	// �Ĵ� �̿�ݾ�

public:
	Diner();
	int GetDiner_time();
	void DinerMenu();
	void Drink();
	void DinerTime();
	int GetDiner_Time();
	int GetDiner_Cost();
};

