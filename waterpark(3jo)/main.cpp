#include<iostream>
#include <cstring>
#include"play.h"
#include"person.h"
#include "Diner.h"

int main()
{
	char name[20];
	int height, weight;

	cout << "�̸� : ";
	cin >> name;
	while (1)
	{
		cout << "Ű : ";
		cin >> height;
		if (height > 40)
			break;
		else
			cout << "40���� ū ���� �Է����ּ���.\n" << endl;
	}
	while (1)
	{
		cout << "������ : ";
		cin >> weight;
		if (weight > 10)
			break;
		else
			cout << "10���� ū ���� �Է����ּ���.\n" << endl;
	}
	person Sangjun(name, height, weight); // �̸�, Ű, �����Է� Person Ŭ������ �����ϱ�
	int ch1, ch2 = 0;

	cout << "������ũ�� �����߽��ϴ�. ������ 20000���Դϴ�." << endl << endl;
	while (1)
	{
		cout << "�� ���� �����ϼ���." << endl;
		cout << "1. ������ �ϱ�" << endl;
		cout << "2. �뿩�� �湮" << endl;
		cout << "3. �Ļ��ϱ�" << endl;
		cout << "4. �������� ����" << endl;
		cout << "5. ���ð� �� ���ݾ� Ȯ��" << endl;
		cout << "6. ������ũ �����ϱ�" << endl;
		cout << endl;

		cout << "�Է� : ";
		cin >> ch1;
		ch2 = 0;

		cout << endl << endl;
		if (ch1 == 1)
		{
			while (1)
			{
				int time = 0;
				Sangjun.myplay.List();	//Sangjun�� ĸ��ȭ�� ���� Ŭ������ myplay ���� List() �Լ� ȣ��
				cout << endl << "�Է� : ";
				cin >> ch2;

				if (ch2 == 1)	//�ĵ�Ǯ ���ý�
					time = Sangjun.myplay.PlayPool(Sangjun.myborrow.GetState());
				//myborrow�� ����� ���������� Ʃ�� ���뿩�θ� �����ϴ� state ������ GetState�� ������ �Ű������� �־���
				//(���������� Ʃ�� ���뿩�θ� �˻��ϱ� ����)
				//time�� PlayPool �Լ����� ����� �ð��� ��ȯ�� ���� �޾Ƽ� ������

				else if (ch2 == 2)	//����Ǯ ���ý�
					time = Sangjun.myplay.PlayRiver();
				else if (ch2 == 3)	//�����̵� ���ý�
					time = Sangjun.myplay.PlaySlide(Sangjun.GetHeight());	//Ű �˻縦 ���� height�� �Űܺ����� �־���
				else if (ch2 == 4)
					break;
				else
					cout << "1~4 ������ ���ڸ� �Է����ּ���.\n\n" << endl;

				if (Sangjun.myborrow.GetState() == 1 || Sangjun.myborrow.GetState() == 3) //�������� �뿩���Ͻ�
					Sangjun.myborrow.AddV_borrow_time(time);	//�������� �뿩���� �ð� ����
				if (Sangjun.myborrow.GetState() == 2 || Sangjun.myborrow.GetState() == 3) //Ʃ	�� �뿩���Ͻ�
					Sangjun.myborrow.AddT_borrow_time(time);	//Ʃ�� �뿩���� �ð� ����
				Sangjun.myplay.AddPlay_time(time);
			}
		}

		else if (ch1 == 2)
		{
				Sangjun.myborrow.borrow_system();
		}

		else if (ch1 == 3)
		{
			Sangjun.myDiner.DinerMenu();
			Sangjun.myDiner.Drink();
			Sangjun.myDiner.DinerTime();
		}

		else if (ch1 == 4)
		{
			Sangjun.ShowPerson();
		}
		else if (ch1 == 5)
		{
			Sangjun.ShowTimeAndUse();
		}

		else if (ch1 == 6)
		{
			if (Sangjun.myborrow.GetState() >= 1) //���������� Ʃ�긦 �뿩���� ��
			{
				cout << "�뿩���� ��ǰ�� ������ ������ �Ұ����մϴ�." << endl;
				cout << "�뿩�ҿ� ���� �ݳ��� �Ϸ����ּ���." << endl;
			}
			else
			{
				cout << "������ũ�� �����մϴ�." << endl;
				cout << "�� ���ݾ��� " << Sangjun.GetCost() << "���� �����մϴ�." << endl;
				cout << "�̿����ּż� �����մϴ�." << endl;
				break;
			}
		}

		else
		{
			cout << "1~7 ������ ���ڸ� �Է����ּ���." << endl;
		}

		cout << endl << endl;
	}
}