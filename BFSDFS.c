#include<stdio.h>
int a[20][20],q[20],visited[20],reach[10];
int n,i,j,count,f=0,r=-1;
void bfs(int v) 
{
	for(i=1;i<=n;i++)
	if(a[v][i] && !reach[i]) 
	q[++r]=i;
	if(f<=r) 
	{
		reach[q[f]]=1; 
		bfs(q[f++]); 
	}
}
void dfs(int v) 
{
	int i;
	visited[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[v][i] && !visited[i])
		{
			printf("\n %d->%d",v,i);
			count++;
			dfs(i);
		}
	}
}
void main()
{
	int v, choice;
	printf("\n Enter the number of cities: ");
	scanf("%d",&n);
	printf("\n Enter graph data in matrix form:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	while(1)
	{
		printf("\n1. Test for reachability") ;
		printf("\n2. Test for connectivity") ;
		printf("\n3. Exit");
		printf("\n Enter Your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the source vertex: ");
			scanf("%d",&v);

			if((v<1)||(v>n))
			printf("\nEnter a valid source vertex");
			else
			{
			for(i=1;i<=n;i++)
				reach[i]=0;
				reach[v]=1;
				bfs(v);
				printf("The reachable nodes from node %d:\n",v);
				for(i=1;i<=n;i++)
					if(reach[i] && i !=v)
						printf("node %d\n",i);
			}
				break;
			case 2: for(i=1;i<=n;i++)
				visited[i]=0;
			printf("ENTER the source vertex");
			count=0;
			scanf("%d",&v); 
			dfs(v); 
			if(count==n-1)
				printf("\nGraph is connected\n");
			else
				printf("\n Graph is not connected");
				break;
			case 3:return;
			default:printf("\nEnter proper Choice");
		} 
	}
}
