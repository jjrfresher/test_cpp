#include<stdio.h>
#include<string.h>
//深度剖析数据在内存中的存储
//1.数据类型详细介绍
//2.整形在内存中的存储：原码，反码，补码
//3.大小端字节序介绍及判断
//4.浮点型在内存中的存储解析
// char  //字符数据类型//1
// short //短整型//2
// int   //整形
// long  //长整型//4
// long long//更长的整形//8
// float  //单精度浮点数//4
// double //双精度浮点数//8
// C语言内置类型
//C语言类型：1，内置类型，2，自定义类型(构造类型)
//类型的意义：1.使用这个类型开辟内存空间的大小（大小决定了适用范围），2，如何看待内存空间的视角
//类型的基本归类
//整形家族：
// char :unsigned char //  signed char
// short:unsigned short//  signed short
// int : unsigned int //   signed int
// long: unsigned long// signed long  
// 浮点型家族:
// float-单精度浮点型 ;; double-双精度浮点型
// 构造类型:
// >数组类型；；>结构体类型  struct；；>枚举类型  enum；；>联合类型 union
//  空类型：void  通常应用于函数的返回类型，函数的参数，指针类型
// 指针类型： int*pi; char* pc; float* pf; void* pv;
//
//
//void test(void)//括号里有void,函数无参
//{
//	printf("hehe\n");
//}
//int main()
//{
//	int a = 10;//0x000000A2A9EFF964
//	short b = 10;
//	float f = 10.0;//0x000000A2A9EFF984
//	test();
//	return 0;
//}
// 整形在内存中的存储
// 
// 无符号数：原码，反码，补码，相同
//int main()
//{
//	int a = 20;
//	//00000000000000000000000000010100-原码
//	//00000000000000000000000000010100-反码
//	//00000000000000000000000000010100-补码
//	//翻译成16进制-0x0000014
//	int b = -10;
//	//10000000000000000000000000001010 - 原码
//	//11111111111111111111111111110101 - 反码
//	//1111 1111 1111 1111 1111 1111 1111 0110-补码
//	//F  F F F F F F6
//	return 0;
//}
//对于整形来说：数据存放内存中其实存放的是补码
//为什么呢？
//在计算机系统中，数据一律用补码来表示和存储，原因在于，使用补码，可以将符号位和数值域
//统一处理，同时，加法和减法也可以统一处理(CPU只有加法器)此外，补码和原码相互转换，其运算过程是
//相同的，不需要额外的硬件电路
//int main()
//{
//	1 - 1;
//	//00000000000000000000000000000001
//	//10000000000000000000000000000001
//	//10000000000000000000000000000010
//	//采用原码计算完全是错误的
//	//00000000000000000000000000000001
//	//11111111111111111111111111111111
//	//100000000000000000000000000000000//进一补码为0
//}
//整数
//1.有符号数  2.无符号数
//int main()
//{
//	int a = 20;
//	//大小端介绍
//	//大端(存储)模式：是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；
//	//小端(存储)模式：是指数据的低位保存在数据的低地址中，而数据的高位，保存在内存的高地址中。
//	//例如 0x 11 22 33 44：大端存储：11 22 33 44 小端存储：44 33 22 11
//	//为什么有大端和小端
//	//大端字节序存储模式，小端字节序存储模式
//	return 0;
//}
int check_sys()
{
	int a = 1;
	/*char* p = (char*)&a;*/
	/*if (*p == 1)
	{
		return 1;//小端
	}
	else
		return 0;*///大端
	/*return *p;*/
	return *(char*)&a;
}
int main()
{
	//请简述大端字节序和小端字节序的概念。设计一个小程序来判断当前机器的字节序
    //写一段代码告诉我们当前机器的字节序
	/*int a = 20;*/
	//0x 00 00 00 14 有两种存储形式，只需拿出来第一个字节存储内容，如果是14那么是小端存储，如果是00那么是大端存储
	
	//0x00 00 00 01
	//01 00 00 00
	//00 00 00 01
	//返回1，小端
	//返回0，大端
	int ret=check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	return 0;
}
