#include<stdio.h>
#include<process.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
typedef struct{
	int num[MAX];//array is used as store-house of stack
	int tos; //Tos=Top of the stack
}stack;
int isEmpty(stack *s)
{
	if(s->tos==-1)
		return TRUE;
	else
		return FALSE;
}
int isFull(stack *s)
{
	if(s->tos==MAX-1)
		return TRUE;
	else
		return FALSE;

}
void push(stack *s)
{
	int n;
	if(isFull(s))
	{
		printf("Stack is Full.You cannot push more items.");
		return;
	}
	printf("Enter a number: ");
	scanf("%d",&n);
	s->tos++;
	s->num[s->tos]=n;
	printf("Items pushed onto the stack");
}
void pop(stack *s)
{
	int n;
	if(isEmpty(s))
	{
		printf("Stack is empty,You cannot pop.");
		return;
	}
	n=s->num[s->tos];
	s->tos--;
	printf("%d was popped from the stack",n);
}
void List(stack *s)
{
	int i;
	if(isEmpty(&s))
		printf("Stack is Empty");
	else
	{
		printf("\nStack Contains:\n");
		for(i=s;i>=0;i--)
			printf("%d\n",s.num[i]);
	}
}
int main()
{
	stack s;
	char choice;
	s.tos=-1;//Initialize stack to be empty.
	while (TRUE)
	{
		system("cls");
		printf("Select an option");
		printf("1.push\n2.Pop\n3.List\n4.Exit");
		fflush(stdin);
		choice=getche();
		system("cls");
		switch(choice)
	{
		case '1'=push(&s);break;
		case'2'=pop(&s);break;
		case'3'=list(&s);break;
		case'4'=return;
		}	
		getch();
	}
}
