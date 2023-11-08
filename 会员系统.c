# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
#define LEN 25 
#define N 70
#define F "数据.txt" //文件路径
 
typedef struct
{
	char no[10];//账号 
	char name[10];//姓名 
	char ID[30];//身份证号 
	char phone[16];//电话 
	int money;	//金额 
	char grade[10];//等级 
	char discounts[10]; //折扣 
}VIP;   //单个会员信息 
 
typedef struct node{
    VIP VIP;            //数据域 
    struct node *next;   //指针域 
}VIPNode;   //会员节点 
 
typedef struct{
    VIPNode *head;  //头指针 
    VIPNode *tail;  //尾指针 
    int count;
}VIPList;     // 会员链表 
 
int  m = 0;//k = 1, n = 0,
 
 
void counts(VIPNode *q);//会员等级 
int menu();   //菜单 
void Instruction();//系统说明 
void initialize(VIPList *L);//初始化链表 
void read(VIPList *L);//从文件中读取 
void input(VIPList *List,int m);  //输入 
void sort(VIPList *L); //排序
void print(VIPList *L); //输出 
void Search(VIPList *L); //查询 
void insert(VIPList *L); //插入 
void Delete(VIPList *L);//删除 
void Modify(VIPList *L);//修改 
void transaction(VIPList *L);//充值或消费 
void save(VIPList *L);//保存 
 
 
 
 
 
