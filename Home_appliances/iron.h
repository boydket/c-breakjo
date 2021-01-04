#pragma once
#include "elecapp.h"

class Iron :public Elecapp
{
private:
	int IronButton; // ��� ��ư (��ɾ���=0, �й���=1, ����=2)
	int IronTem; // ����ٸ��� �µ�
public:
	Iron(int wh) : Elecapp(wh) {	//watt�� �Һ�����
		IronButton = 0;
		IronTem = 0;
	}

	void On() { // ����ٸ��� �ѱ�
		IronTem = 100;
		SetStart(time(0));	//�۵� ���۽ð� ����
		SetState(ON);
		cout << "����ٸ��̰� �������ϴ�." << endl;
	}

	void Off() { // ����ٸ��� ����
		IronButton = 0;
		IronTem = 0;
		SetState(OFF);
		SetEnd(time(0));	//�۵� ����ð� ����
		cout << "����ٸ��̰�  �������ϴ�." << endl;
	}

	void SetButton(int button)	//�Է¹��� button���� ����� ����
	{
		if(button==1)
			cout << "�й��� ";
		else
			cout << "���� ";
		cout << "����� �����մϴ�." << endl;
		IronButton = button;
	}

	void ButtonState()	//���� ���õ� ��� ���
	{
		if(IronButton==0)
			cout << "���õ� ����� �����ϴ�." << endl;
		else if(IronButton==1)
			cout << "���� ��� : �й���" << endl;
		else
			cout << "���� ��� : ����" << endl;
	}

	void IronTemUp(){ //����ٸ��� �µ� 10�� ���� 
		if (IronTem <= 190) {
			IronTem += 10;
			cout << "����ٸ��̴� " << IronTem << "�� �Դϴ�." << endl;
		}
		else {
			cout << "�ְ� �µ��Դϴ�." << endl;
			cout << "����ٸ��̴� " << IronTem << "�� �Դϴ�." << endl;
		}
	}

	void IronTemDown() { // ����ٸ��� �µ� 10�� ����
		if (IronTem >= 110) {
			IronTem -= 10;
			cout << "����ٸ��̴� " << IronTem << "�� �Դϴ�." << endl;
		}
		else {
			cout << "�ּ� �µ��Դϴ�." << endl;
			cout << "����ٸ��̴� " << IronTem << "�� �Դϴ�." << endl;
		}
	}

	void Check()	//����ٸ��� ���� ���� ���
	{
		cout << "����ٸ��� ���� ���� : ";
		if(GetState()==ON)	//���� �ִٸ�
		{	
			cout << "����" << endl;
			ButtonState();	//� �������(�й���,����) ���
			cout << "�µ� : " << IronTem << endl;
		}
		else	//���� �ִٸ�
			cout << "����" << endl;
	}
};

