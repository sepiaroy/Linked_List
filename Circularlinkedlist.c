#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *current=NULL;

void create(struct node *);
void display(struct node *);
int search(struct node *,int s);
int count(struct node *);
struct node* insertatbegin(struct node *,int insert);
void insertatend(struct node *,int insert);
void insertatposition(struct node *,int insert,int position);
void insertafternode(struct node *,int insert,int n);
struct node* deleteatbegin(struct node *);
void deleteatend(struct node *);
void deleteatposition(struct node *,int position);
void deletenum(struct node *h,int num);
struct node* merge(struct node *, struct node *);
void sort(struct node *);
struct node* reverse(struct node *);

int main()
{
    printf("MENU: \n");
    printf("1.Create a circular linked list. \n");
    printf("2.Display the list. \n");
    printf("3.Search an element present in the list. \n");
    printf("4.Count the number of nodes in the list. \n");
    printf("5.Insert new node at the beginning. \n");
    printf("6.Insert new node at the end. \n");
    printf("7.Insert new node at position k. \n");
    printf("8.Insert new node after a node. \n");
    printf("9.Delete a node from the beginning. \n");
    printf("10.Delete a node from the end. \n");
    printf("11.Delete a node from position. \n");
    printf("12.Delete a element. \n");
    printf("13.Merging two lists. \n");
    printf("14.Sort the data items of the list. \n");
    printf("15.Reverse. \n");
    printf("16.Exit.\n");

    int o,op;

    struct node *head=NULL;

    while(1)
    {
        printf("\n\nEnter operation: ");
        scanf("%d", &o);        
        if(o==1)
        {
            printf("Creating linked list 1-\n");

            head= (struct node *)malloc(sizeof(struct node));

            if(head==NULL)
            {
            printf("Memory is not allocated");
            exit(0);
            }
            printf("Enter number of nodes: ");
            scanf("%d", &op);

            current=head;
            printf("Enter data to be allocated in node: ");
            scanf("%d", &head->data);
            head->next=head;
            op--;

            while(op>0)
            {
                create(head);
                op--;
            }    
        }
        else if(o==2)
        {
            printf("\nThe list is: \n");
            display(head);
        }
        else if(o==3)
        {
            int s;
            printf("Enter the item to be searched: \n");
            scanf("%d", &s);
        
            if(search(head,s)==-1)
            {
                printf("Item not found.");
            }
            else
            {
                printf("The number is present at position %d.", search(head,s));
            }
        }
        else if(o==4)
        {
            printf("Number of nodes is %d", count(head));
        }
        else if(o==5)
        {
            int insert;
            printf("Enter item to be inserted at beginning: \n");
            scanf("%d", &insert);
            head=insertatbegin(head,insert);
            display(head);
        }
        else if(o==6)
        {
            int insert;
            printf("Enter item to be inserted at end: \n");
            scanf("%d", &insert);
            insertatend(head,insert);
            display(head);
        }
        else if(o==7)
        {
            int insert,position;
            printf("Enter item to be inserted: \n");
            scanf("%d", &insert);
            printf("Enter position to be inserted at: \n");
            scanf("%d", &position);
            if(position==1)        
            head=insertatbegin(head,insert);
            else if(position > count(head))
            printf("Position not found.\n");
            else 
            insertatposition(head,insert,position);

            display(head);
        } 
        else if(o==8)
        {
            int insert,n;
            printf("Enter item to be inserted: \n");
            scanf("%d", &insert);
            printf("Enter after which node to be inserted: \n");
            scanf("%d", &n);        
            insertafternode(head,insert,n);
            display(head);
        }
        else if(o==9)
        {
            if(head->next==head)
            {
                head=NULL;
                printf("List is empty.\n");
            }
            else
            {
                head=deleteatbegin(head);
                
                display(head);
            }
        }
        else if(o==10)
        {
            if(head->next==head)
            {
                head=NULL;
                printf("List is empty.\n");
            }
            else
            {
                deleteatend(head);
                display(head);
            }
        }
        else if(o==11)
        {
            int position;
            printf("Enter the position to be deleted: ");
            scanf("%d", &position);
            if(position==1)
            {
                if(head->next==head)
                {
                    head=NULL;
                    printf("List is empty.\n");
                }
                else
                {
                    head=deleteatbegin(head);
                    display(head);
                }
            }
            else if(position > count(head))
            printf("Position not found");
            else
            {
                deleteatposition(head,position);
                display(head);
            }
        }
        else if(o==12)
        {
            int num;
            printf("Enter the element to be deleted: ");
            scanf("%d", &num);
            
            if(head->data==num)
            {
                if(head->next==head)
                {
                    head=NULL;
                    printf("List is empty.\n");
                }
                else
                {
                    head=deleteatbegin(head);
                    display(head);
                }
            }
            else
            {
                deletenum(head,num);
                display(head);
            }
        }        
        else if(o==13)
        {
            struct node *head2;
                
            printf("Creating linked list 2-\n");
            
            printf("Enter number of nodes to be created: ");
            scanf("%d", &op);

            head2=(struct node *)malloc(sizeof(struct node));
            current=head2;
            printf("Enter data to be allocated in node: ");
            scanf("%d", &head2->data);
            head2->next=head2;
            op--;

            while(op>0)
            {
                create(head2);
                op--;
            }

            head=merge(head, head2);

            printf("\nThe merged list is:\n");
            display(head);
        }
        else if(o==14)
        {
            sort(head);
            display(head);
        }
        else if(o==15)
        {
            head=reverse(head);
            display(head);
        }  
        else if(o>16)
        {
            printf("\nInvalid option\n");
        }      
        else if(o==16)
        {
            printf("\nExit\n");            
            exit(0);
        }

    }

return 0;
}

