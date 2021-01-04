#pragma once
#include "elecapp.h"

class Aircon : public Elecapp
{
private: 
	int temper;	//희망온도 18~28
	int wind;	//바람세기 1~5
	int shift;	//상하방향 1~5
public :
	Aircon(int wh) : Elecapp(wh)
	{
		temper = 0;
		wind = 0;
		shift = 0;
	}
	
	void On()	//에어컨 켜기
	{
		temper = 23;
		wind = 1;
		shift = 1;
		SetStart(time(0));	//시작시간 설정
		SetState(ON);
		cout << "에어컨이 켜졌습니다." << endl;
	}

	void Off()	//에어컨 끄기
	{
		SetState(OFF);
		SetEnd(time(0));
		cout << "에어컨이 꺼졌습니다." << endl;
	}

	void TemUp()	//온도 1도 증가
	{
		if (temper < 28)
		{
			temper += 1;
			cout << "희망온도 : " << temper << "도" << endl;
		}
		else
			cout << "희망온도 : " << temper << "도" << endl;

	}

	void TemDown()	//온도 1도 감소
	{
		if (temper > 18)
		{
			temper -= 1;
			cout << "희망온도 : " << temper << "도" << endl;
		}
		else
			cout << "희망온도 : " << temper << "도" << endl;

	}

	void WinUp()	//바람세기 1 증가
	{
		if (wind < 5)
		{
			wind += 1;
			cout << "바람세기 : " << wind << "단" << endl;
		}
		else
			cout << "바람세기 : " << wind << "단" << endl;

	}


	void WinDown()	//바람세기 1 감소
	{
		if (wind > 1)
		{
			wind -= 1;
			cout << "바람세기 : " << wind << "단" << endl;
		}
		else
			cout << "바람세기 : " << wind << "단" << endl;

	}

	void DirectUp()	//풍향 1 증가
	{
		if (shift < 5)
		{
			shift += 1;
			cout << "풍향 : " << shift << "단" << endl;
		}
		else
			cout << "풍향 : " << shift << "단" << endl;

	}


	void DirectDown()	//바람세기 1 감소
	{
		if (shift > 1)
		{
			shift -= 1;
			cout << "풍향 : " << shift << "단" << endl;
		}
		else
			cout << "풍향 : " << shift << "단" << endl;

	}

	void Check()	//에어컨 현재 설정 출력
	{
		cout << "에어컨 현재 상태 : ";
		if(GetState())	//켜져 있다면
		{	
			cout << "켜짐" << endl;
			cout << "온도 : " << temper << endl;
			cout << "바람세기 : " << wind << "단" <<endl;
			cout << "풍향 : " << shift << "단" << endl;
		}
		else	//꺼져 있다면
			cout << "꺼짐" << endl;
	}

};
