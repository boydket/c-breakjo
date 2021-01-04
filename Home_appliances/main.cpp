#include <iostream>
#include "aircondition.h"
#include "iron.h"
#include "microwave.h"
#include "tv.h"

using namespace std;

int main(void)
{
	int ch1=0, ch2=0;	//��ȣ �Է¹��� ������
	int wh;	//�Һ����� �Է¹��� ����
	char list[4][20] = {"������", "����ٸ���", "���ڷ�����", "TV"};





	cout << "5���� ������ǰ�� �Һ������� �Է����ּ���.\n" << endl;
	while(1)
	{
		cout << "������ �Һ�����(����:Wh) : ";
		cin >> wh;

		if(wh>0)
			break;
		cout << "0 �̻��� ���ڸ� �Է����ּ���." << endl;
	}
	Aircon aircon(wh);

	while(1)
	{
		cout << "����ٸ��� �Һ�����(����:Wh) : ";
		cin >> wh;

		if(wh>0)
			break;
		cout << "0 �̻��� ���ڸ� �Է����ּ���." << endl;
	}
	Iron iron(wh);

	while(1)
	{
		cout << "���ڷ����� �Һ�����(����:Wh) : ";
		cin >> wh;

		if(wh>0)
			break;
		cout << "0 �̻��� ���ڸ� �Է����ּ���." << endl;
	}
	Microwave micro(wh);

	while(1)
	{
		cout << "TV �Һ�����(����:Wh) : ";
		cin >> wh;

		if(wh>0)
			break;
		cout << "0 �̻��� ���ڸ� �Է����ּ���." << endl;
	}
	TV tv(wh);

	cout << "\n\n\n\n\n";







	while(1)
	{
		cout << "1. ������" << endl;
		cout << "2. ����ٸ���" << endl;
		cout << "3. ���ڷ�����" << endl;
		cout << "4. TV\n\n" << endl;
		cout << "��ȣ �Է� : ";
		cin >> ch1;
		cout << "\n\n\n";
		if (ch1>=1 && ch1<=4)
			cout << list[ch1-1] << "�� �����߽��ϴ�.\n\n";

		cout << "\n\n\n";

		while(ch1==1 && ch2!=10)
		{

			cout << "-----------------������------------------" << endl;
			cout << "1. ���� ����" << endl;
			cout << "2. �µ� ����" << endl;
			cout << "3. �µ� ����" << endl;
			cout << "4. �ٶ����� ����" << endl;
			cout << "5. �ٶ����� ����" << endl;
			cout << "6. ǳ�� ����" << endl;
			cout << "7. ǳ�� ����" << endl;
			cout << "8. ���� ���� Ȯ��" << endl;
			cout << "9. �Һ�����, ���ð�, ���¼Һ� Ȯ��" << endl;
			cout << "10. ��������" << endl;
			cout << "------------------------------------------\n\n" << endl;
			cout << "��ȣ �Է� : ";
			cin >> ch2;

			cout << "\n\n\n";

			aircon.Time_Calculation();	//�ݺ������� ����Ǽ� ����ð��� �������, �ٸ� ��ǰ�鵵 ��������.

			if(ch2==1 && aircon.GetState()==ON)	//���� ���������� ����
				aircon.Off();
			else if(ch2==1 && aircon.GetState()==OFF)	//���� ���������� �ѱ�
				aircon.On();
			else if(ch2>=2 && ch2<=7 && aircon.GetState()==ON)	//������ ��� ����
			{
				if(ch2==2)
					aircon.TemUp();
				else if(ch2==3)
					aircon.TemDown();
				else if(ch2==4)
					aircon.WinUp();
				else if(ch2==5)
					aircon.WinDown();
				else if(ch2==6)
					aircon.DirectUp();
				else if(ch2==7)
					aircon.DirectDown();
			}
			else if(ch2>=2 && ch2<=7 && aircon.GetState()==OFF)	//�������� ���������� ��ɵ��� �۵����� ����
				cout << "������ ���� �ֽ��ϴ�." << endl;
			else if(ch2==8)
				aircon.Check();
			else if(ch2==9)
				aircon.Elec_Usage();
			else if(ch2!=10)
				cout << "1���� 10 ������ ��ȣ�� �Է����ּ���." << endl;

			cout << "\n\n\n";
		}

		while(ch1==2 && ch2!=8)
		{
			iron.Time_Calculation();

			cout << "---------------���� �ٸ���----------------" << endl;
			cout << "1. ���� ����" << endl;
			cout << "2. �й��� ���" << endl;
			cout << "3. ���� ���" << endl;
			cout << "4. �µ� ����" << endl;
			cout << "5. �µ� ����" << endl;
			cout << "6. ���� ���� Ȯ��" << endl;
			cout << "7. �Һ�����, ���ð�, ���¼Һ� Ȯ��" << endl;
			cout << "8. ��������" << endl;
			cout << "------------------------------------------" << endl;
			cout << "���� : ";

			cin >> ch2;

			cout << "\n\n\n";

			iron.Time_Calculation();
			if(ch2==1 && iron.GetState()==OFF)	//���� ���������� Ŵ
				iron.On();
			else if(ch2==1 && iron.GetState()==ON)	//���� ���������� ��
				iron.Off();
			else if(ch2>=2 && ch2<=5 && iron.GetState()==ON)
			{
				if(ch2==2)
					iron.SetButton(1);
				else if(ch2==3)
					iron.SetButton(2);
				else if(ch2==4)
					iron.IronTemUp();
				else if(ch2==5)
					iron.IronTemDown();
			}
			else if(ch2>=2 && ch2<=5 && iron.GetState()==OFF)
				cout << "������ ���� �ֽ��ϴ�. ������ ���� ���ּ���." << endl;
			else if(ch2==6)
				iron.Check();
			else if(ch2==7)
				iron.Elec_Usage();
			else if(ch2!=8)
				cout << "1���� 8 ������ ��ȣ�� �Է����ּ���." << endl;

			cout << "\n\n\n";
		}

		while(ch1==3 && ch2!= 9)
		{
			cout << "----------------���ڷ�����----------------" << endl;	//���ڷ������� ���� ����
			cout << "1. �ص�" << endl;
			cout << "2. ����" << endl;
			cout << "3. ��(��)" << endl;
			cout << "4. ��(��)" << endl;
			cout << "5. ��(��)" << endl;
			cout << "6. ����ϱ�" << endl;
			cout << "7. ���� ���� �� ���� �ð� Ȯ��" << endl;
			cout << "8. �Һ�����, ���ð�, ���¼Һ� Ȯ��" << endl;
			cout << "9. ��������" << endl;
			cout << "------------------------------------------\n\n" << endl;
			cout << "���� : ";

			cin >> ch2;

			cout << "\n\n\n";
			micro.Micro_Time_Calculation();	//�߰��� ���ڷ����� �۵��ð� ����
											//�ð��� Ȯ���� �۵��ð��� �������� ���ڷ������� ���ش�.

			if(ch2>=1 && ch2<=5 && micro.GetState()==OFF)	//���������� ���� �� ��� ������
			{
				micro.ChoiceHeatFunc(ch2);	//��� ����
				micro.ChoiceHeatTime();		//������ �ð� �Է�
			}
			else if(ch2>=1 && ch2<=5 && micro.GetState()==ON)	//���� �߿� ��� ������
				cout << "�̹� �������Դϴ�." << endl;
			else if(ch2==6 && micro.GetState()==ON)
			{
				cout << "�۵��� ����մϴ�." << endl;
				micro.Off();
			}
			else if(ch2==6 && micro.GetState()==OFF)
			{
				cout << "�۵������� �ʽ��ϴ�." << endl;
			}
			else if(ch2==7)
				micro.Check();
			else if(ch2==8)
				micro.Micro_Elec_Usage();
			else if(ch2!=9)
				cout << "1���� 9 ������ ��ȣ�� �Է����ּ���." << endl;

			cout << "\n\n\n";
		}

		while(ch1==4 && ch2!=9)
		{
			cout << "--------------------TV--------------------" << endl;
			cout << "1. ���� ����" << endl;
			cout << "2. ä�� ����" << endl;
			cout << "3. ���� ����" << endl;
			cout << "4. ���� ����" << endl;
			cout << "5. ȭ�� ��� ����" << endl;
			cout << "6. ȭ�� ��� ����" << endl;
			cout << "7. ���� ���� Ȯ��" << endl;
			cout << "8. �Һ�����, ���ð�, ���¼Һ� Ȯ��" << endl;
			cout << "9. ��������" << endl;
			cout << "------------------------------------------\n\n" << endl;
			
			cout << "���� : ";
			cin >> ch2;

			cout << "\n\n\n";

			tv.Time_Calculation();

			if(ch2==1 && tv.GetState()==ON)
				tv.Off();
			else if(ch2==1 && tv.GetState()==OFF)
				tv.On();
			else if(ch2>=2 && ch2<=6 && tv.GetState()==ON)
			{
				if(ch2==2)
					tv.ChannelChoice();
				else if(ch2==3)
					tv.SoundUp();
				else if(ch2==4)
					tv.SoundDown();
				else if(ch2==5)
					tv.LightUp();
				else if(ch2==6)
					tv.LightDown();
			}
			else if(ch2>=2 && ch2<=6 && tv.GetState()==OFF)
				cout << "������ ���� �ֽ��ϴ�." << endl;
			else if(ch2==7)
				tv.Check();
			else if(ch2==8)
				tv.Elec_Usage();
			else if(ch2!=9)
				cout << "1���� 9 ������ ��ȣ�� �Է����ּ���." << endl;

			cout << "\n\n\n";
		}
		ch2 = 0;
	}
	return 0;
}