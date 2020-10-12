#include<iostream>
#include <cstring>
#include"play.h"
#include"person.h"
#include "Diner.h"

int main()
{
	char name[20];
	int height, weight;

	cout << "이름 : ";
	cin >> name;
	while (1)
	{
		cout << "키 : ";
		cin >> height;
		if (height > 40)
			break;
		else
			cout << "40보다 큰 값을 입력해주세요.\n" << endl;
	}
	while (1)
	{
		cout << "몸무게 : ";
		cin >> weight;
		if (weight > 10)
			break;
		else
			cout << "10보다 큰 값을 입력해주세요.\n" << endl;
	}
	person Sangjun(name, height, weight); // 이름, 키, 몸무게로 Person 클래스와 연결하기
	int ch1, ch2 = 0;

	cout << "워터파크에 입장했습니다. 입장료는 20000원입니다." << endl << endl;
	while (1)
	{
		cout << "할 일을 선택하세요." << endl;
		cout << "1. 물놀이 하기" << endl;
		cout << "2. 대여소 방문" << endl;
		cout << "3. 식사하기" << endl;
		cout << "4. 인적사항 보기" << endl;
		cout << "5. 사용시간 및 사용금액 확인" << endl;
		cout << "6. 워터파크 퇴장하기" << endl;
		cout << endl;

		cout << "입력 : ";
		cin >> ch1;
		ch2 = 0;

		cout << endl << endl;
		if (ch1 == 1)
		{
			while (1)
			{
				int time = 0;
				Sangjun.myplay.List();	//Sangjun의 캡슐화된 하위 클래스인 myplay 안의 List() 함수 호출
				cout << endl << "입력 : ";
				cin >> ch2;

				if (ch2 == 1)	//파도풀 선택시
					time = Sangjun.myplay.PlayPool(Sangjun.myborrow.GetState());
				//myborrow에 저장된 구명조끼나 튜브 착용여부를 저장하는 state 변수를 GetState로 가져와 매개변수로 넣어줌
				//(구명조끼나 튜브 착용여부를 검사하기 위함)
				//time은 PlayPool 함수에서 사용한 시간을 반환한 것을 받아서 저장함

				else if (ch2 == 2)	//유수풀 선택시
					time = Sangjun.myplay.PlayRiver();
				else if (ch2 == 3)	//슬라이드 선택시
					time = Sangjun.myplay.PlaySlide(Sangjun.GetHeight());	//키 검사를 위해 height를 매겨변수로 넣어줌
				else if (ch2 == 4)
					break;
				else
					cout << "1~4 범위의 숫자를 입력해주세요.\n\n" << endl;

				if (Sangjun.myborrow.GetState() == 1 || Sangjun.myborrow.GetState() == 3) //구명조끼 대여중일시
					Sangjun.myborrow.AddV_borrow_time(time);	//구명조끼 대여중인 시간 증가
				if (Sangjun.myborrow.GetState() == 2 || Sangjun.myborrow.GetState() == 3) //튜	브 대여중일시
					Sangjun.myborrow.AddT_borrow_time(time);	//튜브 대여중인 시간 증가
				Sangjun.myplay.AddPlay_time(time);
			}
		}

		else if (ch1 == 2)
		{
				Sangjun.myborrow.borrow_system();
		}

		else if (ch1 == 3)
		{
			Sangjun.myDiner.DinerMenu();
			Sangjun.myDiner.Drink();
			Sangjun.myDiner.DinerTime();
		}

		else if (ch1 == 4)
		{
			Sangjun.ShowPerson();
		}
		else if (ch1 == 5)
		{
			Sangjun.ShowTimeAndUse();
		}

		else if (ch1 == 6)
		{
			if (Sangjun.myborrow.GetState() >= 1) //구명조끼나 튜브를 대여중일 시
			{
				cout << "대여중인 물품이 있을시 퇴장이 불가능합니다." << endl;
				cout << "대여소에 가서 반납을 완료해주세요." << endl;
			}
			else
			{
				cout << "워터파크를 퇴장합니다." << endl;
				cout << "총 사용금액인 " << Sangjun.GetCost() << "원을 결제합니다." << endl;
				cout << "이용해주셔서 감사합니다." << endl;
				break;
			}
		}

		else
		{
			cout << "1~7 범위의 숫자를 입력해주세요." << endl;
		}

		cout << endl << endl;
	}
}