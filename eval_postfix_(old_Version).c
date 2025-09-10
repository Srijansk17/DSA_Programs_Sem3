#include <stdio.h>
#include <stdlib.h>

void push(char);
char pop();

char s[10];
int top=-1;

void main()
{
  char postfix[10];
  printf("Enter a valid postfix expression");
  scanf("%s",postfix);
  x=evaluate(postfix);
  printf("The Result is....%d",x);  
}


int evaluate(char postfix[])
{
 
}

void push(char x)
{
	s[++top]= x;
}
	
char pop()
{
  return s[top--];
}
