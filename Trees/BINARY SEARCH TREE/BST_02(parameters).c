#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *lchild;
  struct node *rchild;
  int data;
};

// HEIGHT OF THE BINARY TREE
int height(struct node *root) {
  int left_height = 0, right_height = 0;
  if (root == NULL)
    return 0;
  else {
    left_height = height(root->lchild);
    right_height = height(root->rchild);
    if (left_height > right_height)
      return left_height + 1;
    else
      return right_height + 1;
  }
}

//Number of Nodes
int count(struct node *root)
{
  if(root==NULL)
    return 0;
  else
    return(count(root->lchild)+1+count(root->rchild));
}

//Number of Internal Nodes
int intcount(struct node *root)
{
  if(root->lchild==NULL && root->rchild==NULL)
    return 0;
  else
    return(intcount(root->lchild)+1+intcount(root->rchild));
}

//Smallest Node
int smallest(struct node *root){
  if(root->lchild==NULL)
    return root->data;
  return smallest(root->lchild);
}

//Largest Node
int largest(struct node *root){
  if(root->rchild==NULL)
    return root->data;
  return(largest(root->rchild));
}