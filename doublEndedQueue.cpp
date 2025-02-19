#include<iostream>
using namespace std;

class Deque{
    private:
        int front, rear, size;
        int *array;

    public:
    Deque(int s){
        front = rear = -1;
        size = s;
        array = new int[size];
    }
    bool isEmpty(){
        return front == -1 && rear == -1;
    }
    bool isFull(){
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }
    void insertFront(int key){
        if(isFull()){
            cout << "Deque is full. Cannot enqueue" << endl;
            return;
        }
        if(isEmpty()){
            front = rear = 0;
        }
        else if(front = 0){
            front = size - 1;
        }
        else{
            front -= 1;
        }
        array[front] = key;
        cout << key << " inserted at the front" << endl;
    }
    void insertRear(int key){
        if(isFull()){
            cout << "Deque is full. Cannot enqueue" << endl;
            return;
        }
        if(isEmpty()){
            front = rear = 0;
        }
        else if(rear = size-1){
            rear = 0;
        }
        else{
            rear += 1;
        }
        array[rear] = key;
        cout << key << " inserted at the rear" << endl;
    }
    void deleteFront(){
        if(isEmpty()){
            cout << "Deque is empty. Cannot dequeue" << endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        } 
        else{
            front += 1;
        }
        cout << "Element deleted from the front" << endl;
    }
    void deleteRear(){
        if(isEmpty()){
            cout << "Deque is empty. Cannot dequeue" << endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            front = size-1;
        } 
        else{
            rear -= 1;
        }
        cout << "Element deleted from the rear" << endl;
    }
    int getFront(){
        if(isEmpty()){
            cout << "Deque is empty." << endl;
            return -1;
        }
        return array[front];
    }
    int getRear(){
        if(isEmpty()){
            cout << "Deque is empty." << endl;
            return -1;
        }
        return array[rear];
    }
};

int main()
{
    Deque deque(5);

    deque.insertFront(3);
    deque.insertFront(4);
    deque.insertRear(1);
    deque.insertFront(5);
    deque.insertRear(2);
    deque.insertRear(6);

    deque.deleteFront();
    deque.deleteRear();

    cout << "Front element: " << deque.getFront() << endl;
    cout << "Rear element: " << deque.getRear() << endl;

    return 0;
}