//登录界面 
void login()		
{
   char userName[5];
   char password[5];
   int i;
   printf("\n\n   ---------==========================你好啊==========================-------------\n");
   for(i=1;i<4;i++)
   {
        printf("\n             请输入您的用户名:");
        gets(userName);
        printf("\n             请输入您的密码:");
        gets(password);
        if ((strcmp(userName,"000")==0) && (strcmp(password,"123")==0))/*验证用户名和密码*/
        {
        	
            printf("\n   -------------------------------------------欢迎您，可爱的会员-------------------------------------------");
            Sleep(500); 
            return;
        }
        else
        {
            if(i<3)
            {
                printf("\n           用户名或密码错误，请重新输入!\n");
            }
            else
            {
                printf("\n           您已连续3次将用户名或密码输错，系统将退出!");
                exit(0);
            }
        }
   }
}
 
 
void main()          
{
	int a; 
	login();
    VIPList *L=(VIPList *)malloc(sizeof(VIPList));//创建链表 
    initialize(L);//初始化链表
	read(L);//从文件里读取数据到链表 
	while(1) 
	{
		menu(); 
		printf("\t请选择您要运行的选项按(0-9):");
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
				printf("\t\t\t输入会员的个数：");
				scanf("%d",&m);
				if(m<=0)
				{
					printf("\n\t\t\t请输入正确的人数!");
					break;
				}
				else
				{
					printf("\n\t\t\t输入会员信息\n\n");
					input(L,m); 
	            	break;
				}
            case 2:
            	system("cls");
	            printf("\t\t\t\t\t显示会员信息\n"); 
	            sort(L); 
	            print(L); 
	            break; 
            case 3:
            	system("cls");
				printf("\t\t\t\t\t查询会员信息\n");
				Search(L); 
                break;
            case 4:
            	system("cls");
                printf("\t\t\t\t\t插入会员信息\n");
                insert(L); 
				break;       
			case 5:
				system("cls"); 
				printf("\t\t\t\t\t修改会员信息\n");
                Modify(L);
                
                break;
            case 6:
				system("cls");
                printf("\t\t\t\t\t删除会员信息\n");
                Delete(L);
                break;  
			case 7:
				system("cls");
                printf("\t\t\t\t\t会员消费或充值\n");
                transaction(L);
                break;  	  
            case 8:
            	system("cls");
            	save(L); 
                printf("\n\t\t\t\t\t谢谢使用\n");
                exit(0);
                break; 
        }
	}
}
 
 
int menu()
{      
        system("cls");
        printf("\n\n\t\t超市会员管理系统\n");
        printf("\t\t=  = 0. 系统说明                                            ☆☆\n\n");
        printf("\t\t=  = 1. 输入会员信息                                        ☆☆\n\n");
        printf("\t\t=  = 2. 显示会员信息                                        ☆☆\n\n");
        printf("\t\t=  = 3. 查询会员信息                                        ☆☆\n\n");
        printf("\t\t=  = 4. 插入会员信息                                        ☆☆\n\n");
        printf("\t\t=  = 5. 修改会员信息                                        ☆☆\n\n");
        printf("\t\t=  = 6. 删除会员信息                                        ☆☆\n\n");
        printf("\t\t=  = 7. 会员消费或充值                                      ☆☆\n\n");
		printf("\t\t=  = 8. 退出系统                                            ☆☆\n\n");
        printf("\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		return 1;
}
 
void Instruction() //系统说明 
 
{
	printf("\n\t\t          欢迎您使用系统说明\n");
	printf("\n\t\t          请您选择菜单上的数字\n");
	printf("\n\t\t          修改傻大户信息后请保存\n");
	printf("\n\t\t          谢谢使用这个系统哦\n");
	system("pause");
}
 
 
void initialize(VIPList *L) { //初始化 
	//创建头节点
	VIPNode *s = (VIPNode *)malloc(sizeof(VIPNode));
	s->next = NULL;
	//初始化链表：
	//头尾指针均指向头节点，初始长度为零
	L->head = s;
	L->tail = s;
	L->count = 0;
}
 
void read(VIPList *L) {
	//打开文件流
	FILE *fp = fopen("数据", "w");
	if (fp == NULL) {
		printf("文件打开失败\n");
		exit(EXIT_FAILURE);
	}
	//读取第一行的会员节点总数
	fscanf(fp, "%d", &L->count);
	int i;//循环读取数据，循环次数为count
	for (i = 1; i <= L->count; i++) {
		//创建新节点
		VIPNode *s = (VIPNode *)malloc(sizeof(VIPNode));
		//读取数据
		fscanf(fp, "%s ", s->VIP.no);
		fscanf(fp, "%s ", s->VIP.name);
		fscanf(fp, "%s ", s->VIP.ID);
		fscanf(fp, "%s ", s->VIP.phone);
		fscanf(fp, "%d ", &s->VIP.money);
		fscanf(fp, "%s ", s->VIP.grade);
		fscanf(fp, "%s ", s->VIP.discounts);
		//将新节点插进链表尾部（尾插法）
		s->next = NULL;
		L->tail->next = s;
		L->tail = s;
	}
	//关闭文件流
	fclose(fp);
} 
 
void input(VIPList *L,int m)                  
{
	int i;
	for(i=1;i<=m;i++)
	{
		VIPNode *r = (VIPNode *)malloc(sizeof(VIPNode));
		printf("请输入会员的账号:\n");
	    scanf("%s",r->VIP.no);
	    printf("请输入会员的姓名:\n");               
	    scanf("%s",r->VIP.name);
	    printf("请输入会员的身份证号:");
		scanf("%s",r->VIP.ID);
		printf("请输入会员的联系电话:");
		scanf("%s",r->VIP.phone);
		printf("请输入会员的消费金额:");
		scanf("%d",&r->VIP.money);
    	counts(r);
		printf("会员的会员等级:");
		printf("%s\n", r->VIP.grade); 
		printf("会员的优惠政策:");
		printf("%s\n",r->VIP.discounts);
	    //将新节点插进链表尾部（尾插法）
		L->tail->next = r;
		r->next = NULL;
		L->tail = r;   
		L->count++;                                  //指针后移
	}
	printf("会员信息录入完毕！！！\n");
	system("pause");
	
}
 
void counts(VIPNode *q){
	char grade[6][50]={"普通","白银","黄金","铂金","钻石","黑金"};
	//>=0,普通；>=500,白银；>=1000,黄金；>=3000,铂金；>=6000，钻石；>=10000,黑金 	
	char discounts[6][50]={"原价","九折","八八折","八五折","八折","七折"};
	int num;
	num=q->VIP.money/100; 
	if(num<=5) { 
		strcpy(q->VIP.grade,grade[0]);
		strcpy(q->VIP.discounts,discounts[0]); 
		printf("可以送白菜");
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
	printf("会员个数为%d：",L->count); 
	//插入排序
	VIPNode *p, *pre, *tmp;
	//p指向第二个会员节点
	p = L->head->next;
	//链表从头节点和第一个会员节点处断开
	L->head->next = NULL;
	//从第一个会员节点开始一直往后循环
	while (p) {
		//存好下一个节点的指针
		tmp = p->next;
		//找到插入位置
		pre = L->head;
		while (pre->next != NULL && strcmp(pre->next->VIP.no,p->VIP.no)<0){ 
			pre = pre->next;} 
		//更新尾指针
		if (pre->next == NULL) {
			L->tail = p;
		}
		//插入
		p->next = pre->next;
		pre->next = p;
		//跳到下一个
		p = tmp;
	}
	printf("链表排序完成！\n");
	system("pause");
}
 
 
void print(VIPList *L)  //输出 
{
	printf("共有%d组会员数据：\n", L->count);
	printf("     |=============================================================================================|\n");
	printf("     | 账 号 | 姓 名 |           身份证号          |   联系电话   | 消费金额 | 会员等级 | 优惠政策 |\n");
	printf("     |---------------------------------------------------------------------------------------------|\n");
	//创建一节点指针指向头节点
	VIPNode *p;
	p = L->head;
	//遍历链表输出
	while (p->next) {
		p = p->next;
		printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
	}
	printf("     |=============================================================================================|\n");
	system("pause");
}
 
 
 
void Search(VIPList *L) //查询 
 
{
	int  item, flag;
	char s1[21];
	printf("\t\t------------------------------------------------------------------\n");
	printf("\t\t☆☆---------------------1.按账号查询-----------------------☆☆\n\n");
	printf("\t\t☆☆---------------------2.按姓名查询-----------------------☆☆\n\n");
	printf("\t\t☆☆---------------------3.按身份证号查询--------------------☆☆\n\n");
	printf("\t\t☆☆---------------------4.按联系电话查询-------------------☆☆\n\n");
	printf("\t\t☆☆---------------------0.退出本菜单-----------------------☆☆\n\n");
	printf("\t\t------------------------------------------------------------------\n");
 
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		VIPNode *p =L->head->next;
		flag = 0;
		switch (item)
		{
			case 1:
				printf("请输入要查询的会员的账号:\n");
				scanf("%s",s1);
				while (p){ 
					if (strcmp(p->VIP.no, s1) == 0)
					{
						flag=1; 
					    printf("     |=============================================================================================|\n");
	                    printf("     | 账 号 | 姓 名 |           身份证号          |   联系电话   | 消费金额 | 会员等级 | 优惠政策 |\n");
	                    printf("     |---------------------------------------------------------------------------------------------|\n");
                        printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
					}
                    p = p->next;
                }
                if (0 == flag)
					printf("该账号不存在！\n");
				break;
			case 2:
				printf("请输入要查询的会员的姓名:\n");
				scanf("%s", s1);
				//VIPNode *p = L->head->next;
				while (p){
					if (strcmp(p->VIP.name, s1) == 0)
					{
						flag = 1;
						printf("     |=============================================================================================|\n");
	                	printf("     | 账 号 | 姓 名 |           身份证号          |   联系电话   | 消费金额 | 会员等级 | 优惠政策 |\n");
	                	printf("     |---------------------------------------------------------------------------------------------|\n");
                        printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
					}
					p = p->next;
                }
				if (0 == flag)
					printf("该姓名不存在！\n");
				break;
			case 3:
				printf("请输入要查询的会员的身份证号:\n");
				scanf("%s", s1);
				//VIPNode *p = L->head->next;
				while (p){
					if (strcmp(p->VIP.ID, s1) == 0)
					{
						flag = 1;
						printf("     |=============================================================================================|\n");
	                	printf("     | 账 号 | 姓 名 |           身份证号          |   联系电话   | 消费金额 | 会员等级 | 优惠政策 |\n");
	                	printf("     |---------------------------------------------------------------------------------------------|\n");
                        printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
					}
					p = p->next;
                }
				if (0 == flag)
					printf("该身份证号不存在！\n");
				break;
			case 4:
				printf("请输入要查询的会员的电话号码:\n");
				scanf("%s", s1);
				//VIPNode *p = L->head->next;
				while (p){
					if (strcmp(p->VIP.phone, s1) == 0)
					{
						flag = 1;
						printf("     |=============================================================================================|\n");
	                	printf("     | 账 号 | 姓 名 |           身份证号          |   联系电话   | 消费金额 | 会员等级 | 优惠政策 |\n");
	                	printf("     |---------------------------------------------------------------------------------------------|\n");
                    	printf("     | %5s | %5s |  %25s  |%14s| %8d | %8s | %8s |\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money,p->VIP.grade,p->VIP.discounts);
					}
					p = p->next;
                }
				if (0 == flag)
					printf("该电话号码不存在！\n");
				break;
			case 0:
				return;
			default:
				printf("请在0-4之间选择\n");
		}
 
	}
 
}
 
void insert(VIPList *L)
{
	VIPNode *s = (VIPNode *)malloc(sizeof(VIPNode));
	//键入信息并存到新节点中
        printf("请输入会员的账号:\n");
	    scanf("%s",&s->VIP.no);
	    printf("请输入会员的姓名:\n");               
	    scanf("%s",&s->VIP.name);
	    printf("请输入会员的身份证号:");
		scanf("%s",&s->VIP.ID);
		printf("请输入会员的联系电话:");
		scanf("%s",&s->VIP.phone);
		printf("请输入会员的消费金额:");
		scanf("%d",&s->VIP.money);
    	counts(s);
		printf("会员的会员等级:");
		printf("%s\n", s->VIP.grade); 
		printf("会员的优惠政策:");
		printf("%s\n",s->VIP.discounts);
	    printf("\n");
	//若链表为空，将尾指针指向新节点
	if (L->head == L->tail) {
		L->tail = s;
	}
	//将新节点插进链表头部（头插法）
	s->next = L->head->next;
	L->head->next = s;
	L->count++;
	//输出互动信息
	printf("信息录入成功！\n\n");
	system("pause");
}
 
void Delete(VIPList *L) // 删除 
{
	int  flag = 0;
	char s1[LEN + 1];
	VIPNode *p1,*p2; 
	printf("请输入要删除会员的账号:\n");
	scanf("%s", s1);
	if(L->head->next==NULL)
	{
		printf("\n\t\t链表为空");
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
	    printf("删除成功\n"); 
	    L->count--; 
	       
	}else 
		printf("该账号不存在!!!\n");
	system("pause");
}
 
void Modify(VIPList *L) //修改 
{
	int i, item, num = -1;
	char s1[LEN + 1], s2[LEN + 1],s3[LEN + 1],s4[LEN + 1];
	printf("请输入要要修改会员的账号:\n");
	scanf("%s", s1);
	//遍历链表对比
	VIPNode *p = L->head->next;
	while (p) {
		if (strcmp(p->VIP.no, s1) == 0)
		{
			num = i;
			printf("\t\t------------------------------------------------------------------\n");
	        printf("\t\t☆☆---------------------1.修改姓名-----------------------☆☆\n\n");
	        printf("\t\t☆☆---------------------2.修改身份证号-----------------------☆☆\n\n");
	        printf("\t\t☆☆---------------------3.修改电话号码-------------------☆☆\n\n");
	        printf("\t\t☆☆---------------------0.退出本菜单-----------------------☆☆\n\n");
	        printf("\t\t------------------------------------------------------------------\n");
			while (1)
			{
				printf("请选择子菜单编号:");
				scanf("%d", &item);
				switch (item)
				{
					case 1:
						printf("请输入新的姓名:\n");
						scanf("%s", s2);
						strcpy(p->VIP.name, s2);
						break;
					case 2:
						printf("请输入新的身份证号:\n");
						scanf("%s", s3);
						strcpy(p->VIP.ID, s3);
						break;
					case 3:
						printf("请输入新的电话号码:\n");
						scanf("%s",s4);
						strcpy(p->VIP.phone, s4);
						break;
					case 0:
						return;
					default:
						printf("请在0-3之间选择\n");
				}
					printf("修改完毕！\n");
			} 
			return; 
		}
		p = p->next;
	}
	printf("没有该会员账号!!!");
	system("pause");
}
 
void transaction(VIPList *L)     //消费或充值 
{
	int a,b;
	int found=1;
	char choice,no[LEN+1];
    while(1)
	{
        printf("请输入会员的账号：\n");
        scanf("%s",&no);
        getchar();
        VIPNode *p = L->head->next;
        while(p){ 
            if(strcmp(p->VIP.no,no) == 0)
			{
				found=0;
				printf("%s\t%s\t%s\t%s\t%d\n",p->VIP.no,p->VIP.name,p->VIP.ID,p->VIP.phone,p->VIP.money);
	            printf("请选择类型：1.消费  2.充值\n");
	            scanf("%d",&a);
	        	getchar();
	            printf("请输入金额：\n");
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
			printf("未找到!\n");
		}
		found=1;	
		printf("是否继续(Y/N)\n");
		choice=getchar();
		getchar(); 
		if(choice=='N'|| choice=='n')
			break;
}
} 
 
void save(VIPList *L)     //保存 
{	//打开文件流
	FILE *fp = fopen("数据", "w");
	if (fp == NULL) {
		printf("文件打开失败\n");
		exit(EXIT_FAILURE);
	}
	//将学生节点总数输出在第一行
	fprintf(fp, "%d\n", L->count);
	//创建一节点指针指向头节点
	VIPNode *s;
	s = L->head->next;
	//遍历链表，一组数据作为一行输出
	while (s) {
		fprintf(fp, "%s ", s->VIP.no);
		fprintf(fp, "%s ", s->VIP.name);
		fprintf(fp, "%s ", s->VIP.ID);
		fprintf(fp, "%s ", s->VIP.phone);
		fprintf(fp, "%d ", &s->VIP.money);
		fprintf(fp, "%s ", s->VIP.grade);
		fprintf(fp, "%s ", s->VIP.discounts);
		fprintf(fp, "\n");
		//输出完成之后释放节点空间
		VIPNode *next = s->next;
		free(s);
		s = next;
	}
	//关闭文件流
	fclose(fp);
	//互动信息
	printf("数据已保存！谢谢使用，再见！\n");
}
 
