#include "play.h"


namespace PLAY
{
    enum
    {
        POOL_COST = 100, RIVER_COST = 150,      //�ĵ�Ǯ, ����Ǯ �д� ���
        SLIDE_COST = 3000, SLIDE_TIME = 30,      //�����̵� ���, �ð�
        MIN_HEIGHT = 140, MAX_HEIGHT = 190         //�����̵� Ű����
    };
}


play::play()   //�ʱ�ȭ
{
    play_time = 0;
    play_cost = 0;
}

void play::List()   //���̱ⱸ ����Ʈ ���
{
    cout << "1. �ĵ�Ǯ" << endl;
    cout << "2. ����Ǯ" << endl;
    cout << "3. �����̵�" << endl;
    cout << "4. ��������" << endl << endl;
}

int play::PlayPool(int state)   //�ĵ�Ǯ �̿�ð� �Է�, �ݾ��߰�
{
    int time;
    if (state == 0)
    {
        cout << "�ĵ�Ǯ�� ���������� Ʃ�� ���� �̿��Ͻ� �� �����ϴ�." << endl;
        cout << "�뿩�ҿ��� ���������� Ʃ�긦 �뿩���ּ���." << endl;
        return 0;
    }
    while (1)
    {
        cout << "�ĵ�Ǯ�� ��� �̿��Ͻðڽ��ϱ�?" << endl;
        cin >> time;
        if (time > 0)
            break;
        else
            cout << "0���� ū ���� �Է����ּ���." << endl << endl;
    }
    cout << "�ĵ�Ǯ �̿�ð��� " << time << "���̰�" << endl;
    cout << "�ĵ�Ǯ �̿� �ݾ��� " << time * PLAY::POOL_COST << "�� �Դϴ�." << endl << endl;
    play_cost += time * PLAY::POOL_COST;
    play_time += time;

    return time;
}


int play::PlayRiver()   //����Ǯ �̿�ð� �Է�, �ݾ��߰�
{
    int time;
    while (1)
    {
        cout << "����Ǯ�� ��� �̿��Ͻðڽ��ϱ�?" << endl;
        cin >> time;

        if (time > 0)
            break;
        else
            cout << "0���� ū ���� �Է����ּ���." << endl << endl;
    }
    cout << "����Ǯ �̿�ð��� " << time << "���̰�" << endl;
    cout << "����Ǯ �̿� �ݾ���" << time * PLAY::RIVER_COST << "�� �Դϴ�." << endl << endl;
    play_cost += time * PLAY::RIVER_COST;
    play_time += time;

    return time;
}


int play::PlaySlide(int height)   //�����̵� �̿�ð�, �ݾ� �߰�
{
    if (height<PLAY::MIN_HEIGHT || height>PLAY::MAX_HEIGHT)
    {
        cout << "�����̵�� Ű�� 140�̻�, 190�̸��̾�� ž���Ͻ� �� �ֽ��ϴ�." << endl << endl;
        return 0;
    }
    cout << "�����̵� ����ð��� " << PLAY::SLIDE_TIME << "�� �̰�" << endl;
    cout << "�����̵� �̿� �ݾ���" << PLAY::SLIDE_COST << "�� �Դϴ�." << endl << endl;
    play_cost += PLAY::SLIDE_COST;
    play_time += PLAY::SLIDE_TIME;

    return PLAY::SLIDE_TIME;
}


int play::GetPlay_Time() { return play_time; }   //�ü� �̿� �ð� ��ȯ


int play::GetPlay_Cost() { return play_cost; }   //�ü� �̿� ��� ��ȯ

void play::AddPlay_time(int time)
{
    play_time += time;
}