#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len node *worker
struct staff //����ְ���ṹ�� 
{
	char num[20];//���
	char name[20];//���� 
	char sex[20];//�Ա� 
	char bir[20];//���� (birthday)
	char edu[20];//ѧ�� (education)
	char sta[20];//��ְʱ�� (start time)
	char job[20];//���� 
	char addr[50];//��ַ(address) 
	char tel[20];//�绰 (telphone)
	char sal[20];//н�� (salary)
};
typedef struct link//��������ṹ�� 
{
	struct staff worker;
	struct link *next;
	struct link *prior;	
}node;
void menu(len);//�˵�(menu)
void add(len);//����(add)
void del(len);//ɾ��(delete)
int cha(len);//�޸�(change) 
void sea(len);//����(search)
void sort(len);//����(sort) 
void saveFile(len);//�洢���ļ��� 
void savenode(len);//���������Ϣ 
void readFile(len);//��ȡ�ļ��е���Ϣ 
void next(len); //������һ��
int main() 
{
	void lock();
	system("color 3f");
	len;
	worker=(node*)malloc(sizeof(node));//�൱��һ��ͷָ�� 
	worker->next=NULL;
	worker->prior=NULL;
	system("color 3f");
	readFile(worker);
	menu(worker);
	return 0;
}
void menu(len)//����˵����漰���к���������ѡ��
{
	int command=0;
	printf("--------------------------------------------------------------------------------------------\n");	
	printf("\t��ӭ����������ѧԺְ������ϵͳ��                                                 |\n");
	printf("\t������ִ�����²�����                                                               |\n");
	printf("\t\t1. ����ְ��                                                                |\n");
	printf("\t\t2. ɾ��ְ��                                                                |\n");
	printf("\t\t3. ��ѯְ��                                                                |\n");
	printf("\t\t4. �޸�ְ��                                                                |\n");
	printf("\t\t5. ����ְ��                                                                |\n");
	printf("\t\t6. �˳�ϵͳ                                                                |\n");
	printf("\t����������������Ӧ�����֣�                                                       |\n");//6�ֲ��� 
	printf("--------------------------------------------------------------------------------------------\n");
	scanf("%d",&command);
	switch(command)//�����ִ�в�ͬ���123456
	{
		case 1:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("��ӭ��������ְ��ҳ��\n");
			printf("--------------------------------------------------------------------------------------------\n");
			add(worker);//���ְ����Ϣ  
			saveFile(worker);//����ְ����Ϣ 
			next(worker); 
			break;
		case 2:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("��ӭ����ɾ��ְ��ҳ��\n");
			printf("--------------------------------------------------------------------------------------------\n");
			del(worker);
			next(worker);
			break;
		case 3:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("��ӭ�����ѯְ��ҳ��\n");
			printf("--------------------------------------------------------------------------------------------\n");
			sea(worker);
			saveFile(worker);
			next(worker);
			break;	
		case 4:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("��ӭ�����޸�ְ��ҳ��\n");
			printf("--------------------------------------------------------------------------------------------\n");
			cha(worker);
			saveFile(worker);
			next(worker);
			break;
		case 5:
			system("cls");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("��ӭ��������ְ��ҳ��\n");
			printf("--------------------------------------------------------------------------------------------\n");
			sort(worker);
			next(worker);
			break;
		case 6:
			exit(0);
		default:
			system("cls");//��ָ����ϣ��������� 
			printf("�������ָ���������������룺\n");
			menu(worker); 
	}
}
void add(len)//���ְ������ 
{
	int command;
	printf("���ӣ�1  ���أ�2\n");
	scanf("%d",&command);
	if(command==1)
	{
		printf("��������������ְ��������Ϣ:\n");
		printf("���\t����\t�Ա�\t����\tѧ��\t�绰\t\tסַ\t\t��ְʱ��\tְ��\tн�� \n");
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
		node *p,*q,*k;
		q=worker;
		k=worker->next; 
		p=(node *)malloc(sizeof(node));
		scanf("%s%s%s%s%s%s%s%s%s%s",
		p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
		while(k!=NULL)//�жϱ���Ƿ�ɲ��� �����أ� 
		{
			if(strcmp(p->worker.num,k->worker.num)==0)
			{
				printf("�ñ���Ѿ����ڣ������������룡\n");
				scanf("%s",p->worker.num);
				k=worker;//��ָ��ͷ�ڵ㣬���½��в��� 
			}
			k=k->next;
		}
		printf("��ӳɹ�������ְ����Ϣ���£�\n\n");
		printf("���\t����\t�Ա�\t����\t\tѧ��\t�绰\t\tסַ\t\t\t��ְʱ��\tְ��\tн�� \n");
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
		while(q!=NULL)//��������֮��ʼ��ӣ��������� 
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
		printf("�������ָ���������������룡\n");
		scanf("%d",&command);
		add(worker);	
	}	
}
void del(len)//ɾ��ְ������ 
{
	node *k,*p;
	char delnum[20];
	k=worker->next;
	if(k==NULL)
	{
		printf("Sorry,Ŀǰ��������ϣ�\n");
	}else
	{
		printf("--------------------------------------------------------------------------------------------\n");
		int num=0;
		printf("��������Ҫɾ����ְ����ţ�\n");
		scanf("%s",delnum);
		while(k!=NULL)
		{
			if(strcmp(k->worker.num,delnum)==0)//�жϸ�ְ���Ƿ���� 
			{
				num==1;
				printf("���\t����\t�Ա�\t����\t\tѧ��\t�绰\t\tסַ\t\t\t\t��ְʱ��\tְ��\tн�� \n");
				printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n",
				k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);	
				printf("��ȷ��Ҫɾ��%s��\n\n",k->worker.name);
				printf("ɾ����1 ȡ����2\n");
				int command=0;
				scanf("%d",&command);
				if(command==1)//����ɾ������
				{
					printf("%sɾ���ɹ���\n",k->worker.name);//֮��ɾ���ýڵ㣬��������
					p=worker;
					while(p->next!=k)
					{
						p=p->next;
					}
					p->next=p->next->next;//ֱ�������ýڵ㣨ɾ���� 
					saveFile(worker);//ɾ��������� 
				}else if(command==2)//ȡ��ɾ������ 
				{
					printf("ȡ��ɾ���ɹ���\n");
					break;
				}
				break;
			}else
			{
				if(k->next==NULL && num==0)
				{
					printf("Sorry,��Ҫ���ҵ���λְ�������ڣ�\n");
				}
			}
			k=k->next;
		}
	}	
}
int cha(len)//�޸�ְ����Ϣ 
{
	int command;
	printf("�޸ģ�1  ���أ�2\n");
	scanf("%d",&command);
	if(command==1)
	{
		char chanum[20];
		node *k=worker->next;
		if(k==NULL)
		{
			printf("Sorry,Ŀǰ��������ϣ�\n");
			return 0;
		}else
		{
			printf("��������Ҫ�޸ĵ�ְ����ţ�\n");
			scanf("%s",chanum);
			int num=0;
			while(k!=NULL)
			{
				if(strcmp(k->worker.num,chanum)==0)//���ְ�����ڣ��������в��� 
				{
					num=1;
					printf("���ҵ���ְ������Ϣ���£�\n");//ԭ����Ϣ 
					printf("���\t����\t�Ա�\t����\t\tѧ��\t�绰\t\tסַ\t\t\t\t��ְʱ��\tְ��\tн�� \n");
					printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n",
					k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);	
					printf("\n����������Ϣ�Խ����޸ģ�\n");//��ʼ�޸���Ϣ 
					
					printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%s\t\n",k->worker.num);
					scanf("%s%s%s%s%s%s%s%s%s",//��������Ϣ 
					k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);	
					printf("ְ����Ϣ�޸ĺ����£�\n\n");//��ʾ�޸ĺ����Ϣ
					printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
					printf("���\t����\t�Ա�\t����\t\tѧ��\t�绰\t\tסַ\t\t\t\t��ְʱ��\tְ��\tн�� \n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n",
					k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);	
					break;	
				}else//��������ֱ�ӽ��� 
				{
					if(k->next==NULL && num==0)
					{
						printf("Sorry,δ�ҵ����ְ������!\n");
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
void sea(len)//����ְ������ ������ְ����Ų��ң� 
{
	char seanum[20];
	node *k=worker->next;
	if(k==NULL)//�ж��Ƿ���� 
	{
		printf("Sorry��Ŀǰ��������ϣ�\n");
	}else
	{
		int num=0;
		printf("������Ҫ����ѯ��ְ����ţ�\n");
		scanf("%s",seanum);
		while(k!=NULL)
		{
			if(strcmp(k->worker.num,seanum)==0)//�ж��Ƿ���� 
			{
				num=1;
				if(num==1)
				{
					printf("--------------------------------------------------------------------------------------------\n");
					
				}
				printf("���ҵ���ְ��������Ϣ���£�\n");
				printf("���\t����\t�Ա�\t����\t\tѧ��\t�绰\t\tסַ\t\t\t\t��ְʱ��\tְ��\tн�� \n");
				printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n",
				k->worker.num,k->worker.name,k->worker.sex,k->worker.bir,k->worker.edu,k->worker.tel,k->worker.addr,k->worker.sta,k->worker.job,k->worker.sal);		
			}else
			{
				if(k->next==NULL && num==0)
				{
					printf("Sorry,δ�ҵ����ְ�����ϣ�\n");	
				}
			}
				k=k->next;					
		}	
	} 	 
}
void sort(len)//ְ��ͳ�ƺ�����(������߽���) 
{
	node *k,*p1,*p2,*p3; 
	k=worker->next;//�����ж�ѭ��ֹͣλ�� 
	p1=(node*)malloc(sizeof(node)); //����һ����ͷ���洢������ 
	p1->next=NULL;
	p1->prior=NULL;	
	p2=p1->next;
	int salnum;	
	if(k==NULL)
	{
		printf("Ŀǰû������\n\n");
	}else
	{
		printf("��ѡ��������Ҫ������ʽ��\n");
		printf("���� 1  ���� 2\n"); 
		int command;
		scanf("%d",&command);
		if(command==1)//���� 
		{
			system("cls");
			printf("����ְ����Ϣ�����ʴӸߵ��ͽ�������\n"); 
			printf("���\t����\t�Ա�\t����\t\tѧ��\t�绰\t\tסַ\t\t\t\t��ְʱ��\tְ��\tн�� \n");
			printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
			p2=(node*)malloc(sizeof(node));
			p2->prior=p1;
			p2->next=NULL;
			p2->worker=k->worker;
			k=k->next;
			while(k!=NULL)//�ж�ѭ��ֹͣ������  
			{		
				salnum=atoi(k->worker.sal);//�������ʵ��ַ���ת��Ϊ����(atoi������			
				p3=(node *)malloc(sizeof(node));//��֤k������������ѭ��  
				p3->worker=k->worker;						
				while(p2!=NULL)//����
				{
					if(p1->next==NULL) 
					{
						p1->next=p2;	
					}
					//��壬û������ֵ��������ȵ�һ����С ;����������һ���ұ����һ��С��ע��p2�ص�ͷ�ڵ����±���		
					if(salnum<=atoi(p2->worker.sal) && p2->next==NULL)//�޵���ֵ���
					{					
						p2->next=p3;
						p3->prior=p2;
						p3->next=NULL; 				  			
						break;
					}else if(salnum<=atoi(p2->prior->worker.sal) && salnum>atoi(p2->worker.sal) )//����ֵʱһ��һС���м�  
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
			savenode(p1);//����������Ϣ				
		}else if(command==2)//���� 
		{
			system("cls");
			printf("����ְ����Ϣ�����ʴӴӵ͵��߽�������\n"); 
			printf("���\t����\t�Ա�\t����\t\tѧ��\t�绰\t\tסַ\t\t\t\t��ְʱ��\tְ��\tн�� \n");
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
				while(p2!=NULL)//�������� 
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
			printf("�������ָ���������������룺\n");
			sort(worker);	
		}	
	} 
}
void saveFile(len)//�����ļ���Ϣ 
{
	node *p=NULL;
	FILE *fp;
	if(worker->next==NULL)
	{
		printf("Sorry,����ؼ�¼��\n");
	}else
	{
		p=worker->next;
	}
	fp=fopen("C:\\Users\\86198\\Desktop\\1.txt","w");
	if(fp==NULL)
	{
		printf("Sorry,���ļ��޷��򿪣�\n");
	}
	while(p!=NULL)
	{
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\t%s\n",
		p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
		p=p->next; 
	}
	fclose(fp);
}
void savenode(len)//�������õ�������Ϣ 
{
	node *p=NULL;
	if(worker->next==NULL)
	{
		printf("Sorry,�޸�ְ����ؼ�¼��\n");
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
			printf("����Ϊ���������ְ����Ϣ��\n");
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
		printf("Sorry,���ļ���ʧ�ܣ������ļ�����ȷ����Ҫ���ļ���Ϣ������ٲ�����\n");
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
	printf("�������˵� 1  �˳�ϵͳ 2\n");
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
			printf("�������ָ���������������룺\n");
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
	printf("���������Ա�˻������롢\n");
	printf("�˻���");
	scanf("%s",c);
	printf("\n");
	printf("���룺");
	scanf("%s",d);
	if((strcmp(a,c)==0)&&strcmp(b,d)==0)
	{
		printf("��½�ɹ���\n");
		return;
	}else
	{
		system("cls");
		printf("�����˻������������������µ�¼��");
		void lock(); 
	}
 } 
//	node *p=worker->next;
//	if(p==NULL)
//	{
//		printf("Sorry,Ŀǰ��������ϣ�\n");
//	}else
//	{
//		printf("������Ϣ������ְ��������������\n");
//		printf("���\t����\t�Ա�\t����\t\tѧ��\t�绰\t\t\tסַ\t\t\t\t��ְʱ��\tְ��\tн�� \n");
//		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
//		while(p!=NULL)
//		{
//			printf("%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\t%s\n",
//			p->worker.num,p->worker.name,p->worker.sex,p->worker.bir,p->worker.edu,p->worker.tel,p->worker.addr,p->worker.sta,p->worker.job,p->worker.sal);
//			p=p->next;
//		} 
//	}

