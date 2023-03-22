
// BINARY TREE TRAVERSAL
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *lchild;
  struct node *rchild;
};

// CREATE THE BINARY TREE
struct node *create() {
  struct node *p;
  int x
  printf("Enter data (Enter -1 for no data)\n");
  scanf("%d", &x);
  if (x == -1)
    return NULL;
  else {
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    printf("Enter the left child of %d\n", x);
    p->lchild = create();
    printf("Enter the right child of %d\n", x);
    p->rchild = create();
    return p;
  }
}

//PRE-ORDER
void preorder(struct node *root)
{
  if(root==NULL)
    return;
  printf("%d\n",root->data);
  preorder(root->lchild);
  preorder(root->rchild);
}

//IN-ORDER
void inorder(struct node *root)
{
  if(root==NULL)
    return;
  inorder(root->lchild);
  printf("%d\n",root->data);
  inorder(root->rchild);
  return;
}

//POST-ORDER
void postorder(struct node *root)
{
  if(root==NULL)
    return;
  postorder(root->lchild);
  postorder(root->rchild);
  printf("%d\n",root->data);
  return;
}

void main()
{
  struct node *root,*p;
  int choice;
  root=create();
    do
      {
        p=root;
        printf("\nEnter 1:PRE-ORDER ");
        printf("\nEnter 2:IN-ORDER ");
        printf("\nEnter 3:POST-ORDER ");
        printf("\nEnter 4:EXIT");
        printf("\nEnter choice :\n");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1: preorder(p);
                  break;
          case 2:inorder(p);
                  break;
          case 3:postorder(p);
                  break;
          case 4: exit(1);
        }
            }while(choice !=4);
  }