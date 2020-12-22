#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 51;
//这个程序没有任何问题，只是使用gdb调试有问题，改用vs2013就没有问题
void help()
{
    printf("\n*********************打字游戏规则***************************");
    printf("\n* 输入过程中无法退出，输入错误的字符用!表示*");
    printf("\n* 按任意键开始测试，按下首字母开始计时*");
    printf("\n***********************************************************\n");
}

void start(char *str)
{
    srand((unsigned int)time(NULL)); //随机数种子
    int i = 0;
    int len = MAX - 1;
    for (i = 0; i < len; i++)
    {
        *(str + i) = rand() % 26 + 'a';
    }
    *(str + len) = '\0';
}
void typetest(char *str)
{
    char ch;
    int i;
    int count = 0;
    time_t start, end;
    system("cls");
    printf("\n%s\n", str);
    int len = MAX - 1;
    for (i = 0; i < len; i++)
    {
        ch = _getch();
        if (i == 0)
        {
            start = time(NULL);
        }
        if (ch == *(str + i))
        {
            printf("%c", ch);
            count++;
        }
        else
        {
            printf("!");
        }
    }
    end = time(NULL);
    printf("\n测试结束，耗时:%d\n", end - start);
    printf("正确率：%d\n", (int)(count * 1.0 / len) * 100);
    printf("按下esc键结束，其他键继续....\n\n");
}

int main(int argc, char const *argv[])
{
    char str[51] = {0};
    while (1)
    {
        help();     //显示游戏说明
        start(str); //产生随机字母
        _getch();
        // printf("str=%s", str);
        typetest(str); //开始游戏
        char ch = _getch();
        if (ch == 27)
        {
            exit(1);
        }
        system("cls");
    }

    return 0;
}
