#pragma once
#include<iostream>
using namespace std;

class play
{
private:

	int play_time;      //���̱ⱸ �̿�ð�
	int play_cost;      //���̱ⱸ �̿�ݾ�

public:
	play();
	void List();			//���̽ü� ����Ʈ
	int PlayPool(int state);		//�ĵ�Ǯ �̿�
	int PlayRiver();		//����Ǯ �̿�
	int PlaySlide(int height);	//���ͽ����̵� �̿�
	int GetPlay_Time();
	int GetPlay_Cost();
	void AddPlay_time(int time);
};
