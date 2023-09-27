#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


//int main()
//{
//    printf("Hello, World!\n");
//    return 0;
//}

void menu()
{
    printf("********************\n");
    printf("***   1.play   *****\n");
    printf("***   2.exit   *****\n");
    printf("********************\n");
}

void game()
{
    //先生成随机数
    int guess;
    int r = rand()%100+1;
    //进行猜数字
    int count = 5;
    while(count)
    {
        printf("请输入数字:>");
        scanf("%d",&guess);
        if(guess > r)
        {
            printf("猜大了\n");
        }
        else if(guess < r)
        {
            printf("猜小了\n");
        }
        else
        {
            printf("恭喜你，猜对了\n");
            break;
        }
        count--;
    }
    if (count == 0)
    {
        printf("猜数字失败，正确的值是：%d\n",r);
    }
}


int main()
{
    setbuf(stdout,NULL);
    int input;
    srand((unsigned int)time(NULL));
    do
    {
        //打印菜单
        menu();
        printf("请选择:<");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择\n");
                break;
        }
    }while(input);
    return 0;
}
