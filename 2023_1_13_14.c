//
//  2023_1_10_11.c
//  随堂coding
//
//  Created by 邱浩轩 on 2023/1/10.
//
#include "2023_1_10_11.h"
#include <stdlib.h>
#include <stdio.h>

void add(int *a)
{
    (*a)++;
}

//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
void chengfabiao(int x)
{
    for(int i=1;i<x+1;i++)
    {
        for(int j=1;j<i+1;j++)
        {
            printf("%dx%d = %d ",i,j,i*j);
        }
        printf("\n");
    }
}

//交换两个数
void Swap(int *a,int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void test1()
{
    int a=10;
    int b=20;
    int *p = &b;
    *p = 100;
    printf("%d,%d\n",*p,b);
    Swap(&a, &b); // 传址调用
    printf("%d,%d\n",a,b);
}

//判断闰年
void isrunnian(int x)
{
    if(x%400==0)
    {
        printf("%d年是闰年\n",x);
    }
    else if(x%4==0 && x%100!=0)
    {
        printf("%d年是闰年\n",x);
    }
    else
    {
        printf("%d年不是闰年\n",x);
    }
}

//实现一个函数，判断一个数是不是素数。
void isPrime(int x)
{
    int flag=0;
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
        {
            printf("%d不是素数\n",x);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("%d是素数\n",x);
    }
}

//递归顺序打印整形
void shunxudayinint(unsigned int x)
{
    if(x>9)
    {
        shunxudayinint(x/10); //当x四位数时，调用了四个函数
    }
    printf("%d ",x%10);
}

//递归求字符串长度
int my_strlen(char *p)
{
    if(*p!='\0')
    {
        return 1 + my_strlen(++p);
    }
    else
    {
        return 0;
    }
}

//非递归求字符串长度
int my_strlen_(char *p)
{
    int i=0;
    while (*p!='\0')
    {
        i++;
        p++;
    }
    return i;
}

//递归求阶乘
int my_jiecheng(int x)
{
    if(x!=1)
    {
        return x * my_jiecheng(x-1);
    }
    else
    {
        return 1;
    }
}

//非递归求阶乘
int my_jiecheng_(int x)
{
    int sum=1;
    for(int i=1;i<x+1;i++)
    {
        sum*=i;
    }
    return sum;
}

//斐波那契数列 1 1 2 3 5 8 13 21 34 .....,求第n个斐波那契数，递归效率低
int Fibonacci_1(int x)
{
    if(x>2)
    {
        return Fibonacci_1(x-1)+Fibonacci_1(x-2);
    }
    else
    {
        return 1;
    }
}

//用迭代效率高
int Fibonacci_2(int x)
{
    int a=1;
    int b=1;
    int c=1;
    while(x>=3)
    {
        c = a+b;
        a=b;
        b=c;
        x--;
    }
    return c;
}

//递归实现一个数字的n次方
int my_pow(int x,int y)
{
    if(y>1)
    {
        return x * my_pow(x, y-1);
    }
    else
    {
        return x;
    }
}

//计算一个数的每位之和（递归实现）
int DigitSum(int x)
{
    if(x>0)
    {
        return x%10+DigitSum(x/10);
    }
    else
    {
        return 0;
    }
}

//将参数字符串中的字符反向排列
/*************************************************************************************
递归方式：
对于字符串“abcdefg”，递归实现的大概原理：
  1. 交换a和g，
  2. 以递归的方式逆置源字符串的剩余部分，剩余部分可以看成一个有效的字符串，再以类似的方式逆置
*/
void reverse_string(char *arr)  //qwer
{
    int len = my_strlen(arr);
    char tmp = *arr;
    *arr = *(arr+len-1);  //rwer
    *(arr+len-1) = '\0';  //rwe
    if(my_strlen(++arr)>=2)
    {
        reverse_string(++arr);
    }
    *(arr+len-1) = tmp;
}

int main()
{
    char str[] = "qwer";
    char *p = str;
    *(p+1)='1';
    printf("%s\n",str);
}
