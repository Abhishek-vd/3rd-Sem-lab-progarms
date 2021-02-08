#include<stdio.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST *llink,*rlink;
};
typedef struct BST NODE;
NODE* Createtree(NODE *node,int data)
{
	if(node==NULL)
	{
		NODE *temp=(NODE *)mallac(sizeof(NODE));
		temp->data=data;
		temp->llink=temp->rlink=NULL;
		return temp;
	}
	if(data<(node->data))
		node->llink=createnode(node->llink,data);
	else if(data>node->data)
		node->rlink=createnode(node->rlink,data);
	else
		printf("Duplicate data found\n");
	return node;
}
NODE *search(NODE *node,int data)
{
	NODE *curr=root;
	if(root==NULL)
		printf("tree is empty\n");
	else if(data<curr->data)
		search(curr->llink,data);
	else if(item>curr->data)
		search(curr->rlink->data);
	else
		printf("Element found");
	return node;
}
void inorder(NODE*root)
{
	if(root==NULL)
	return;
	else
	{
		inorder(root->llink);
		printf("%d",root->data);
		inorder(root->rlink);
	}
}
void preorder(NODE*root)
{
	if(root==NULL)
	return;
	else
	{
		printf("%d",root->data);
		preorder(root->llink);
		preorder(root->rlink);
	}
}
void postorder(NODE*root)
{
	if(root==NULL)
	return;
	else
	{
		postorder(root->llink);
		postorder(root->rlink);
		printf("%d",root->data);
	}
}
void main()
{
do
{
	int data,ch,i,n;
	NODE *root=NULL;
	int a[20];
	do
	{
		printf("1.Insertion in Binary search tree\n2.Search element in Binary search tree\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter N value\n");
				scanf("%d",&n);
				printf("Enter the values for the BST\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
					root=createtree(root,a[i]);
				}
			case 2:printf("Enter the element to search\n");
				scanf("%d",&data);
				root=search(root,data);
				break;
			case 3:printf("Inorder traversal\n");
				inorder(root);
				break;
			case 4:printf("Preoder traversal\n");
				preorder(root);
				break;
			case 5:printf("Postorder traversal\n");
				postorder(root);
				break;
			case 6:exit(0);
			default:printf("Invalid choice\n");
		}
	}while(1);
}	
}
