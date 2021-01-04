#pragma once
#include <iostream>
#include <ctime>
using namespace std;

#define ON 1	//전원 ON/OFF를 표시하기 위해 매크로 사용
#define OFF 0

class Elecapp
{
private:
	int wh;			//시간당 소비전력(wh)/
	double watt;	//초당 소비전력
	int state;	//전원 켜져있는지 여부(0,1)
	int usedtime;	//사용시간(초)
	time_t start, now, end;	//작동시간 측정할 때 사용하는 변수들
public:					//start는 기기 시작시간, now는 현재시간, end는 종료시간
						//now나 end에서 시작시간인 start를 빼서 제품 사용ㅇ시간 계산
	Elecapp(int wh) //시간당 전력사용량(Wh) 넣기
	{
		this->wh = wh;
		watt = wh/3600.0;	//초당 소비전력은 1시간이 3600초이므로 3600으로 나눠서 저장
		state = OFF;
		usedtime = 0;
		start = 0;
		now = 0;
		end = 0;
	}

	virtual void On()	//가상함수로 각 전자제품마다 On(), Off()가 구현되어 있음
	{

	}

	virtual void Off()
	{

	}

	int GetState()	//Get으로 시작하는 함수들은 외부에서 정보은닉된 Elecapp 클래스에 접근할 수 있도록 해당 변수들을 리턴해주는 함수이다.
	{
		return state;
	}

	void SetState(int set)	//Set으로 시작하는 함수들은 Get과 마찬가지로 정보은닉 때문에 수정 못하는 내부 변수를 외부에서 수정할 수 있도록 하는 함수.
	{
		state = set;
	}

	double GetStart()
	{
		return start;
	}

	void SetStart(time_t start)
	{
		this->start = start;
	}

	double GetEnd()
	{
		return end;
	}

	void SetEnd(time_t end)
	{
		this->end = end;
	}

	int GetWh()
	{
		return wh;
	}

	int GetUsedtime()
	{
		return usedtime;
	}

	double GetWatt()
	{
		return watt;
	}

	void PlusUsedtime(int t)	//사용시간에 t만큼의 값을 더해줌
	{
		usedtime += t;
	}

	void Time_Calculation()	//기기 사용시간 계산
	{						//반복적으로 실행되어 계속 기기 사용시간을 갱신해준다.
		if (state==OFF && start!=end)	//기기가 꺼져있고 start와 end가 같지 않다면
		{
			usedtime += end-start;	//기기의 종료시간에서 시작시간 빼서 마지막으로 사용된 시간 계산
			start = end;	//start와 end를 같게 해 실수로 사용시간에 또 더하는 일이 없도록 함
							//start와 end가 같다는 건 또 계산하지 말라는 일종의 표시
		}
		else if(state==ON)	//기기가 켜져 있는 상태에서 시간계산
		{
			now = time(0);	//현재 시각 저장
			usedtime += now-start;	//사용시간에 시작시각부터 현재시각까지의 시간을 더해줌
			start = now;		//시작시간은 현재시간부터로 다시 시작
		}
	}

	void Elec_Usage()	//소비전력, 사용시간, 전력소비량 출력
	{
		cout << "소비전력 : " << wh << "wh" << endl;
		cout << "사용시간 : ";
		if(usedtime>=3600)	//1시간 이상일 때
			cout << usedtime/3600 << "시간 ";
		if(usedtime>=60)	//1분 이상일 때
			cout << (usedtime%3600)/60 << "분 ";
		cout << usedtime%60 << "초" << endl;
		
		cout << "전력소비량 : " << usedtime*watt << "w" << endl;
	}
};