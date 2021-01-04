#pragma once
#include "elecapp.h"

class Aircon : public Elecapp
{
private: 
	int temper;	//����µ� 18~28
	int wind;	//�ٶ����� 1~5
	int shift;	//���Ϲ��� 1~5
public :
	Aircon(int wh) : Elecapp(wh)
	{
		temper = 0;
		wind = 0;
		shift = 0;
	}
	
	void On()	//������ �ѱ�
	{
		temper = 23;
		wind = 1;
		shift = 1;
		SetStart(time(0));	//���۽ð� ����
		SetState(ON);
		cout << "�������� �������ϴ�." << endl;
	}

	void Off()	//������ ����
	{
		SetState(OFF);
		SetEnd(time(0));
		cout << "�������� �������ϴ�." << endl;
	}

	void TemUp()	//�µ� 1�� ����
	{
		if (temper < 28)
		{
			temper += 1;
			cout << "����µ� : " << temper << "��" << endl;
		}
		else
			cout << "����µ� : " << temper << "��" << endl;

	}

	void TemDown()	//�µ� 1�� ����
	{
		if (temper > 18)
		{
			temper -= 1;
			cout << "����µ� : " << temper << "��" << endl;
		}
		else
			cout << "����µ� : " << temper << "��" << endl;

	}

	void WinUp()	//�ٶ����� 1 ����
	{
		if (wind < 5)
		{
			wind += 1;
			cout << "�ٶ����� : " << wind << "��" << endl;
		}
		else
			cout << "�ٶ����� : " << wind << "��" << endl;

	}


	void WinDown()	//�ٶ����� 1 ����
	{
		if (wind > 1)
		{
			wind -= 1;
			cout << "�ٶ����� : " << wind << "��" << endl;
		}
		else
			cout << "�ٶ����� : " << wind << "��" << endl;

	}

	void DirectUp()	//ǳ�� 1 ����
	{
		if (shift < 5)
		{
			shift += 1;
			cout << "ǳ�� : " << shift << "��" << endl;
		}
		else
			cout << "ǳ�� : " << shift << "��" << endl;

	}


	void DirectDown()	//�ٶ����� 1 ����
	{
		if (shift > 1)
		{
			shift -= 1;
			cout << "ǳ�� : " << shift << "��" << endl;
		}
		else
			cout << "ǳ�� : " << shift << "��" << endl;

	}

	void Check()	//������ ���� ���� ���
	{
		cout << "������ ���� ���� : ";
		if(GetState())	//���� �ִٸ�
		{	
			cout << "����" << endl;
			cout << "�µ� : " << temper << endl;
			cout << "�ٶ����� : " << wind << "��" <<endl;
			cout << "ǳ�� : " << shift << "��" << endl;
		}
		else	//���� �ִٸ�
			cout << "����" << endl;
	}

};
