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
//ָ����ָ�������ָ��
//�ص�����--һ��ͨ������ָ����õĺ����������Ѻ�����ָ��(��ַ)��Ϊ�������ݸ���һ�������������ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص�������
//�ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ����һ�����õģ����ڶԸ��¼�������������Ӧ
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
//	printf("����������������:>");
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
//		printf("��ѡ��:>");
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
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//ͨ���ص��������������
//ָ����ָ�������ָ��
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10] = &arr;//ȡ������ĵ�ַ
//	int(*pfArr[4])(int,int);//pfArr��һ������-����ָ�������
//	int(*(*ppfArr)[4])(int, int) = &pfArr;
//	//
//	//ppfArr ��һ������ָ�룬ָ��ָ���������4��Ԫ��
//	//ָ��������ÿ��Ԫ�ص�������һ������ָ�� int(*)(int,int)
//	return 0;
//}ppfArr��һ��ָ��(����ָ������)��ָ��

//�ص�����
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
//	//ð��������ֻ��������������
//	int arr[] = { 1,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr,sz);
//
//	return 0;
//}
//qsort--���������������͵�����//�⺯��
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//ָ������
//	//int* arr[10];//ָ������
//    //int*(*pa)[10] = &arr;
//    //����ָ��
//	int(*pAdd)(int, int) = Add;
//	/*int sum=(*pAdd)(1, 2);
//	printf("sum=%d\n", sum);*/
//	//����ָ�������
//	int(*pArr[5])(int, int);
//	//ָ����ָ�������ָ��
//	int(*(*ppArr)[5])(int, int) = &pArr;
//
//	return 0;
//}
//�ص�����
// qsort

void bubble_sort(int arr[], int sz)
{
	int i = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		//һ��ð������
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
//qsort-�⺯��-����
//quick sort-�㷨˼�룬��������
//void qsort(void* base,
//	size_t num,
//	size_t width,
//	int(__cdecl* cmp)(const void* e1, const void* e2));
//qsort(arr,sizeof(arr),sizeof(arr[0]),)
int cmp_int(const void* e1, const void* e2)
{
	//�Ƚ���������ֵ��
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
	struct Stu s[3] = { {"����",20},{"����",30},{"����",10} };
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
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ���ã�<=���Ƚϣ�Ӧ����strcmp����
	return strcmp(((struct Stu*)e1)->name , ((struct Stu*)e2)->name);
}
void test4()
{
	struct Stu s[3] = { {"����",20},{"����",30},{"����",10} };
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
//	struct Stu s[3] = { {"����",20},{"����",30},{"����",10} };
	//float f[] = {9.0,8.0,7.0,6.0,5.0,4.0};

	/*bubble_sort(arr,sz);*/
	return 0;
}
//���������
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	/*char* pc = &a;*/
//	//������char��int�����ݣ���ô��û��һ��ָ����Բ����������أ�
//	void* p = &a;//�����͵�ָ��
//	//*p = 0;//����void�͵�ָ�룬���ܽ��н����ò���
//	// p++;Ҳ�ᱨ��void*���͵�ָ�룬���ܽ��мӼ������Ĳ���
//	//void*���͵�ָ�룬���Խ����������͵ĵ�ַ
//}
//
