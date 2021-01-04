#pragma once
#include "elecapp.h"

char list[5][20] = {"해동", "보온", "열(약)", "열(중)", "열(강)"};	//전자레인지 기능 5개 단어 저장

class Microwave :public Elecapp
{
private:
	int HeatFuc; // 열 기능 선택 (해동, 보온, 약, 중, 강)
	int HeatTime; // 작동시간(초)
	int spenttime;	//작동중에 흘러간 시간(초,남은 시간을 계산하기 위함)
					//예를 들어 전자레인지를 3분을 돌리도록 설정한 뒤 1분이 지났다면 spenttime은 1분을 초로 변환한 60이 된다.(남은시간은 3분에서 60을 뺀 120으로 계산하는 식)
public:				
	Microwave(int wh) : Elecapp(wh)
	{ 
		HeatFuc = 0;
		HeatTime = 0;
	}

	void On() { // 전자렌지 가동 시작		
		cout << HeatTime << "분 작동을 시작합니다." << endl;
		SetStart(time(0));	//시작시간 저장
		SetState(ON);
		}

	void Off() { // 전자렌지 가동 끝
		HeatFuc = 0;
		HeatTime = 0;
		SetEnd(time(0));	//종료시간 저장
		PlusUsedtime(GetEnd()-GetStart());	//가동한 만큼의 시간을 사용시간인 usedtime에 더해준다.
		SetState(OFF);	//전자레인지 가동 종료(전원 끔)
	}

	int GetHeatTime()
	{
		return HeatTime;
	}


	void ChoiceHeatFunc(int ch2)
	{
		cout << list[ch2-1] << " 기능을 선택했습니다." << endl;
		HeatFuc = ch2-1;
	}
	
	void ChoiceHeatTime() { // 전자렌지 작동 시간 설정
		while(1)
		{
			cout << "몇 분 작동시키시겠습니까?" << endl;
			cin >> HeatTime;
			if(HeatTime<=0)
			{
				cout << "1 이상의 숫자를 입력해주세요." << endl;
				continue;
			}
			break;
		}
		On();
		SetStart(time(0));	//시작시각 저장
		HeatTime *= 60;	//분을 초로 변환해 저장
		SetEnd(GetStart()+HeatTime);	//종료시간이 정확히 예정되어 있으므로 미리 저장한다.
										//(중간에 취소시에는 해당 시간을 종료시간으로 다시 저장하도록 되어있음)
	}

	void Check()
	{
		time_t now = time(0);	//현재시간
		int remaintime = HeatTime-spenttime;	//남은시간 계산(남은시간 = 작동설정시간 - 작동한 시간)
	
		cout << "현재 상태 : ";
		if(GetState()==ON)
		{
			cout << "작동중" << endl;
			cout << "현재 기능 : " << list[HeatFuc] << endl;
			cout << "남은 시간 : " << remaintime << "초" << endl;
		}
		else
			cout << "꺼짐" << endl;
	}
	
	void Micro_Elec_Usage()	//전자레인지 소비전력, 사용시간, 전력소비량 출력함수
	{
		int usedtime;	//임시로 쓰는 사용시간
		usedtime = GetUsedtime();
		if(GetState()==ON)	//전자레인지가 가동중이라면
			usedtime += spenttime;	//사용시간에 가동중 흘러간 시간을 임시로 추가
		cout << "소비전력 : " << GetWh() << "wh" << endl;
		cout << "사용시간 : ";
		if(usedtime>=3600)
			cout << usedtime/3600 << "시간 ";
		if(usedtime>=60)
			cout << (usedtime%3600)/60 << "분 ";
		cout << usedtime%60 << "초" << endl;
		
		cout << "전력소비량 : " << usedtime*GetWatt() << "w" << endl;
	}

	void Micro_Time_Calculation()	//전자레인지는 시간 계산 함수, 부모 클래스에 이미 시간계산 함수가 있지만 따로 만들었다.
	{							//다른 전자제품들과 달리 사용자가 끄지 않아도 시간이 지나면 저절로 꺼지는 기능이 있기 때문
								//사용시간을 계산해주는 것 외에도 작동시간이 끝났다면 전자레인지를 꺼 주는 역할도 하는 함수
								//반복적으로 실행되어 시각을 점검한다.
		time_t now = time(0);	//현재시각 저장
		
		if(GetState()==OFF && GetStart()!=GetEnd())	//전자레인지가 가동중이지 않고 start와 end가 같지 않다면
		{
			PlusUsedtime(GetEnd()-GetStart());	//이전에 작동했었던 시간, 즉 end(종료시각)에서 start(시작시각)를 뺀 사용시간을 usedtime에 더해줌
			SetEnd(GetStart());	//end는 start와 같게 한다. 이미 추가한 시간을 또 추가하지 않도록 하는 표시.
		}


		if(GetState()==ON && now-GetStart()>=HeatTime)	//전자레인지가 가동중이고 현재시각에서 가동 시작시각을 뺀 값이 작동설정시간보다 크거나 같다면
		{
			Off();	//전자레인지가 설정한 시간만큼 시간이 흘러갔다는 뜻이므로 전자레인지를 꺼준다.
		}
		//예를 들어 전자레인지를 10분(HeatTime)을 설정하고 1:00에 가동을 시작(start)했고 현재시각이 1:15(now)이라면
		//현재시각(now)에서 시작시각(start)을 뺀 값이 15분이므로 설정한 시간인 10분(HeatTime)을 넘는다.
		//이 말은 설정한 시간이 다 지나서 가동이 완료되었다는 뜻이므로 Off()로 꺼주게 된다.


		if(GetState()==ON && now-GetStart()<HeatTime)	//전자레인지가 가동중이고 현재시각에서 시작시간을 뺀 값이 작동설정시간보다 작다면
		{												
			spenttime = now-GetStart();	//아직 전자레인지 가동시간이 남아있다는 뜻. 종료하거나 하지는 않고 spenttime에 현재 시각에서 가동시작시간을 뺀, 즉 가동한 만큼의 시간을 저장해준다.
		}

	}
};
