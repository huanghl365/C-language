#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 51;

void help()
{
	printf("\n*********************������Ϸ����***************************");
	printf("\n* ����������޷��˳������������ַ���!��ʾ*");
	printf("\n* ���������ʼ���ԣ���������ĸ��ʼ��ʱ*");
	printf("\n***********************************************************\n");
}

void start(char *str)
{
	srand((unsigned int)time(NULL)); //���������
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
	printf("\n���Խ�������ʱ:%d\n", end - start);
	printf("��ȷ�ʣ�%d %%\n", (int)(count *1.0 / len) * 100);
	printf("����esc������������������....\n\n");
}

int main(int argc, char const *argv[])
{
	char str[51] = { 0 };
	while (1)
	{
		help();     //��ʾ��Ϸ˵��
		start(str); //���������ĸ
		_getch();
		// printf("str=%s", str);
		typetest(str); //��ʼ��Ϸ
		char ch = _getch();
		if (ch == 27)
		{
			//break;
			exit(1);
		}
		system("cls");
	}

	return 0;
}
