#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int main()
//{
//    //申请一块空间用来存放10个整型
//    int* p = (int*)malloc(10*sizeof(int));
//    if(p == NULL)
//    {
//        perror("malloc");
//        return 1;
//    }
//    int i = 0;
//    for(i = 0;i < 10;i++)
//    {
//        *(p + i) = i;
//    }
//    for(i = 0;i < 10;i++)
//    {
//        printf("%d",p[i]);
//    }
//
//    free(p);
//    p = NULL;
//
//    return 0;
//}

//int main()
//{
//    int* p = calloc(10 , sizeof(int));
//    if(p == NULL)
//    {
//        perror("malloc");
//        return 1;
//    }
//
//    int i = 0;
//    for(i = 0;i < 10;i++)
//    {
//        p[i] = i;
//    }
//    //打印
//    for(i = 0;i < 10;i++)
//    {
//        printf("%d",*(p + i));
//    }
//    //调整p的空间为20个整型
//    int* ptr = (int*)realloc(p,20 * sizeof(int));
//    if(ptr != NULL)
//    {
//        p = ptr;
//    }
//    //释放
//    free(p);
//    p = NULL;
//    return 0;
//}

//int main()
//{
//    int* p = (int*)realloc(NULL,40);//==malloc(40)
//}

//int main()
//{
//    int* p = (int*)malloc(40);
//    //不做返回值判断，就可能对NULL进行解引用操作
//    if(p == NULL)
//    {
//
//    }
//    *p = 20;
//
//    return 0;
//}

//int main()
//{
//    int* p = calloc(10 , sizeof(int));
//    if(p == NULL)
//    {
//        perror("calloc");
//        return 1;
//    }
//
//    int i = 0;
//    //越界了
//    for(i = 0;i <= 10;i++)
//    {
//        p[i] = i;
//    }
//    //打印
//    for(i = 0;i <= 10;i++)
//    {
//        printf("%d",*(p + i));
//    }
//
//    //释放
//    free(p);
//    p = NULL;
//    return 0;
//}

//对非动态开辟的内存使用free释放
//int main()
//{
//    int a = 10;
//    int* p = &a;
//    free(p);
//    p = NULL;
//    return 0;
//}

//使用free释放一块动态开辟内存的一部分
//int main()
//{
//    int* p = calloc(10 , sizeof(int));
//    if(p == NULL)
//    {
//        perror("calloc");
//        return 1;
//    }
//
//    int i = 0;
//    for(i = 0;i < 5;i++)
//    {
//        *p = i;
//        p++;
//    }
//    //释放了其中的一部分
//
//    //释放
//    free(p);
//    p = NULL;
//    return 0;
//}

//对同一块动态内存多次释放
//int main()
//{
//    int* p = malloc(40);
//    if(p == NULL)
//    {
//        return 1;
//    }
//    free(p);
//    p = NULL;
//    free(p);
//}

//动态开辟内存忘记释放（内存泄漏）
//void test()
//{
//    int* p = (int*)malloc(40);
//    if(3)
//        return;
//    free(p);
//    p = NULL;
//}
//int main()
//{
//    int* ret = test();
//    free(ret);
//    ret = NULL;
//    while(1)
//    {
//        ;
//    }
//    return 0;
//}

//void GetMemory(char** p)
//{
//    *p = (char *)malloc(100);
//}
//void Test(void)
//{
//    char* str = NULL;
//    GetMemory(&str);
//    strcpy(str, "hello world");
//    printf(str);
//    free(str);
//    str = NULL;
//}
//int main()
//{
//    Test();
//    return 0;
//}

//char *GetMemory(void)
//{
//    char p[] = "hello world";
//    return p;
//}
//void Test(void)
//{
//    char *str = NULL;
//    str = GetMemory();
//    printf(str);
//}
//int main()
//{
//    Test();
//    return 0;
//}

//int test()
//{
//    int a = 10;
//    int b = 20;
//    int c = a + b;
//    return c;
//}
//
//int main()
//{
//    int d = test();
//    return 0;
//}

//int* test()
//{
//    int a = 10;
//    return &a;
//}
//int main()
//{
//    int* p = test();
//    printf("%d\n",*p);
//    return 0;
//}

//void GetMemory(char **p, int num)
//{
//    *p = (char *)malloc(num);
//}
//void Test(void)
//{
//    char *str = NULL;
//    GetMemory(&str, 100);
//    strcpy(str, "hello");
//    printf(str);
//}
//int main()
//{
//    Test();
//    return 0;
//}

//void Test(void)
//{
//    char *str = (char *) malloc(100);
//    strcpy(str, "hello");
//    free(str);
//    if(str != NULL)
//    {
//        strcpy(str, "world");
//        printf(str);
//    }
//}
//int main()
//{
//    Test();
//    return 0;
//}

struct S
{
    char c;//1
    //3
    int i;//4
    int arr[];
};
int main()
{
    struct S* ps = malloc(sizeof(struct S) + 20);
    if(ps == NULL)
    {
        perror("malloc");
        return 1;
    }
    ps->c = 'w';
    ps->i = 100;
    int i = 0;
    for(i = 0;i < 5;i++)
    {
        ps->arr[i] = i;
    }
    //打印
    for(i = 0;i < 5;i++)
    {
        printf("%d",ps->arr[i] );
    }
    //空间不够了
    struct S* ptr = (struct S*)realloc(ps,sizeof(struct S) + 40);
    if(ptr == NULL)
    {
        ps = ptr;
    }
    else
    {
        perror("realloc");
        return 1;
    }
    //增容成功后可以继续使用
    //释放
    free(ps);
    ps = NULL;
    return 0;
}





















