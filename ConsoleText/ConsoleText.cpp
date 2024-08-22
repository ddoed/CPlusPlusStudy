#include "Windows.h"
#include <iostream>
#include <consoleapi2.h>
#include <tchar.h>
#include <string>
#include <strsafe.h>
#include <conio.h>
#include <stdio.h>
#include "Parser.h"
#include "GameCore.h"



int main()
{
    TCHAR buf[256]; // 키보드 자판을 모두 대응하는 크기
    StringCchPrintfW(buf, 256, TEXT("%s 콘솔 텍스트 게임 버전 %f"), _T("MadeBy 임나빈"), 1.00f);
    SetConsoleTitleW(buf);
    // 1. 메인메뉴 : 게임 시작(데이터의 초기화 진행 : 맵생성)
    // InitializeGame()
    PlayerState player;
    WorldState world;
    InitializeGame(player, world);
    // namespace ConsoleText Gameplay 클래스
    // -> 1. 플레이어의 입력 변환, 플레이어 함수 구현
    
    
    while (true)
    {
        // 플레이어의 입력 : if(Async wasd)
        ParseCommand(); // player의 x,y 좌표 이동
        // Rendering : 이미지를 그려주는 것
        // Update : 특정위치에 도착하면 다음 맵으로 이동
        // Quit : 게임 종료 기능 함수, Bool Quit -> break Exit(0)
    }
    //데이터 기록
}

