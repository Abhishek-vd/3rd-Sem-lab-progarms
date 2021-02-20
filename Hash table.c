#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct employee
{
	int id;
	char name[15];
};
typedef struct employee EMP;
EMP emp[MAX];
int a[MAX];
void linear_prob(int key)
{
	int flag=0,i=key;
	if(a[i]==-1)
	flag=-1;
	else
	{
		printf("\n collision detected\n");
		i=key+1;
		do
		{
			if(a[i]==-1)
			{
			flag=1;
			break;
			}
			else
			{
			i=(++i)%MAX;
			}
			}while(i!=key&&flag==0);
			}
				if(flag==0)
				printf("hash table is full\n");
				else
				{
				printf("\n enter emp id\n");
				scanf("%d",&emp[i].id);
				printf("enter employee name\n");
				scanf("%s",emp[i].name);
				a[i]=i;
				printf("collision is avoided\n");
				}
			}

	void display()
	{
		int i,ch;
		printf(	"\n 1.display all\n2.filtered display\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		printf("\n HT key\tEmpid\tEMP name\n");
		for(i=0;i<MAX;i++)
		{
			if(ch==2 && a[i]==-1)
			continue;
			else{
			printf("\n %d\t%d\t%s\n",i,emp[i].id,emp[i].name);
			}
		}
	}

int main()
{
	int num,i;
	int ch=1;
	printf("\n collision handling by linear probing\n");
	for(i=0;i<MAX;i++)
	{
		a[i]=-1;
	}
	do
	{
		printf("enter the data\n");
		scanf("%d",&num);
		linear_prob(num%10);
		printf("do you wish to continue\n");
		scanf("%d",&ch);
	}
	while(ch);
	display();
}