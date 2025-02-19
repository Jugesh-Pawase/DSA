/*
//Stack using queue
//TC O(n)  SC O(n)
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
*/
/*
//Evaluation of postfix expression
//TC O(n)  SC O(n)
class twoStacks
{
    public:
    int size,top1,top2;
    int *array;
    
    twoStacks(int n=100)
    {
        size=n;
        array=new int[n];
        top1=-1;
        top2=size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        top1++;
        array[top1]=x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       top2--;
       array[top2]=x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1==-1) return -1;
        else return array[top1--];
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(top2==size) return -1;
       else return array[top2++];
    }
};
*/
/*
//Two stacks using one array
//TC O(1)  SC O(1)
class twoStacks
{
    public:
    int size,top1,top2;
    int *array;
    
    twoStacks(int n=100)
    {
        size=n;
        array=new int[n];
        top1=-1;
        top2=size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        top1++;
        array[top1]=x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       top2--;
       array[top2]=x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1==-1) return -1;
        else return array[top1--];
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(top2==size) return -1;
       else return array[top2++];
    }
};
*/
/*
//reverse queue
//TC O(n)  SC O(n)
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
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
//Convert infix expressoin to postfix expression
#include<iostream>
#include<stack>
using namespace std;

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

string infixToPostfix(string s){
    stack<char> st;
    string res;

    for (int i = 0; i <= s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res += s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    string infix;
    
    cout << "Enter the infix expression: ";
    cin >> infix;
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}
*/
/*
//Special Stack with getMin() funcction
//It has two brut force aproaches
//Optimal aproach
// TC O(1) SC O(1) for all functions
int mi=99999;
void push(stack<int>& s, int a){
	// Your code goes here
	if(s.empty()){
	    mi=a;
	    s.push(a);
	}
	else{
    	int x=a;
	    if(a<mi){
	        x=2*a-mi;
	        mi=a;
	    }
	    s.push(x);
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

int pop(stack<int>& s){
	// Your code goes here
	int v=s.top();
	if(v>=mi){
	    s.pop();
	}
	else{
	    int y=2*mi-v;
	    mi=y;
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
        st.push(-1);
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
                    st.push(i);
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
bool duplicateParanthesis(string &expr)
{
    // Write your code here
    int n=expr.length();
    stack<char> st;
    bool ans=false;

    for(int i=0; i<n; i++){
        if(expr[i]==')'){
            if(st.top()=='('){
                ans=true;
                break;
            }
            else{
                while (st.top() != '(') {
                  st.pop();
                }
                st.pop();
            }
        }
        else{
            st.push(expr[i]);
        }
    }
    
    return ans;
}
*/
/*
//Permutation Stack
//TC O(n)    SC O(n)
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

int main()
{
	int n = 15;
	cout << count(n) << endl;

	return 0;
}
*/
/*
//Sort a staxk using recursion
//TC O(n^2)    SC O(n)
void insert_at_correct_position(stack<int> &s, int x){
    if(s.size()==0 || s.top()<=x){
        s.push(x);
    }
    else{
        int a=s.top();
        s.pop();
        insert_at_correct_position(s, x);
        s.push(a);
    }
}

void reverse(stack<int> &s){
    if(s.size()>0){
       int x=s.top();
       s.pop();
       reverse(s);
       insert_at_correct_position(s, x);
   }
}

void SortedStack :: sort()
{
   //Your code here
   reverse(s);
}
*/
/*
//First non-repeating character in a stream
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
//Brut force aproach
//TC O(n^2)   SC O(n)
class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        vector<int> in(n, 0);
        vector<int> out(n, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(M[i][j] == 1){
                    in[j]++;
                    out[i]++;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(in[i]==n-1 && out[i]==0){
                return i;
            }
        }
        
        return -1;
    }
};
*/
/*
//find if there is a celebrity in the party or not.
//Optimal aproach
//TC O(n)   SC O(1)
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
//Brut force aproach
//TC O(n^2)   SC O(1)

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
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
*/
/*
//Next Greater Element
//Optimal aproach
//TC O(n)   SC O(n)
vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    vector<long long> ans(n, -1);
    stack<long long> st;
    
    for(int i=0; i<n; i++){
        if(st.empty() || arr[st.top()]>arr[i]){
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
//Smallest distance of next cell
//TC(m*n)   SC(m*n)
vector<vector<int>> nearest(vector<vector<int>>& grid) {
    // Code here
    int n=grid.size();
    int m=grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                q.push({{i, j}, 0});
                vis[i][j]=1;
            }
        }
    }
    
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;
        
        q.pop();
        dist[row][col]=steps;
        
        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                q.push({{nrow, ncol}, steps+1});
                vis[nrow][ncol]=1;
            }
        }
    }
    
    return dist;
}
*/
/*
//Rotten orange
//TC(m*n)   SC(m*n)

int orangesRotting(vector<vector<int>>& grid) {
        // Code here
    int n=grid.size();
    int m=grid[0].size();
    int ans=0;
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({{i, j}, 0});
                vis[i][j]=1;
            }
        }
    }
    
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;
        
        q.pop();
        dist[row][col]=2;
        ans=steps;
        
        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                q.push({{nrow, ncol}, steps+1});
                vis[nrow][ncol]=1;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1 && dist[i][j]==0){
                return -1;
            }
        }
    }
    
    return ans;
    }
*/
/*
//Reverse stack using recursion
//TC O(n)   SC O(1)
void insert_at_bottom(stack<int> &St, int x){
    if(St.size()==0){
        St.push(x);
    }
    else{
        int a=St.top();
        St.pop();
        insert_at_bottom(St, x);
        St.push(a);
    }
}

void reverse(stack<int> &St){
    if(St.size()>0){
        int x=St.top();
        St.pop();
        reverse(St);
        insert_at_bottom(St, x);
    }
}

void Reverse(stack<int> &St){
    reverse(St);
}
*/
/*
//program to find circular tour for a truck 
//TC O(n)   SC O(n)
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
*/
/*
// A C++ program to demonstrate implementation of k stacks in a single array in time and space efficient way
//TC O(1)   SC O(n)
#include<bits/stdc++.h>
using namespace std;

// A C++ class to represent k stacks in a single array of size n
class kStacks
{
	int *arr; // Array of size n to store actual content to be stored in stacks
	int *top; // Array of size k to store indexes of top elements of stacks
	int *next; // Array of size n to store next entry in all stacks
				// and free list
	int n, k;
	int free; // To store beginning index of free list
public:
	//constructor to create k stacks in an array of size n
	kStacks(int k, int n);

	// A utility function to check if there is space available
	bool isFull() { return (free == -1); }

	// To push an item in stack number 'sn' where sn is from 0 to k-1
	void push(int item, int sn);

	// To pop an from stack number 'sn' where sn is from 0 to k-1
	int pop(int sn);

	// To check whether stack number 'sn' is empty or not
	bool isEmpty(int sn) { return (top[sn] == -1); }
};

//constructor to create k stacks in an array of size n
kStacks::kStacks(int k1, int n1)
{
	// Initialize n and k, and allocate memory for all arrays
	k = k1, n = n1;
	arr = new int[n];
	top = new int[k];
	next = new int[n];

	// Initialize all stacks as empty
	for (int i = 0; i < k; i++)
		top[i] = -1;

	// Initialize all spaces as free
	free = 0;
	for (int i=0; i<n-1; i++)
		next[i] = i+1;
	next[n-1] = -1; // -1 is used to indicate end of free list
}

// To push an item in stack number 'sn' where sn is from 0 to k-1
void kStacks::push(int item, int sn)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nStack Overflow\n";
		return;
	}

	int i = free;	 // Store index of first free slot

	// Update index of free slot to index of next slot in free list
	free = next[i];

	// Update next of top and then top for stack number 'sn'
	next[i] = top[sn];
	top[sn] = i;

	// Put the item in array
	arr[i] = item;
}

// To pop an element from stack number 'sn' where sn is from 0 to k-1
int kStacks::pop(int sn)
{
	// Underflow check
	if (isEmpty(sn))
	{
		cout << "\nStack Underflow\n";
		return INT_MAX;
	}


	// Find index of top item in stack number 'sn'
	int i = top[sn];

	top[sn] = next[i]; // Change top to store next of previous top

	// Attach the previous top to the beginning of free list
	next[i] = free;
	free = i;

	// Return the previous top item
	return arr[i];
}

int main()
{
	// Let us create 3 stacks in an array of size 10
	int k = 3, n = 10;
	kStacks ks(k, n);

	// Let us put some items in stack number 2
	ks.push(15, 2);
	ks.push(45, 2);

	// Let us put some items in stack number 1
	ks.push(17, 1);
	ks.push(49, 1);
	ks.push(39, 1);

	// Let us put some items in stack number 0
	ks.push(11, 0);
	ks.push(9, 0);
	ks.push(7, 0);

	cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

	return 0;
}
*/
/*
//Tower of Honoi
//TC O(2^n - 1)~O(2^n)   SC O(n)
    void tohcol(int n, int from, int to, int aux){
        if(n==1){
            cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
            return;
        }
        
        tohcol(n-1, from, aux, to);
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        
        tohcol(n-1, aux, to, from);
    }

    long long toh(int n, int from, int to, int aux) {
        // Your code here
        tohcol(n, from, to, aux);
        
        return pow(2, n)-1;
    }
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
    
    //access vextor:left  i.e lenght of current element in left side.
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty()) left[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    
    //access vextor:right  i.e lenght of current element in right side.
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
        dltprev->next=dltnode->next;
        dltnext->prev=dltnode->prev;
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