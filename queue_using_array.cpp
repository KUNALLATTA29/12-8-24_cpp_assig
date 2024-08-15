#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int Queue[MAX];
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return (rear + 1) % MAX == front;
}

void enqueue(int x) {
    if (isFull()) {
        cout<<"queue is full."<<x<<endl;
    }else{
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        Queue[rear] = x;
        cout<<x<<" enqueued"<<endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout<<"queue is empty."<<endl;
    }else{
        cout<<Queue[front]<<" dequeued"<<endl;
        if (front == rear) {
            front = rear = -1;
        }else {
            front = (front + 1) % MAX;
        }
    }
    
}

int getFront() {
    if (isEmpty()) {
        cout << "queue is empty." << endl;
        return -1;
    }
    return Queue[front];
}

void display() {
    if (isEmpty()) {
        cout << "queue is empty." << endl;
        return;
    }
    int i = front;
    do {
        cout << Queue[i] << " ";
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();
    
    cout<<getFront()<<endl;
    
    dequeue();
    
    
    return 0;
}