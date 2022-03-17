#include<stdio.h>
//指针进阶
//1.字符指针
//2.数组指针
//3.指针数组
//4.数组传参和指针传参
//5.函数指针
//6.函数指针数组
//7.指向函数指针数组的指针
//8.回调函数
//9.指针和数组面试题解析
//
//指针的大小是固定的4/8个字节(32位平台/64位平台)
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);//64位内存是8个字节，所以为2
//	printf("%d\n", sz);//
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);
//	return 0;
//}
//字符指针
//int main()
//{
//	char arr[] = "abcdef";
//	/*char ch = 'w';
//	char* pc = &ch;*/
//	/*char* pc = arr;*/
//	printf("%s\n", arr);
//	
//	return 0;
//}
//int main()
//{
//	const char* p = "abcdef";//"abcdef"是一个常量字符串,加一个const就行，所以无法更改
//	//其实是把a的地址赋给了p
//	printf("%c\n", *p);//a
//	//那么可以把*p对应的值更改吗？
//	//*p = 'w';//错误，const 修饰无法更改
//	printf("%s\n", p);//根据a的地址打印一段字符串"abcdef"
//	return 0;
//}
//www.stackoverflow.com
//segment fault，段错误
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";//这两个地址不同
//	const char* p1 = "abcdef";//常量字符串，不能被修改，一模一样，所以存的是一份字符串
//	const char* p2 = "abcdef";
//	if (p1 == p2)
//	{
//		printf("hehe\n");
//	}
//	else
//		printf("haha\n");
//	//打印hehe,因为所存储都是a的地址，所以一样的
//	/*if (arr1 == arr2)
//	{
//		printf("hehe\n");
//	}
//	else
//		printf("haha\n");*/
//	return 0;
//}
// 指针数组 数组
//int main()
//{
//	int arr[10] = { 0 };//整型数组
//	char ch[5] = { 0 };//字符数组
//	int* parr[4];//存放整形指针的数组-
//	char* pch[5];//存放字符指针的数组-指针数组
//
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int* arr[4] = { &a,&b,&c,&d };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d", *(arr[i]));
//	}
//	return 0;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ",*(parr[i] + j));
//		}
//		printf("\n");
//		
//	}
//	return 0;
//}
//数组指针
//
//int main()
//{
//	int* p=NULL;//整形指针-指向整型的指针-可以存放整形的地址
//	char* pc = NULL;//pc是字符指针-指向字符的指针-可以存放字符的地址
//	//数组指针-指向数组的指针-存放数组的地址
//	int arr[10] = { 0 };
//	//arr-首元素地址
//	//&arr[0]-首元素地址
//	//&arr-数组的地址
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	/*int*p[10] = &arr;*///数组地址存起来,如果这么写，这是整形指针数组，因为[]的优先级高于*,
//	//所以要这么写：
//	int(*p)[10] = &arr;//
//	
//
//	return 0;
//}
//int main()
//{
//	char* arr[5];
//	char*(*pa)[5] = &arr;//类似于二级指针，pa指向的数组的元素类型是char*
//	int arr2[10] = { 0 };
//	int (*pa2)[10] = &arr2;
//	return 0;
//}
//&数组名vs数组名
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));//最简单
//	}
//	//int(* pa)[10] = &arr;
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ",*pa+i);//*pa==arr
//	//}
//	/*for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*pa)[i]);这是一种写法
//	}*/
//}
//一般数组指针要用到二维数组以上，才方便
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////参数是指针的形式
//void print2(int (*p)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(p[i] + j));//p[i][j]
//			printf("%d ", *(*(p + i) + j));//两次操作
//			printf("%d ", (*(p + i))[j]);//两种写法均可以
//		}
//		printf("\n");
//	}
// int(*parr3[10])[5];是一个类似于二维数组，每个元素是一个int地址




//int main()
//{
//	//int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	//
//	//print1(arr,3,5);//arr-数组名-首元素地址，是1吗？不是
//	////把arr想象成一维数组，arr其实有三个元素，第一行就是它的首元素，就是第一行的地址
//	//print2(arr, 3, 5);//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int* p = arr;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//		printf("%d ", *(p + i));
//		printf("%d ", *(arr + i));
//		printf("%d ", arr[i]);//arr[i]== *(arr+i) == *(p+i) ==p[i]
//	}
//	return 0;
//}
//数组参数，指针参数
//一维数组传参
//void test2(int* arr[20])//0k
//{}
//void test2(int** arr)//ok
//{}
//int main()
//{
//	int* arr2[20] = { 0 };
//	test2(arr2);
//}
//void test(int arr[3][5])
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);//二维数组传参，可以省略行，不能省略列
//	return 0;
//}
//void test3(int *arr)//error
//void test4(int**arr )//error
//{}
//void test5(int(*arr)[5])
//{}
//
//int main()
//{
//	int arr[3][5] = { 0 };
//	test5(arr);
//	return 0;
//}
//一级指针传参,接受地址
//二级指针传参
//void test(int** p)
//{
//
//}
//int main()
//{
//	int* ptr;
//	int** pp = &ptr;
//	test(pp);
//	test(&ptr);
//	int* arr[10];//
//	test(arr);//一级指针数组也可以
//	return 0;
//}
//函数指针
//数组指针-指向数组的指针
//函数指针-指向函数的指针
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;
//	//printf("%d\n", Add(a, b));
//	//函数有地址吗？
//	//printf("%p\n", &Add);
//	//printf("%p\n", Add);//一样，在函数里&函数名和函数名都是函数的地址
//	int (* pa)(int, int) = Add;//仿照数组，由于优先级高，所以要*pa括起来
//	printf("%d\n", (*pa)(2, 3));//5
//	return 0;
//}

//void Print(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	void(*p)(const char*) = Print;
//	(*p)("hello bit");
//	return 0;
//}
//两端有趣的代码
//(*(void(*)())0)();//void(*)()-函数指针类型；强制转换整形0为函数地址。再之前的*是解读这个地址,找到了这个函数
//这个函数是函数调用，调用0地址处的该函数
//《C陷阱和缺陷》
//代码2       整形  函数指针类型
//void(*signal(int,void(*)(int)))(int)-返回类型-函数指针
//void(*)(int) signal(int,void(*)(int))--正确方式，难以理解
//void(*signal(int, void(*)(int)))(int);//简化,利用typedef函数
//typedef void(* pfun_t)(int);
//typedef unsigned int uint;//之前操作
////改造
//pfun_t signal(int, pfun_t);
//signal 是一个函数声明
//signal 函数的参数有2个，第一个是int ，第二个是函数指针，该函数指针指向的函数的参数是int，返回类型是void
//signal 函数的返回类型也是一个函数指针：该函数指针指向的函数的参数是int，返回类型是void
