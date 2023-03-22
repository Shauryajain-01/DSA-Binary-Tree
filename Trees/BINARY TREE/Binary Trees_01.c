// BINARY TREE
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
  int x;
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
// FIND THE MAXIMUM ELEMENT

int findmax(struct node *root) {
  int left, right, result;
  if (root == NULL)
    return INT_MIN;
  else{
  result = root->data;
  left = findmax(root->lchild);
  right = findmax(root->rchild);
  if (left > result)
    result = left;
  else if (right > result)
    result = right;
  return result;
}}

// FIND THE MINIMUM ELEMENT

int findmin(struct node *root) {
  int left, right, result;
  if (root == NULL)
    return INT_MAX;
  else{
  result = root->data;
  left = findmin(root->lchild);
  right = findmin(root->rchild);
  if (left < result)
    result = left;
  else if (right <result)
    result = right;
  return result;
}}


// SEARCH FOR AN ELEMENT
int search(struct node *root, int key) {
  int result1, result2;
  if (root == NULL)
    return 0;
  if (root->data == key)
    return 1;
  else {
    result1 = search(root->lchild, key);
    if (result1 != 0)
      return 1;
    else
      result2 = search(root->rchild, key);
    return result2;
  }
}

// SIZE OF THE BINARY TREE
int size(struct node *root) {
  if (root == NULL)
    return 0;
  else
    return (size(root->lchild) + 1 + size(root->rchild));
}

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

void main() {
  struct node *root;
  root = create();
  int ch, max,min, key, s, h;
  do {
    printf("\n\nEnter 1: Find max\n\t2: Search an element\n\t3: Find size\n\t4: Find "
           "height\n\5: Find min\n\t6: Exit: \n ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      max = findmax(root);
      printf("\nThe maximum element is %d", max);
      break;
    case 2:
      printf("\nEnter element to search : ");
      scanf("%d", &key);
      int res = search(root, key);
      if (res == 1)
        printf("\nElement Founded");
      else
      printf("\nElement Not Present");
      break;
    case 3:
      s = size(root);
      printf("\nSize of the tree is =%d", s);
      break;
    case 4:
      h = height(root);
      printf("\nHeight of the tree=%d", h-1);
      break;
      case 5:
      min = findmin(root);
      printf("\nThe minimum element is %d", min);
      break;
    case 6:
      break;
    }
  } while (ch != 6);
}