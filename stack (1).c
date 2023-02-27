/*stack*/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	int data;
	struct node *link;
};

struct node *stack=NULL;

void push(int num)
{
	struct node *ptr = (struct node *) malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory in heap seagment");
		exit(1);
	}
	ptr->data = num;
	ptr->link = stack;
	stack = ptr;
}
void pop()
{
	struct node *temp;
	if(stack==NULL)
	{
		printf("\nstack is empty\n");
		return;
	}
	temp = stack;
	stack = stack->link;
	free(temp);
}
void display()
{
	struct node *temp;
	if(stack==NULL)
	{
		printf("\nstack is empty\n");
		return;
	}
	temp=stack;
	printf("\nelements in list:");
	while(temp!=NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->link;
	}
}
void search(int num)
{
	struct node *temp;
	int pos = 0;
 	if(stack==NULL)
	{
		printf("\nstack is empty\n");
		return;
	}
	temp = stack;
	while(temp!=NULL)
	{
		++pos;
		if(temp->data==num)
		{
			printf("\nposition = %d\n",pos);
			return;
		}
			temp = temp->link;
	}
	printf("element not found\n");
	return;

}
void delete_stack()
{
	struct node *temp;
	if(stack==NULL)
	{
		printf("\nstack is empty\n");
		return;
	}
	temp=stack;
	while(stack!=NULL)
	{
		stack = stack->link;
		free(temp);
		temp=stack;
	}
}
void count()
{
	struct node *temp;
	int count = 0;
	if(stack==NULL)
	{
		printf("\ncount = %d\n",count);
		return;
	}
	temp=stack;
	while(temp!=NULL)
 	{
		count++;
		temp=temp->link;
	}
	printf("\ncount = %d\n",count);
}
void delete_particular_node(int num)
{
	struct node*prev,*cur;
	if(stack==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	if(stack->data==num)
	{
		if(stack->link==NULL)
		{
			free(stack);
			stack=NULL;
			return;
		}
		cur=stack;
		stack=stack->link;
		free(cur);
		return;
	}

	prev=stack;
	cur= stack->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			prev->link=cur->link;
			free(cur);
			return;
		}	
		prev=cur;
		cur=cur->link;
	}
	printf("element not found\n");

}
void reverse_list()
{
	struct node *prev,*cur,*next;
	if(stack==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	prev = NULL;
	cur  = stack;
	while(cur!=NULL)
	{
		next = cur->link;
		cur->link = prev;
		prev = cur;
		cur = next;
	}
	stack=prev;
}
void create_stack(int *iptr,int n)
{
	int i;
	struct node *ptr;
	for(i=0;i<n;i++)
	{
		ptr = (struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory\n");
			exit(1);
		}
		ptr->data = iptr[i];
		ptr->link = stack;
		stack = ptr;
	}
}
void swap_by_data(int num,int val)
{
	int temp;
	struct node *p1,*p2;
	if(stack==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	p1=p2=stack;
	while(p1!=NULL)
	{
		if(p1->data==num)
		break;
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		if(p2->data==val)
		break;
		p2=p2->link;
	}
	if((p1==NULL)||(p2==NULL))
	{
		printf("data not found");
		return;
	}
	temp=p1->data;
	p1->data=p2->data;
	p2->data=temp;
}
void swap_by_links(int num,int val)
{
	struct node *p,*q,*r,*s,*temp;
	int pos1=0,pos2=0;
	if(stack==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	if(num==val)
		return;
	p=q=stack;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num)
		break;
		r=p;
		p=p->link;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==val)
		break;
		s=q;
		q=q->link;
	}
	if((p==NULL)||(q==NULL))
	{
		printf("data not found");
		exit(1);
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
		temp=r;
		r=s;
		s=temp;
	}
	//non-adjacent nodes
	if(p->link!=q)
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;
		if(p!=stack)
			r->link=q;
		else
			stack=q;
		s->link=p;
		return;
	}
	//adjacent nodes
	else 
	{
		p->link = q->link;
		q->link =p;
		if(p!=stack)
		r->link = q;
		else
			stack =q;
		return;
	}
}
void delete_duplicate()
{
	struct node *p,*q,*s;
	
	if(stack==NULL)
	{
		printf("list is empty");
		return;
	}

	for(p=stack;p!=NULL;p=p->link)
	{
		for(s=p,q=p->link;q!=NULL;s=q,q=q->link)
		{
			if(p->data==q->data)
			{
				s->link=q->link;
				free(q);
				q=s;
			}
		}
	}
}

void main()
{
	
	int num,opt,val,c=0,i;
	int *ptr;
	while(1)
	{
		printf("\n0.exit\n1.push\n2.pop\n3.display\n4.search\n5.delete stack\n6.count list\n7.delete particular node\n8.reverse list\n9.create stack\n10.swap by data\n11.swap by links\n12.delete duplicate\n\nEnter option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0 : exit(1);

			case 1 : printf("\nenter number:");
				 scanf("%d",&num);
				 push(num);
				 break;
			
			case 2: pop();
				  break;
			case 3: display(); 
				  break;
			case 4: if(stack!=NULL)
				{
					printf("\nenter number:");
				  	scanf("%d",&num);
					search(num);
					break;
				}
				else
				{
					printf("\nlist is empty\n");
					break;
				}
			case 5: delete_stack();
				  break;
			case 6: count();
				  break;
			case 7: printf("\nenter number:");
				 scanf("%d",&num);
				 delete_particular_node(num);
				 break;
			case 8: reverse_list();
				 break; 
			case 9: printf("enter the count of elements to be added:");
				 scanf("%d",&c);
				 ptr = (int *)malloc(c*sizeof(int));
				 if(ptr==NULL)
				 {
					 printf("failed to allocate memory\n");
					 exit(1);
				 }
				 for(i=0;i<c;i++)
				 {
					 printf("enter number:");
					 scanf("%d",&ptr[i]);
				 }
				 create_stack(ptr,c);
				 free(ptr);
				 break;
			case 10: printf("enter numbers to be swapped:");
				 scanf("%d-%d",&num,&val);
				 swap_by_data(num,val);
				 break;
			case 11: printf("enter numbers to be swapped:");
				 scanf("%d-%d",&num,&val);
				 swap_by_links(num,val);
				 break;
			case 12: delete_duplicate();
				   break;

			default : printf("enter valid option\n");
		}
	}
}

