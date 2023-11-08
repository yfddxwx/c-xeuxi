# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
#define LEN 25 
#define N 70
#define F "����.txt" //�ļ�·��
 
typedef struct
{
	char no[10];//�˺� 
	char name[10];//���� 
	char ID[30];//���֤�� 
	char phone[16];//�绰 
	int money;	//��� 
	char grade[10];//�ȼ� 
	char discounts[10]; //�ۿ� 
}VIP;   //������Ա��Ϣ 
 
typedef struct node{
    VIP VIP;            //������ 
    struct node *next;   //ָ���� 
}VIPNode;   //��Ա�ڵ� 
 
typedef struct{
    VIPNode *head;  //ͷָ�� 
    VIPNode *tail;  //βָ�� 
    int count;
}VIPList;     // ��Ա���� 
 
int  m = 0;//k = 1, n = 0,
 
 
void counts(VIPNode *q);//��Ա�ȼ� 
int menu();   //�˵� 
void Instruction();//ϵͳ˵�� 
void initialize(VIPList *L);//��ʼ������ 
void read(VIPList *L);//���ļ��ж�ȡ 
void input(VIPList *List,int m);  //���� 
void sort(VIPList *L); //����
void print(VIPList *L); //��� 
void Search(VIPList *L); //��ѯ 
void insert(VIPList *L); //���� 
void Delete(VIPList *L);//ɾ�� 
void Modify(VIPList *L);//�޸� 
void transaction(VIPList *L);//��ֵ������ 
void save(VIPList *L);//���� 
 
 
 
 
 
//��¼���� 
void login()		
{
   char userName[5];
   char password[5];
   int i;
   printf("\n\n   ---------==========================��ð�==========================-------------\n");
   for(i=1;i<4;i++)
   {
        printf("\n             �����������û���:");
        gets(userName);
        printf("\n             ��������������:");
        gets(password);
        if ((strcmp(userName,"000")==0) && (strcmp(password,"123")==0))/*��֤�û���������*/
        {
        	
            printf("\n   -------------------------------------------��ӭ�����ɰ��Ļ�Ա-------------------------------------------");
            Sleep(500); 
            return;
        }
        else
        {
            if(i<3)
            {
                printf("\n           �û����������������������!\n");
            }
            else
            {
                printf("\n           ��������3�ν��û������������ϵͳ���˳�!");
                exit(0);
            }
        }
   }
}
 
 
void main()          
{
	int a; 
	login();
    VIPList *L=(VIPList *)malloc(sizeof(VIPList));//�������� 
    initialize(L);//��ʼ������
	read(L);//���ļ����ȡ���ݵ����� 
	while(1) 
	{
		menu(); 
		printf("\t��ѡ����Ҫ���е�ѡ�(0-9):");
	    scanf("%d",&a);
        switch(a) 
        {
        	case 0: 
        		system("cls");
        	    Instruction();
        	    break;
            case 1:
				system("cls");
            	printf("\n\n\t\t------------------------------------------------------------------------\n\n");
				printf("\t\t\t�����Ա�ĸ�����");
				scanf("%d",&m);
				if(m<=0)
				{
					printf("\n\t\t\t��������ȷ������!");
					break;
				}
				else
				{
					printf("\n\t\t\t�����Ա��Ϣ\n\n");
					input(L,m); 
	            	break;
				}
            case 2:
            	system("cls");
	            printf("\t\t\t\t\t��ʾ��Ա��Ϣ\n"); 
	            sort(L); 
	            print(L); 
	            break; 
            case 3:
            	system("cls");
				printf("\t\t\t\t\t��ѯ��Ա��Ϣ\n");
				Search(L); 
                break;
            case 4:
            	system("cls");
                printf("\t\t\t\t\t�����Ա��Ϣ\n");
                insert(L); 
				break;       
			case 5:
				system("cls"); 
				printf("\t\t\t\t\t�޸Ļ�Ա��Ϣ\n");
                Modify(L);
                
                break;
            case 6:
				system("cls");
                printf("\t\t\t\t\tɾ����Ա��Ϣ\n");
                Delete(L);
                break;  
			case 7:
				system("cls");
                printf("\t\t\t\t\t��Ա���ѻ��ֵ\n");
                transaction(L);
                break;  	  
            case 8:
            	system("cls");
            	save(L); 
                printf("\n\t\t\t\t\tллʹ��\n");
                exit(0);
                break; 
        }
	}
}
 
 
int menu()
{      
        system("cls");
        printf("\n\n\t\t���л�Ա����ϵͳ\n");
        printf("\t\t=  = 0. ϵͳ˵��                                            ���\n\n");
        printf("\t\t=  = 1. �����Ա��Ϣ                                        ���\n\n");
        printf("\t\t=  = 2. ��ʾ��Ա��Ϣ                                        ���\n\n");
        printf("\t\t=  = 3. ��ѯ��Ա��Ϣ                                        ���\n\n");
        printf("\t\t=  = 4. �����Ա��Ϣ                                        ���\n\n");
        printf("\t\t=  = 5. �޸Ļ�Ա��Ϣ                                        ���\n\n");
        printf("\t\t=  = 6. ɾ����Ա��Ϣ                                        ���\n\n");
        printf("\t\t=  = 7. ��Ա���ѻ��ֵ                                      ���\n\n");
		printf("\t\t=  = 8. �˳�ϵͳ                                            ���\n\n");
        printf("\t\t�������������������������������������\n");
		return 1;
}
 
