#include<stdio.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST *left,*right;
};
typedef struct BST NODE;
NODE *createnode(NODE *node,int data)
{
	if(node==NULL)
	{
		NODE *temp=(NODE*)malloc(sizeof(NODE));
		temp->data=data;
		temp->left=temp->right=NULL;
		return temp;
	}
	if(data<node->data)
	{
		node->left=createnode(node->left,data);
	}
	else if(data>node->data)
	{
		node->right=createnode(node->right,data);
	}
	else
	{
		printf("duplicate data is found\n");
	}
	return node;
}
NODE *search(NODE *node,int data)
{
	if(node==NULL)
	printf("\n data not fount\n");
	else if(data<node->data)
	node->left=search(node->left,data);
	else if(data>node->data)
	node->right=search(node->right,data);
	else
	printf("\n element found is %d",node->data);
	return node;
	}
void inorder(NODE *node)
{
	if(node!=NULL)
	{
		inorder(node->left);
		printf("%d\t",node->data);
		inorder(node->right);
	}
}
void preorder(NODE *node)
{
	if(node!=NULL)
	{
	printf("%d\t",node->data);
	preorder(node->left);
	preorder(node->right);
	}
}
void postorder(NODE *node)
{
	if(node!=NULL)
	{
	postorder(node->left);
	postorder(node->right);
	printf("%d\t",node->data);
	}
}
void main()
{
	int data,ch,i,n;
	NODE *root=NULL;
	int a[20];
	do
	{
		printf("\n1.insertion in BST\n2.search element in BST\n3.inorder\n4.preorder\n5.postorder\n6.exit\nenter ur choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the n value\n");
			scanf("%d",&n);
			printf("enter the values for BST");
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
				root=createnode(root,a[i]);
			}
				break;
			case 2:printf("enter the element to be searched\n");
				scanf("%d",&data);
				root=search(root,data);
				break;
			case 3:printf("\n inorder traversal;\n");
				inorder(root);
				break;
			case 4:printf("\n preorder traversal;\n");
				preorder(root);
				break;
			case 5:printf("\n postorder traversal;\n");
				postorder(root);
				break;
			case 6:exit(0);
			default:printf("\n invalid choice\n");
				break;
		}
	}while(1);
}
