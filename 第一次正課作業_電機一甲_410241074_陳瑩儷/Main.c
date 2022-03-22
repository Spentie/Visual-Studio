//電機一甲_410241074_陳瑩儷

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//prototype functions
int func1(int L, int W, int H);
float func2(int R, int H);

int main()
{
	printf("郵筒問題計算\n");

	int boxH, boxW, boxL, boxR;  //郵筒箱的高、寬、長、半徑
	int pillarR, pillarH, pillarD;  //郵筒柱的半徑、高、直徑
	int dowhat = 0; //變數：選擇執行
	printf("輸入郵筒箱長 寬 高：");
	scanf("%d %2d %2d", &boxL, &boxW, &boxH);

	printf("輸入郵筒柱半徑 高：");
	scanf("%d %2d", &pillarR, &pillarH);
	pillarD = pillarR + pillarH;  //直徑=半徑+高

	if (pillarD < boxW)
	{
		printf("輸入完成\n");
	}
	else if (pillarD >= boxW)
	{
		while (pillarD >= boxW)  //一直不符合條件則重新輸入
		{
			int R = 0, H = 0, D;  //新的郵筒柱半徑&高
			D = R + H;
			printf("輸入錯誤，接合處柱子直徑不得大於箱子長、寬\n");
			printf("重新輸入郵筒柱半徑 高：");
			scanf("%d %d", &R, &H);
			if (D < boxW)
			{
				printf("輸入完成\n");
			}
			pillarR = R;
			pillarH = H; //覆寫
			break;
		}
	}

	while (1)
	{
		printf("\n");
		printf("(1)新建郵筒資訊\n(2)列出郵筒資訊\n(3)列出郵筒體積\n(4)可以裝幾個郵差包\n(0)離開\n");
		printf("請問你要做什麼：");
		scanf("%d", &dowhat);

		if (dowhat == 1)
		{
			printf("輸入郵筒箱長 寬 高：");
			scanf("%d %d %d", &boxL, &boxW, &boxH);

			printf("輸入郵筒柱半徑 高：");
			scanf("%d %d", &pillarR, &pillarH);
			pillarD = pillarR + pillarH;

			if (pillarD <= boxL && pillarD <= boxW)
			{
				printf("輸入完成\n");
			}
			else
			{
				while (pillarD >= boxW)
				{
					int R = 0, H = 0, D;
					D = R + H;
					printf("輸入錯誤，接合處柱子直徑不得大於箱子長、寬\n");
					printf("重新輸入郵筒柱半徑 高：");
					scanf("%d %d", &R, &H);
					if (D < boxW)
					{
						printf("輸入完成\n");
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
			printf("郵筒箱[長 寬 高]：[%d%2d%2d]\n", boxL, boxW, boxH);
			printf("郵筒柱[半徑 高]：[%d%2d]\n", pillarR, pillarH);
			printf("\n");
		}

		if (dowhat == 3)
		{
			printf("郵筒箱體積為：%d *%2d *%2d =%2d\n", boxL, boxW, boxH, func1(boxL, boxW, boxH));
			printf("郵筒柱體積為：%d *%2d * 3.14 *%2d=%2.2f\n", pillarR, pillarR, pillarH, func2(pillarR, pillarH));
			printf("郵筒總體積為：%d+ %2.2f= %2.2f", func1(boxL, boxW, boxH), func2(pillarR, pillarH), (func1(boxL, boxW, boxH) + func2(pillarR, pillarH)));
			printf("\n");
		}

		if (dowhat == 4)
		{
			int bag = 10;  //布袋10體積單位
			int bag_amount, backbag_amount;

			bag_amount = func1(boxL, boxW, boxH) / bag;  //布袋需要的數量=郵筒箱體積/10體積單位(捨去餘數)
			backbag_amount = func1(boxL, boxW, boxH) % bag;  //揹袋需要的數量=郵筒箱體積%10體積單位(取餘數)
			printf("以郵筒箱體積%d，共需要%d個布袋和%d個揹袋\n", func1(boxL, boxW, boxH), bag_amount, backbag_amount);
			printf("\n");
		}

		if (dowhat == 0)
		{
			printf("程式結束\n");
			break;
		}
	}
		system("PAUSE");
		return 0;
}

	int func1(int L, int W, int H)  //計算郵筒箱體積
	{
		int ans1;
		ans1 = L * W * H;

		return ans1;
	}

	float func2(int R, int H)  //計算郵筒柱體積
	{
		float ans2;
		ans2 = R * R * 3.14 * H;

		return ans2;
	}