void Instruction() //ϵͳ˵�� 
 
{
	printf("\n\t\t          ��ӭ��ʹ��ϵͳ˵��\n");
	printf("\n\t\t          ����ѡ��˵��ϵ�����\n");
	printf("\n\t\t          �޸�ɵ����Ϣ���뱣��\n");
	printf("\n\t\t          ллʹ�����ϵͳŶ\n");
	system("pause");
}
 
 
void initialize(VIPList *L) { //��ʼ�� 
	//����ͷ�ڵ�
	VIPNode *s = (VIPNode *)malloc(sizeof(VIPNode));
	s->next = NULL;
	//��ʼ������
	//ͷβָ���ָ��ͷ�ڵ㣬��ʼ����Ϊ��
	L->head = s;
	L->tail = s;
	L->count = 0;
}
 
void read(VIPList *L) {
	//���ļ���
	FILE *fp = fopen("����", "w");
	if (fp == NULL) {
		printf("�ļ���ʧ��\n");
		exit(EXIT_FAILURE);
	}
	//��ȡ��һ�еĻ�Ա�ڵ�����
	fscanf(fp, "%d", &L->count);
	int i;//ѭ����ȡ���ݣ�ѭ������Ϊcount
	for (i = 1; i <= L->count; i++) {
		//�����½ڵ�
		VIPNode *s = (VIPNode *)malloc(sizeof(VIPNode));
		//��ȡ����
		fscanf(fp, "%s ", s->VIP.no);
		fscanf(fp, "%s ", s->VIP.name);
		fscanf(fp, "%s ", s->VIP.ID);
		fscanf(fp, "%s ", s->VIP.phone);
		fscanf(fp, "%d ", &s->VIP.money);
		fscanf(fp, "%s ", s->VIP.grade);
		fscanf(fp, "%s ", s->VIP.discounts);
		//���½ڵ�������β����β�巨��
		s->next = NULL;
		L->tail->next = s;
		L->tail = s;
	}
	//�ر��ļ���
	fclose(fp);
} 
 
void input(VIPList *L,int m)                  
{
	int i;
	for(i=1;i<=m;i++)
	{
		VIPNode *r = (VIPNode *)malloc(sizeof(VIPNode));
		printf("�������Ա���˺�:\n");
	    scanf("%s",r->VIP.no);
	    printf("�������Ա������:\n");               
	    scanf("%s",r->VIP.name);
	    printf("�������Ա�����֤��:");
		scanf("%s",r->VIP.ID);
		printf("�������Ա����ϵ�绰:");
		scanf("%s",r->VIP.phone);
		printf("�������Ա�����ѽ��:");
		scanf("%d",&r->VIP.money);
    	counts(r);
		printf("��Ա�Ļ�Ա�ȼ�:");
		printf("%s\n", r->VIP.grade); 
		printf("��Ա���Ż�����:");
		printf("%s\n",r->VIP.discounts);
	    //���½ڵ�������β����β�巨��
		L->tail->next = r;
		r->next = NULL;
		L->tail = r;   
		L->count++;                                  //ָ�����
	}
	printf("��Ա��Ϣ¼����ϣ�����\n");
	system("pause");
	
}
 
