#pragma once
#include "elecapp.h"

class TV : public Elecapp
{
private:
	int channel;	//채널변경
	int sound;		//음량 1~10
	int light;		//화면 밝기 1~10

public:
	TV(int watt) : Elecapp(watt) {
		channel = 1;	//초기 채널
		sound = 0;
		light = 0;
	}

	void On()		//티비 전원 켜기
	{
		cout << "텔레비전이 켜졌습니다." << endl;
		SetState(ON);
		SetStart(time(0));
	}

	void Off()	//티비 전원 끄기
	{
		cout << "텔레비전이 꺼졌습니다." << endl;
		SetState(OFF);
		SetEnd(time(0));
	}

	void ChannelChoice() {	//채널 변경
		int ch;
		cout << "변경하실 채널 번호를 입력하세요(1~100) : ";
		cin >> ch;
		if(ch>=1 && ch<=100)
		{
			channel = ch;
			cout << "채널 : " << channel << endl;
		}
		else
			cout << "잘못된 채널입니다. 1에서 100 사이를 입력해주세요." << endl;
	}

	void SoundUp()	//음량 1 증가
	{
		if (sound < 10) {
			sound += 1;
			cout << "음량 : " << sound << endl;
		}
		else if (sound == 10)
			cout << "음량이 최대입니다." << endl;
	}

	void SoundDown()	//음량 1 감소
	{
		if (sound > 0) {
			sound -= 1;
			cout << "음량 : " << sound << endl;
		}
		else if (sound == 0)
			cout << "음량이 최소입니다." << endl;
	}

	void LightUp()	 //화면 밝기 1 증가
	{
		if (light < 10) {
			light += 1;
			cout << "화면 밝기 : " << light << endl;
		}
		else if (light == 10)
			cout << "화면 밝기가 최대입니다." << endl;
	}

	void LightDown()	//화면 밝기 1 감소
	{
		if (light > 0) {
			light -= 1;
			cout << "화면 밝기 : " << light << endl;
		}
		else if (light == 0)
			cout << "화면 밝기가 최소입니다." << endl;
	}

	void Check()
	{
		cout << "현재 상태 : ";
		if(GetState()==ON)
		{
			cout << "켜짐" << endl;
			cout << "채널 : " << channel << endl;
			cout << "음량 : " << sound << endl;
			cout << "화면 밝기 :  " << light << endl;
		}
		else
			cout << "꺼짐" << endl;
	}
};