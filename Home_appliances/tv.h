#pragma once
#include "elecapp.h"

class TV : public Elecapp
{
private:
	int channel;	//ä�κ���
	int sound;		//���� 1~10
	int light;		//ȭ�� ��� 1~10

public:
	TV(int watt) : Elecapp(watt) {
		channel = 1;	//�ʱ� ä��
		sound = 0;
		light = 0;
	}

	void On()		//Ƽ�� ���� �ѱ�
	{
		cout << "�ڷ������� �������ϴ�." << endl;
		SetState(ON);
		SetStart(time(0));
	}

	void Off()	//Ƽ�� ���� ����
	{
		cout << "�ڷ������� �������ϴ�." << endl;
		SetState(OFF);
		SetEnd(time(0));
	}

	void ChannelChoice() {	//ä�� ����
		int ch;
		cout << "�����Ͻ� ä�� ��ȣ�� �Է��ϼ���(1~100) : ";
		cin >> ch;
		if(ch>=1 && ch<=100)
		{
			channel = ch;
			cout << "ä�� : " << channel << endl;
		}
		else
			cout << "�߸��� ä���Դϴ�. 1���� 100 ���̸� �Է����ּ���." << endl;
	}

	void SoundUp()	//���� 1 ����
	{
		if (sound < 10) {
			sound += 1;
			cout << "���� : " << sound << endl;
		}
		else if (sound == 10)
			cout << "������ �ִ��Դϴ�." << endl;
	}

	void SoundDown()	//���� 1 ����
	{
		if (sound > 0) {
			sound -= 1;
			cout << "���� : " << sound << endl;
		}
		else if (sound == 0)
			cout << "������ �ּ��Դϴ�." << endl;
	}

	void LightUp()	 //ȭ�� ��� 1 ����
	{
		if (light < 10) {
			light += 1;
			cout << "ȭ�� ��� : " << light << endl;
		}
		else if (light == 10)
			cout << "ȭ�� ��Ⱑ �ִ��Դϴ�." << endl;
	}

	void LightDown()	//ȭ�� ��� 1 ����
	{
		if (light > 0) {
			light -= 1;
			cout << "ȭ�� ��� : " << light << endl;
		}
		else if (light == 0)
			cout << "ȭ�� ��Ⱑ �ּ��Դϴ�." << endl;
	}

	void Check()
	{
		cout << "���� ���� : ";
		if(GetState()==ON)
		{
			cout << "����" << endl;
			cout << "ä�� : " << channel << endl;
			cout << "���� : " << sound << endl;
			cout << "ȭ�� ��� :  " << light << endl;
		}
		else
			cout << "����" << endl;
	}
};