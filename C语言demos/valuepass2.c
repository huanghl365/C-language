#include <stdio.h>
#include <malloc.h>
void valuepass(int *tmp)
{
    tmp = (int *)malloc(sizeof(int));
    *tmp = 100;
}

void valuepass2(int *tmp) //注意与valuepass的区别，如果堆内存在调用函数里面创建就没有问题
{

    *tmp = 200;
}

int setValue(int *tmp)
{
    tmp = (int *)malloc(sizeof(int));
    *tmp = 100;
    return *tmp; //必须将值返回否则得不到值
}
int main(int argc, char const *argv[])
{
    /* int *p = NULL;
    valuepass(p); //注意，这里只是修改了p的副本所指向的内存的值，因为这是值传递
    printf("*p=%d", *p);//这里会报错 */

    /*  int a = 0;
    a = setValue(&a);
    printf("a=%d", a); */
    int *p = NULL;
    p = (int *)malloc(sizeof(int));
    valuepass2(p); //ok
    printf("*p=%d", *p);
    return 0;
}
