#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct queue{
	float items[MAX];
	int front;
	int rear;
};
void insert(struct queue *q, int val)
{
 if(q->rear==MAX-1)
 {
 	printf("\n Queue is full.You cannot insert More items");
 	return;
 }
 q->rear++;
 q->items[q->rear]==val;
 printf("\n Item inserted Sucessfully");
}
int remove(struct queue *q)
{
	int val;
	if(q->rear==-1)//if empty queue
	{
		printf("\nQueue is empty.you cannot remove any item");
		exit(0);
	}
	val=q->items[q->rear];
	q->rear--;
	printf("\n Items removed Sucessfully");
}
void display(struct queue *q)
{
	int i;
	printf("\nQueue Contains:\n");
	for(i=q->front;i<=q->rear;i++)
	{
		printf("%d\t,q->items[i]");
	}
}
int main()
{
	struct queue q;
	int item;
	char ch;
	q.front=0;
	q.rear=-1;
	do{
		printf("Enter your choice: \n");
		printf("1.Insert \n 2.Remove \n 3.Dislay \n 4.Exit");
		ch= getche();
		switch(ch)
		{
			case '1':
				printf("Enter your Number:");
				scanf("%d",&item);
				insert(&q,item);
				break;
			case '2':
				prinf("%d was removed.",remove(&q));break;
			case '3' :
				display(q);break;
			case '4':
				return;	
		}
	getch();
	}while(1);
}

