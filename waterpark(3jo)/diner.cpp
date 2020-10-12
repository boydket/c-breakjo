#include "Diner.h"

Diner::Diner() {
	Diner_time = 0;
	Diner_cost = 0;
}

void Diner::DinerMenu()    //�޴� ���� (��ȣ�� �޴��� ����)
{
	char OtherChoice;	//���� �߰����� 
	while (1)
	{
		cout << " -----------------------------" << endl;
		cout << "|             MENU            |" << endl;
		cout << "|                             |" << endl;
		cout << "|     1. �ܹ��� - 5000��      |" << endl;
		cout << "|     2. �ֵ��� - 3000��      |" << endl;
		cout << "|     3. ������ - 3000��      |" << endl;
		cout << "|     4. ��  �� - 2500��      |" << endl;
		cout << "|     5. �߷ν� - 2000��      |" << endl;
		cout << "|                             |" << endl;
		cout << "|     ����� - 1000��      |" << endl;
		cout << "|     6. ��������             |" << endl;
		cout << " -----------------------------" << endl;

		int DinerNum = 0;
		cout << "� �޴��� ��ðڽ��ϱ�? : " << endl;
		cin >> DinerNum;

			if (DinerNum == 1)
			{
				cout << "�ܹ��Ÿ� ��ðڽ��ϱ�?" << endl;
				cout << "�ܹ��Ŵ� 5000���Դϴ�." << endl;
				cout << "������ �Ĵ� ������ ��ø� �˴ϴ�." << endl;
				Diner_cost += 5000;
			}
			else if (DinerNum == 2)
			{
				cout << "�ֵ��׸� ��ðڽ��ϱ�?" << endl;
				cout << "�ֵ��״� 3000���Դϴ�." << endl;
				cout << "������ �Ĵ� ������ ��ø� �˴ϴ�." << endl;
				Diner_cost += 3000;
			}
			else if (DinerNum == 3)
			{
				cout << "�����̸� ��ðڽ��ϱ�?" << endl;
				cout << "�����̴� 3000���Դϴ�." << endl;
				cout << "������ �Ĵ� ������ ��ø� �˴ϴ�." << endl;
					Diner_cost += 3000;
			}
			else if (DinerNum == 4)
			{
				cout << "����� ��ðڽ��ϱ�?" << endl;
				cout << "����� 2500���Դϴ�." << endl;
				cout << "������ �Ĵ� ������ ��ø� �˴ϴ�." << endl;
				Diner_cost += 2500;
			}
			else if (DinerNum == 5)
			{
				cout << "�߷ν��� ��ðڽ��ϱ�?" << endl;
				cout << "�߷ν��� 2000���Դϴ�." << endl;
				cout << "������ �Ĵ� ������ ��ø� �˴ϴ�." << endl;
				Diner_cost += 2000;
			}
			else if (DinerNum == 6)
			{
				return;
			}
			else {
				cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
				cout << "1~5�� �� �ϳ��� ��ȣ�� �Է����ּ���." << endl << endl;
				continue;
			}
			
		while (1)
		{
			cout << "�ٸ� �޴��� �߰��Ͻðڽ��ϱ�? (Y/N)" << endl;    //�ٸ� �޴� �߰� ����
			cin >> OtherChoice;
			if (OtherChoice == 'Y' || OtherChoice == 'y'
				 || OtherChoice == 'N' || OtherChoice == 'n')
				break;	//y�Ǵ� n �Է½� �������� �Է��� �� ���̹Ƿ� while��  Ż��
			else 
			{
				cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
				cout << "Y/N�� �ϳ��� �Է����ּ���." << endl << endl;
			}
		}
		if (OtherChoice == 'Y' || OtherChoice == 'y')
			continue;	//y �Է½� 13��° ���� �޴� ������� ���ư��� �߰� �ֹ���
		else
		{
			break;	//n �Է½� Ż��
			cout << endl << endl;
		}
	}
};
void Diner::Drink()     //����� �߰�
{
	while (1) {
		char DrinkChoice;
		cout << "������� �߰��Ͻðڽ��ϱ�? (Y/N)" << endl;
		cin >> DrinkChoice;
		if (DrinkChoice == 'Y' || DrinkChoice == 'y' || DrinkChoice == 'N'
			 || DrinkChoice == 'n') 
		{
			switch (DrinkChoice) 
			{
			case 'Y':
			case 'y':
				cout << "������� 1000���Դϴ�. " << endl;
				cout << "������� ���漭���� �̿��Ͻø� �˴ϴ�." << endl;
				Diner_cost += 1000;
				break;
			case 'N':
			case 'n':
				break;
			default:
				break;
			}
			cout << endl << endl;
			return;
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			cout << "Y/N�� �ϳ��� �Է����ּ���." << endl << endl;
		}
	}
};

void Diner::DinerTime()     //�Ĵ��� �̿��� �ð��� �� ������ �Է�
{
	int time;
	while (1)
	{
		cout << "�Ĵ��� �̿��Ͻ� �ð�(��)�� �Է����ּ���." << endl;
		cin >> time;
		if (time > 0)
			break;
		else
			cout << "0���� ū ���� �Է����ּ���." << endl << endl;
	}
	cout << "�Ĵ� �̿� �ð� " << time << "�� �Է��ϼ̽��ϴ�." << endl;
	cout << "��ſ� �Ļ� �ð� �ǽʽÿ�." << endl << endl;
	cout << endl;
	Diner_time += time;
};

int Diner::GetDiner_Time() { return Diner_time; } // �Ĵ� �̿� �ð� ��ȯ
int Diner::GetDiner_Cost() { return Diner_cost; } // �Ĵ� �̿� �ݾ� ��ȯ