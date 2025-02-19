#include<iostream>
using namespace std;
#define n 20

class stack{
    int *array;
    int top;

    public:
    stack(){
        array = new int[n];
        top = -1;
    }
    void push(){
        int item;
        if(top == n-1){
            cout << "Stack is full" << endl;
        }
        else{
            cout << "Push into stack: ";
            cin >> item;
            top += 1;
            array[top] = item;
        }
    }
    void pop(){
        if(top == -1){
            cout << "Stack is empty" << endl;
        }
        else{
            cout << "Pop from stack: " << array[top] << endl;
            top -= 1;
        }
    }
};

int main()
{
    stack st;
    int choice;
    cout << "1.Push\n2.Pop" << endl;
    while(1){
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                st.push();
                break;
            case 2:
                st.pop();
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}