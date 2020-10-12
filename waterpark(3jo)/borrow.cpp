#include "borrow.h"
#include <iostream>

borrow::borrow()
{
    height = 0;			//Ű
    weight = 0;			//������
    state = 0;			//�ƹ��͵� ������ 0, �������� ������´� 1, Ʃ�� ������ 2, �� �� ������ 3			
    vest_price = 0;		//�������� ����
    tube_price = 0;		//Ʃ�� ����
    v_borrow_time = 0;	//�������� �뿩�ð�
    t_borrow_time = 0;	//Ʃ�� �뿩�ð�
    b_cost = 0;			//�� �뿩���
}

void borrow::Fixborrow(int height, int weight)
{
    this->height = height;
    this->weight = weight;
}

int borrow::GetVest_price()
{
    return this->vest_price;
}

int borrow::GetTube_price()
{
    return this->tube_price;
}

int borrow::GetV_borrow_time()
{
    return this->v_borrow_time;
}

int borrow::GetT_borrow_time()
{
    return this->t_borrow_time;
}

int borrow::GetState()
{
    return this->state;
}

int borrow::GetB_cost()
{
    return b_cost;
}

void borrow::AddState(int value)
{
    this->state += value;
}

void borrow::SubState(int value)
{
    this->state -= value;
}

void borrow::AddV_borrow_time(int time)
{
    v_borrow_time += time;
}

void borrow::AddT_borrow_time(int time)
{
    t_borrow_time += time;
}

void borrow::AddB_cost(int cost)
{
    b_cost += cost;
}

void borrow::borrow_system()
{
    int selection;  //�ϰ���� �ൿ�� ������ ����
    int cost;       //�߻��ϴ� �뿩�Ḧ �ӽ÷� ������ ����
    cout << "�뿩�ҿ� �湮�߽��ϴ�." << endl << endl;
    while (1)
    {
        
        cout << "1. �������� �뿩" << endl;
        cout << "2. Ʃ�� �뿩" << endl;
        cout << "3. �������� �ݳ�" << endl;
        cout << "4. Ʃ�� �ݳ�" << endl;
        cout << "5. �������� ���ư���" << endl;

        cout << endl << "�Է� : ";
        cin >> selection;
        cout << endl << endl;
        //���������� 1��, Ʃ��� 2������ �޾� selection�� ����.

        if (selection == 1) //���������� ����
        {
            if (state == 1 || state == 3)
            {
                cout << "�̹� ���������� �뿩���Դϴ�.\n\n\n" << endl;
                continue;
            }

            cout << height << "cm�Դϴ�." << endl;

            if (height <= 140) //Ű 140cm���ϸ� �������� ����
            {
                cout << "�������� ������ �뿩�ϼ̽��ϴ�." << endl;
                vest_price = 3000; //1�ð��� 3000��

            }
            else if (140 < height < 165)//Ű 140�ʰ�, 165�̸��̸� �������� ����
            {
                cout << "�������� ������ �뿩�ϼ̽��ϴ�." << endl;
                vest_price = 4000; //1�ð��� 4000��
            }
            else if (height >= 165)//Ű 165cm�̻��̸� �������� ����
            {
                cout << "�������� ������ �뿩�ϼ̽��ϴ�." << endl;
                vest_price = 5000; //1�ð��� 5000��
            }
            cout << "�뿩��� �ð��� " << vest_price << "�� �Դϴ�." << endl;
            state += 1;  //state�� ���� 1 �߰�
        }

        else if (selection == 2) //Ʃ�긦 ����
        {
            if (state == 2 || state == 3)
            {
                cout << "�̹� Ʃ�긦 �뿩���Դϴ�.\n\n\n" << endl;
                continue;
            }

            cout << weight << "kg�Դϴ�." << endl;

            if (weight <= 50) //������ 50kg���ϸ� Ʃ�� ����
            {
                cout << "Ʃ�� ������ �뿩�ϼ̽��ϴ�." << endl;
                tube_price = 3000;  //1�ð��� 3000��

            }
            else if (50 < weight < 70)//������ 50kg�ʰ�, 70kg�̸��̸� Ʃ�� ����
            {
                cout << "Ʃ�� ������ �뿩�ϼ̽��ϴ�." << endl;
                tube_price = 4000;  //1�ð��� 4000��
            }
            else if (weight >= 70)  //������ 70kg�̻��̸� Ʃ�� ����
            {
                cout << "Ʃ�� ������ �뿩�ϼ̽��ϴ�." << endl;
                tube_price = 5000;  //1�ð��� 5000��
            }
            cout << "�뿩��� �ð��� " << tube_price << "�� �Դϴ�." << endl;
            state += 2;  //state�� ���� 2 �߰�
        }

        else if (selection == 3)
        {
            if (state == 1 || state == 3)   //���������� �����ߴ��� Ȯ��
            {
                cout << "���������� �ݳ��մϴ�." << endl;
                cost = vest_price * ((v_borrow_time / 60) + 1);
                cout << v_borrow_time << "���� �뿩�߽��ϴ�." << endl;
                cout << "�뿩��� " << cost << "���Դϴ�." << endl;
                state -= 1; //state ���� 1 ����
                v_borrow_time = 0;  //�ݳ������Ƿ� �뿩�ð� 0
                b_cost += cost;     //�� �뿩��뿡 ���� �߻��� �뿩��� �߰�
            }
            else
            {
                cout << "���������� �뿩�ϰ� ���� �ʽ��ϴ�." << endl;
            }
        }

        else if (selection == 4)
        {
            if (state == 2 || state == 3) //Ʃ�� �����ߴ��� Ȯ��
            {
                cout << "Ʃ�긦 �ݳ��մϴ�." << endl;
                cost = tube_price * ((t_borrow_time / 60) + 1);
                cout << t_borrow_time << "���� �뿩�߽��ϴ�." << endl;
                cout << "�뿩��� " << cost << "���Դϴ�." << endl;
                state -= 2; //state ���� 2 ����
                t_borrow_time = 0;  //�ݳ������Ƿ� �뿩�ð� 0
                b_cost += cost; //�� �뿩��뿡 ���� �߻��� �뿩��� �߰�
            }

            else
            {
                cout << "Ʃ�긦 �뿩�ϰ� ���� �ʽ��ϴ�." << endl;
            }
        }

        else if (selection == 5)
            return;

        cout << "\n\n\n" << endl;
    }
}