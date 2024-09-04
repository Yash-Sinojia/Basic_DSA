#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct stack{
    int data;
    struct stack* next;
} st;

st* top=NULL;
int size=0;

void push(int data){
    st* newnode = new st();
    if(!newnode){
        cout<<"stack overflow\n";
        return;
    }
    newnode->data=data;
    newnode->next=top;
    top=newnode;
    size++;
}

bool isEmpty(){
    return top==NULL;
}

int funsize(){
    return size;
}

int peek(){
    if(isEmpty()){
        cout<<"is empty\n";
        return -1;
    }
    return top->data;
}

int pop(){
    st* temp = top;
    if(isEmpty()){
        cout<<"is empty\n";
        return -1;
    }
    int ele= temp -> data;
    top = top -> next;
    free(temp);
    --size;
    return ele;
    
}

int main(){
    push(10);
    push(20);
    push(30);    
    push(40);
    push(50);
    
    cout<<"size is "<<funsize()<<endl;
    cout<<"top -> "<<peek()<<endl;

    cout<<"ele popped is "<<pop()<<endl;

    cout<<"size is "<<funsize()<<endl;
    cout<<"top -> "<<peek()<<endl;

    return 0;
}
