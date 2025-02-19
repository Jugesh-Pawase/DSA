#include<iostream>
using namespace std;

class circularQueue{
    private:
        int front, rear, size;
        int *array;

    public:
        circularQueue(int s){
            size = s;
            front = rear = -1;
            array = new int[size];
        }
        bool isEmpty(){
            return front == -1 && rear == -1;
        }
        bool isFull(){
            return (rear + 1) % size == front;
        }
        void enqueue(int val){
            if(isFull()){
                cout << "Queue is full. Element cannot enqueue." << endl;
                return;
            }
            if(isEmpty()){
                front = rear = 0;
            }
            else{
                rear = (rear + 1) % size;
            }
            array[rear] = val;
            cout << val << " enqueued to the queue." << endl;
        }
        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty. Element cannot dequeue." << endl;
                return;
            }
            cout << array[front] << " dequeue from the queue." << endl;
            if(front == rear){
                front = rear = -1;
            }
            else{
                front = (front + 1) % size;
            }
        }
        void display(){
            if(isEmpty()){
                cout << "Queue is empty." << endl;
                return;
            }
            int i = front;
            cout << "Queue elements: ";
            do{
                cout << array[i] << " ";
                i = (i+1)%size;
            } while (i != (rear+1)%size);
            cout << endl;
        }
        
};

int main()
{
    circularQueue cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();

    cq.dequeue();
    cq.display();

    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);
    cq.enqueue(7);
    cq.display();

    return 0;
}