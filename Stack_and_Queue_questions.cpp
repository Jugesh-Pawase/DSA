/*
//two stacks using single array    
//dont see this because this dont work for all test cases its just for knowledge
//TC O(1)     SC O(1)
#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n) 
    { 
        size = n;
        arr = new int[n]; 
        top1 = size / 2 + 1;  // top1 starts from the middle of the array + 1
        top2 = size / 2;      // top2 starts from the middle of the array
    }

    void push1(int x)
    {
        if (top1 < size) {  // Ensure there is space for stack1
            arr[top1++] = x;  // Increment top1 and then insert the element
        }
        else {
            cout << "Stack Overflow for stack1" << endl;
        }
    }

    void push2(int x)
    {
        if (top2 >= 0) {  // Ensure there is space for stack2
            arr[top2--] = x;  // Decrement top2 and then insert the element
        }
        else {
            cout << "Stack Overflow for stack2" << endl;
        }
    }

    int pop1()
    {
        if (top1 > size / 2) {  // Ensure stack1 is not empty
            return arr[--top1];  // Decrement top1 and return the element
        }
        else {
            return -1;  // Stack Underflow for stack1
        }
    }

    int pop2()
    {
        if (top2 < size / 2) {  // Ensure stack2 is not empty
            return arr[++top2];  // Increment top2 and return the element
        }
        else {
            return -1;  // Stack Underflow for stack2
        }
    }
};

//Efficient i.e work for all test cases: TC O(1)    SC O(1)
class twoStacks {
    int size;
    int *arr;
    int top1, top2;
  public:
    twoStacks(int n=100) {
        size=n;
        arr = new int[size];
        top1=-1, top2=size;
    }

    void push1(int x) {
        top1++;
        arr[top1]=x;
    }

    void push2(int x) {
        top2--;
        arr[top2]=x;
    }

    int pop1() {
        if(top1==-1) return -1;
        
        int val=arr[top1];
        top1--;
        return val;
    }

    int pop2() {
        if(top2==size) return -1;
        
        int val=arr[top2];
        top2++;
        return val;
    }
};
/*
//Evaluation of postfix expression
//TC O(n)  SC O(n)
class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        for(string s:arr){
            if(isdigit(s[0]) || s.size()>1&&s[0]=='-'){
                st.push(stoi(s));
            }
            else{
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                
                if(s=="+"){
                    st.push(op1+op2);
                }
                else if(s=="-"){
                    st.push(op1-op2);
                }
                else if(s=="*"){
                    st.push(op1*op2);
                }
                else if(s=="/"){
                    st.push(op1/op2);
                }
            }
        }
        
        return st.top();
    }
};
//Evaluation of postfix expression
//TC O(n)  SC O(n)
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        int n=S.length();
        for(int i=0; i<n; i++){
            if(S[i]>='0' && S[i]<='9'){
                st.push(S[i]-'0');
            }
            else{
                int opp2=st.top();
                st.pop();
                int opp1=st.top();
                st.pop();
                
                switch(S[i]){
                    case '+':st.push(opp1+opp2);
                    break;
                    case '-':st.push(opp1-opp2);
                    break;
                    case '*':st.push(opp1*opp2);
                    break;
                    case '/':st.push(opp1/opp2);
                    break;
                }
            }
        }
        
        return st.top();
    }
};
*/
/*
//Convert infix expressoin to postfix expression
//TC O(n)     SC O(n)
class Solution {
  public:
    int prec(char c){
        if(c=='^'){
            return 3;
        }
        else if(c=='*' || c=='/'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }

    string infixToPostfix(string& s) {
        // code here
        int n=s.size();
        stack<char>st;
        string postfix;

        for(int i=0; i<n; i++){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')
            || (s[i]>='0' && s[i]<='9')){
                postfix += s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top()!='('){
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && prec(st.top())>=prec(s[i])){
                    postfix += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }
};
*/
/*
//Stack using two queues
//TC O(n) for push operation, TC O(1)  for all other operations,  SC O(n)
class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int ans;
        if (q1.empty()) {
            ans = -1;
        } else {
            ans = q1.front();
            q1.pop();
        }
        return ans;
    }

    int top() {
        if (q1.empty())
            return -1;
        else
            return q1.front();
    }

    bool empty() {
        if (q1.empty())
            return true;
        else
            return false;
    }
};
//Stack using single queue
//TC O(n) for push operation, TC O(1)  for all other operations,  SC O(n)
class MyStack {
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int n=q.size();
        for(int i=0; i<n-1; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int ans;
        if (q.empty()) {
            ans = -1;
        } else {
            ans = q.front();
            q.pop();
        }
        return ans;
    }

    int top() {
        if (q.empty())
            return -1;
        else
            return q.front();
    }

    bool empty() {
        if (q.empty())
            return true;
        else
            return false;
    }
};
*/
/*
//reverse queue
//Using stack: TC O(n)  SC O(n)
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }

        return q;
    }
};
//Using recursion:TC O(n)  SC O(n)
class Solution {
  public:
    void reverse(queue<int> &q){
        if(!q.empty()){
            int val=q.front();
            q.pop();
            reverse(q);
            q.push(val);
        }
    }
  
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        reverse(q);
        return q;
    }
};
*/
/*
//implement stack and queue using deque
class Stack {
    deque<int> dq;
  public:
    void push(int x) {
        dq.push_back(x);
    }
    void pop() {
        if (!dq.empty()) dq.pop_back();
    }
    int top() {
        return dq.back();
    }
    bool empty() {
        return dq.empty();
    }
};
class Queue {
    deque<int> dq;
  public:
    void enqueue(int x) {
        dq.push_back(x);
    }
    void dequeue() {
        if (!dq.empty()) dq.pop_front();
    }
    int front() {
        return dq.front();
    }
    bool empty() {
        return dq.empty();
    }
};
*/
/*
//reverse first k elements of queue
//TC O(n)     SC O(n)
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (q.size() < k) return q;  // Edge case
        
        stack<int>st;
        for(int i=0; i<k; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        int remaining=q.size()-k;
        for(int i=0; i<remaining; i++){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
*/
/*
//Remove middle element without using extra data structure
//TC O(n)     SC O(n)
class Solution {
  public:
    void solve(stack<int>& s, int curr, int size){
        if(s.empty() || curr==size/2){
            s.pop();
            return;
        }
        
        int top=s.top();
        s.pop();
        solve(s, curr+1, size);
        s.push(top);
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int n=s.size();
        solve(s, 0, n);
    }
};
*/
/*
//C++ Program to implement a stack that supports findMiddle() and deleteMiddle in O(1) time
#include <bits/stdc++.h>
using namespace std;

class myStack {
    struct Node {
        int num;
        Node* next;
        Node* prev;

        Node(int num) { this->num = num; }
    };

    // Members of stack
    Node* head = NULL;
    Node* mid = NULL;
    int size = 0;

public:
    void push(int data)
    {
        Node* temp = new Node(data);
        if (size == 0) {
            head = temp;
            mid = temp;
            size++;
            return;
        }

        head->next = temp;
        temp->prev = head;

        // update the pointers
        head = head->next;
        if (size % 2 == 1) {
            mid = mid->next;
        }
        size++;
    }

    int pop()
    {
    int data=-1;
        if (size != 0) {
        Node* toPop = head;
        data = toPop->num;
            if (size == 1) {
                head = NULL;
                mid = NULL;
            }
            else {
                head = head->prev;
                head->next = NULL;
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
            }
            delete toPop;
            size--;
        }
    return data;
    }

    int findMiddle()
    {
        if (size == 0) {
            return -1;
        }
        return mid->num;
    }

    void deleteMiddle()
    {
        if (size != 0) {
            Node* toDelete = mid;
            if (size == 1) {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2) {
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
                else {
                    mid = mid->next;
                }
            }
            delete toDelete;
            size--;
        }
    }
};

int main()
{
    myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}
*/
/*
//Special Stack with getMin() funcction
//It has two brut force aproaches
//Optimal aproach
// TC O(1) SC O(1) for all functions
int mi;
void push(stack<int>& s, int a){
    // Your code goes here
    if(s.empty()){
        mi=a;
        s.push(a);
    }
    else{
        if(a<mi){
            s.push(2*a-mi);
            mi=a;
        }
        else{
            s.push(a);
        }
    }
}

bool isFull(stack<int>& s,int n){
    // Your code goes here
    if(s.size()==n) return true;
    else return false;
}

bool isEmpty(stack<int>& s){
    // Your code goes here
    if(s.empty()) return true;
    else return false;
}

int pop(stack<int>& s) {
    // Your code goes here
    if(!s.empty()){
        if(s.top()<mi){
            mi=2*mi-s.top();
        }
        s.pop();
    }
}

int getMin(stack<int>& s){
    // Your code goes here
    return mi;
}
*/
/*
//Longest Valid parantheses
// TC O(n) SC O(n)
class Solution{
public:
    int maxLength(string S){
        // code here
        int n=S.length();
        stack<int> st;
        st.push(-1);           //base index
        int result=0;
        for (int i = 0; i < n; i++){
            if(S[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(!st.empty()){
                    result=max(result, i-st.top());
                }
                else{
                    st.push(i);          //new base index
                }
            }
        }

        return result;
    }
};
*/
/*
//Redundant/Duplicate parentheses
//TC O(n)   SC O(n)
#include <bits/stdc++.h> 
bool duplicateParanthesis(string &expr){
    // Write your code here
    int n=expr.size();
    stack<char>st;

    for(int i=0; i<n; i++){
        if(expr[i] == ')'){
            if(st.top() == '(') return true;
            while(!st.empty() && st.top()!='('){
                st.pop();
            }
            st.pop();
        }
        else{
            st.push(expr[i]);
        }
    }

    return false;
}
*/
/*
//Permutation Stack
//Brut force: TC O(n)    SC O(n)       //usless aproach dont see nothing to learn
class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        queue<int> ip;
        queue<int> op;
        for(int i=0; i<N; i++){
            ip.push(A[i]);
            op.push(B[i]);
        }

        stack<int> st;
        while(ip.size()){
            int temp=ip.front();
            ip.pop();
            if(temp==op.front()){
                op.pop();
                while(st.size()){
                    if(st.top()==op.front()){
                        st.pop(); op.pop();
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                st.push(temp);
            }
        }

        return (st.empty() && op.empty());
    }
};
//Optimal Aproach:TC O(n)    SC O(1)
class Solution {
  public:
    bool checkPerm(vector<int>& a, vector<int>& b) {
        // code here
        stack<int>st;
        int n=a.size(), j=0;
        
        for(int i=0; i<n; i++){
            st.push(a[i]);
            
            if(st.top() == b[j]){
                while(!st.empty() && st.top()==b[j]){
                    st.pop();
                    j++;
                }
            }
        }
        
        if(st.empty()) return true;
        else return false;
    }
};
*/
/*
// C++ program to count the number less than N,  whose all permutation is greater than or equal to the number.
//TC O(n)    SC O(n)
#include<iostream>
#include<stack>
using namespace std;

int count(int n){
    int result = 0;
    stack<int> st;
    for (int i = 1; i <= 9; i++){
        if(i<=n){
            result++;
            st.push(i);
        }
    }
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        for (int j = temp % 10; j <= 9; j++){
            int x = temp * 10 + j;
            if(x<=n){
                st.push(x);
                result++;
            }
        }
    }
    return result;
}
*/
/*
//Sort a staxk using recursion
//TC O(n^2)    SC O(n)
void insert_at_correct_position(stack<int> &s, int val){
    if(s.empty() || s.top()<=val){
        s.push(val);
    }
    else{
        int x=s.top();
        s.pop();
        insert_at_correct_position(s, val);
        s.push(x);
    }
}

void reverse(stack<int> &s){
    if(!s.empty()){
        int val=s.top();
        s.pop();
        reverse(s);
        insert_at_correct_position(s, val);
    }
}

void SortedStack ::sort() {
    // Your code here
    reverse(s);
}
*/
/*
//Reverse stack using recursion
//TC O(n)   SC O(n)
void insert_at_bottom(stack<int> &St, int val){
    if(St.empty()){
        St.push(val);
    }
    else{
        int x=St.top();
        St.pop();
        insert_at_bottom(St, val);
        St.push(x);
    }
}
void reverse(stack<int> &St){
    if(!St.empty()){
        int val=St.top();
        St.pop();
        reverse(St);
        insert_at_bottom(St, val);
    }
}

void Reverse(stack<int> &St){
    reverse(St);
}
*/
/*
//First non-repeating character in a stream
//abcbbac -> aaaaac#
//TC O(n)   SC O(n)
class solution{
    public:
    string FirstNonRepeating(string A){
        // Code here
        int n=A.length();
        int frec[26]={0};
        queue<char> q;
        string ans="";

        for(int i=0; i<n; i++){
            q.push(A[i]);
            frec[A[i]-'a']++;
            while(!q.empty()){
                if(frec[q.front()-'a']>1){
                    q.pop();
                }
                else{
                    ans+=q.front();
                    break;
                }
            }
            if(q.empty()){
                ans+='#';
            }
        }

        return ans;
    }
}
*/
/*
//find if there is a celebrity in the party or not.
//Brut force aproach: TC O(n^2)   SC O(1)
int celebrity(vector<vector<int>>& M, int n) {
    for(int i = 0; i < n; i++) {
        bool isCelebrity = true;
        
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(M[i][j] == 1 || M[j][i] == 0) {
                isCelebrity = false;
                break;
            }
        }
        
        if(isCelebrity) return i;
    }
    return -1;
}
//Optimal aproach: TC O(n)   SC O(1)
class Solution
{
    public:
    int celebrity(vector<vector<int> >& M, int n)
    {
        // code here
        int c=0;
        for(int i=1; i<n; i++){
            if(M[c][i]==1)c=i;
        }

        for(int i=0; i<n; i++){
            if(i!=c && (M[i][c]==0 || M[c][i]==1)) return -1;
        }
        return c;
    }
};
*/
/*
//Next Greater Element
//Brut force aproach: TC O(n^2)   SC O(1)
class Solution
{
    public:
        for(int i=0; i<n; i++){
            int j=i+1;
            while(j<n){
                if(arr[i]<arr[j]){
                    arr[i]=arr[j];
                    break;
                }
                j++;
            }
            if(j>=n){
                arr[i]=-1;
            }
        }
        return arr;
    }
};
//Optimal aproach: TC O(n)   SC O(n)
vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    vector<long long> ans(n, -1);
    stack<long long> st;

    for(int i=0; i<n; i++){
        if(st.empty() || arr[st.top()]>=arr[i]){
            st.push(i);
        }
        else{
            while(!st.empty() && arr[st.top()]<arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}
*/
/*
//Next smallest Element
//Brut force aproach: TC O(n^2)   SC O(1)
class Solution
{
    public:
        for(int i=0; i<n; i++){
            int j=i+1;
            while(j<n){
                if(arr[i]>arr[j]){
                    arr[i]=arr[j];
                    break;
                }
                j++;
            }
            if(j>=n){
                arr[i]=-1;
            }
        }
        return arr;
    }
};
//Optimal aproach: TC O(n)   SC O(n)
vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    vector<long long> ans(n, -1);
    stack<long long> st;

    for(int i=0; i<n; i++){
        if(st.empty() || arr[st.top()]<=arr[i]){
            st.push(i);
        }
        else{
            while(!st.empty() && arr[st.top()]>arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}
*/
/*
//program to find circular tour for a truck
//TC O(n)   SC O(1)
#include <bits/stdc++.h>
using namespace std;

class petrolPump
{
    public:
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
    {
       //Your code here
       int start=0;
       int extrafuel=0;
       int requirefuel=0;

       for(int i=0; i<n; i++){
           extrafuel += (p[i].petrol-p[i].distance);
           if(extrafuel<0){
               start=i+1;
               requirefuel += extrafuel;
               extrafuel=0;
           }
       }
       if((requirefuel+extrafuel)>=0) return start;
       else return -1;
    }

int main()
{
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};

    int n = sizeof(arr)/sizeof(arr[0]);
    int start = tour(arr, n);

    (start == -1)? cout<<"No solution": cout<<"Start = "<<start;

    return 0;
}

//For new syntax
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n=gas.size();
        int extraFuel=0, requireFuel=0, start=0;
        
        for(int i=0; i<n; i++){
            extraFuel += gas[i]-cost[i];
            if(extraFuel<0){
                requireFuel += extraFuel;
                extraFuel=0;
                start=i+1;
            }
        }
        
        return ((extraFuel+requireFuel) >=0)?start:-1;
    }
};
*/
/*
//K stacks in a single array
//Naive Approach (Partition the array into K parts)
TC O(1)   SC O(n)
#include <bits/stdc++.h>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int *base;
    int n, s;

public:
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[S];
        top = new int[N];
        base = new int[N];

        int partitionSize = S / N;
        for (int i = 0; i < N; i++) {
            top[i] = i * partitionSize - 1;
            base[i] = i * partitionSize;
        }
    }

    bool push(int x, int m) {
        int partitionSize = s / n;
        int limit = base[m - 1] + partitionSize - 1;
        if (top[m - 1] >= limit) return false;
        top[m - 1]++;
        arr[top[m - 1]] = x;
        return true;
    }

    int pop(int m) {
        if (top[m - 1] < base[m - 1]) return -1;
        return arr[top[m - 1]--];
    }
};
//Optimal:Using single array and extra arrays
TC O(1)   SC O(n)
#include <bits/stdc++.h>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freeSpot;

public:
    // Initialize your data structure.
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for (int i = 0; i < n; i++) top[i] = -1;
        for (int i = 0; i < s - 1; i++) next[i] = i + 1;
        next[s - 1] = -1;
        freeSpot = 0;
    }
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        if (freeSpot == -1) return false;

        int index = freeSpot;
        freeSpot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }
    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        if (top[m - 1] == -1) return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};
*/
/*
//Maximum of minimum for N windows
//TC O(n)   SC O(n)
vector <int> maxOfMin(int arr[], int n)
{
    // Your code here
    stack<int> st;
    vector<int> left(n, -1);
    vector<int> right(n, n);

    //access vector:left  i.e lenght of current element in left side.
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty()) left[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();

    //access vector:right  i.e lenght of current element in right side.
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty()) right[i]=st.top();
        st.push(i);
    }

    vector<int> ans(n+1);

    for(int i=0; i<n; i++){
        int len=right[i]-left[i]-1;
        ans[len]=max(ans[len], arr[i]);
    }
    for(int i=n-1; i>=1; i--){
        ans[i]=max(ans[i], ans[i+1]);
    }
    ans.erase(ans.begin());

    return ans;
}
*/
/*
//LRU Cache
//TC O(1)  SC O(1)
class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class node{
        public:

        int key;
        int val;
        node* prev;
        node* next;

        node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int capacity;
    unordered_map<int, node*>m;

    LRUCache(int cap)
    {
        // code here
        capacity=cap;
        head->next=tail;
        tail->prev=head;
    }

    void addnode(node* resnode){
        node* temp=head->next;
        resnode->next=temp;
        resnode->prev=head;
        head->next=resnode;
        temp->prev=resnode;
    }

    void delnode(node* dltnode){
        node* dltprev=dltnode->prev;
        node* dltnext=dltnode->next;
        dltprev->next=dltnext;
        dltnext->prev=dltprev;
    }

    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(m.find(key) != m.end()){
            node* resnode=m[key];
            int value=resnode->val;
            m.erase(key);
            delnode(resnode);
            addnode(resnode);
            m[key]=head->next;

            return value;
        }

        return -1;
    }

    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        if(m.find(key) != m.end()){
            node* existingnode=m[key];
            m.erase(key);
            delnode(existingnode);
        }
        if(m.size()==capacity){
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }

        addnode(new node(key, value));
        m[key]=head->next;
    }
};
*/