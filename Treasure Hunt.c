#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
  char clue[30];
  struct Node *next;
};
struct Node *head=NULL;
void addend(char clueNew[])
{
  struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->clue,clueNew);
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
    printf("No checkpoints added yet.");
    return ;
  }
  int i=1;
  while(temp!=NULL)
  {
    printf("Checkpoint %d: %s\n",i++,temp->clue);
    temp=temp->next;
  }
}
int search(int pos)
{
   struct Node *temp=head;
  int i;
  for(i=1;i<pos && temp!=NULL;i++)
     temp=temp->next;
     if(i==pos && temp!=NULL)
     printf("Clue at Checkpoint %d: %s\n",pos,temp->clue); 
     else
     printf("Checkpoint %d not found.",pos);
}

int main()
{
  int i,size,op,pos;
  char clue[30];
  scanf("%d",&size);
  for(i=1;i<=size;i++)
  {
    scanf("%d",&op);
    getchar();
    if(op==1)
    {
      scanf("%s",clue);
      addend(clue);
    }
    else if(op==2)
    {
      display();
    }
    else if(op==3)
    {
      scanf("%d",&pos);
      if(pos>size){
         printf("Checkpoint %d not found.",pos);
         return 0;}
      search(pos);
    }
    else if(op==4)
     exit(0);
  }
}
