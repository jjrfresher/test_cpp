#include<stdio.h>
//ָ�����
//1.�ַ�ָ��
//2.����ָ��
//3.ָ������
//4.���鴫�κ�ָ�봫��
//5.����ָ��
//6.����ָ������
//7.ָ����ָ�������ָ��
//8.�ص�����
//9.ָ����������������
//
//ָ��Ĵ�С�ǹ̶���4/8���ֽ�(32λƽ̨/64λƽ̨)
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);//64λ�ڴ���8���ֽڣ�����Ϊ2
//	printf("%d\n", sz);//
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);
//	return 0;
//}
//�ַ�ָ��
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
//	const char* p = "abcdef";//"abcdef"��һ�������ַ���,��һ��const���У������޷�����
//	//��ʵ�ǰ�a�ĵ�ַ������p
//	printf("%c\n", *p);//a
//	//��ô���԰�*p��Ӧ��ֵ������
//	//*p = 'w';//����const �����޷�����
//	printf("%s\n", p);//����a�ĵ�ַ��ӡһ���ַ���"abcdef"
//	return 0;
//}
//www.stackoverflow.com
//segment fault���δ���
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";//��������ַ��ͬ
//	const char* p1 = "abcdef";//�����ַ��������ܱ��޸ģ�һģһ�������Դ����һ���ַ���
//	const char* p2 = "abcdef";
//	if (p1 == p2)
//	{
//		printf("hehe\n");
//	}
//	else
//		printf("haha\n");
//	//��ӡhehe,��Ϊ���洢����a�ĵ�ַ������һ����
//	/*if (arr1 == arr2)
//	{
//		printf("hehe\n");
//	}
//	else
//		printf("haha\n");*/
//	return 0;
//}
// ָ������ ����
//int main()
//{
//	int arr[10] = { 0 };//��������
//	char ch[5] = { 0 };//�ַ�����
//	int* parr[4];//�������ָ�������-
//	char* pch[5];//����ַ�ָ�������-ָ������
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
//����ָ��
//
//int main()
//{
//	int* p=NULL;//����ָ��-ָ�����͵�ָ��-���Դ�����εĵ�ַ
//	char* pc = NULL;//pc���ַ�ָ��-ָ���ַ���ָ��-���Դ���ַ��ĵ�ַ
//	//����ָ��-ָ�������ָ��-�������ĵ�ַ
//	int arr[10] = { 0 };
//	//arr-��Ԫ�ص�ַ
//	//&arr[0]-��Ԫ�ص�ַ
//	//&arr-����ĵ�ַ
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	/*int*p[10] = &arr;*///�����ַ������,�����ôд����������ָ�����飬��Ϊ[]�����ȼ�����*,
//	//����Ҫ��ôд��
//	int(*p)[10] = &arr;//
//	
//
//	return 0;
//}
//int main()
//{
//	char* arr[5];
//	char*(*pa)[5] = &arr;//�����ڶ���ָ�룬paָ��������Ԫ��������char*
//	int arr2[10] = { 0 };
//	int (*pa2)[10] = &arr2;
//	return 0;
//}
//&������vs������
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));//���
//	}
//	//int(* pa)[10] = &arr;
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ",*pa+i);//*pa==arr
//	//}
//	/*for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*pa)[i]);����һ��д��
//	}*/
//}
//һ������ָ��Ҫ�õ���ά�������ϣ��ŷ���
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
////������ָ�����ʽ
//void print2(int (*p)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(p[i] + j));//p[i][j]
//			printf("%d ", *(*(p + i) + j));//���β���
//			printf("%d ", (*(p + i))[j]);//����д��������
//		}
//		printf("\n");
//	}
// int(*parr3[10])[5];��һ�������ڶ�ά���飬ÿ��Ԫ����һ��int��ַ




//int main()
//{
//	//int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	//
//	//print1(arr,3,5);//arr-������-��Ԫ�ص�ַ����1�𣿲���
//	////��arr�����һά���飬arr��ʵ������Ԫ�أ���һ�о���������Ԫ�أ����ǵ�һ�еĵ�ַ
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
//���������ָ�����
//һά���鴫��
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
//	test(arr);//��ά���鴫�Σ�����ʡ���У�����ʡ����
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
//һ��ָ�봫��,���ܵ�ַ
//����ָ�봫��
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
//	test(arr);//һ��ָ������Ҳ����
//	return 0;
//}
//����ָ��
//����ָ��-ָ�������ָ��
//����ָ��-ָ������ָ��
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
//	//�����е�ַ��
//	//printf("%p\n", &Add);
//	//printf("%p\n", Add);//һ�����ں�����&�������ͺ��������Ǻ����ĵ�ַ
//	int (* pa)(int, int) = Add;//�������飬�������ȼ��ߣ�����Ҫ*pa������
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
//������Ȥ�Ĵ���
//(*(void(*)())0)();//void(*)()-����ָ�����ͣ�ǿ��ת������0Ϊ������ַ����֮ǰ��*�ǽ�������ַ,�ҵ����������
//��������Ǻ������ã�����0��ַ���ĸú���
//��C�����ȱ�ݡ�
//����2       ����  ����ָ������
//void(*signal(int,void(*)(int)))(int)-��������-����ָ��
//void(*)(int) signal(int,void(*)(int))--��ȷ��ʽ���������
//void(*signal(int, void(*)(int)))(int);//��,����typedef����
//typedef void(* pfun_t)(int);
//typedef unsigned int uint;//֮ǰ����
////����
//pfun_t signal(int, pfun_t);
//signal ��һ����������
//signal �����Ĳ�����2������һ����int ���ڶ����Ǻ���ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int������������void
//signal �����ķ�������Ҳ��һ������ָ�룺�ú���ָ��ָ��ĺ����Ĳ�����int������������void
