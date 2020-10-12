#pragma once
#include<iostream>
#include "person.h"

using namespace std;
//Ű �޴� ������

person::person() 
{
    height = 0;
    weight = 0;
    state = 0;
    cost = 20000;
}

person::person(char name[], int height, int weight)
{
    strcpy(this->name, name);
    this->height = height;
    this->weight = weight;
    myborrow.Fixborrow(height, weight);
    state = 0;
    cost = 20000;
}
// �� ���̱ⱸ �̿� �ð�

void person::AddCost(int cost)
{
    this->cost += cost;
}

play person::GetPlay()
{
    return myplay;
}

Diner person::GetDinner()
{
    return myDiner;
}

borrow person::GetBorrow()
{
    return this->myborrow;
}

int person::GetWeight() //������ ��ȯ
{
    return weight;
}

int person::GetHeight() //Ű ��ȯ
{
    return height;
}

int person::GetState()
{
    return state;
}

int person::GetCost()
{
    return cost;
}

void person::ShowPlayList()   //���̱ⱸ ����Ʈ ���
{
    myplay.List();
}

void person::ShowPerson()
{
    cout << "�̸� : " << name << endl;
    cout << "Ű : " << height << "cm" << endl;
    cout << "������ : " << weight << "kg" << endl;
}

void person::ShowTimeAndUse()   // �ð� �� ���ݾ� ���
{
    cout << "���̽ü� �̿�ð� : " << myplay.GetPlay_Time()/60 << "�ð� " << myplay.GetPlay_Time()%60 << "��" << endl;
    cout << "�Ĵ� �̿�ð� : " << myDiner.GetDiner_Time()/60 << "�ð� " << myDiner.GetDiner_Time() %60 << "��" << endl;
    cout << "�������� �뿩���νð� : " << myborrow.GetV_borrow_time()/60 << "�ð� " << myborrow.GetV_borrow_time() % 60
        << "��" << endl;
    cout << "Ʃ�� �뿩���νð� : " << myborrow.GetT_borrow_time() / 60 << "�ð� " << myborrow.GetT_borrow_time() % 60
        << "��" << endl;
    cost = myDiner.GetDiner_Cost() + myborrow.GetB_cost() + myplay.GetPlay_Cost() + 20000;
    cout << "�� �̿�ݾ� : " << cost << "��." << endl << endl;
}