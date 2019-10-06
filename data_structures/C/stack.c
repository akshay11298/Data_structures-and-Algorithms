#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
} *head=NULL;


// Stack is a linked list where insertion happens only at beginning and so does deletion
struct node *create_node(int x);
int is_empty();
void push(int x);
void pop();
int peek();
void print_stack(); //Happens in reverse order

int main(int argc, char const *argv[])
{
  int n,x;  
  head = NULL;
  printf("1.Push\n2.Pop\n3.Peek\n4.Print\n0.Exit\n");
  do{
    printf("Make the choice\n");
    scanf("%d",&n);
    switch(n){
        case 1:
            printf("Enter the element to push ");
            scanf("%d",&x);
            push(x);
            break;
        case 2:
            if (is_empty()){
                printf("Stack is empty\n");
                break;
            }
            printf("%d has been deleted\n",peek());
            pop();
            break;
        case 3:
            if (is_empty()){
                printf("Stack is empty\n");
                break;
            }
            printf("Top element is %d\n",peek());
            break;
        case 4:
            print_stack();
            break;
        case 0:
            break;
        default:
            printf("Enter a valid entry");

    }
  }while(n!=0);

  return 0;
}

struct node *create_node(int x)
{
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->next = NULL;
  n->data = x;
  return n;
}


int is_empty()
{
  return head == NULL;
}

void push(int x)
{
  struct node *node = create_node(x);

  if (is_empty())
  {
    head=node;
    return;
  }
  node->next=head;
  head=node;
}

void pop()
{
  struct node *temp = head;

  head=temp->next;

  free(temp);
}

int peek(){
    
    return head->data;
}

void print_stack()
{
  for (struct node *temp = head; temp != NULL; temp = temp->next)
  {
    printf("%d ", temp->data);
  }

  printf("\n");
}