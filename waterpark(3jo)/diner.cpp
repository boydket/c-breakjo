#include "Diner.h"

Diner::Diner() {
	Diner_time = 0;
	Diner_cost = 0;
}

void Diner::DinerMenu()    //메뉴 선정 (번호로 메뉴를 선택)
{
	char OtherChoice;	//음식 추가여부 
	while (1)
	{
		cout << " -----------------------------" << endl;
		cout << "|             MENU            |" << endl;
		cout << "|                             |" << endl;
		cout << "|     1. 햄버거 - 5000원      |" << endl;
		cout << "|     2. 핫도그 - 3000원      |" << endl;
		cout << "|     3. 떡볶이 - 3000원      |" << endl;
		cout << "|     4. 김  밥 - 2500원      |" << endl;
		cout << "|     5. 추로스 - 2000원      |" << endl;
		cout << "|                             |" << endl;
		cout << "|     음료수 - 1000원      |" << endl;
		cout << "|     6. 이전으로             |" << endl;
		cout << " -----------------------------" << endl;

		int DinerNum = 0;
		cout << "어떤 메뉴를 드시겠습니까? : " << endl;
		cin >> DinerNum;

			if (DinerNum == 1)
			{
				cout << "햄버거를 드시겠습니까?" << endl;
				cout << "햄버거는 5000원입니다." << endl;
				cout << "음식은 식당 내에서 드시면 됩니다." << endl;
				Diner_cost += 5000;
			}
			else if (DinerNum == 2)
			{
				cout << "핫도그를 드시겠습니까?" << endl;
				cout << "핫도그는 3000원입니다." << endl;
				cout << "음식은 식당 내에서 드시면 됩니다." << endl;
				Diner_cost += 3000;
			}
			else if (DinerNum == 3)
			{
				cout << "떡볶이를 드시겠습니까?" << endl;
				cout << "떡볶이는 3000원입니다." << endl;
				cout << "음식은 식당 내에서 드시면 됩니다." << endl;
					Diner_cost += 3000;
			}
			else if (DinerNum == 4)
			{
				cout << "김밥을 드시겠습니까?" << endl;
				cout << "김밥은 2500원입니다." << endl;
				cout << "음식은 식당 내에서 드시면 됩니다." << endl;
				Diner_cost += 2500;
			}
			else if (DinerNum == 5)
			{
				cout << "추로스를 드시겠습니까?" << endl;
				cout << "추로스는 2000원입니다." << endl;
				cout << "음식은 식당 내에서 드시면 됩니다." << endl;
				Diner_cost += 2000;
			}
			else if (DinerNum == 6)
			{
				return;
			}
			else {
				cout << "잘못 입력하셨습니다." << endl;
				cout << "1~5번 중 하나의 번호를 입력해주세요." << endl << endl;
				continue;
			}
			
		while (1)
		{
			cout << "다른 메뉴를 추가하시겠습니까? (Y/N)" << endl;    //다른 메뉴 추가 선택
			cin >> OtherChoice;
			if (OtherChoice == 'Y' || OtherChoice == 'y'
				 || OtherChoice == 'N' || OtherChoice == 'n')
				break;	//y또는 n 입력시 정상적인 입력을 한 것이므로 while문  탈출
			else 
			{
				cout << "잘못 입력하셨습니다." << endl;
				cout << "Y/N중 하나를 입력해주세요." << endl << endl;
			}
		}
		if (OtherChoice == 'Y' || OtherChoice == 'y')
			continue;	//y 입력시 13번째 줄의 메뉴 출력으로 돌아가서 추가 주문함
		else
		{
			break;	//n 입력시 탈출
			cout << endl << endl;
		}
	}
};
void Diner::Drink()     //음료수 추가
{
	while (1) {
		char DrinkChoice;
		cout << "음료수를 추가하시겠습니까? (Y/N)" << endl;
		cin >> DrinkChoice;
		if (DrinkChoice == 'Y' || DrinkChoice == 'y' || DrinkChoice == 'N'
			 || DrinkChoice == 'n') 
		{
			switch (DrinkChoice) 
			{
			case 'Y':
			case 'y':
				cout << "음료수는 1000원입니다. " << endl;
				cout << "음료수는 디스펜서에서 이용하시면 됩니다." << endl;
				Diner_cost += 1000;
				break;
			case 'N':
			case 'n':
				break;
			default:
				break;
			}
			cout << endl << endl;
			return;
		}
		else {
			cout << "잘못 입력하셨습니다." << endl;
			cout << "Y/N중 하나를 입력해주세요." << endl << endl;
		}
	}
};

void Diner::DinerTime()     //식당을 이용할 시간을 분 단위로 입력
{
	int time;
	while (1)
	{
		cout << "식당을 이용하실 시간(분)을 입력해주세요." << endl;
		cin >> time;
		if (time > 0)
			break;
		else
			cout << "0보다 큰 수를 입력해주세요." << endl << endl;
	}
	cout << "식당 이용 시간 " << time << "분 입력하셨습니다." << endl;
	cout << "즐거운 식사 시간 되십시오." << endl << endl;
	cout << endl;
	Diner_time += time;
};

int Diner::GetDiner_Time() { return Diner_time; } // 식당 이용 시간 반환
int Diner::GetDiner_Cost() { return Diner_cost; } // 식당 이용 금액 반환