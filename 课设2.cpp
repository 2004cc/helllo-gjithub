#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len node *worker
struct staff //定义职工结构体 
{
	char num[20];//编号
	char name[20];//姓名 
	char sex[20];//性别 
	char bir[20];//生日 (birthday)
	char edu[20];//学历 (education)
	char sta[20];//入职时间 (start time)
	char job[20];//工作 
	char addr[50];//地址(address) 
	char tel[20];//电话 (telphone)
	char sal[20];//薪资 (salary)
};
typedef struct link//定义链表结构体 
{
	struct staff worker;
	struct link *next;
	struct link *prior;	
}node;
void menu(len);//菜单(menu)
void add(len);//增加(add)
void del(len);//删除(delete)
int cha(len);//修改(change) 
void sea(len);//查找(search)
void sort(len);//排序(sort) 
void saveFile(len);//存储至文件中 
void savenode(len);//输出已有信息 
void readFile(len);//读取文件中的信息 
void next(len); //进行下一步
int main() 
{
	void lock();
	system("color 3f");
	len;
	worker=(node*)malloc(sizeof(node));//相当于一个头指针 
	worker->next=NULL;
	worker->prior=NULL;
	system("color 3f");
	readFile(worker);
	menu(worker);
	return 0;
}
void menu(len)//进入菜单界面及进行后续操作的选择
{
	int command=0;
	printf("--------------------------------------------------------------------------------------------\n");	
	printf("\t欢迎来到南阳理工学院职工管理系统！                                                 |\n");
	printf("\t您可以执行以下操作：                                                               |\n");
	printf("\t\t1. 新增职工                                                                |\n");
	printf("\t\t2. 删除职工                                                                |\n");
	printf("\t\t3. 查询职工                                                                |\n");
	printf("\t\t4. 修改职工                                                                |\n");
	printf("\t\t5. 排序职工                                                                |\n");
	printf("\t\t6. 退出系统                                                                |\n");
	printf("\t请输入所需操作相对应的数字：                                                       |\n");//6种操作 
	printf("--------------------------------------------------------------------------------------------\n");
	scanf("%d",&command);
	switch(command)//分情况执行不同命令：123456
	{
		case 1:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("欢迎进入新增职工页面\n");
			printf("--------------------------------------------------------------------------------------------\n");
			add(worker);//添加职工信息  
			saveFile(worker);//保存职工信息 
			next(worker); 
			break;
		case 2:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("欢迎进入删除职工页面\n");
			printf("--------------------------------------------------------------------------------------------\n");
			del(worker);
			next(worker);
			break;
		case 3:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("欢迎进入查询职工页面\n");
			printf("--------------------------------------------------------------------------------------------\n");
			sea(worker);
			saveFile(worker);
			next(worker);
			break;	
		case 4:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("欢迎进入修改职工页面\n");
			printf("--------------------------------------------------------------------------------------------\n");
			cha(worker);
			saveFile(worker);
			next(worker);
			break;
		case 5:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("欢迎进入排序职工页面\n");
			printf("--------------------------------------------------------------------------------------------\n");
			sort(worker);
			next(worker);
			break;
		case 6:
			exit(0);
		default:
			system("cls");//若指令不符合，从新输入 
			printf("您输入的指令有误，请重新输入：\n");
			menu(worker); 
	}
}
void add(len)//添加职工操作 
{
	int command;
	printf("增加：1  返回：2\n");
	scanf("%d",&command);
	if(command==1)
	{
		printf("请依次输入新增职工以下信息:\n");
		printf("编号\t姓名\t性别\t生日\t学历\t电话\t\t住址\t\t入职时间\t职务\t薪资 \n");
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
		node *p,*q,*k;
		q=worker;
		k=worker->next; 
		p=(node *)malloc(sizeof(node));
		scanf("%s%s%s%s%s%s%s%s%s%s",
		p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
		while(k!=NULL)//判断编号是否可操作 （查重） 
		{
			if(strcmp(p->worker.num,k->worker.num)==0)
			{
				printf("该编号已经存在，请您从新输入！\n");
				scanf("%s",p->worker.num);
				k=worker;//再指回头节点，重新进行操作 
			}
			k=k->next;
		}
		printf("添加成功！新增职工信息如下：\n\n");
		printf("编号\t姓名\t性别\t生日\t\t学历\t电话\t\t住址\t\t\t入职时间\t职务\t薪资 \n");
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
		while(q!=NULL)//符合条件之后开始添加，操作如下 
		{
			if(q->next==NULL)
			{
				q->next=p;
				p->prior=q;
				p->next=NULL;
				break;
			}else
			{
				q=q->next;	
			}  
		} 
	}else if(command==2)
	{
		system("cls");
		menu(worker);
	}else
	{
		system("cls");
		printf("您输入的指令有误，请重新输入！\n");
		scanf("%d",&command);
		add(worker);	
	}	
}
void del(len)//删除职工操作 
{
	node *k,*p;
	char delnum[20];
	k=worker->next;
	if(k==NULL)
	{
		printf("Sorry,目前无相关资料！\n");
	}else
	{
		printf("--------------------------------------------------------------------------------------------\n");
		int num=0;
		printf("请输入需要删除的职工编号：\n");
		scanf("%s",delnum);
		while(k!=NULL)
		{
			if(strcmp(k->worker.num,delnum)==0)//判断该职工是否存在 
			{
				num==1;
				printf("编号\t姓名\t性别\t生日\t\t学历\t电话\t\t住址\t\t\t\t入职时间\t职务\t薪资 \n");
				printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n",
				k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);	
				printf("您确定要删除%s吗？\n\n",k->worker.name);
				printf("删除：1 取消：2\n");
				int command=0;
				scanf("%d",&command);
				if(command==1)//进行删除操作
				{
					printf("%s删除成功！\n",k->worker.name);//之后删除该节点，操作如下
					p=worker;
					while(p->next!=k)
					{
						p=p->next;
					}
					p->next=p->next->next;//直接跳过该节点（删除） 
					saveFile(worker);//删除操作完成 
				}else if(command==2)//取消删除操作 
				{
					printf("取消删除成功！\n");
					break;
				}
				break;
			}else
			{
				if(k->next==NULL && num==0)
				{
					printf("Sorry,您要查找的这位职工不存在！\n");
				}
			}
			k=k->next;
		}
	}	
}
int cha(len)//修改职工信息 
{
	int command;
	printf("修改：1  返回：2\n");
	scanf("%d",&command);
	if(command==1)
	{
		char chanum[20];
		node *k=worker->next;
		if(k==NULL)
		{
			printf("Sorry,目前无相关资料！\n");
			return 0;
		}else
		{
			printf("请输入所要修改的职工编号：\n");
			scanf("%s",chanum);
			int num=0;
			while(k!=NULL)
			{
				if(strcmp(k->worker.num,chanum)==0)//如果职工存在，继续进行操作 
				{
					num=1;
					printf("已找到该职工，信息如下：\n");//原本信息 
					printf("编号\t姓名\t性别\t生日\t\t学历\t电话\t\t住址\t\t\t\t入职时间\t职务\t薪资 \n");
					printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n",
					k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);	
					printf("\n请输入新信息以进行修改：\n");//开始修改信息 
					
					printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%s\t\n",k->worker.num);
					scanf("%s%s%s%s%s%s%s%s%s",//输入新信息 
					k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);	
					printf("职工信息修改后如下：\n\n");//显示修改后的信息
					printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
					printf("编号\t姓名\t性别\t生日\t\t学历\t电话\t\t住址\t\t\t\t入职时间\t职务\t薪资 \n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n",
					k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);	
					break;	
				}else//不存在则直接结束 
				{
					if(k->next==NULL && num==0)
					{
						printf("Sorry,未找到相关职工资料!\n");
					}
				}
				k=k->next;
			}	
		}	
	}else if(command==2)
	{
		system("cls");
		menu(worker);
	} 	
}
void sea(len)//查找职工操作 （根据职工编号查找） 
{
	char seanum[20];
	node *k=worker->next;
	if(k==NULL)//判断是否存在 
	{
		printf("Sorry，目前无相关资料！\n");
	}else
	{
		int num=0;
		printf("请输入要所查询的职工编号：\n");
		scanf("%s",seanum);
		while(k!=NULL)
		{
			if(strcmp(k->worker.num,seanum)==0)//判断是否存在 
			{
				num=1;
				if(num==1)
				{
					printf("--------------------------------------------------------------------------------------------\n");
					
				}
				printf("已找到该职工，其信息如下：\n");
				printf("编号\t姓名\t性别\t生日\t\t学历\t电话\t\t住址\t\t\t\t入职时间\t职务\t薪资 \n");
				printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n",
				k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);		
			}else
			{
				if(k->next==NULL && num==0)
				{
					printf("Sorry,未找到相关职工资料！\n");	
				}
			}
				k=k->next;					
		}	
	} 	 
}
void sort(len)//职工统计和排序(升序或者降序) 
{
	node *k,*p1,*p2,*p3; 
	k=worker->next;//用于判断循环停止位置 
	p1=(node*)malloc(sizeof(node)); //创建一个新头结点存储新链表 
	p1->next=NULL;
	p1->prior=NULL;	
	p2=p1->next;
	int salnum;	
	if(k==NULL)
	{
		printf("目前没有资料\n\n");
	}else
	{
		printf("请选择你所需要的排序方式：\n");
		printf("升序 1  降序 2\n"); 
		int command;
		scanf("%d",&command);
		if(command==1)//升序 
		{
			system("cls");
			printf("以下职工信息按工资从高到低进行排序\n"); 
			printf("编号\t姓名\t性别\t生日\t\t学历\t电话\t\t住址\t\t\t\t入职时间\t职务\t薪资 \n");
			printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
			p2=(node*)malloc(sizeof(node));
			p2->prior=p1;
			p2->next=NULL;
			p2->worker=k->worker;
			k=k->next;
			while(k!=NULL)//判断循环停止的条件  
			{		
				salnum=atoi(k->worker.sal);//将代表工资的字符串转化为数字(atoi函数）			
				p3=(node *)malloc(sizeof(node));//保证k链可正常用于循环  
				p3->worker=k->worker;						
				while(p2!=NULL)//遍历
				{
					if(p1->next==NULL) 
					{
						p1->next=p2;	
					}
					//后插，没有两个值的情况，比第一个数小 ;或遍历到最后一个且比最后一个小，注意p2回到头节点重新遍历		
					if(salnum<=atoi(p2->worker.sal) && p2->next==NULL)//无第三值情况
					{					
						p2->next=p3;
						p3->prior=p2;
						p3->next=NULL; 				  			
						break;
					}else if(salnum<=atoi(p2->prior->worker.sal) && salnum>atoi(p2->worker.sal) )//有三值时一大一小插中间  
					{
						p3->prior=p2->prior;
						p3->next=p2;
						p2->prior->next=p3;							
						p2->prior=p3;	
						break;
					}				
					p2->prior=p2;
					p2=p2->next;
				}
				p2 =p1->next;
				p2->prior=p1;		
				k=k->next;									
			}
			savenode(p1);//输出排序后信息				
		}else if(command==2)//降序 
		{
			system("cls");
			printf("以下职工信息按工资从从低到高进行排序\n"); 
			printf("编号\t姓名\t性别\t生日\t\t学历\t电话\t\t住址\t\t\t\t入职时间\t职务\t薪资 \n");
			printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
			p2=(node*)malloc(sizeof(node));
			p2->prior=p1;
			p2->next=NULL;
			p2->worker=k->worker;
			k=k->next;
			while(k!=NULL)  
			{		
				salnum=atoi(k->worker.sal);		
				p3=(node *)malloc(sizeof(node));
				p3->worker=k->worker;						
				while(p2!=NULL)//遍历整链 
				{
					if(p1->next==NULL) 
					{
						p1->next=p2;	 
					}		
					if(salnum>=atoi(p2->worker.sal) && p2->next==NULL) 
					{					
						p2->next=p3;
						p3->prior=p2;
						p3->next=NULL; 				  			
						break;
					}else if(salnum>=atoi(p2->prior->worker.sal) && salnum<atoi(p2->worker.sal))
					{
						p3->prior=p2->prior;
						p3->next=p2;
						p2->prior->next=p3;							
						p2->prior=p3;	
						break;
					}				 
					p2->prior=p2;
					p2=p2->next;
				}
				p2 =p1->next;
				p2->prior=p1;		
				k=k->next;									
			}	
			savenode(p1);			
		}else
		{
			system("cls");
			printf("您输入的指令有误，请重新输入：\n");
			sort(worker);	
		}	
	} 
}
void saveFile(len)//储存文件信息 
{
	node *p=NULL;
	FILE *fp;
	if(worker->next==NULL)
	{
		printf("Sorry,无相关记录！\n");
	}else
	{
		p=worker->next;
	}
	fp=fopen("C:\\Users\\86198\\Desktop\\1.txt","w");
	if(fp==NULL)
	{
		printf("Sorry,该文件无法打开！\n");
	}
	while(p!=NULL)
	{
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\t%s\n",
		p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
		p=p->next; 
	}
	fclose(fp);
}
void savenode(len)//输出排序好的链表信息 
{
	node *p=NULL;
	if(worker->next==NULL)
	{
		printf("Sorry,无该职工相关记录！\n");
	}else
	{
		p=worker->next;
	}
	while(p!=NULL)
	{
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n",
	p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
		p=p->next;
		if(p==NULL)
		{
			printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
			printf("以上为排序后所有职工信息！\n");
		}
	}
}
void readFile(len)
{
	node *p,*r;
	FILE *fp;
	r=worker;
	fp=fopen("C:\\Users\\86198\\Desktop\\1.txt","rt");
	p=(node*)malloc(sizeof(node));
	fscanf(fp,"%s%s%s%s%s%s%s%s%s%s",
	p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
	if(fp==NULL)
	{
		printf("Sorry,该文件打开失败，请检查文件名或确认所要打开文件信息无误后再操作！\n");
	}
	while(!feof(fp))
	{
		r->next=p;
		r=p;
		r->next=NULL;
		p=(node*)malloc(sizeof(node));
		fscanf(fp,"%s%s%s%s%s%s%s%s%s%s",
		p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal); 
	}
	fclose(fp);
}
void next(len)
{
	printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
	printf("返回主菜单 1  退出系统 2\n");
	int choose;
	scanf("%d",&choose);
	while(true)
	{
		if(choose==1)
		{
			system("cls");
			menu(worker);
		}else if(choose==2)
		{
			exit(0);
		}else
		{
			printf("您输入的指令有误，请重新输入：\n");
			scanf("%d",&choose);
			continue;
		}
	}
}
void lock()
{
	system("color 3f");
	char a[100]="user";
	char b[100]="userdemimashi123...";
	char c[100]={0};
	char d[100]={0};
	printf("请输入管理员账户及密码、\n");
	printf("账户：");
	scanf("%s",c);
	printf("\n");
	printf("密码：");
	scanf("%s",d);
	if((strcmp(a,c)==0)&&strcmp(b,d)==0)
	{
		printf("登陆成功！\n");
		return;
	}else
	{
		system("cls");
		printf("您的账户或者密码有误，请重新登录！");
		void lock(); 
	}
 } 
//	node *p=worker->next;
//	if(p==NULL)
//	{
//		printf("Sorry,目前无相关资料！\n");
//	}else
//	{
//		printf("以下信息将按照职工姓名进行排序：\n");
//		printf("编号\t姓名\t性别\t生日\t\t学历\t电话\t\t\t住址\t\t\t\t入职时间\t职务\t薪资 \n");
//		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
//		while(p!=NULL)
//		{
//			printf("%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\t%s\n",
//			p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
//			p=p->next;
//		} 
//	}

