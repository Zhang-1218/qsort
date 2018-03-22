#define _CRT_SECURE_NO_WARNINGS 1

//使用冒泡排序的方法模拟实现函数qsort
#if 0
#include<stdio.h>

struct S //定义结构体S
{
	char name[20];
	int age;
};

void swap(char *elem1, char *elem2, int w)//交换函数
{
	int k = 0;
	char temp;
	for (k = 0; k < w; k++)//以字节为单位进行交换
	{
		temp = *(elem1 + k);
		*(elem1 + k) = *(elem2 + k);
		*(elem2 + k) = temp;
	}
}

int cmp_int(const void *elem1, const void *elem2)//整型比较
{
	return ((*(int *)elem1) - (*(int *)elem2));
}

int cmp_char(const void *elem1, const void *elem2)//字符比较
{
	return ((*(char *)elem1) - (*(char *)elem2));
}

int cmp_struct(const void *elem1, const void *elem2)//结构比较
{
	return (((struct S*)elem1)->age) - (((struct S*)elem2)->age);
}

void my_qsort(void * base, int num, int width, int(*cmp)(const void *elem1, const void *elem2))
{
	int i = 0;
	int j = 0;
	//int k = 0;
	//char tmp = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < (num - i - 1); j++)
		{
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
			{
				//for (k = 0; k < width; k++)
				//{
				//	tmp = *((char*)base + k + j*width);
				//	*((char*)base + k + j*width) = *((char*)base + k + (j + 1)*width);
				//	*((char*)base + k + (j + 1)*width) = tmp;
				//}
				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

int main()
{
	int i = 0;
	int arr[5] = { 1, 3, 2, 5, 4 };
	char str[5] = { 'a', 'c', 'd', 'b', 'e' };
	struct S s[] ={{ "zhaohaiyang", 21 },{ "zhanghang", 22 },{ "xuqiang",23}};

	int sz1 = sizeof(arr) / sizeof(arr[0]);
	int sz2 = sizeof(str) / sizeof(str[0]);
	int sz3 = sizeof(s) / sizeof(s[0]);

	int width1 = sizeof(arr[0]);
	int width2 = sizeof(str[0]);
	int width3 = sizeof(str[0]);

	my_qsort(arr, sz1, width1, cmp_int);
	my_qsort(str, sz2, width2, cmp_char);
	my_qsort(s, sz3, width3, cmp_struct);

	for (i = 0; i < sz1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (i = 0; i < sz2; i++)
	{
		printf("%c ",str[i]);
	}

	system("pause");
	return 0;
}
#endif

//计算器
#if 0
#include <stdio.h>
void menu()
{
	printf("*****************************************\n");
	printf("***********    1.Add   2.Sub    *********\n");
	printf("***********    3.Mul   4.Div    *********\n");
	printf("**************    0.EXIT    *************\n");
	printf("*****************************************\n");
}
int Add(int x, int y)
{
	return (x + y);
}
int Sub(int x, int y)
{
	return (x - y);
}
int Mul(int x, int y)
{
	return (x * y);
}
int Div(int x, int y)
{
	return (x / y);
}
void print(int(*p)(int, int))//通过函数指针p来接收函数Add等的地址
{
	int a = 0;
	int b = 0;
	int ret = 0;
	printf("请输入数字：<");
	scanf("%d%d", &a, &b);
	printf("%d\n\n", p(a,b));//通过函数指针p来对函数完成访问
}
int main()
{
	int input = 0;
	int ret = 0;
	do 
	{
		menu();
		printf("请选择:< ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			print(Add);
			break;
		case 2:
			print(Sub);
			break;
		case 3:
			print(Mul);
			break;
		case 4:
			print(Div);
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}
#endif