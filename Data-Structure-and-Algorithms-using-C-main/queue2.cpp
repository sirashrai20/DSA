#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#define MAX 10
struct queue
{
	int item[MAX];
	int rear;
};

void enqueue(struct queue*q,int val)
{
	if(q->rear==MAX-1)
	{
		printf("Queue is full.You cannot insert more items");
		return;
	}
	//q->rear++
	q->item[++q->rear]=val;
	printf("Items inserted sucessfully");
	return;
}
int dqueue(struct queue q)
{
	int val,i;
	if(q.rear==-1)
	{
		printf("Queue is Empty. You cannot remove the items");
		exit(0);
	}
	val=q.items[0];
	for(i=1;i<=q.rear;i++)
	{
	q.item[i-1]=q.item[i];
	q.rear--;
	}
	return val;
	
}

void display(struct queue*q)
{
	int i;
	if(q->rear==-1)
	printf("Queue is Empty");
	else
	{
		printf("\nQueue contains\n");
		for(i=0;i<=q->rear;i++)
		printf("%d\t",q->item[i]);
	}
}
int main()
{
	struct queue q;
	char ch;
	q.rear=-1;
	while(1){
	system("CLS");
	printf("Select an option\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit")
	ch=getche();
	switch(ch)
	{
		case '1':
			printf("Enter a Number");
			scanf("%d",&n);
			enqueue(&q,n);
			break;
			case '2':
				if(q.rear==-1)
				printf("Queue is Empty");
				else
				{
					n=dequeue(&q)
					printf("\n%d was removed",n);
				}
				break;
				case '3':
					display(q);
					break;
					case '4':
						return;
	}
	getch()
	}
}
