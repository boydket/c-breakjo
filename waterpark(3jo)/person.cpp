#pragma once
#include<iostream>
#include "person.h"

using namespace std;
//키 받는 생성자

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
// 총 놀이기구 이용 시간

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

int person::GetWeight() //몸무게 반환
{
    return weight;
}

int person::GetHeight() //키 반환
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

void person::ShowPlayList()   //놀이기구 리스트 출력
{
    myplay.List();
}

void person::ShowPerson()
{
    cout << "이름 : " << name << endl;
    cout << "키 : " << height << "cm" << endl;
    cout << "몸무게 : " << weight << "kg" << endl;
}

void person::ShowTimeAndUse()   // 시간 및 사용금액 출력
{
    cout << "놀이시설 이용시간 : " << myplay.GetPlay_Time()/60 << "시간 " << myplay.GetPlay_Time()%60 << "분" << endl;
    cout << "식당 이용시간 : " << myDiner.GetDiner_Time()/60 << "시간 " << myDiner.GetDiner_Time() %60 << "분" << endl;
    cout << "구명조끼 대여중인시간 : " << myborrow.GetV_borrow_time()/60 << "시간 " << myborrow.GetV_borrow_time() % 60
        << "분" << endl;
    cout << "튜브 대여중인시간 : " << myborrow.GetT_borrow_time() / 60 << "시간 " << myborrow.GetT_borrow_time() % 60
        << "분" << endl;
    cost = myDiner.GetDiner_Cost() + myborrow.GetB_cost() + myplay.GetPlay_Cost() + 20000;
    cout << "총 이용금액 : " << cost << "원." << endl << endl;
}