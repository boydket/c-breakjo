#pragma once
#include <iostream>
#include <ctime>
using namespace std;

#define ON 1	//���� ON/OFF�� ǥ���ϱ� ���� ��ũ�� ���
#define OFF 0

class Elecapp
{
private:
	int wh;			//�ð��� �Һ�����(wh)/
	double watt;	//�ʴ� �Һ�����
	int state;	//���� �����ִ��� ����(0,1)
	int usedtime;	//���ð�(��)
	time_t start, now, end;	//�۵��ð� ������ �� ����ϴ� ������
public:					//start�� ��� ���۽ð�, now�� ����ð�, end�� ����ð�
						//now�� end���� ���۽ð��� start�� ���� ��ǰ ��뤷�ð� ���
	Elecapp(int wh) //�ð��� ���»�뷮(Wh) �ֱ�
	{
		this->wh = wh;
		watt = wh/3600.0;	//�ʴ� �Һ������� 1�ð��� 3600���̹Ƿ� 3600���� ������ ����
		state = OFF;
		usedtime = 0;
		start = 0;
		now = 0;
		end = 0;
	}

	virtual void On()	//�����Լ��� �� ������ǰ���� On(), Off()�� �����Ǿ� ����
	{

	}

	virtual void Off()
	{

	}

	int GetState()	//Get���� �����ϴ� �Լ����� �ܺο��� �������е� Elecapp Ŭ������ ������ �� �ֵ��� �ش� �������� �������ִ� �Լ��̴�.
	{
		return state;
	}

	void SetState(int set)	//Set���� �����ϴ� �Լ����� Get�� ���������� �������� ������ ���� ���ϴ� ���� ������ �ܺο��� ������ �� �ֵ��� �ϴ� �Լ�.
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

	void PlusUsedtime(int t)	//���ð��� t��ŭ�� ���� ������
	{
		usedtime += t;
	}

	void Time_Calculation()	//��� ���ð� ���
	{						//�ݺ������� ����Ǿ� ��� ��� ���ð��� �������ش�.
		if (state==OFF && start!=end)	//��Ⱑ �����ְ� start�� end�� ���� �ʴٸ�
		{
			usedtime += end-start;	//����� ����ð����� ���۽ð� ���� ���������� ���� �ð� ���
			start = end;	//start�� end�� ���� �� �Ǽ��� ���ð��� �� ���ϴ� ���� ������ ��
							//start�� end�� ���ٴ� �� �� ������� ����� ������ ǥ��
		}
		else if(state==ON)	//��Ⱑ ���� �ִ� ���¿��� �ð����
		{
			now = time(0);	//���� �ð� ����
			usedtime += now-start;	//���ð��� ���۽ð����� ����ð������� �ð��� ������
			start = now;		//���۽ð��� ����ð����ͷ� �ٽ� ����
		}
	}

	void Elec_Usage()	//�Һ�����, ���ð�, ���¼Һ� ���
	{
		cout << "�Һ����� : " << wh << "wh" << endl;
		cout << "���ð� : ";
		if(usedtime>=3600)	//1�ð� �̻��� ��
			cout << usedtime/3600 << "�ð� ";
		if(usedtime>=60)	//1�� �̻��� ��
			cout << (usedtime%3600)/60 << "�� ";
		cout << usedtime%60 << "��" << endl;
		
		cout << "���¼Һ� : " << usedtime*watt << "w" << endl;
	}
};