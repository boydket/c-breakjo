#pragma once
#include <iostream>
#include "play.h"
#include "Diner.h"
#include "borrow.h"

class person
{
private:
    int state;  //아무것도 없으면 0, 구명조끼 착용상태는 1, 튜브 착용은 2, 둘 다 착용은 3
    int cost;
    char name[20];
    int height;     //키
    int weight;     //몸무게

public:
    play myplay;
    Diner myDiner;
    borrow myborrow;
    person(); 
    person(char name[], int height, int weight);   // 키와 몸무게를 받는 생성자
    void AddCost(int cost);
    
    //멤버변수 반환하는 Get 함수들
    play GetPlay();
    Diner GetDinner();
    borrow GetBorrow();
    int GetHeight();
    int GetWeight();
    int GetState();
    int GetCost();

    // Play (놀이기구)
    void ShowPlayList();   //놀이기구 리스트 출력
  

    void ShowPerson();  //인적사항 출력
    void ShowTimeAndUse();  //이용시간 및 이용금액 출력
    // cost(비용)
};