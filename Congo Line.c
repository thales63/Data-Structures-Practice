#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node 
{
  char name[30];
  struct Node *next;
};
struct Node *head=NULL;
void addend(char nameNew[])
{
  struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->name,nameNew);
  newNode->next=NULL;
  if(head==NULL)
    head=newNode;
  else
  {
    struct Node *temp=head;
    while(temp->next!=NULL)
       temp=temp->next;
    temp->next=newNode;   
  }
}
void display()
{
  struct Node *temp=head;
  if(temp==NULL)
  {
    printf("Congo line is empty.\n");
    return ;
  }
  printf("Congo Line:");
  while(temp!=NULL)
  {
    printf(" %s",temp->name);
    temp=temp->next;
  }printf("\n");
}
void delhead()
{
  struct Node *temp=head;
  if(temp==NULL)
  {
    printf("Congo line is empty. No one to remove.");
    return;
  }
  head=head->next;
  printf("%s has left the Congo line.\n",temp->name);
  free(temp);
}
int main()
{
  int size,i,op;
  char name[30];
  scanf("%d",&size);
  for(i=1;i<=size;i++)
  {
    scanf("%d",&op);
    getchar();
    if(op==1)
    {
      scanf("%s",name);
      addend(name);
    }
    else if(op==2)
    {
      delhead();
    }
    else if(op==3)
    {
      display();
    }
    else if(op==4)
    exit(0);
  }
}