void counts(VIPNode *q){
	char grade[6][50]={"��ͨ","����","�ƽ�","����","��ʯ","�ڽ�"};
	//>=0,��ͨ��>=500,������>=1000,�ƽ�>=3000,����>=6000����ʯ��>=10000,�ڽ� 	
	char discounts[6][50]={"ԭ��","����","�˰���","������","����","����"};
	int num;
	num=q->VIP.money/100; 
	if(num<=5) { 
		strcpy(q->VIP.grade,grade[0]);
		strcpy(q->VIP.discounts,discounts[0]); 
		printf("�����Ͱײ�");
	}else if(num<=10){ 
	    strcpy(q->VIP.grade,grade[1]);
		strcpy(q->VIP.discounts,discounts[1]);printf("2wwswd");
	}else if(num<=30){ 
		strcpy(q->VIP.grade,grade[2]);
		strcpy(q->VIP.discounts,discounts[2]);printf("3wwswd");
	}else if(num<=60){ 
		strcpy(q->VIP.grade,grade[3]);
		strcpy(q->VIP.discounts,discounts[3]);printf("4wwswd");
	}else if(num<=100){ 
		strcpy(q->VIP.grade,grade[4]);
		strcpy(q->VIP.discounts,discounts[4]);
	}else{ 
		strcpy(q->VIP.grade,grade[5]);
		strcpy(q->VIP.discounts,discounts[5]);
	} 
}
 
void sort(VIPList *L) {
	printf("��Ա����Ϊ%d��",L->count); 
	//��������
	VIPNode *p, *pre, *tmp;
	//pָ��ڶ�����Ա�ڵ�
	p = L->head->next;
	//�����ͷ�ڵ�͵�һ����Ա�ڵ㴦�Ͽ�
	L->head->next = NULL;
	//�ӵ�һ����Ա�ڵ㿪ʼһֱ����ѭ��
	while (p) {
		//�����һ���ڵ��ָ��
		tmp = p->next;
		//�ҵ�����λ��
		pre = L->head;
		while (pre->next != NULL && strcmp(pre->next->VIP.no,p->VIP.no)<0){ 
			pre = pre->next;} 
		//����βָ��
		if (pre->next == NULL) {
			L->tail = p;
		}
		//����
		p->next = pre->next;
		pre->next = p;
		//������һ��
		p = tmp;
	}
	printf("����������ɣ�\n");
	system("pause");
}
 
 
void print(VIPList *L)  //��� 
{
	printf("����%d���Ա���ݣ�\n", L->count);
	printf("     |=============================================================================================|\n");
	printf("     | �� �� | �� �� |           ���֤��          |   ��ϵ�绰   | ���ѽ�� | ��Ա�ȼ� | �Ż����� |\n");
	printf("     |---------------------------------------------------------------------------------------------|\n");
	//����һ�ڵ�ָ��ָ��ͷ�ڵ�
	VIPNode *p;
	p = L->head;
	//�����������
	while (p->next) {
		p = p->next;
		printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
	}
	printf("     |=============================================================================================|\n");
	system("pause");
}
 
 
 
void Search(VIPList *L) //��ѯ 
 
