#pragma once
#include <iostream>
#include "play.h"
#include "Diner.h"
#include "borrow.h"

class person
{
private:
    int state;  //�ƹ��͵� ������ 0, �������� ������´� 1, Ʃ�� ������ 2, �� �� ������ 3
    int cost;
    char name[20];
    int height;     //Ű
    int weight;     //������

public:
    play myplay;
    Diner myDiner;
    borrow myborrow;
    person(); 
    person(char name[], int height, int weight);   // Ű�� �����Ը� �޴� ������
    void AddCost(int cost);
    
    //������� ��ȯ�ϴ� Get �Լ���
    play GetPlay();
    Diner GetDinner();
    borrow GetBorrow();
    int GetHeight();
    int GetWeight();
    int GetState();
    int GetCost();

    // Play (���̱ⱸ)
    void ShowPlayList();   //���̱ⱸ ����Ʈ ���
  

    void ShowPerson();  //�������� ���
    void ShowTimeAndUse();  //�̿�ð� �� �̿�ݾ� ���
    // cost(���)
};