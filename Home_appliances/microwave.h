#pragma once
#include "elecapp.h"

char list[5][20] = {"�ص�", "����", "��(��)", "��(��)", "��(��)"};	//���ڷ����� ��� 5�� �ܾ� ����

class Microwave :public Elecapp
{
private:
	int HeatFuc; // �� ��� ���� (�ص�, ����, ��, ��, ��)
	int HeatTime; // �۵��ð�(��)
	int spenttime;	//�۵��߿� �귯�� �ð�(��,���� �ð��� ����ϱ� ����)
					//���� ��� ���ڷ������� 3���� �������� ������ �� 1���� �����ٸ� spenttime�� 1���� �ʷ� ��ȯ�� 60�� �ȴ�.(�����ð��� 3�п��� 60�� �� 120���� ����ϴ� ��)
public:				
	Microwave(int wh) : Elecapp(wh)
	{ 
		HeatFuc = 0;
		HeatTime = 0;
	}

	void On() { // ���ڷ��� ���� ����		
		cout << HeatTime << "�� �۵��� �����մϴ�." << endl;
		SetStart(time(0));	//���۽ð� ����
		SetState(ON);
		}

	void Off() { // ���ڷ��� ���� ��
		HeatFuc = 0;
		HeatTime = 0;
		SetEnd(time(0));	//����ð� ����
		PlusUsedtime(GetEnd()-GetStart());	//������ ��ŭ�� �ð��� ���ð��� usedtime�� �����ش�.
		SetState(OFF);	//���ڷ����� ���� ����(���� ��)
	}

	int GetHeatTime()
	{
		return HeatTime;
	}


	void ChoiceHeatFunc(int ch2)
	{
		cout << list[ch2-1] << " ����� �����߽��ϴ�." << endl;
		HeatFuc = ch2-1;
	}
	
	void ChoiceHeatTime() { // ���ڷ��� �۵� �ð� ����
		while(1)
		{
			cout << "�� �� �۵���Ű�ðڽ��ϱ�?" << endl;
			cin >> HeatTime;
			if(HeatTime<=0)
			{
				cout << "1 �̻��� ���ڸ� �Է����ּ���." << endl;
				continue;
			}
			break;
		}
		On();
		SetStart(time(0));	//���۽ð� ����
		HeatTime *= 60;	//���� �ʷ� ��ȯ�� ����
		SetEnd(GetStart()+HeatTime);	//����ð��� ��Ȯ�� �����Ǿ� �����Ƿ� �̸� �����Ѵ�.
										//(�߰��� ��ҽÿ��� �ش� �ð��� ����ð����� �ٽ� �����ϵ��� �Ǿ�����)
	}

	void Check()
	{
		time_t now = time(0);	//����ð�
		int remaintime = HeatTime-spenttime;	//�����ð� ���(�����ð� = �۵������ð� - �۵��� �ð�)
	
		cout << "���� ���� : ";
		if(GetState()==ON)
		{
			cout << "�۵���" << endl;
			cout << "���� ��� : " << list[HeatFuc] << endl;
			cout << "���� �ð� : " << remaintime << "��" << endl;
		}
		else
			cout << "����" << endl;
	}
	
	void Micro_Elec_Usage()	//���ڷ����� �Һ�����, ���ð�, ���¼Һ� ����Լ�
	{
		int usedtime;	//�ӽ÷� ���� ���ð�
		usedtime = GetUsedtime();
		if(GetState()==ON)	//���ڷ������� �������̶��
			usedtime += spenttime;	//���ð��� ������ �귯�� �ð��� �ӽ÷� �߰�
		cout << "�Һ����� : " << GetWh() << "wh" << endl;
		cout << "���ð� : ";
		if(usedtime>=3600)
			cout << usedtime/3600 << "�ð� ";
		if(usedtime>=60)
			cout << (usedtime%3600)/60 << "�� ";
		cout << usedtime%60 << "��" << endl;
		
		cout << "���¼Һ� : " << usedtime*GetWatt() << "w" << endl;
	}

	void Micro_Time_Calculation()	//���ڷ������� �ð� ��� �Լ�, �θ� Ŭ������ �̹� �ð���� �Լ��� ������ ���� �������.
	{							//�ٸ� ������ǰ��� �޸� ����ڰ� ���� �ʾƵ� �ð��� ������ ������ ������ ����� �ֱ� ����
								//���ð��� ������ִ� �� �ܿ��� �۵��ð��� �����ٸ� ���ڷ������� �� �ִ� ���ҵ� �ϴ� �Լ�
								//�ݺ������� ����Ǿ� �ð��� �����Ѵ�.
		time_t now = time(0);	//����ð� ����
		
		if(GetState()==OFF && GetStart()!=GetEnd())	//���ڷ������� ���������� �ʰ� start�� end�� ���� �ʴٸ�
		{
			PlusUsedtime(GetEnd()-GetStart());	//������ �۵��߾��� �ð�, �� end(����ð�)���� start(���۽ð�)�� �� ���ð��� usedtime�� ������
			SetEnd(GetStart());	//end�� start�� ���� �Ѵ�. �̹� �߰��� �ð��� �� �߰����� �ʵ��� �ϴ� ǥ��.
		}


		if(GetState()==ON && now-GetStart()>=HeatTime)	//���ڷ������� �������̰� ����ð����� ���� ���۽ð��� �� ���� �۵������ð����� ũ�ų� ���ٸ�
		{
			Off();	//���ڷ������� ������ �ð���ŭ �ð��� �귯���ٴ� ���̹Ƿ� ���ڷ������� ���ش�.
		}
		//���� ��� ���ڷ������� 10��(HeatTime)�� �����ϰ� 1:00�� ������ ����(start)�߰� ����ð��� 1:15(now)�̶��
		//����ð�(now)���� ���۽ð�(start)�� �� ���� 15���̹Ƿ� ������ �ð��� 10��(HeatTime)�� �Ѵ´�.
		//�� ���� ������ �ð��� �� ������ ������ �Ϸ�Ǿ��ٴ� ���̹Ƿ� Off()�� ���ְ� �ȴ�.


		if(GetState()==ON && now-GetStart()<HeatTime)	//���ڷ������� �������̰� ����ð����� ���۽ð��� �� ���� �۵������ð����� �۴ٸ�
		{												
			spenttime = now-GetStart();	//���� ���ڷ����� �����ð��� �����ִٴ� ��. �����ϰų� ������ �ʰ� spenttime�� ���� �ð����� �������۽ð��� ��, �� ������ ��ŭ�� �ð��� �������ش�.
		}

	}
};
