//410241074_電機一甲_陳瑩儷

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

//prototype functions
int func1(int A, int B);
int func2(int a);

int main()
{
	int  choice;
	printf("1.求最大公因數\n");
	printf("2.計算排列組合< C<n, m> >\n");
	printf("請選擇要使用的功能：");
	scanf("%d", &choice);

	if (choice == 1)  //功能選第一個
	{
		int A, B;
		printf("輸入兩個介於20~200的整數：");
		scanf("%d%d", &B, &A);
		printf("\n");
		printf("最大公因數：%d\n", func1((B > A) ? B, A : B, A));  //從func1將值輸入進來
	}

	if (choice == 2)//從func2將值輸入進來
	{
		int n, m;
		int ans;
		printf("輸入兩個介於5~20的整數：");
		scanf("%d%d", &n, &m);
		printf("\n");

		ans = func2(n) / (func2(m) * func2(n - m));  //排列組合運算式
		printf("總組合數：%d\n", ans);
	}

	system("PAUSE");
	return 0;
}

int func1(int A, int B)
{
	int R;
	R = A % B;
	if (R != 0)
	{
		return func1(B, R);
	}
	else
	{
		return B;
	}
}

int func2(int a)
{
	if (a > 1)
	{
		return(a * func2(a - 1));
	}
	else
	{
		return 1;
	}
}