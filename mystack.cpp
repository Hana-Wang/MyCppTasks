/* Implementing Stack DataStructure using linked list
Stacks works on the principle of LIFO(Late-in-first-out)
hence the function we are implementing are:
1. push() to denote the queue is forming hence all the node added from top.
2. pop() removes the first element that was inserted at the starting.
3. display() show all the elements in the queue.
4. peek() returns the topElement in the stack.

 50-->20-->30-->20-->10
topElement         bottomElement
*/


#include <iostream>
#include <cstdio>
using namespace std;

class Node{
public:
  int data;
  Node *next;
};

class MyStack{
   Node *top, *bottom;
   int totalElements;
public:
   MyStack(){
       top = NULL;
       bottom = NULL;
       totalElements = 0;
   }
   int peek(){
     return top->data;
   }

   void push(int data){
      Node *newNode = new Node;
      newNode->data = data;
      newNode->next = NULL;

      if(top == NULL){
         top = newNode;
         bottom = newNode;
         totalElements++;
         return;
      }

      newNode->next = top;
      top = newNode;
      totalElements++;
   }

 void pop(){
      if(top == NULL){
        cout<<"Stack Already Empty"<<endl;
        return;
      }
      Node *temp = top;
      top = top->next;
      free(temp);
      totalElements--;
 }


   void display(){
     if(top == NULL){
       cout<<"Stack is Empty"<<endl;
       return;
     }
     Node *temp = top;
     for(int i = 0; i < totalElements && temp != NULL; i++){
       if(temp->next !=NULL){
         cout<<temp->data<<"->";
         temp = temp->next;
       }else{
         cout<<temp->data<<" ";
         temp = temp->next;
       }

     }
     cout<<endl;
   }
};

int main() {
    MyStack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50); // 50->40->30->20->10
    myStack.display();

    cout<<myStack.peek()<<endl;

    myStack.pop();
    myStack.display(); //40->30->20->10
    cout<<myStack.peek()<<endl;

    myStack.pop();
    myStack.display(); //40->30->20->10

}
