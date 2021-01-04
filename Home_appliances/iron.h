#pragma once
#include "elecapp.h"

class Iron :public Elecapp
{
private:
	int IronButton; // 기능 버튼 (기능없음=0, 분무기=1, 스팀=2)
	int IronTem; // 전기다리미 온도
public:
	Iron(int wh) : Elecapp(wh) {	//watt는 소비전력
		IronButton = 0;
		IronTem = 0;
	}

	void On() { // 전기다리미 켜기
		IronTem = 100;
		SetStart(time(0));	//작동 시작시간 저장
		SetState(ON);
		cout << "전기다리미가 켜졌습니다." << endl;
	}

	void Off() { // 전기다리미 끄기
		IronButton = 0;
		IronTem = 0;
		SetState(OFF);
		SetEnd(time(0));	//작동 종료시간 저장
		cout << "전기다리미가  꺼졌습니다." << endl;
	}

	void SetButton(int button)	//입력받은 button으로 기능을 설정
	{
		if(button==1)
			cout << "분무기 ";
		else
			cout << "스팀 ";
		cout << "기능을 실행합니다." << endl;
		IronButton = button;
	}

	void ButtonState()	//현재 선택된 기능 출력
	{
		if(IronButton==0)
			cout << "선택된 기능이 없습니다." << endl;
		else if(IronButton==1)
			cout << "현재 기능 : 분무기" << endl;
		else
			cout << "현재 기능 : 스팀" << endl;
	}

	void IronTemUp(){ //전기다리미 온도 10도 증가 
		if (IronTem <= 190) {
			IronTem += 10;
			cout << "전기다리미는 " << IronTem << "도 입니다." << endl;
		}
		else {
			cout << "최고 온도입니다." << endl;
			cout << "전기다리미는 " << IronTem << "도 입니다." << endl;
		}
	}

	void IronTemDown() { // 전기다리미 온도 10도 감소
		if (IronTem >= 110) {
			IronTem -= 10;
			cout << "전기다리미는 " << IronTem << "도 입니다." << endl;
		}
		else {
			cout << "최소 온도입니다." << endl;
			cout << "전기다리미는 " << IronTem << "도 입니다." << endl;
		}
	}

	void Check()	//전기다리미 현재 설정 출력
	{
		cout << "전기다리미 현재 상태 : ";
		if(GetState()==ON)	//켜져 있다면
		{	
			cout << "켜짐" << endl;
			ButtonState();	//어떤 기능인지(분무기,스팀) 출력
			cout << "온도 : " << IronTem << endl;
		}
		else	//꺼져 있다면
			cout << "꺼짐" << endl;
	}
};

