//410241074_�q���@��_������

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

//prototype functions
int func1(int A, int B);
int func2(int a);

int main()
{
	int  choice;
	printf("1.�D�̤j���]��\n");
	printf("2.�p��ƦC�զX< C<n, m> >\n");
	printf("�п�ܭn�ϥΪ��\��G");
	scanf("%d", &choice);

	if (choice == 1)  //�\���Ĥ@��
	{
		int A, B;
		printf("��J��Ӥ���20~200����ơG");
		scanf("%d%d", &B, &A);
		printf("\n");
		printf("�̤j���]�ơG%d\n", func1((B > A) ? B, A : B, A));  //�qfunc1�N�ȿ�J�i��
	}

	if (choice == 2)//�qfunc2�N�ȿ�J�i��
	{
		int n, m;
		int ans;
		printf("��J��Ӥ���5~20����ơG");
		scanf("%d%d", &n, &m);
		printf("\n");

		ans = func2(n) / (func2(m) * func2(n - m));  //�ƦC�զX�B�⦡
		printf("�`�զX�ơG%d\n", ans);
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