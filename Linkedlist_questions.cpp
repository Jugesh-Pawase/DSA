/*
//Reverse linkedlist
//TC O(n)   SC O(1)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};

/*
//Linkedlist cycle
//BrutForce(hashMap): TC O(n)    SC O(n)
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        unordered_map<Node*, int>mp;
        while(head){
            if(!mp[head]){
                mp[head]=1;
                head=head->next;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};

//Optimal: TC O(n)   SC O(1)
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        
        return false;
    }
};

/*
//Merge two sorted lists
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* dummy = new Node(-1);
        Node* temp=dummy;
        
        while(head1!=nullptr && head2!=nullptr){
            if(head1->data < head2->data){
                temp->next=head1;
                temp=head1;
                head1=head1->next;
            }
            else{
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }
        }
        
        if(head1!=nullptr){
            temp->next=head1;
        }
        else{
            temp->next=head2;
        }
        
        return dummy->next;
    }
};

/*
//Remove node without head referemce
//TC O(1)   SC O(1)
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    void deleteNode(Node* del_node) {
        // Your code here
        del_node->data = del_node->next->data;
        del_node->next = del_node->next->next;
    }
};

/*
//remove duplicates from unsorted linked list.
//TC O(n)   SC O(n)
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        unordered_map<int, int>mp;
        Node* curr=head;
        mp[curr->data]=1;
        Node* prev=curr;
        curr=curr->next;
        
        while(curr != nullptr){
            if(mp[curr->data]){
                prev->next = curr->next;
                free(curr);
            }
            else{
                mp[curr->data]=1;
                prev=curr;
            }
            curr=prev->next;
        }
        
        return head;
    }
};
/*
//sort a linked list 0s, 1s or 2s
//Expected Aproach-1:  Time Complexity: O(n)    Auxiliary Space: O(1)      not you decide to refer this due to less code and same tc & sc
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int count[3]={0};
        
        Node* temp=head;
        
        while(temp != nullptr){
            count[temp->data]++;
            temp=temp->next;
        }
        
        temp=head;
        int i=0;
        while(temp != nullptr){
            if(count[i] == 0){
                i++;
            }
            else{
                temp->data=i;
                count[i]--;
                temp = temp->next;
            }
        }
        
        return head;
    }
};

//Expected Aproach-2:  Time Complexity: O(n)    Auxiliary Space: O(1)
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        // Create dummy heads and tails for 0s, 1s, 2s lists
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);

        Node* zero = zeroD, *one = oneD, *two = twoD;

        Node* curr = head;

        // Distribute nodes into three lists
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect the three lists
        zero->next = oneD->next ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;

        // New head is the start of 0s list
        Node* newHead = zeroD->next;

        // Clean up dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;

        return newHead;
    }
};
*/
/*
//Multiply two linkedlists
//TC O(n)    SC O(1)
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        const long long MOD = 1000000007;
        long long num1 = 0, num2 = 0;

        // Convert first list to number
        while (first != nullptr) {
            num1 = (num1 * 10 + first->data) % MOD;
            first = first->next;
        }

        // Convert second list to number
        while (second != nullptr) {
            num2 = (num2 * 10 + second->data) % MOD;
            second = second->next;
        }

        return (num1 * num2) % MOD;
    }
};
*/
/*
//Remove nth node from end
//Optimal aproach: TC O(n)    SC O(1)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head;
        for(int i=0; i<n; i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            return head->next;
        }
        ListNode *slow=head;
        while(fast->next != nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *todelete=slow->next;
        slow->next=slow->next->next;
        delete todelete;
        return head;
    }
};

//BrutForce: TC O(2n)   SC O(1)       note its brutforce due to 2n
Node* deleteNthFromEnd(Node* head, int n) {
    int len = 0;
    Node* temp = head;

    // Count length
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }

    // If deleting the first node
    if (n == len) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    int pos = len - n;
    temp = head;
    for (int i = 1; i < pos; ++i) {
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    return head;
}
*/
/**
//Reorder lists
//TC O(n)     SC O(1)
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverse(Node* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        Node* last=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        
        return last;
    }
  
    void reorderList(Node* head) {
        // Your code here
        Node* slow=head;
        Node* fast=head->next;
        //To find middle element/node
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //split into two lists
        Node* first=head;
        Node* second=reverse(slow->next);
        slow->next=nullptr;
        
        //merge two lists
        while(second){
            Node* temp1=first->next;
            Node* temp2=second->next;
            first->next=second;
            first=temp1;
            second->next=first;
            second=temp2;
        }
    }
};
*/
/*
//Remove loop in linkedlist
//BrutForce: TC O(n)   SC O(n)
void removeLoop(Node *head) {
    unordered_set<Node *> st;

    Node *prev = nullptr;
    while (head != nullptr) {
        if (st.find(head) == st.end()) {
            st.insert(head);
            prev = head;
            head = head->next;
        }
        else {
            prev->next = nullptr;
            break;
        }
    }
}
//Optimal Aproach: TC O(n)    SC O(1)
class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        if(head==nullptr || head->next==nullptr) return;
        
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast){
                break;
            }
        }
        
        if(slow == head){
            while(fast->next != slow){
                fast = fast->next;
            }
            fast->next = nullptr;
        }
        else if(slow == fast){
            slow=head;
            
            while(fast->next != slow->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=nullptr;
        }
    }
};
*/
/*
//Intersection point in two Y shaped linkedlists
//BrutForce: TC O(m*n)    SC O(1)
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node *intersectPoint(Node *head1, Node *head2) {
    while (head2 != nullptr) {
        Node *temp = head1;
        while (temp != nullptr) {
            if (temp == head2){
                return head2;
            }
            temp = temp->next;
        }
        head2 = head2->next;
    }
  	
    // intersection is not present between the lists
    return nullptr;
}
//Better: TC O(n)    SC O(n)
Node *intersectPoint(Node *head1, Node *head2) {
    unordered_set<Node *> visitedNodes;

    Node *curr1 = head1;
    while (curr1 != nullptr) {
        visitedNodes.insert(curr1);
        curr1 = curr1->next;
    }

    Node *curr2 = head2;
    while (curr2 != nullptr) {
        if (visitedNodes.find(curr2) != visitedNodes.end()) {
            return curr2;
        }
        curr2 = curr2->next;
    }

    return nullptr;
}

//Optimal aproach: TC O(N+M)   SC O(1)
class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node* temp1=head1;
        Node* temp2=head2;
        
        while(1){
            if(temp1 == temp2){
                return temp1;
            }
            if(temp1==nullptr){
                temp1=head2;
            }
            if(temp2==nullptr){
                temp2=head1;
            }
            
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
};
*/
/*
//Flatten linkedlist
//BrutForce: TC O(n*m)   SC O(2n*m) 
//traverese through all childs of all first level nodes and store in array then sort and convert into linklist
//Optimal: TC O(n*2m)    SC O(1)
class Node {
 public:
	int data;
	Node *next;
		Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
 

 Node* merge(Node* list1, Node* list2){
	 Node* dummyNode=new Node(-1);
	 Node* res=dummyNode;

	 while(list1!=nullptr && list2!=nullptr){
		 if(list1->data < list2->data){
			 res->child=list1;
			 res=list1;
			 list1=list1->child;
		 }
		 else{
			 res->child=list2;
			 res=list2;
			 list2=list2->child;
		 }
		 res->next=nullptr;
	 }
	 if(list1){
		 res->child=list1;
	 }
	 else{
		 res->child=list2;
	 }
	 if(dummyNode->child){
		 dummyNode->child->next=nullptr;
	 }
	 return dummyNode->child;
 }

Node* flattenLinkedList(Node* head){
	if(head==nullptr || head->next==nullptr){
		return head;
	}

	Node* mergedHead = flattenLinkedList(head->next);
	head=merge(head, mergedHead);

	return head;
}
*/
/*
//arrange linked list in zigzag fashion
//TC O(n)   SC O(1)
struct Node {
	int data;
	struct Node* next;
};

class Solution {
  public:
    Node* zigZag(Node* head) {
        bool flag=true;
        Node* curr=head;
        
        while(curr->next != nullptr){
            if(flag){
                if(curr->data > curr->next->data){
                    swap(curr->data, curr->next->data);
                }
            }
            else{
                if(curr->data < curr->next->data){
                    swap(curr->data, curr->next->data);
                }
            }
            
            flag = !flag;
            curr=curr->next;
        }
        
        return head;
    }
};
*/
/*
//Reverse DLL
//TC O(n)   SC O(1)
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(!head || !head->next) return head;
        
        DLLNode* curr=head;
        DLLNode* temp=nullptr;
        while(curr){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            
            curr=curr->prev;
        }
        
        head = temp->prev;
        return head;
    }
};
*/
/*
//Remove all nodes which has greater element on right sidel
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* reverseList(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    Node* reverseList(Node* headref) {
        Node* curr = headref;
        Node* prev = nullptr;
        Node* next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  
    Node *compute(Node *head) {
        // your code goes here
        head = reverseList(head);
        
        Node* prev=head;
        int max=head->data;
        Node* curr=head->next;
        
        while(curr){
            if(curr->data >= max){
                max=curr->data;
                prev=curr;
            }
            else{
                prev->next = curr->next;
            }
            
            curr = prev->next;
        }
        
        head = reverseList(head);
        return head;
    }
};
*/
/*
//Sagrigate even odd elements in linkedlist
//TC O(n)   SC O(1)
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node* oddD= new Node(-1);
        Node* evenD= new Node(-1);
        Node* odd=oddD, *even=evenD;
        
        Node* curr=head;
        while(curr){
            if(curr->data%2 == 0){
                even->next=curr;
                even=curr;
            }
            else{
                odd->next=curr;
                odd=curr;
            }
            curr=curr->next;
        }
        
        even->next = (oddD->next)?oddD->next:nullptr;
        odd->next=nullptr;
        head=evenD->next;
        
        return head;
    }
};
*/
/*
// sort the biotonic doubly linked list
#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// Function to reverse a Doubly Linked List
void reverse(struct Node* head_ref)
{
	struct Node* temp = NULL;
	struct Node* current = head_ref;

	while (current != NULL) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
		head_ref = temp->prev;
}

struct Node* merge(struct Node* first, struct Node* second)
{
	// If first linked list is empty
	if (!first)
		return second;

	// If second linked list is empty
	if (!second)
		return first;

	// Pick the smaller value
	if (first->data < second->data) {
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else {
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

// function to sort a biotonic doubly linked list
struct Node* sort(struct Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	struct Node* current = head->next;

	while (current != NULL) {

		if (current->data < current->prev->data)
			break;

		current = current->next;
	}

	if (current == NULL)
		return head;

	current->prev->next = NULL;
	current->prev = NULL;

	reverse(current);

	return merge(head, current);
}

// Function to insert a node at the beginning
// of the Doubly Linked List
void push(struct Node** head_ref, int new_data)
{
	// allocate node
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	// put in the data
	new_node->data = new_data;

	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list of the new node
	new_node->next = (*head_ref);

	// change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// Function to print nodes in a given doubly
// linked list
void printList(struct Node* head)
{
	// if list is empty
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	struct Node* head = NULL;

	// Create the doubly linked list:
	// 2<->5<->7<->12<->10<->6<->4<->1
	push(&head, 1);
	push(&head, 4);
	push(&head, 6);
	push(&head, 10);
	push(&head, 12);
	push(&head, 7);
	push(&head, 5);
	push(&head, 2);

	cout << "Original Doubly linked list:\n";
	printList(head);

	// sort the biotonic DLL
	head = sort(head);

	cout << "\nDoubly linked list after sorting:\n";
	printList(head);

	return 0;
}
*/
/*
//Merge K sorted lists
//Simple aproach
TC O(n*k*k)  SC(1)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                res->next = list1;
                res = list1;
                list1 = list1->next;
            } else {
                res->next = list2;
                res = list2;
                list2 = list2->next;
            }
        }

        if (list1) {
            res->next = list1;
        } else {
            res->next = list2;
        }
        return dummyNode->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* res=nullptr;
        if (n == 0) {
            return res;
        }
        res=lists[0];
        if(n==1){
            return res;
        }
        
        for(int i=1; i<n; i++){
            res=merge(res, lists[i]);
        }

        return res;
    }
};
*/
/*
//Merge k sorted lists
//Optimal aproach
//TC O(n*k*logk)  SC(1)
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

Node* mergeKLists(Node* arr[], int last)
{
    // repeat until only one list is left
    while (last != 0) {
        int i = 0, j = last;

        // (i, j) forms a pair
        while (i < j) {
            // merge List i with List j and store
            // merged list in List i
            arr[i] = SortedMerge(arr[i], arr[j]);

            // consider next pair
            i++, j--;

            // If all pairs are merged, update last
            if (i >= j)
                last = j;
        }
    }

    return arr[0];
}

Node* newNode(int data)
{
    struct Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list

    // an array of pointers storing the head nodes
    // of the linked lists
    Node* arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // Merge all lists
    Node* head = mergeKLists(arr, k - 1);

    printList(head);

    return 0;
}
*/
/*
//mergeSort for linkedlist
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = nullptr; }
};

class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeBoth(Node* first, Node* second){
        Node* answer=nullptr;
        
        if(!first)
            return second;
        if(!second)
            return first;
            
        if(first->data<=second->data){
            answer=first;
            answer->next=mergeBoth(first->next, second);
        }
        else{
            answer=second;
            answer->next=mergeBoth(first, second->next);
        }
        
        return answer;
    }
    
    void findMiddle(Node* cur, Node** first, Node** second){
        Node* fast;
        Node* slow;
        slow=cur;
        fast=cur->next;
        
        while(fast!=nullptr){
            fast=fast->next;
            if(fast!=nullptr){
                slow=slow->next;
                fast=fast->next;
            }
        }
        
        *first=cur;
        *second=slow->next;
        slow->next=nullptr;
    }
    
    void mergeSorting(Node** head){
        Node* cur= *head;
        Node* first;
        Node* second;
        if(cur==nullptr || cur->next==nullptr){
            return;
        }
        
        findMiddle(cur, &first, &second);
        mergeSorting(&first);
        mergeSorting(&second);
        
        *head=mergeBoth(first, second);
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        mergeSorting(&head);
        return head;
    }
};
*/
/*
// C++ program for Quick Sort on Singly Linked List 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = nullptr;
    }
}

struct node* getTail(struct node* head){
    struct node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        temp=temp->next;
    }
    return temp;
}

struct node* partition(struct node* head, struct node* tail){
    struct node* pivot=head;
    struct node* cur=head->next;
    struct node* prev=head;
    
    while(cur!=tail->next){
        if(pivot->data > cur->data){
            swap(prev->next->data, cur->data);
            prev=prev->next;
        }
        cur=cur->next;
    }
    
    swap(pivot->data, prev->data);
    return prev;
}

void solveSort(struct node* head, struct node* tail){
    if(head==nullptr || tail==nullptr || head==tail){
        return;
    }
    
    struct node* pivot=partition(head, tail);
    
    solveSort(head, pivot);
    solveSort(pivot->next, tail);
}

void quickSort(struct node **headRef) {
    struct node* head=*headRef;
    if(head==nullptr || head->next==nullptr){
        return;
    }
    
    struct node* tail=getTail(head);
    
    solveSort(head, tail);
}
*/
/*
//Add numbers represent by linkedlists
//TC O(max(N, M))  SC O(max(N, M))
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);

        ListNode* res=nullptr;
        ListNode* cur=nullptr;
        ListNode* temp;
        int s=0, c=0;

        while(l1!=nullptr || l2!=nullptr){
            s=(l1?l1->val:0)+(l2?l2->val:0)+c;
            c=(s>=10)?1:0;
            s=s%10;
            temp=new ListNode(s);
            if(res==nullptr)res=temp;
            else cur->next=temp;
            cur=temp;

            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(c>0){
            temp=new ListNode(c);
            cur->next=temp;
            cur=temp;
        }
        //res=reverseList(res);
        return res;
    }
};
*/
/*
//Substract two numbers represented by two linkedlists
//TC O(max(N, M))  SC O(max(N, M))
#include<bits/stdc++.h>
using namespace std;

struct Node {
     int data;
     Node *next;
     Node() : data(0), next(nullptr) {}
     Node(int x) : data(x), next(nullptr) {}
     Node(int x, Node *next) : data(x), next(next) {}
 };

class Solution {
public:

    int getLength(Node* Node)
    {
        int size = 0;
        while (Node != nullptr) {
            Node = Node->next;
            size++;
        }
        return size;
    }
    
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode;
        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        while(head1 && head1->data==0){
            head1=head1->next;
        }
        while(head2 && head2->data==0){
            head2=head2->next;
        }
        
        int n1=getLength(head1);
        int n2=getLength(head2);
        
        Node* t1;
        Node* t2;
        
        if(n2>n1) swap(head1, head2);
        if(n1==n2){
            t1=head1;
            t2=head2;
            while(t1 && t2 && t1->data == t2->data){
                t1=t1->next;
                t2=t2->next;
            }
            if(!t1) return new Node(0);
            if(t2 && t2->data>t1->data) swap(head1, head2);
        }
        
        head1=reverseList(head1);
        head2=reverseList(head2);
        
        Node* res=nullptr;
        Node* n;
        t1=head1;
        t2=head2;
        
        while(t1){
            int small=0;
            if(t2) small=t2->data;
            
            if(small>t1->data){
                t1->next->data=t1->next->data-1;
                t1->data=t1->data+10;
            }
            
            n=new Node(t1->data - small);
            n->next=res;
            res=n;
            
            t1=t1->next;
            if(t2) t2=t2->next;
        }
        
        while(res->next && res->data==0){
            res=res->next;
        }
        
        return res;
    }
};
*/