#include<stdio.h>
//qsort 第一个参数：待排序数组的首元素地址，第二个参数：待排序数组的元素个数，
//第三个参数：待排序数组的每个元素的大小—单位是字节；第四个参数：是函数指针，比较两个元素的所用函数的地址
//这个函数使用者自己实现。函数指针的两个参数是：待比较的两个元素的地址
struct Stu
{
	char name[10];
	int age;
};
//实现bubble_sort函数的程序员，他是否知道未来排序的数据类型-不知道
//那程序员也不知道待比较的两个元素的类型
void Swap(char* buf1, char* buf2,int width)//必须把width也给传过去，因为交换要明确几个字节，不能只交换一个字节
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
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//每一趟比较的对数
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//两个元素的比较
			//如何传过来两个元素的地址呢？如果传过来base的地址，那么怎么得到base的下一个元素的地址呢？
			//cmp(base,base+1)?错误，因为是void类型，那么cmp(base,(int*)base+1)?也不行，因为这样只能是整形
			//那么就要利用width这个字节，所以要把base强制转换成char*这种类型，(因为char*是一个字节)再+width，即可得到下一元素的地址
			
			if (cmp((char*)base+j*width,(char*)base+width*(j+1)) > 0)
			{
				//交换
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
	//使用冒泡函数的程序员一定知道自己排序的是什么数据
	//他就应该知道如何比较待排序数组中的元素
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
	struct Stu s[3] = { {"张三",20},{"李四",30},{"王五",34} };
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
	struct Stu s[3] = { {"张三",20},{"李四",30},{"王五",34} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%s ", s[j].name);
	}
}
//怎么改造冒泡排序的数组
int main()
{
	test4();
	printf("\n");
	test5();
	printf("\n");
	test6();
	return 0;
}