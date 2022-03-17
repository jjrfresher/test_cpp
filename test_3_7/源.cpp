#include<stdio.h>
//#pragma warning(disable:4996)

//int main()
//{
//	char ch1 = 0;
//	char ch2 = 0;
//	char ch3 = 0;
//	scanf_s("%c%c%c", &ch1, &ch2, &ch3);
//	printf("%c%c%c", ch1, ch2, ch3);
//	return 0;
//}
//指向函数指针数组的指针
//回调函数--一个通过函数指针调用的函数，如果你把函数的指针(地址)作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。
//回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另一方调用的，用于对该事件或条件进行响应
//void menu()
//{
//	printf("*************************\n");
//	printf("**  1.add      2.sub   **\n");
//	printf("**  3.mul      4.div   **\n");
//	printf("**        0.exit       **\n");
//	printf("*************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Xor(int x, int y)
//{
//	return x ^ y;
//}
//void Calc(int (*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数:>");
//	scanf_s("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//
//int main()
//{
//	int input = 0;
//	int x, y;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 5:
//			Calc(Xor);
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//通过回调函数解决了冗余
//指向函数指针数组的指针
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10] = &arr;//取出数组的地址
//	int(*pfArr[4])(int,int);//pfArr是一个数组-函数指针的数组
//	int(*(*ppfArr)[4])(int, int) = &pfArr;
//	//
//	//ppfArr 是一个数组指针，指针指向的数组有4个元素
//	//指向的数组的每个元素的类型是一个函数指针 int(*)(int,int)
//	return 0;
//}ppfArr是一个指向(函数指针数组)的指针

//回调函数
//void print(const char* str)
//{
//	printf("hehe:%s", str);
//}
//void test(void(*p)(const char*))
//{
//	printf("test\n");
//	p("bit");
//}
//int main()
//{
//
//	test(print);
//	return 0;
//}
//void BubbleSort(int arr[], int sz)
//{}
//int main()
//{
//	//冒泡排序函数只能排序整形数组
//	int arr[] = { 1,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr,sz);
//
//	return 0;
//}
//qsort--可以排序任意类型的数据//库函数
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//指针数组
//	//int* arr[10];//指针数组
//    //int*(*pa)[10] = &arr;
//    //函数指针
//	int(*pAdd)(int, int) = Add;
//	/*int sum=(*pAdd)(1, 2);
//	printf("sum=%d\n", sum);*/
//	//函数指针的数组
//	int(*pArr[5])(int, int);
//	//指向函数指针数组的指针
//	int(*(*ppArr)[5])(int, int) = &pArr;
//
//	return 0;
//}
//回调函数
// qsort

void bubble_sort(int arr[], int sz)
{
	int i = 0;
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//一趟冒泡排序
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			else
				break;
		}
	}
		
	
}
struct Stu 
{
	char name[20];
	int age;

};
//qsort-库函数-排序
//quick sort-算法思想，快速排序
//void qsort(void* base,
//	size_t num,
//	size_t width,
//	int(__cdecl* cmp)(const void* e1, const void* e2));
//qsort(arr,sizeof(arr),sizeof(arr[0]),)
int cmp_int(const void* e1, const void* e2)
{
	//比较两个整形值的
	return *(int*)e1 - *(int*)e2;
}
#include<stdlib.h>
#include<search.h>
#include<string.h>
void test1()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int cmp_float(const void* e1, const void* e2)
{
	return (int)( * (float*)e1 - *(float*)e2);
}
void test2()
{
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0 };
	int sz = (sizeof(f) / sizeof(f[0]));
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%f ", f[j]);
	}
}
int cmp_Stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
void test3()
{
	struct Stu s[3] = { {"张三",20},{"李四",30},{"王五",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_Stu_by_age);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",s[i].age);
	}

}
int cmp_Stu_by_name(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用＞<=来比较，应该用strcmp函数
	return strcmp(((struct Stu*)e1)->name , ((struct Stu*)e2)->name);
}
void test4()
{
	struct Stu s[3] = { {"张三",20},{"李四",30},{"王五",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_Stu_by_name);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ", s[i].name);
	}

}
int main()
{
	test1();
	printf("\n");
	test2();
	printf("\n");
	test3();
	printf("\n");
	test4();
//	struct Stu s[3] = { {"张三",20},{"李四",30},{"王五",10} };
	//float f[] = {9.0,8.0,7.0,6.0,5.0,4.0};

	/*bubble_sort(arr,sz);*/
	return 0;
}
//这样来理解
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	/*char* pc = &a;*/
//	//很明显char和int不兼容，那么有没有一种指针可以不介意类型呢？
//	void* p = &a;//无类型的指针
//	//*p = 0;//对于void型的指针，不能进行解引用操作
//	// p++;也会报错，void*类型的指针，不能进行加减整数的操作
//	//void*类型的指针，可以接收任意类型的地址
//}
//
