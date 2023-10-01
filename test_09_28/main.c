#include "add.h"

void menu()
{
    printf("***********************\n");
    printf("******  1. play   *****\n");
    printf("******  0. exit   *****\n");
    printf("***********************\n");
}

void game()
{
    char mine[ROWS][COLS];//'0'
    char show[ROWS][COLS];//'*'
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    DisplayBoard(show, ROW, COL);

    //布置雷
    SetMine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);

    //排查雷
    FindMine(mine, show, ROW, COL);
}

int main()
{
    setbuf(stdout,NULL);
    int input;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择:>");
                break;
        }
    }while(input);
    return 0;
}