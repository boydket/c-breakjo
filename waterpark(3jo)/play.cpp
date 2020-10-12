#include "play.h"


namespace PLAY
{
    enum
    {
        POOL_COST = 100, RIVER_COST = 150,      //파도풀, 유수풀 분당 비용
        SLIDE_COST = 3000, SLIDE_TIME = 30,      //슬라이드 비용, 시간
        MIN_HEIGHT = 140, MAX_HEIGHT = 190         //슬라이드 키제한
    };
}


play::play()   //초기화
{
    play_time = 0;
    play_cost = 0;
}

void play::List()   //놀이기구 리스트 출력
{
    cout << "1. 파도풀" << endl;
    cout << "2. 유수풀" << endl;
    cout << "3. 슬라이드" << endl;
    cout << "4. 이전으로" << endl << endl;
}

int play::PlayPool(int state)   //파도풀 이용시간 입력, 금액추가
{
    int time;
    if (state == 0)
    {
        cout << "파도풀은 구명조끼나 튜브 없이 이용하실 수 없습니다." << endl;
        cout << "대여소에서 구명조끼나 튜브를 대여해주세요." << endl;
        return 0;
    }
    while (1)
    {
        cout << "파도풀을 몇분 이용하시겠습니까?" << endl;
        cin >> time;
        if (time > 0)
            break;
        else
            cout << "0보다 큰 수를 입력해주세요." << endl << endl;
    }
    cout << "파도풀 이용시간은 " << time << "분이고" << endl;
    cout << "파도풀 이용 금액은 " << time * PLAY::POOL_COST << "원 입니다." << endl << endl;
    play_cost += time * PLAY::POOL_COST;
    play_time += time;

    return time;
}


int play::PlayRiver()   //유수풀 이용시간 입력, 금액추가
{
    int time;
    while (1)
    {
        cout << "유수풀을 몇분 이용하시겠습니까?" << endl;
        cin >> time;

        if (time > 0)
            break;
        else
            cout << "0보다 큰 수를 입력해주세요." << endl << endl;
    }
    cout << "유수풀 이용시간은 " << time << "분이고" << endl;
    cout << "유수풀 이용 금액은" << time * PLAY::RIVER_COST << "원 입니다." << endl << endl;
    play_cost += time * PLAY::RIVER_COST;
    play_time += time;

    return time;
}


int play::PlaySlide(int height)   //슬라이드 이용시간, 금액 추가
{
    if (height<PLAY::MIN_HEIGHT || height>PLAY::MAX_HEIGHT)
    {
        cout << "슬라이드는 키가 140이상, 190미만이어야 탑승하실 수 있습니다." << endl << endl;
        return 0;
    }
    cout << "슬라이드 경과시간은 " << PLAY::SLIDE_TIME << "분 이고" << endl;
    cout << "슬라이드 이용 금액은" << PLAY::SLIDE_COST << "원 입니다." << endl << endl;
    play_cost += PLAY::SLIDE_COST;
    play_time += PLAY::SLIDE_TIME;

    return PLAY::SLIDE_TIME;
}


int play::GetPlay_Time() { return play_time; }   //시설 이용 시간 반환


int play::GetPlay_Cost() { return play_cost; }   //시설 이용 요금 반환

void play::AddPlay_time(int time)
{
    play_time += time;
}