#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
};
typedef struct node NODE;
NODE*start=NULL,*p,*q;
void traverse()
{
if(start==NULL)
{
    printf("The Linked List is Empty.");
}
else
{
 int i=1;
 p=start;
 while(p!=NULL)
 {
    printf("%d.%d\n",i,p->data);
    p=p->next;
    i++;
 }
 printf("END");
}
}
void create_at_start()
{
    p=(NODE*)malloc(sizeof(NODE));
    printf("Enter the Data in the Node: ");
    scanf("%d",&p->data);
    if(start==NULL)
    {
        start=p;
        p->next=NULL;
    }
    else
    {
      p->next=start;
      start=p;
    }
}
void create_at_end()
{
    p=(NODE*)malloc(sizeof(NODE));
    printf("Enter the Data in the Node: ");
    scanf("%d",&p->data);
    if(start==NULL)
    {
        start=p;
        p->next=NULL;
    }
    else
    {
      q=start;
      int i=1;
      while(q->next!=NULL)
      {
        q=q->next;
        i++;
      }
      q->next=p;
      p->next=NULL;
    }
}
void create_at_given_location()
{
    int loc;
    int i=1;
    p=(NODE*)malloc(sizeof(NODE));
    printf("Enter the Data in the Node: \n");
    scanf("%d",&p->data);
    printf("Enter the Location of the Node: \n");
    scanf("%d",&loc);
    if(start==NULL)
    {
      if(loc==1)
      {
        start=p;
        p->next=NULL;
      }
      else
      {
        printf("Invalid Location\n");
        free(p);
      }
    }
    else
    {
        if(loc==1)
        {
            p->next=start;
            start=p;
        }
        else
        {
            q=start;
        while(i<loc-1&&q!=NULL)
        {
            q=q->next;
            i++;
        }
        if(q!=NULL)
        {
            p->next=q->next;
            q->next=p;
        }
        else
        {
            printf("Invalid Location\n");
            free(p);
        }
        }
    }
}
void delete_at_start()
{
    if(start==NULL)
    {
        printf("The Linked List is Empty.Delete cannot be performed.");
    }
    else
    {
     p=start;
     start=p->next;
     printf("%d is Deleted.",p->data);
     free(p);
    }
}
void delete_at_end()
{
    if(start==NULL)
    {
        printf("The Linked List is Empty.Delete cannot Be Performed.");
    }
    else
    {
        if(start->next==NULL)
        {
            p=start;
            start=NULL;
            printf("%d is Deleted.",p->data);
            free(p);
        }
        else
        {
           p=start;
           while(p->next!=NULL)
          {
            q=p;
            p=p->next;
          }
          q->next=NULL;
          printf("%d is Deleted.",p->data);
          free(p);
        }
    }
}
void delete_at_given_location()
{
    int loc;
    printf("Enter the Location of the NODE: ");
    scanf("%d",&loc);
    if(start==NULL)
    {
        printf("The Linked List is Empty.Delete cannot be Performed.");
    }
    else
    {
        int i=1;
        if(loc==1)
        {
            p=start;
            start=p->next;
            printf("%d is Deleted.",p->data);
            free(p);
        }
        else
        {
            p=start;
            while(i<loc&&p!=NULL)
            {
                q=p;
                p=p->next;
                i++;
            }
            if(p!=NULL)
            {
                q->next=p->next;
                printf("%d is Deleted.",p->data);
                free(p);
            }
            else
            {
                printf("Invalid Location");
            }
        }
    }
}
int main()
{
    int n;
    do
    {
    printf("\n1.Create a Node at Start.\n");
    printf("2.Create a Node at End.\n");
    printf("3.Create a Node at any Location.\n");
    printf("4.Delete the Node at Start.\n");
    printf("5.Delete the Node at End.\n");
    printf("6.Delete the Node at given Location.\n");
    printf("7.Traverse\n");
    printf("8.Exit\n");
    printf("Enter the Option Number: \n");
    scanf("%d",&n);
    switch (n)
    {
        case 1:
        create_at_start();
        break;
        case 2: 
        create_at_end();
        break;
        case 3:
        create_at_given_location();
        break;
        case 4:
        delete_at_start();
        break;
        case 5:
        delete_at_end();
        break;
        case 6:
        delete_at_given_location();
        break;
        case 7:
        traverse();
        break;
        case 8:
        break;
        default :
        printf("Invalid Operator");
        break;
    }
    }while(n!=8);
   return 0; 

}
