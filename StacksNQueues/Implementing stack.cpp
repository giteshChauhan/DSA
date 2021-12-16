#include<iostream>
using namespace std;

// Implementing stack <long> using dynamic arrays.

class Stack{
    int capacity,top;
    long *arr;

public:

    Stack(){
        capacity=2;
        top=-1;
        arr=new long[2];
    }

private:

    void sizeInc(){
        if(capacity == top+1){
            long *newArr=new long[2*capacity];
            for(int i=0;i<=top;i++)
                newArr[i]=arr[i];
            delete []arr;
            arr=newArr;
            capacity*=2;
        }
    }

    void sizeDec(){
        if(capacity/2 > (top+1)){
            long *newArr=new long[capacity/2];
            for(int i=0;i<=top;i++)
                newArr[i]=arr[i];
            delete []arr;
            arr=newArr;
            capacity/=2;
        }
    }

public:

    bool isEmpty(){
        if(top==-1)
            return 1;
        return 0;
    }

    void push(long data){
        sizeInc();
        top++;
        arr[top]=data;
    }

    void pop(){
        if(top==-1)
            return;
        top--;
        sizeDec();
    }

    int size(){
        return(top+1);
    }

    long peek(){
        if(top != -1)
            return(arr[top]);
        return -1;
    }

    void display(){
        if(top==-1)
            cout<<"Stack is empty";
        for(int i=0;i<top+1;i++)
            cout<<arr[i]<<" ";
    }

};