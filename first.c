#include <stdio.h>
#include <stdlib.h>

typedef struct node {
                    int info;
	                struct node *next;
                   }NODE;
				   
 NODE* frontins(NODE *,int);
 void display(NODE *);
 NODE* endins(NODE *,int);
 NODE* frontdel(NODE *);
 NODE* enddel(NODE *);
 NODE* posins(NODE *,int,int);
 NODE* posdel(NODE *list,int pos);
 NODE* orderedins(NODE *, int);
				   
void main()
 {
   NODE *list, *newnode;
   int choice,x,pos;
   list=NULL;
   while(1)
   {
   printf("Enter 1->Front Insertion\n2->Display\n3->End Insertion\n");  
   printf("Enter 4->Front deletion\n5->End deletion\n6->position Insertion\n");
   printf("Enter 7->Position deletion\n8->Ordered Insertion\n9->Exit");
   scanf("%d", &choice);
   switch(choice)
   {
   case 1:{
          printf("Enter the value of to insert..");
          scanf("%d", &x);
          list=frontins(list,x);
          }break;
   case 2:{
	      display(list);
          }break;
   case 3:{
          printf("Enter the value of to insert..");
          scanf("%d", &x);
          list=endins(list,x);
          }break;
	case 4:{
	        list=frontdel(list);
           }break;	  
	case 5:{
	        list=enddel(list);
           }break;	
    case 6:{
          printf("Enter the value and position");
          scanf("%d %d", &x,&pos);
          list=posins(list,x,pos);
          }break;
	case 7:{
          printf("Enter the position");
          scanf("%d", &pos);
          list=posdel(list,pos);
          }break;
	case 8:{
          printf("Enter the value");
          scanf("%d", &x);
          list=orderedins(list,x);
          }break;			  
  default: exit(0);
	 
   }
  }
 }
 
 NODE* frontins(NODE *list, int x)
 {
	 NODE *newnode;
	 
     newnode = (NODE *)(malloc(sizeof(NODE)));
	 newnode->info=x;
	 newnode->next=NULL;
	 
	 if(list==NULL) list=newnode;
	 else {
		 newnode->next=list;
		 list=newnode;
	 }
	 return list;
 }
 
 void display(NODE *list)
 {  NODE *temp;
     temp=list;
	 if(list==NULL){printf("Empty List..");
	                return;
				   }
	 while(temp!=NULL)
	 {
	   printf("\t%d", temp->info);	
       temp=temp->next;	   
	 }
 }
 
 NODE* endins(NODE *list, int x)
 {
	 NODE *newnode,*temp;
	 
     newnode = (NODE *)(malloc(sizeof(NODE)));
	 newnode->info=x;
	 newnode->next=NULL;
	 
	 if(list==NULL) list=newnode;
	 else { temp=list;
	      while(temp->next!=NULL)
			temp=temp->next;  
		  temp->next=newnode;
	 }
	 return list;
 }
 
 NODE* frontdel(NODE *list)
 {   NODE *temp;
	 if(list==NULL) printf("Empty List..");
	 else { temp=list;
		   list=list->next;
		   free(temp); 
	      }
	 return list;
 }
 
  NODE* enddel(NODE *list)
 {
	 NODE *temp,*prev;
	 temp=list; 
	 if(list==NULL) printf("Empty List..");
	 else if(list->next==NULL)list=NULL;
	 else { 
	      while(temp->next!=NULL)
		  {   prev=temp;
			  temp=temp->next;  
		  }
		  prev->next=NULL;
	 }
	 free(temp);
	 return list;
 }
 
 NODE* posins(NODE *list, int x,int pos)
 {
	 NODE *newnode,*prev,*temp;
	 int i=1;
	 newnode = (NODE *)(malloc(sizeof(NODE)));
	 newnode->info=x;
	 newnode->next=NULL;
	 temp=list;
	 
	 if(list==NULL) list=newnode;
	 else if(pos==1){
			        newnode->next=list;
					list=newnode;
		          }
	else{
		while(temp->next!=NULL && i<pos)
		{
		  prev=temp;
		  temp=temp->next;
		  i++;
		}
		if(i==pos)
		{
		  newnode->next=prev->next;
          prev->next=newnode;		  
		}
		else if(i+1==pos) temp->next=newnode;
		else printf("\nInvalid Position..");
	 }
	 return list;
 }
 
 NODE* posdel(NODE *list,int pos)
 {
	 NODE *prev,*temp;
	 int i=1;
	 
	 temp=list;
	 if(list==NULL) printf("Empty List");
	 else if(pos==1)list=list->next;
	 else {
		while(temp->next!=NULL && i<pos)
		{
		  prev=temp;
		  temp=temp->next;
		  i++;
		}
		if(i==pos) prev->next=temp->next;
        else printf("\nInvalid Position..");
	 }
	 free(temp);
	 return list;
 }
 
 NODE* orderedins(NODE *list, int x)
 {
	 NODE *newnode,*prev,*temp;
	 
	 newnode = (NODE *)(malloc(sizeof(NODE)));
	 newnode->info=x;
	 newnode->next=NULL;
	 
	 temp=list;
	 
	 if(list==NULL) list=newnode;
	 else if(x<list->info){
			        newnode->next=list;
					list=newnode;
		          }
	else{
		while(temp->next!=NULL && temp->info < x)
		{
		  prev=temp;
		  temp=temp->next;
		 }
		if(temp->info > x)
		{
		  newnode->next=prev->next;
          prev->next=newnode;		  
		}
		else temp->next=newnode;
	 }
	 return list;
 }