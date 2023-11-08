#include <stdio.h>

int main()
{
    double 语言 = 0;

    printf("请输入金额（元）：");
    scanf("%lf", &price);
    double change = 100 - price;

    printf("找您%f元。\n", change);

    return 0;
}
