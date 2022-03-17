#include<stdio.h>
//qsort ��һ���������������������Ԫ�ص�ַ���ڶ��������������������Ԫ�ظ�����
//�����������������������ÿ��Ԫ�صĴ�С����λ���ֽڣ����ĸ��������Ǻ���ָ�룬�Ƚ�����Ԫ�ص����ú����ĵ�ַ
//�������ʹ�����Լ�ʵ�֡�����ָ������������ǣ����Ƚϵ�����Ԫ�صĵ�ַ
struct Stu
{
	char name[10];
	int age;
};
//ʵ��bubble_sort�����ĳ���Ա�����Ƿ�֪��δ���������������-��֪��
//�ǳ���ԱҲ��֪�����Ƚϵ�����Ԫ�ص�����
void Swap(char* buf1, char* buf2,int width)//�����widthҲ������ȥ����Ϊ����Ҫ��ȷ�����ֽڣ�����ֻ����һ���ֽ�
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width,int (*cmp)(const void*e1,const void*e2))
{
	int i = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		//ÿһ�˱ȽϵĶ���
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//����Ԫ�صıȽ�
			//��δ���������Ԫ�صĵ�ַ�أ����������base�ĵ�ַ����ô��ô�õ�base����һ��Ԫ�صĵ�ַ�أ�
			//cmp(base,base+1)?������Ϊ��void���ͣ���ôcmp(base,(int*)base+1)?Ҳ���У���Ϊ����ֻ��������
			//��ô��Ҫ����width����ֽڣ�����Ҫ��baseǿ��ת����char*�������ͣ�(��Ϊchar*��һ���ֽ�)��+width�����ɵõ���һԪ�صĵ�ַ
			
			if (cmp((char*)base+j*width,(char*)base+width*(j+1)) > 0)
			{
				//����
				Swap((char*)base + j * width, (char*)base + width * (j + 1),width);
			}
		}
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test4()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//ʹ��ð�ݺ����ĳ���Աһ��֪���Լ��������ʲô����
	//����Ӧ��֪����αȽϴ����������е�Ԫ��
	bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%d ", arr[j]);
	}
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
void test5()
{
	struct Stu s[3] = { {"����",20},{"����",30},{"����",34} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]),cmp_stu_by_age );
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%d ", s[j].age);
	}
}
#include<string.h>
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test6()
{
	struct Stu s[3] = { {"����",20},{"����",30},{"����",34} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%s ", s[j].name);
	}
}
//��ô����ð�����������
int main()
{
	test4();
	printf("\n");
	test5();
	printf("\n");
	test6();
	return 0;
}