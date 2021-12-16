#include<iostream>
using namespace std;

// Implementing Queue <long> using dynamic arrays.

class Queue{
    int capacity,front,rear;
    long *arr;

public:

    Queue(){
        capacity=2;
        arr=new long[2];
        front=-1;
        rear=-1;
    }

private:

    void sizeInc(){
        capacity*=2;
        long *newArr=new long[capacity];
        for(int i=front,j=0;j<size();j++){
            newArr[j]=arr[i%capacity];
            i++;
        }
        delete arr;
        arr=newArr;
        front=0;
        rear=capacity/2 - 1;
    }

    void sizeDec(){
        long *newArr=new long[capacity/2];
        for(int i=0,j=front;i<capacity/2;i++){
            newArr[i]=arr[j];
            if(j == capacity-1)
                j=0;
            else 
                j++;
        }
        capacity/=2;
        delete arr;
        arr=newArr;
        front=0;
        rear=capacity - 1;
    }

public:

    bool isEmpty(){
        if(front==-1)
            return 1;
        return 0;
    }

    bool isFull(){
        if((capacity-front+rear+1)%capacity == 0)
            return 1;
        return 0;
    }

    void push(long val){
        if(isEmpty())
            front=rear=0;
        else if(isFull()){
            sizeInc();
            rear++;
            }
        else{
            if(rear == capacity-1)
                rear=0;
            else
                rear++;
        }

        arr[rear]=val;
    }

    void pop(){
        if(size()){
            if(front == rear)
                front=rear=-1;
            else if(front == capacity-1)
                front=0;
            else
                front++;
            
            if(!isEmpty())
                if(size() == capacity/2)
                    sizeDec();
        }
    }

    long peek(){
        if(front != -1)
            return(arr[front]);
        return -1;
    }

    void display(){
        if(front==-1)
            cout<<"Queue is empty";
        for(int j=1,i=front;j<=size();j++){
            cout<<arr[i%capacity]<<" ";
            i++;
        }
    }

    int size(){
        if(front == -1)
            return 0;
        else if(isFull())
            return(capacity);
        return((capacity-front+rear+1)%capacity);
    }


};