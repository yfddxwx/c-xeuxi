#include <stdio.h>

int main()
{
	//	��ʼ��
	float price = 0;
	int bill = 0;
	//	�������Ʊ��
	printf("�������");
	scanf("%f", &price);
	printf("������Ʊ�棺");
	scanf("%d", &bill);
	//	��������
	printf("Ӧ��������%.1f\n", bill - price);

	return 0;
}

