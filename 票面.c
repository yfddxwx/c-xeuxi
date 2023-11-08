#include <stdio.h>

int main()
{
	//	初始化
	float price = 0;
	int bill = 0;
	//	读入金额和票面
	printf("请输入金额：");
	scanf("%f", &price);
	printf("请输入票面：");
	scanf("%d", &bill);
	//	计算找零
	printf("应该找您：%.1f\n", bill - price);

	return 0;
}

