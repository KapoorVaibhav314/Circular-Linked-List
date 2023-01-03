#include<iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << value << endl; 
    }
};

void insertNode(Node* &tail, int element, int d){
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode; //its coming on itself
    }

   //non-empty list
   else{
   Node* curr = tail;
   while(curr -> data != element){
    curr = curr -> next;
   }
   //element found, curr representing node which contains that element 
   Node* temp = new Node(d);
   temp -> next = curr -> next;
   curr -> next = temp;
   }
}

void print(Node* tail){
    Node* temp = tail;
    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail ==NULL){
        //nothing to do so just print a generic message
        cout << "List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty case
        Node* prev = tail;
        Node* curr = prev -> next;
        while (curr -> data != value){
            //move forward
            prev = curr;
            curr = curr -> next;
        }
        //1 Node Linked List
        if(curr == prev){
            tail ==NULL;
        }
        //>2 node Linked List
        //handle tail
        if(tail == curr){
            //point it to previous one
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
  Node* tail = NULL;
  
  insertNode(tail, 5, 3);
  print(tail);
  
  insertNode(tail, 3, 5);
  print(tail);
  
  deleteNode(tail,3);
  print(tail);

  return 0;

}