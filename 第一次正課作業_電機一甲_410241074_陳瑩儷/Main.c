//�q���@��_410241074_������

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//prototype functions
int func1(int L, int W, int H);
float func2(int R, int H);

int main()
{
	printf("�l�����D�p��\n");

	int boxH, boxW, boxL, boxR;  //�l���c�����B�e�B���B�b�|
	int pillarR, pillarH, pillarD;  //�l���W���b�|�B���B���|
	int dowhat = 0; //�ܼơG��ܰ���
	printf("��J�l���c�� �e ���G");
	scanf("%d %2d %2d", &boxL, &boxW, &boxH);

	printf("��J�l���W�b�| ���G");
	scanf("%d %2d", &pillarR, &pillarH);
	pillarD = pillarR + pillarH;  //���|=�b�|+��

	if (pillarD < boxW)
	{
		printf("��J����\n");
	}
	else if (pillarD >= boxW)
	{
		while (pillarD >= boxW)  //�@�����ŦX����h���s��J
		{
			int R = 0, H = 0, D;  //�s���l���W�b�|&��
			D = R + H;
			printf("��J���~�A���X�B�W�l���|���o�j��c�l���B�e\n");
			printf("���s��J�l���W�b�| ���G");
			scanf("%d %d", &R, &H);
			if (D < boxW)
			{
				printf("��J����\n");
			}
			pillarR = R;
			pillarH = H; //�мg
			break;
		}
	}

	while (1)
	{
		printf("\n");
		printf("(1)�s�ضl����T\n(2)�C�X�l����T\n(3)�C�X�l����n\n(4)�i�H�˴X�Ӷl�t�]\n(0)���}\n");
		printf("�аݧA�n������G");
		scanf("%d", &dowhat);

		if (dowhat == 1)
		{
			printf("��J�l���c�� �e ���G");
			scanf("%d %d %d", &boxL, &boxW, &boxH);

			printf("��J�l���W�b�| ���G");
			scanf("%d %d", &pillarR, &pillarH);
			pillarD = pillarR + pillarH;

			if (pillarD <= boxL && pillarD <= boxW)
			{
				printf("��J����\n");
			}
			else
			{
				while (pillarD >= boxW)
				{
					int R = 0, H = 0, D;
					D = R + H;
					printf("��J���~�A���X�B�W�l���|���o�j��c�l���B�e\n");
					printf("���s��J�l���W�b�| ���G");
					scanf("%d %d", &R, &H);
					if (D < boxW)
					{
						printf("��J����\n");
					}
					pillarR = R;
					pillarH = H;
					break;
				}
			}
			printf("\n");
		}

		if (dowhat == 2)
		{
			printf("�l���c[�� �e ��]�G[%d%2d%2d]\n", boxL, boxW, boxH);
			printf("�l���W[�b�| ��]�G[%d%2d]\n", pillarR, pillarH);
			printf("\n");
		}

		if (dowhat == 3)
		{
			printf("�l���c��n���G%d *%2d *%2d =%2d\n", boxL, boxW, boxH, func1(boxL, boxW, boxH));
			printf("�l���W��n���G%d *%2d * 3.14 *%2d=%2.2f\n", pillarR, pillarR, pillarH, func2(pillarR, pillarH));
			printf("�l���`��n���G%d+ %2.2f= %2.2f", func1(boxL, boxW, boxH), func2(pillarR, pillarH), (func1(boxL, boxW, boxH) + func2(pillarR, pillarH)));
			printf("\n");
		}

		if (dowhat == 4)
		{
			int bag = 10;  //���U10��n���
			int bag_amount, backbag_amount;

			bag_amount = func1(boxL, boxW, boxH) / bag;  //���U�ݭn���ƶq=�l���c��n/10��n���(�˥h�l��)
			backbag_amount = func1(boxL, boxW, boxH) % bag;  //���U�ݭn���ƶq=�l���c��n%10��n���(���l��)
			printf("�H�l���c��n%d�A�@�ݭn%d�ӥ��U�M%d�Ӵ��U\n", func1(boxL, boxW, boxH), bag_amount, backbag_amount);
			printf("\n");
		}

		if (dowhat == 0)
		{
			printf("�{������\n");
			break;
		}
	}
		system("PAUSE");
		return 0;
}

	int func1(int L, int W, int H)  //�p��l���c��n
	{
		int ans1;
		ans1 = L * W * H;

		return ans1;
	}

	float func2(int R, int H)  //�p��l���W��n
	{
		float ans2;
		ans2 = R * R * 3.14 * H;

		return ans2;
	}