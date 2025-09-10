#include <stdio.h>
#include <stdlib.h>
#define size 5

void push(int[],int,int);
int pop(int[],int);
int seek(int[],int);
int display(int[],int);

void main()
{
  int st[size], choice,x;	
  int *top;
  *top =-1;
  
  while(1)
  {
  printf("Enter 1->Push\n2->Pop\nEnter 3->Seek\n4->Display\nEnter 5->Exit\n");
  scanf("%d",&choice);
  
  switch(choice)
  {
	case 1: {
		printf("Enter the element to be pushed ");
		scanf("%d",&x);
		push(st,top,x);
		}
		break;

	case 2: {
		x=pop(st,top);
		printf("The element deleted is %d",x);
		}
		break;

	case 3: {
		x=seek(st,top);
		printf("The element on top of the list is %d ",x);
		}
		break;

	case 4: {
		display(st,top);
		}
		break;

	default: exit(0);
  }
 }
}

void push(int s[], int t, int x)
{
	if(t=(size-1))
		printf("Stack overflow");
	else 
	{
	t++;
	s[t]=x;
	}

}

