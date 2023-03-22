#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *lchild;
  struct node *rchild;
  int data;
};

// Number of Internal Nodes
int intcount(struct node *root) {
  if (root->lchild == NULL && root->rchild == NULL)
    return 0;
  else if (root->lchild == NULL && root->rchild != NULL)
    return (intcount(root->rchild) + 1);
  else if (root->rchild == NULL && root->lchild != NULL)
    return (intcount(root->lchild) + 1);
  else
    return (intcount(root->lchild) + 1 + intcount(root->rchild));
}

// Number of Leaves
int leaves(struct node *root) {
  if(root==NULL)
return 0;
  else if (root->lchild == NULL && root->rchild == NULL)
    return 1;
  else
    return (leaves(root->lchild) +leaves(root->rchild));
}

// Smallest Node
int smallest(struct node *root) {
  if (root->lchild == NULL)
    return root->data;
  return smallest(root->lchild);
}

// Largest Node
int largest(struct node *root) {
  if (root->rchild == NULL)
    return root->data;
  return (largest(root->rchild));
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

//Number of Nodes
int count(struct node *root)
{
  if(root==NULL)
    return 0;
  else
    return(count(root->lchild)+1+count(root->rchild));
  }

//Mirror Image
void mirrorimg(struct node *root)
{
if (root== NULL)
return;
else {
struct Node *p;
mirrorimg(root->lchild);
mirrorimg(root->rchild);
p = root->lchild;
root->lchild = root->rchild;
root->rchild = p;
}
}

// Search
int search(struct node *root, int key) {
  if (root == NULL)
    return 0;
  else if (root->data == key)
    return 1;
  else {
    if (root->data > key)
      return (search(root->lchild, key));
    else
      return (search(root->rchild, key));
  }
  return 0;
}

// Inserting A Node
struct node *insert(struct node *root, int value) {
  struct node *prev, *temp, *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->lchild = NULL;
  newnode->rchild = NULL;
  if (root == NULL) {
    root = newnode;
    return root;
  } else {
    temp = root;
    prev = NULL;
    while (temp != NULL) {
      prev = temp;
      if (temp->data > value)
        temp = temp->lchild;
      else
        temp = temp->rchild;
    }
    if (prev->data > value)
      prev->lchild = newnode;
    else
      prev->rchild = newnode;
  }
  return root;
}

//Deleting A Node
struct node *delete (struct node *root, int key) {
  struct node *prev, *current, *newcurrent;
  current = root;
  prev = NULL;
  while (current != NULL && current->data != key) {
    prev = current;
    if (key < current->data)
      current = current->lchild;
    else
      current = current->rchild;
  }
  if (current == NULL) {
    printf("%d is not found in the Binary Search Tree\n", key);
    return root;
  }
  if (current->lchild == NULL || current->rchild == NULL) {
    if (current->lchild == NULL)
      newcurrent = current->rchild;
    else
      newcurrent = current->lchild;
    if (prev == NULL)
      return newcurrent;
    if (current == prev->lchild)
      prev->lchild = newcurrent;
    else
      prev->rchild = newcurrent;
    free(current);
  } else {
    struct node *p, *temp;
    p = NULL;
    temp = current->rchild;
    while (temp->lchild != NULL) {
      p = temp;
      temp = temp->lchild;
    }
    if (p != NULL)
      p->lchild = temp->lchild;
    else
      current->rchild = temp->rchild;
    current->data = temp->data;
    free(temp);
  }
  return root;
}

// PRE-ORDER
void preorder(struct node *root) {
  if (root == NULL)
    return;
  printf("Hye Shaurz!! \n");
  printf("%d\n", root->data);
  preorder(root->lchild);
  preorder(root->rchild);
}

// IN-ORDER
void inorder(struct node *root) {
  if (root == NULL)
    return;
  inorder(root->lchild);
  printf("%d\n", root->data);
  inorder(root->rchild);
  return;
}

// POST-ORDER
void postorder(struct node *root) {
  if (root == NULL)
    return;
  postorder(root->lchild);
  postorder(root->rchild);
  printf("%d\n", root->data);
  return;
}

void main() {
  struct node *root;
  int res, val, ele, ch, choice, delle, c, l;
  root = (struct node *)malloc(sizeof(struct node));
  root = NULL;
  do {
    printf(
        "\nEnter 1 : Insert or Create A BST \n\t 2: Search an Element\n\t 3: "
        "Delete An Element \n\t 4 : Print Preorder Traversal \n\t 5 : Print "
        "Inorder Traversal \n\t 6 : Print Postorder Traversal \n\t 7: Number "
        "of internal nodes\n\t 8 : Number of Leaves\n\t 9:Mirror image\n\t 10: Exit");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      do {
        printf("Enter element to insert\n");
        scanf("%d", &val);
        root = insert(root, val);
        printf("DYWTC(1/0)\n");
        scanf("%d", &ch);
      } while (ch == 1);
      break;
    case 2:
      printf("Enter element to search\n");
      scanf("%d", &ele);
      res = search(root, ele);
      if (res == 1)
        printf("YAAYY !! Element Founded :)");
      else
        printf("OOPSIES !! Element not found :(");
      break;
    case 3:
      printf("Enter element to delete\n");
      scanf("%d", &delle);
      root = delete (root, delle);
      break;
    case 4:
      preorder(root);
      break;
    case 5:
      inorder(root);
      break;
    case 6:
      postorder(root);
      break;
    case 7:
      c = intcount(root);
      printf("Number of internal nodes=%d\n", c);
      break;
    case 8:
      l = leaves(root);
      printf("Number of leaf nodes=%d\n", l);
      break;
      case 9: mirrorimg(root);
      break;
    case 10:
      exit(1);
    }
  } while (choice != 10);
}