#include "borrow.h"
#include <iostream>

borrow::borrow()
{
    height = 0;			//키
    weight = 0;			//몸무게
    state = 0;			//아무것도 없으면 0, 구명조끼 착용상태는 1, 튜브 착용은 2, 둘 다 착용은 3			
    vest_price = 0;		//구명조끼 가격
    tube_price = 0;		//튜브 가격
    v_borrow_time = 0;	//구명조끼 대여시간
    t_borrow_time = 0;	//튜브 대여시간
    b_cost = 0;			//총 대여비용
}

void borrow::Fixborrow(int height, int weight)
{
    this->height = height;
    this->weight = weight;
}

int borrow::GetVest_price()
{
    return this->vest_price;
}

int borrow::GetTube_price()
{
    return this->tube_price;
}

int borrow::GetV_borrow_time()
{
    return this->v_borrow_time;
}

int borrow::GetT_borrow_time()
{
    return this->t_borrow_time;
}

int borrow::GetState()
{
    return this->state;
}

int borrow::GetB_cost()
{
    return b_cost;
}

void borrow::AddState(int value)
{
    this->state += value;
}

void borrow::SubState(int value)
{
    this->state -= value;
}

void borrow::AddV_borrow_time(int time)
{
    v_borrow_time += time;
}

void borrow::AddT_borrow_time(int time)
{
    t_borrow_time += time;
}

void borrow::AddB_cost(int cost)
{
    b_cost += cost;
}

void borrow::borrow_system()
{
    int selection;  //하고싶은 행동을 저장할 변수
    int cost;       //발생하는 대여료를 임시로 저장할 변수
    cout << "대여소에 방문했습니다." << endl << endl;
    while (1)
    {
        
        cout << "1. 구명조끼 대여" << endl;
        cout << "2. 튜브 대여" << endl;
        cout << "3. 구명조끼 반납" << endl;
        cout << "4. 튜브 반납" << endl;
        cout << "5. 이전으로 돌아가기" << endl;

        cout << endl << "입력 : ";
        cin >> selection;
        cout << endl << endl;
        //구명조끼는 1번, 튜브는 2번으로 받아 selection에 넣음.

        if (selection == 1) //구명조끼를 선택
        {
            if (state == 1 || state == 3)
            {
                cout << "이미 구명조끼를 대여중입니다.\n\n\n" << endl;
                continue;
            }

            cout << height << "cm입니다." << endl;

            if (height <= 140) //키 140cm이하면 구명조끼 소형
            {
                cout << "구명조끼 소형을 대여하셨습니다." << endl;
                vest_price = 3000; //1시간에 3000원

            }
            else if (140 < height < 165)//키 140초과, 165미만이면 구명조끼 중형
            {
                cout << "구명조끼 중형을 대여하셨습니다." << endl;
                vest_price = 4000; //1시간에 4000원
            }
            else if (height >= 165)//키 165cm이상이면 구명조끼 소형
            {
                cout << "구명조끼 대형을 대여하셨습니다." << endl;
                vest_price = 5000; //1시간에 5000원
            }
            cout << "대여료는 시간당 " << vest_price << "원 입니다." << endl;
            state += 1;  //state의 값에 1 추가
        }

        else if (selection == 2) //튜브를 선택
        {
            if (state == 2 || state == 3)
            {
                cout << "이미 튜브를 대여중입니다.\n\n\n" << endl;
                continue;
            }

            cout << weight << "kg입니다." << endl;

            if (weight <= 50) //몸무게 50kg이하면 튜브 소형
            {
                cout << "튜브 소형을 대여하셨습니다." << endl;
                tube_price = 3000;  //1시간에 3000원

            }
            else if (50 < weight < 70)//몸무게 50kg초과, 70kg미만이면 튜브 중형
            {
                cout << "튜브 중형을 대여하셨습니다." << endl;
                tube_price = 4000;  //1시간에 4000원
            }
            else if (weight >= 70)  //몸무게 70kg이상이면 튜브 대형
            {
                cout << "튜브 대형을 대여하셨습니다." << endl;
                tube_price = 5000;  //1시간에 5000원
            }
            cout << "대여료는 시간당 " << tube_price << "원 입니다." << endl;
            state += 2;  //state의 값에 2 추가
        }

        else if (selection == 3)
        {
            if (state == 1 || state == 3)   //구명조끼를 착용했는지 확인
            {
                cout << "구명조끼를 반납합니다." << endl;
                cost = vest_price * ((v_borrow_time / 60) + 1);
                cout << v_borrow_time << "분을 대여했습니다." << endl;
                cout << "대여료는 " << cost << "원입니다." << endl;
                state -= 1; //state 값에 1 빼줌
                v_borrow_time = 0;  //반납했으므로 대여시간 0
                b_cost += cost;     //총 대여비용에 지금 발생한 대여비용 추가
            }
            else
            {
                cout << "구명조끼를 대여하고 있지 않습니다." << endl;
            }
        }

        else if (selection == 4)
        {
            if (state == 2 || state == 3) //튜브 착용했는지 확인
            {
                cout << "튜브를 반납합니다." << endl;
                cost = tube_price * ((t_borrow_time / 60) + 1);
                cout << t_borrow_time << "분을 대여했습니다." << endl;
                cout << "대여료는 " << cost << "원입니다." << endl;
                state -= 2; //state 값에 2 빼줌
                t_borrow_time = 0;  //반납했으므로 대여시간 0
                b_cost += cost; //총 대여비용에 지금 발생한 대여비용 추가
            }

            else
            {
                cout << "튜브를 대여하고 있지 않습니다." << endl;
            }
        }

        else if (selection == 5)
            return;

        cout << "\n\n\n" << endl;
    }
}