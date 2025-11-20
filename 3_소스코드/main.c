#include <stdio.h>

#include <stdio.h>
#include <string.h>

/*
    1. [설계]에서 정의한 변수, 배열, 구조체 선언
*/

struct Player {
    char name[30];     // 선수 이름
    char position[20]; // 포지션 (공격수, 수비수 등)
    int goals;         // 득점 수
    int games;         // 출전 경기 수
};

// 구조체 배열
struct Player players[100];
int count = 0;   // 현재 등록된 선수 수



/*
    2. [알고리즘]에서 설계한 핵심 기능 함수 선언
*/
void addPlayer();
void listPlayers();
void searchPlayer();
void showStats();



int main() {

    printf("--- C언어 미니 프로젝트 시작! ---\n");

    int menu;

    while (1) {

        printf("\n===== 메뉴 =====\n");
        printf("1. 선수 정보 입력\n");
        printf("2. 선수 목록 출력\n");
        printf("3. 선수 검색\n");
        printf("4. 통계 보기 (최고 득점자 / 평균 득점)\n");
        printf("0. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &menu);

        if (menu == 1) {
            addPlayer();
        }
        else if (menu == 2) {
            listPlayers();
        }
        else if (menu == 3) {
            searchPlayer();
        }
        else if (menu == 4) {
            showStats();
        }
        else if (menu == 0) {
            printf("프로그램 종료.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}



/*
    --- 핵심 기능 1: 선수 정보 입력 ---
*/
void addPlayer() {

    printf("\n[선수 정보 입력]\n");

    printf("이름: ");
    scanf("%s", players[count].name);

    printf("포지션: ");
    scanf("%s", players[count].position);

    printf("득점 수: ");
    scanf("%d", &players[count].goals);

    printf("출전 경기 수: ");
    scanf("%d", &players[count].games);

    count++;

    printf("선수 정보가 추가되었습니다.\n");
}



/*
    --- 핵심 기능 2: 선수 목록 출력 ---
*/
void listPlayers() {

    printf("\n[선수 목록]\n");

    if (count == 0) {
        printf("등록된 선수가 없습니다.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n--- 선수 %d ---\n", i + 1);
        printf("이름: %s\n", players[i].name);
        printf("포지션: %s\n", players[i].position);
        printf("득점: %d\n", players[i].goals);
        printf("경기 수: %d\n", players[i].games);
    }
}



/*
    --- 핵심 기능 3: 선수 검색 ---
*/
void searchPlayer() {

    char name[30];
    int found = 0;

    printf("\n검색할 선수 이름: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("\n[검색 결과]\n");
            printf("이름: %s\n", players[i].name);
            printf("포지션: %s\n", players[i].position);
            printf("득점: %d\n", players[i].goals);
            printf("경기 수: %d\n", players[i].games);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("해당 이름의 선수가 없습니다.\n");
    }
}



/*
    --- 핵심 기능 4: 통계 기능 ---
*/
void showStats() {

    if (count == 0) {
        printf("등록된 선수가 없어 통계를 볼 수 없습니다.\n");
        return;
    }

    int maxGoals = players[0].goals;
    int maxIndex = 0;
    int sum = 0;

    for (int i = 0; i < count; i++) {

        if (players[i].goals > maxGoals) {
            maxGoals = players[i].goals;
            maxIndex = i;
        }

        sum += players[i].goals;
    }

    double avg = (double)sum / count;

    printf("\n[통계 정보]\n");
    printf("최고 득점자: %s (%d 골)\n", players[maxIndex].name, maxGoals);
    printf("전체 평균 득점: %.2f 골\n", avg);
}
