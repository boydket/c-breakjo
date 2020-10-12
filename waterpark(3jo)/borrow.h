#pragma once

#include <iostream>
using namespace std;

class borrow {
private: // ����
	int height;			//Ű
	int weight;			//������
	int state;			//�ƹ��͵� ������ 0, �������� ������´� 1, Ʃ�� ������ 2, �� �� ������ 3			
	int vest_price;		//�������� ����
	int tube_price;		//Ʃ�� ����
	int v_borrow_time;	//�������� �뿩�ð�
	int t_borrow_time;	//Ʃ�� �뿩�ð�
	int b_cost;			//�� �뿩���

public: // �Լ�
	borrow();
	borrow(int height, int weight);
	int GetVest_price();
	int GetTube_price();
	int GetV_borrow_time();
	int GetT_borrow_time();
	int GetState();
	int GetB_cost();
	void Fixborrow(int height, int weight);
	void AddState(int value);	//���������� Ʃ�� ����� ����(state) ��ȭ��Ű�� �Լ�
	void SubState(int value);	//���������� Ʃ�� ������ ����(state) ��ȭ��Ű�� �Լ�
	void AddV_borrow_time(int time);	//�ð� �带�� �������� �뿩�ð��� �߰���ų �� ���� �Լ�
	void AddT_borrow_time(int time);	//�ð� �带�� Ʃ�� �뿩�ð��� �߰���ų �� ���� �Լ�
	void AddB_cost(int cost);	//�ݳ��� �� �뿩��뿡 �뿩����� �߰������ִ� �Լ�
	void borrow_system();		//�뿩��� ������ �Լ�
};