void create(struct node *h)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("Memory is not allocated");
        exit(0);
    }

    current->next=newnode;
    current=newnode;
    printf("Enter data to be allocated in node: ");
    scanf("%d", &current->data);
 
    current->next=h;
}

void display(struct node *h)
{
    if(h==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        current=h;
        do
        {
            printf("%d\t", current->data);
            current=current->next;
        }while(current!=h);
    }
}

int search(struct node *h,int s)
{
    int index=1;
    if(h==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        current=h;
        do
        {
            if(current->data==s)
            {
                return index;
                break;
            }
            index++;
            current=current->next;
        }while(current!=h);
    }

    return -1;
}

int count(struct node *h)
{
    int c=0;
    current=h;
    do
    {
        c++;
        current=current->next;
    }while(current!=h);

    return c;    
}

struct node* insertatbegin(struct node *h,int insert)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("Memory is not allocated.\n");
        exit(0);
    } 
    newnode->data=insert;

    if(h==NULL)
    {
        printf("The list is empty. Enter 1 to create linked list.\n");
    }
    else
    {
        newnode->next=h;
        current=h;
        do
        {
            current=current->next;
        }while(current->next!=h);

        current->next=newnode;
        h=newnode;

        printf("\nNode inserted\n");        
    }

    return h;
}

void insertatend(struct node *h,int insert)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("Memory is not allocated.\n");
        exit(0);
    }

    newnode->data=insert;
    newnode->next=h;

    if(h==NULL)
    {
        printf("The list is empty. Enter 1 to create linked list.\n");
    }
    else
    {
        current=h;
        do
        {
            current=current->next;
        }while(current->next!=h);
        
        current->next=newnode;
        printf("\nNode inserted.\n");    
    }
}    

void insertatposition(struct node *h,int insert, int position)
{
    int k=1;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("Memory is not allocated.\n");
        exit(0);
    }
 
    newnode->data=insert;
    struct node *temp;
    if(h==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        current=h;
        do
        {
            if(k==position-1)
            {
                temp=current->next;
                current->next=newnode;
                newnode->next=temp;
                break;
            }          
            k++;
            current=current->next;
        }while(current!=h);

        printf("\nNode inserted.\n");
    }        
}

void insertafternode(struct node *h,int insert,int n)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("Memory is not allocated.\n");
        exit(0);
    }
 
    newnode->data=insert;

    struct node *temp;
    if(h==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        current=h;
        do
        {
            if(n==current->data)
            {
                temp=current->next;
                current->next=newnode;
                newnode->next=temp;
                break;
            }          
            current=current->next;
        }while(current!=h);

        if(current==h && current->data!=n)
        printf("Node not found.\n");
        else
        printf("\nNode inserted.\n");
    }        
}

struct node* deleteatbegin(struct node *h)
{
    struct node *temp=NULL;

    if(h==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        temp = h;
        h = h->next;
        current=h;
        while(current->next!=temp)
        {
            current=current->next;
        }
        current->next=h;
        free(temp);
        printf("\nNode deleted\n");
    }
    return h;
}

void deleteatend(struct node *h)
{
    struct node *temp;
    if(h==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        temp=h;
        while(temp->next!=h)
        {
            current=temp;
            temp=temp->next;
        }

        free(temp);
        current->next=h;
        printf("\nNode deleted\n");
    }
}

void deleteatposition(struct node *h,int position)
{
    struct node *temp;
    int k=1;

    if(h==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        temp=h;
        do
        {
            if(k==position-1)
            {
                current=temp;
                temp=temp->next;        
                break;
            }
            temp=temp->next;        
            k++;
        }while(temp!=h);
        
        current->next=temp->next;
        free(temp);
        printf("\nNode deleted\n");   
    }
}

void deletenum(struct node *h,int num)
{
    struct node *temp;

    if(h==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        temp=h;
        while(temp->next!=h)
        {
            if(temp->next->data==num)
            {
                current=temp;
                temp=temp->next;
                break;
            }
            temp=temp->next;        
        }

        if(temp->next==h && temp->data!=num)
        {
            printf("Node not found.\n");
        }        
        else
        {
            current->next=temp->next;
            free(temp);
            printf("\nNode deleted\n");
        }
    }
}

void sort(struct node *h)
{
    int temp;

    int n=count(h);

    if(h==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        while(n>0)
        {
        current=h;
        for(int j=0; j<n-1; j++)
        {
            if(current->data>current->next->data)
            {
                temp=current->data;
                current->data=current->next->data;
                current->next->data=temp;
            }
            current=current->next;
        }
        n--;
        }
    printf("\nList sorted.\n");    
    }    
}

struct node* merge(struct node *h, struct node *h2)
{
    printf("\nThe list 1 is: \n");
    display(h);
    printf("\nThe list 2 is: \n");
    display(h2);
    
    if(h == NULL){
        h=h2;
    }
    else
    {
        current=h;
        while(current->next!=h)
        {
            current=current->next;       
        }
        current->next=h2;
        
        current=h2;
        while(current->next!=h2)
        {
            current=current->next;       
        }
        current->next=h;
    }
    return h;
}

struct node* reverse(struct node *h)
{
    struct node *p1, *p2, *p3;
    
    if(h == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    else if (h->next == h)
    {
        return h; 
    }
    
    p1 = NULL;
    p2 = h;
    
    do {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    } while (p2 != h);
 
    h->next = p1;
    h = p1;
    
    return h;
}
