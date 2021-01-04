#include <iostream>
#include "aircondition.h"
#include "iron.h"
#include "microwave.h"
#include "tv.h"

using namespace std;

int main(void)
{
	int ch1=0, ch2=0;	//번호 입력받을 변수들
	int wh;	//소비전력 입력받을 변수
	char list[4][20] = {"에어컨", "전기다리미", "전자레인지", "TV"};





	cout << "4개의 전자제품의 소비전력을 입력해주세요.\n" << endl;
	while(1)
	{
		cout << "에어컨 소비전력(단위:Wh) : ";
		cin >> wh;

		if(wh>0)
			break;
		cout << "0 이상의 숫자를 입력해주세요." << endl;
	}
	Aircon aircon(wh);

	while(1)
	{
		cout << "전기다리미 소비전력(단위:Wh) : ";
		cin >> wh;

		if(wh>0)
			break;
		cout << "0 이상의 숫자를 입력해주세요." << endl;
	}
	Iron iron(wh);

	while(1)
	{
		cout << "전자레인지 소비전력(단위:Wh) : ";
		cin >> wh;

		if(wh>0)
			break;
		cout << "0 이상의 숫자를 입력해주세요." << endl;
	}
	Microwave micro(wh);

	while(1)
	{
		cout << "TV 소비전력(단위:Wh) : ";
		cin >> wh;

		if(wh>0)
			break;
		cout << "0 이상의 숫자를 입력해주세요." << endl;
	}
	TV tv(wh);

	cout << "\n\n\n\n\n";







	while(1)
	{
		cout << "1. 에어컨" << endl;
		cout << "2. 전기다리미" << endl;
		cout << "3. 전자레인지" << endl;
		cout << "4. TV\n\n" << endl;
		cout << "번호 입력 : ";
		cin >> ch1;
		cout << "\n\n\n";
		if (ch1>=1 && ch1<=4)
			cout << list[ch1-1] << "을 선택했습니다.\n\n";

		cout << "\n\n\n";

		while(ch1==1 && ch2!=10)
		{

			cout << "-----------------에어컨------------------" << endl;
			cout << "1. 전원 조작" << endl;
			cout << "2. 온도 증가" << endl;
			cout << "3. 온도 감소" << endl;
			cout << "4. 바람세기 증가" << endl;
			cout << "5. 바람세기 감소" << endl;
			cout << "6. 풍향 증가" << endl;
			cout << "7. 풍향 감소" << endl;
			cout << "8. 현재 설정 확인" << endl;
			cout << "9. 소비전력, 사용시간, 전력소비량 확인" << endl;
			cout << "10. 이전으로" << endl;
			cout << "------------------------------------------\n\n" << endl;
			cout << "번호 입력 : ";
			cin >> ch2;

			cout << "\n\n\n";

			aircon.Time_Calculation();	//반복적으로 실행되서 실행시간을 계산해줌, 다른 제품들도 마찬가지.

			if(ch2==1 && aircon.GetState()==ON)	//전원 켜져있을시 끄기
				aircon.Off();
			else if(ch2==1 && aircon.GetState()==OFF)	//전원 꺼져있을시 켜기
				aircon.On();
			else if(ch2>=2 && ch2<=7 && aircon.GetState()==ON)	//에어컨 기능 조작
			{
				if(ch2==2)
					aircon.TemUp();
				else if(ch2==3)
					aircon.TemDown();
				else if(ch2==4)
					aircon.WinUp();
				else if(ch2==5)
					aircon.WinDown();
				else if(ch2==6)
					aircon.DirectUp();
				else if(ch2==7)
					aircon.DirectDown();
			}
			else if(ch2>=2 && ch2<=7 && aircon.GetState()==OFF)	//에어컨이 꺼져있으면 기능들은 작동하지 않음
				cout << "전원이 꺼져 있습니다." << endl;
			else if(ch2==8)
				aircon.Check();
			else if(ch2==9)
				aircon.Elec_Usage();
			else if(ch2!=10)
				cout << "1에서 10 사이의 번호를 입력해주세요." << endl;

			cout << "\n\n\n";
		}

		while(ch1==2 && ch2!=8)
		{
			iron.Time_Calculation();

			cout << "---------------전기 다리미----------------" << endl;
			cout << "1. 전원 조작" << endl;
			cout << "2. 분무기 기능" << endl;
			cout << "3. 스팀 기능" << endl;
			cout << "4. 온도 증가" << endl;
			cout << "5. 온도 감소" << endl;
			cout << "6. 현재 설정 확인" << endl;
			cout << "7. 소비전력, 사용시간, 전력소비량 확인" << endl;
			cout << "8. 이전으로" << endl;
			cout << "------------------------------------------" << endl;
			cout << "선택 : ";

			cin >> ch2;

			cout << "\n\n\n";

			iron.Time_Calculation();
			if(ch2==1 && iron.GetState()==OFF)	//전원 꺼져있을시 킴
				iron.On();
			else if(ch2==1 && iron.GetState()==ON)	//전원 켜져있을시 끔
				iron.Off();
			else if(ch2>=2 && ch2<=5 && iron.GetState()==ON)
			{
				if(ch2==2)
					iron.SetButton(1);
				else if(ch2==3)
					iron.SetButton(2);
				else if(ch2==4)
					iron.IronTemUp();
				else if(ch2==5)
					iron.IronTemDown();
			}
			else if(ch2>=2 && ch2<=5 && iron.GetState()==OFF)
				cout << "전원이 꺼져 있습니다. 전원을 먼저 켜주세요." << endl;
			else if(ch2==6)
				iron.Check();
			else if(ch2==7)
				iron.Elec_Usage();
			else if(ch2!=8)
				cout << "1에서 8 사이의 번호를 입력해주세요." << endl;

			cout << "\n\n\n";
		}

		while(ch1==3 && ch2!= 9)
		{
			cout << "----------------전자레인지----------------" << endl;	//전자레인지만 전원 없음
			cout << "1. 해동" << endl;
			cout << "2. 보온" << endl;
			cout << "3. 열(약)" << endl;
			cout << "4. 열(중)" << endl;
			cout << "5. 열(강)" << endl;
			cout << "6. 취소하기" << endl;
			cout << "7. 현재 설정 및 남은 시간 확인" << endl;
			cout << "8. 소비전력, 사용시간, 전력소비량 확인" << endl;
			cout << "9. 이전으로" << endl;
			cout << "------------------------------------------\n\n" << endl;
			cout << "선택 : ";

			cin >> ch2;

			cout << "\n\n\n";
			micro.Micro_Time_Calculation();	//중간에 전자레인지 작동시간 점검
											//시각을 확인해 작동시간이 끝났으면 전자레인지를 꺼준다.

			if(ch2>=1 && ch2<=5 && micro.GetState()==OFF)	//가동중이지 않을 때 기능 설정시
			{
				micro.ChoiceHeatFunc(ch2);	//기능 선택
				micro.ChoiceHeatTime();		//가동할 시간 입력
			}
			else if(ch2>=1 && ch2<=5 && micro.GetState()==ON)	//가동 중에 기능 설정시
				cout << "이미 가동중입니다." << endl;
			else if(ch2==6 && micro.GetState()==ON)
			{
				cout << "작동을 취소합니다." << endl;
				micro.Off();
			}
			else if(ch2==6 && micro.GetState()==OFF)
			{
				cout << "작동중이지 않습니다." << endl;
			}
			else if(ch2==7)
				micro.Check();
			else if(ch2==8)
				micro.Micro_Elec_Usage();
			else if(ch2!=9)
				cout << "1에서 9 사이의 번호를 입력해주세요." << endl;

			cout << "\n\n\n";
		}

		while(ch1==4 && ch2!=9)
		{
			cout << "--------------------TV--------------------" << endl;
			cout << "1. 전원 조작" << endl;
			cout << "2. 채널 변경" << endl;
			cout << "3. 음량 증가" << endl;
			cout << "4. 음량 감소" << endl;
			cout << "5. 화면 밝기 증가" << endl;
			cout << "6. 화면 밝기 감소" << endl;
			cout << "7. 현재 설정 확인" << endl;
			cout << "8. 소비전력, 사용시간, 전력소비량 확인" << endl;
			cout << "9. 이전으로" << endl;
			cout << "------------------------------------------\n\n" << endl;
			
			cout << "선택 : ";
			cin >> ch2;

			cout << "\n\n\n";

			tv.Time_Calculation();

			if(ch2==1 && tv.GetState()==ON)
				tv.Off();
			else if(ch2==1 && tv.GetState()==OFF)
				tv.On();
			else if(ch2>=2 && ch2<=6 && tv.GetState()==ON)
			{
				if(ch2==2)
					tv.ChannelChoice();
				else if(ch2==3)
					tv.SoundUp();
				else if(ch2==4)
					tv.SoundDown();
				else if(ch2==5)
					tv.LightUp();
				else if(ch2==6)
					tv.LightDown();
			}
			else if(ch2>=2 && ch2<=6 && tv.GetState()==OFF)
				cout << "전원이 꺼져 있습니다." << endl;
			else if(ch2==7)
				tv.Check();
			else if(ch2==8)
				tv.Elec_Usage();
			else if(ch2!=9)
				cout << "1에서 9 사이의 번호를 입력해주세요." << endl;

			cout << "\n\n\n";
		}
		ch2 = 0;
	}
	return 0;
}
