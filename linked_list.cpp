/*

    This file contains linked lists

    - There are a linked list classe and one structure node

    - It has all functions I can think off

    - Main has implementation of those functions
*/



#include<iostream>
using namespace std;


struct ListNode{
    double value;
    ListNode* next;
};

// first list class

class LinkedList{

    private:

        ListNode* head;

    public:

        LinkedList(){
            head = nullptr;
        }

        void displayList() const;
        void add(double item); // add to the end
        void appendNode(double); // add to the end second way
        int get(int index);
        void insertNode(double);
        void remove(int index);
        void remove_value(double val); // remove a node that holds val

        int length();

        void reverse();

};

void LinkedList::add(double item){

    ListNode* newNode = new ListNode;
    newNode->value = item;
    newNode->next = NULL;

    ListNode* temp = head;

    if(temp==nullptr){
        head = newNode;
        return;
    }

    while(temp->next!=nullptr){
        temp=temp->next;
    }

    temp->next = newNode;
}

void LinkedList::appendNode(double val){
    ListNode* newNode;
    ListNode* nodePtr;

    newNode = new ListNode;
    newNode->value = val;
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
    }
    else{
        nodePtr = head;
        while(nodePtr->next!=NULL){
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

// insert in sorting style (in front of bigger val)
void LinkedList::insertNode(double val){
    ListNode* newNode;
    ListNode* nodePtr;
    ListNode* previousNode;

    newNode = new ListNode;
    newNode->value = val;

    if(head==NULL){
        head = newNode;
        newNode->next = NULL;
    }
    else{
        nodePtr = head;
        previousNode = NULL;

        while(nodePtr!=NULL && nodePtr->value<val){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(previousNode == NULL){
            head = newNode;
            newNode->next = nodePtr;
        }
        else{
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void LinkedList::remove(int index){

    // go to index and remove that one

    if(!head) return;

    ListNode* temp = head;
    ListNode* rem;

    int curr = 0; // current index

    while(curr!=index-1 && temp!=nullptr){
        curr++;
        temp = temp->next;
    }

    rem = temp->next;

    temp->next = rem->next;

    delete rem;

}

void LinkedList::remove_value(double val){

    if(!head) return;

    ListNode* temp = head;
    ListNode* prev;

    if(head->value==val){
        head = temp->next;
        delete temp;
    }
    else{
        while(temp->value!=val && temp!=nullptr)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;

        delete temp;
    }

}

int LinkedList::get(int index){

    ListNode* temp = head;
    int curr = 0;
    while(curr != index && temp!=nullptr){
        temp = temp->next;
        curr++;
    }
    if(curr==0){
        return INT32_MAX;
    }
        
    return temp->value;
}

void LinkedList::displayList() const{
    ListNode* nodePtr = head;
    while(nodePtr != NULL){
        cout<<nodePtr->value<<endl;
        nodePtr = nodePtr->next;
    }
}

void LinkedList::reverse(){
    ListNode* temp = NULL;
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
}

int main(){

    LinkedList List;

    List.appendNode(1.0);
    List.appendNode(2.0);
    List.appendNode(3.0);
    List.appendNode(5.0);
    List.insertNode(4.0);

    List.displayList();
    List.remove_value(3.0);
    cout<<endl;
    List.displayList();
    List.reverse();
    cout<<endl;
    List.displayList();
}