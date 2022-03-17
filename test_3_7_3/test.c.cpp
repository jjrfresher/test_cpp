#include<stdio.h>
#include<string.h>
//一维数组
//数组名是元素首元素地址
//1.sizeof(数组名)-数组名表示整个数组
//2.&数组名-数组名表示整个数组
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//sizeof(数组名)-计算是数组总大小-16
//	printf("%d\n", sizeof(a + 0));//8，为什么是8呢（64位平台上地址大小为8）
//	printf("%d\n", sizeof(*a));//4
//	printf("%d\n", sizeof(a + 1));//8,这是第二个元素的地址
//	printf("%d\n", sizeof(a[1]));//4-第二个元素的大小	
//	printf("%d\n", sizeof(&a));//8, &a取出的是数组的地址，但是数组的地址也是地址，地址的大小就是4个或8个，😅
//	printf("%d\n", sizeof(*&a));//16
//	printf("%d\n", sizeof(&a + 1));//8
//	printf("%d\n", sizeof(&a[0]));//8
//	printf("%d\n", sizeof(&a[0] + 1));//8
//	return 0;
//}
int main()
{
	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(arr));//6
	//printf("%d\n", sizeof(arr + 0));//8
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//1
	//printf("%d\n", sizeof(&arr));//8
	//printf("%d\n", sizeof(&arr + 1));//8
	//printf("%d\n", sizeof(&arr[0] + 1));//8
	printf("%d\n", strlen(arr));//随机值
	printf("%d\n", strlen(arr + 0));//随机值,没有'\0'，不是字符串，不会自动补'\0'
	//printf("%d\n", strlen(*arr));//给他一个97地址，往后程序崩溃
	//printf("%d\n", strlen(arr[1]));//还是一个‘b’，error
	printf("%d\n", strlen(&arr[6]));//随机值
	printf("%d\n", strlen(&arr[6] + 1));//随机值-6
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1
	return 0;
}