{
	int  item, flag;
	char s1[21];
	printf("\t\t------------------------------------------------------------------\n");
	printf("\t\t���---------------------1.���˺Ų�ѯ-----------------------���\n\n");
	printf("\t\t���---------------------2.��������ѯ-----------------------���\n\n");
	printf("\t\t���---------------------3.�����֤�Ų�ѯ--------------------���\n\n");
	printf("\t\t���---------------------4.����ϵ�绰��ѯ-------------------���\n\n");
	printf("\t\t���---------------------0.�˳����˵�-----------------------���\n\n");
	printf("\t\t------------------------------------------------------------------\n");
 
	while (1)
	{
		printf("��ѡ���Ӳ˵����:");
		scanf("%d", &item);
		VIPNode *p =L->head->next;
		flag = 0;
		switch (item)
		{
			case 1:
				printf("������Ҫ��ѯ�Ļ�Ա���˺�:\n");
				scanf("%s",s1);
				while (p){ 
					if (strcmp(p->VIP.no, s1) == 0)
					{
						flag=1; 
					    printf("     |=============================================================================================|\n");
	                    printf("     | �� �� | �� �� |           ���֤��          |   ��ϵ�绰   | ���ѽ�� | ��Ա�ȼ� | �Ż����� |\n");
	                    printf("     |---------------------------------------------------------------------------------------------|\n");
                        printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
					}
                    p = p->next;
                }
                if (0 == flag)
					printf("���˺Ų����ڣ�\n");
				break;
			case 2:
				printf("������Ҫ��ѯ�Ļ�Ա������:\n");
				scanf("%s", s1);
				//VIPNode *p = L->head->next;
				while (p){
					if (strcmp(p->VIP.name, s1) == 0)
					{
						flag = 1;
						printf("     |=============================================================================================|\n");
	                	printf("     | �� �� | �� �� |           ���֤��          |   ��ϵ�绰   | ���ѽ�� | ��Ա�ȼ� | �Ż����� |\n");
	                	printf("     |---------------------------------------------------------------------------------------------|\n");
                        printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
					}
					p = p->next;
                }
				if (0 == flag)
					printf("�����������ڣ�\n");
				break;
			case 3:
				printf("������Ҫ��ѯ�Ļ�Ա�����֤��:\n");
				scanf("%s", s1);
				//VIPNode *p = L->head->next;
				while (p){
					if (strcmp(p->VIP.ID, s1) == 0)
					{
						flag = 1;
						printf("     |=============================================================================================|\n");
	                	printf("     | �� �� | �� �� |           ���֤��          |   ��ϵ�绰   | ���ѽ�� | ��Ա�ȼ� | �Ż����� |\n");
	                	printf("     |---------------------------------------------------------------------------------------------|\n");
                        printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
					}
					p = p->next;
                }
				if (0 == flag)
					printf("�����֤�Ų����ڣ�\n");
				break;
			case 4:
				printf("������Ҫ��ѯ�Ļ�Ա�ĵ绰����:\n");
				scanf("%s", s1);
				//VIPNode *p = L->head->next;
				while (p){
					if (strcmp(p->VIP.phone, s1) == 0)
					{
						flag = 1;
						printf("     |=============================================================================================|\n");
	                	printf("     | �� �� | �� �� |           ���֤��          |   ��ϵ�绰   | ���ѽ�� | ��Ա�ȼ� | �Ż����� |\n");
	                	printf("     |---------------------------------------------------------------------------------------------|\n");
                    	printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
					}
					p = p->next;
                }
				if (0 == flag)
					printf("�õ绰���벻���ڣ�\n");
				break;
			case 0:
				return;
			default:
				printf("����0-4֮��ѡ��\n");
		}
 
	}
 
}
 
void insert(VIPList *L)
{
	VIPNode *s = (VIPNode *)malloc(sizeof(VIPNode));
	//������Ϣ���浽�½ڵ���
        printf("�������Ա���˺�:\n");
	    scanf("%s",&s->VIP.no);
	    printf("�������Ա������:\n");               
	    scanf("%s",&s->VIP.name);
	    printf("�������Ա�����֤��:");
		scanf("%s",&s->VIP.ID);
		printf("�������Ա����ϵ�绰:");
		scanf("%s",&s->VIP.phone);
		printf("�������Ա�����ѽ��:");
		scanf("%d",&s->VIP.money);
    	counts(s);
		printf("��Ա�Ļ�Ա�ȼ�:");
		printf("%s\n", s->VIP.grade); 
		printf("��Ա���Ż�����:");
		printf("%s\n",s->VIP.discounts);
	    printf("\n");
	//������Ϊ�գ���βָ��ָ���½ڵ�
	if (L->head == L->tail) {
		L->tail = s;
	}
	//���½ڵ�������ͷ����ͷ�巨��
	s->next = L->head->next;
	L->head->next = s;
	L->count++;
	//���������Ϣ
	printf("��Ϣ¼��ɹ���\n\n");
	system("pause");
}
 
void Delete(VIPList *L) // ɾ�� 
{
	int  flag = 0;
	char s1[LEN + 1];
	VIPNode *p1,*p2; 
	printf("������Ҫɾ����Ա���˺�:\n");
	scanf("%s", s1);
	if(L->head->next==NULL)
	{
		printf("\n\t\t����Ϊ��");
		return; 
	} 
	p1=L->head->next; 
	while (p1!=NULL&&(strcmp(p1->VIP.no, s1) != 0)) 
	{
		p2=p1;
		p1=p1->next; 
		L->count--; 
	}
	if(strcmp(p1->VIP.no, s1) == 0){
		if(p1==L->head->next)
		    L->head->next=L->head->next->next; 
		else
		   p2->next=p1->next; 
	    printf("ɾ���ɹ�\n"); 
	    L->count--; 
	       
	}else 
		printf("���˺Ų�����!!!\n");
	system("pause");
}
 
