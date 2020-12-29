/*
Input: 1,2,3,4,5
Output: The constructed AVL Tree would be
         4
        / \
       2  5
      / \  \
     1  3
preorder traversal sequence is 2,1,4,3,5
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;
  int height;
};

int max(int a, int b){
   return (a > b)? a : b;
}

int height(Node *N){
   if(N == NULL)
          return 0;
   return N->height;
}

Node* newNode(int data){
   Node *node = new Node;
   node->data = data;
   node->left = node->right = NULL;
   node->height = 1;
   return (node);
}

//right roation with y as pivot
Node *rightRotate(Node *z){
    // trace and hold y, T;
    Node *y = z->left;
    Node *T = y->right;

    //Perform right rotation; change z, T
    y->right= z;
    z->left = T;

    //Update heights
    z->height = max(height(z->left), height(z->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    //return new root
    return y;
}

//right roation with y as pivot
Node *leftRotate(Node *z){
    // trace and hold y, T;
    Node *y = z->right;
    Node *T = y->left;

    //Perform right rotation; change z, T
    y->left= z;
    z->right = T;

    //Update heights; change the heights of node z and y
    z->height = max(height(z->left), height(z->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    //return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int data)
{   //if no node, return the new node as root
    if (node == NULL)
        return(newNode(data));

    //if new data less than current node data value
    //insert as left child
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else  // Equal keys are not allowed in BST, no insertion
        return node;

    //Update height of this ancestor node
    node->height = 1 + max(height(node->left),
                        height(node->right));

    /*Get the balance factor of the
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case; left subtree has difference height >1
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        //left rotate with pivot 'node->left'
        node->left = leftRotate(node->left);
        //after becoming left left case, then do the right rotation
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        //right rotate with pivot 'node->right'
        node->right = rightRotate(node->right);

        //after becoming right right case, then do the left rotation
        return leftRotate(node);
    }

    /* The node has its subtrees height difference <= 1
    return the node pointer */
    return node;
}

//print the preorder traversal of the tree
void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main()
{
    Node *root = NULL;

    /* Constructing tree  */
    for(int i=1; i<6; i++){
       root = insert(root, i);
    }



    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);

    return 0;
}