void Modify(VIPList *L) //�޸� 
{
	int i, item, num = -1;
	char s1[LEN + 1], s2[LEN + 1],s3[LEN + 1],s4[LEN + 1];
	printf("������ҪҪ�޸Ļ�Ա���˺�:\n");
	scanf("%s", s1);
	//��������Ա�
	VIPNode *p = L->head->next;
	while (p) {
		if (strcmp(p->VIP.no, s1) == 0)
		{
			num = i;
			printf("\t\t------------------------------------------------------------------\n");
	        printf("\t\t���---------------------1.�޸�����-----------------------���\n\n");
	        printf("\t\t���---------------------2.�޸����֤��-----------------------���\n\n");
	        printf("\t\t���---------------------3.�޸ĵ绰����-------------------���\n\n");
	        printf("\t\t���---------------------0.�˳����˵�-----------------------���\n\n");
	        printf("\t\t------------------------------------------------------------------\n");
			while (1)
			{
				printf("��ѡ���Ӳ˵����:");
				scanf("%d", &item);
				switch (item)
				{
					case 1:
						printf("�������µ�����:\n");
						scanf("%s", s2);
						strcpy(p->VIP.name, s2);
						break;
					case 2:
						printf("�������µ����֤��:\n");
						scanf("%s", s3);
						strcpy(p->VIP.ID, s3);
						break;
					case 3:
						printf("�������µĵ绰����:\n");
						scanf("%s",s4);
						strcpy(p->VIP.phone, s4);
						break;
					case 0:
						return;
					default:
						printf("����0-3֮��ѡ��\n");
				}
					printf("�޸���ϣ�\n");
			} 
			return; 
		}
		p = p->next;
	}
	printf("û�иû�Ա�˺�!!!");
	system("pause");
}
 
void transaction(VIPList *L)     //���ѻ��ֵ 
{
	int a,b;
	int found=1;
	char choice,no[LEN+1];
    while(1)
	{
        printf("�������Ա���˺ţ�\n");
        scanf("%s",&no);
        getchar();
        VIPNode *p = L->head->next;
        while(p){ 
            if(strcmp(p->VIP.no,no) == 0)
			{
				found=0;
				printf("%s\t%s\t%s\t%s\t%d\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money);
	            printf("��ѡ�����ͣ�1.����  2.��ֵ\n");
	            scanf("%d",&a);
	        	getchar();
	            printf("�������\n");
	            scanf("%d",&b); 
	            getchar();
	            if(a==1)
	            {
	            	p->VIP.money=p->VIP.money-b;
					printf("%s\t%s\t%s\t%s\t%d\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money);
				}
				else
				{
					p->VIP.money=p->VIP.money+b;
				    printf("%s\t%s\t%s\t%s\t%d\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money);
				}
			}	
			    p=p->next; 
		} 
        if(found==1)
		{
			printf("δ�ҵ�!\n");
		}
		found=1;	
		printf("�Ƿ����(Y/N)\n");
		choice=getchar();
		getchar(); 
		if(choice=='N'|| choice=='n')
			break;
}
} 
 
void save(VIPList *L)     //���� 
{	//���ļ���
	FILE *fp = fopen("����", "w");
	if (fp == NULL) {
		printf("�ļ���ʧ��\n");
		exit(EXIT_FAILURE);
	}
	//��ѧ���ڵ���������ڵ�һ��
	fprintf(fp, "%d\n", L->count);
	//����һ�ڵ�ָ��ָ��ͷ�ڵ�
	VIPNode *s;
	s = L->head->next;
	//��������һ��������Ϊһ�����
	while (s) {
		fprintf(fp, "%s ", s->VIP.no);
		fprintf(fp, "%s ", s->VIP.name);
		fprintf(fp, "%s ", s->VIP.ID);
		fprintf(fp, "%s ", s->VIP.phone);
		fprintf(fp, "%d ", &s->VIP.money);
		fprintf(fp, "%s ", s->VIP.grade);
		fprintf(fp, "%s ", s->VIP.discounts);
		fprintf(fp, "\n");
		//������֮���ͷŽڵ�ռ�
		VIPNode *next = s->next;
		free(s);
		s = next;
	}
	//�ر��ļ���
	fclose(fp);
	//������Ϣ
	printf("�����ѱ��棡ллʹ�ã��ټ���\n");
}
 
