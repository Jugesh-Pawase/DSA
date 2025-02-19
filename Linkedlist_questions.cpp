/*
//Reverse linkedlist
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

/*
//Merge two sorted lists
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }

        ListNode* result;
        if(list1->val<list2->val){
            result=list1;
            result->next=mergeTwoLists(list1->next, list2);
        }
        else{
            result=list2;
            result->next=mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};

/*
//Remove node without head referemce
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(Node* head)
{
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void deleteNode(Node* node)
{
	//Node* prev;
	if (node == nullptr)
		return;
	else {
		Node* temp = node->next;
		node->data = temp->data;
		node->next = temp->next;
		temp = nullptr;
	}
}

int main()
{
	Node* head = nullptr;

	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	push(&head, 12);
	push(&head, 1);

	cout << "Before deleting \n";
	printList(head);

	// I m deleting the head itself. 
	// 	You can check for more cases
	deleteNode(head);

	cout << "\nAfter deleting \n";
	printList(head);
	return 0;
}

/*
//Remove duplicates from unsorted list
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*
//remove duplicates from unsorted linked list.
class Solution
{
    public:
    Node * removeDuplicates( Node *head)
    {
     // your code goes here
     map<int, int>mp;
     Node* cur=head;
     mp[cur->data]=1;
     Node* prev=cur;
     cur=cur->next;
     while(cur->next != nullptr){
         if (head==nullptr || head->next==nullptr) {
            return head;
         }
         if(mp[cur->data]){
             prev->next=cur->next;
             delete cur;
         }
         else{
             mp[cur->data]=1;
             prev=cur;
         }
         cur=prev->next;
     }
     return head;
    }
};

int main() {
    // your code goes here
    int T;
    cin>>T;

    while(T--)
    {
        int K;
        cin>>K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for(int i=0;i<K;i++){
        int data;
        cin>>data;
            if(head==NULL)
            head=temp=new Node(data);
            else
            {
                temp->next = new Node(data);
                temp=temp->next;
            }
        }

        Solution ob;
        Node *result  = ob.removeDuplicates(head);
        print(result);
        cout<<endl;

    }
    return 0;
}
/*
//sort a linked list 0s, 1s or 2s
//Brut force aproach
// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Auxiliary Space: O(1)
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

// Function to sort a linked list of 0s, 1s and 2s
void sortList(Node *head)
{
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0
    Node *ptr = head;

    while (ptr nullptr)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }

    int i = 0;
    ptr = head;

    while (ptr nullptr)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}

void push (Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main(void)
{
    Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);

    cout << "Linked List before Sorting\n";
    printList(head);

    sortList(head);

    cout << "Linked List after Sorting\n";
    printList(head);

    return 0;
}
/*
//Remove nth node from end
//Brut force aproach
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
        ListNode *temp=head;
        int size=0;
        while(temp!=nullptr){
            size+=1;
            temp=temp->next;
        }
        if(size==n){
            ListNode *todelete=head;
            ListNode *temp=head->next;
            delete head;
            return temp;
        }
        int cnt = 1;
        temp=head;
        while(cnt < (size-n)){
            cnt+=1;
            temp=temp->next;
        }
        ListNode *todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
        return head;
    }
};
*/
/*
//Remove nth node from end
//Optimal aproach
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
*/
/**
//Reorder lists
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* first = head;
        ListNode* second = reverse(slow->next);
        slow->next = nullptr;

        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            first = temp1;
            second->next = first;
            second = temp2;
        }
    }
};
*/
/*
//Remove loop in linkedlist
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
      
      Node(int x) {
        data = x;
          next = NULL;
    }
};

void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void detectAndRemoveLoop(Node* head)
{
    // If list is empty or has only one node without loop
    if (head == NULL || head->next == NULL)
        return;

    Node *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == fast) {
        slow = head;

        // this check is needed when slow and fast both meet
        // at the head of the LL eg: 1->2->3->4->5 and then
        // 5->next = 1 i.e the head of the LL
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        fast->next = NULL; 
    }
}

int main()
{
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);

    head->next->next->next->next->next = head;

    detectAndRemoveLoop(head);

    printf("Linked List after removing loop \n");
    printList(head);

    return 0;
}
*/
/*
//Intersection point in two Y shaped linkedlists
//there are two brut force aproaches
//Optimal aproach
//TC O(N+M)   SC O(1)
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==nullptr && temp2==nullptr){
            return -1;
        }
        if(temp1==temp2){
            return temp1->data;
        }
        if(temp1==nullptr){
            temp1=head2;
        }
        if(temp2==nullptr){
            temp2=head1;
        }
    }
    return temp1->data;
}
*/
//Flatten linkedlist
/*
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

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
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
//Optimal aproach
//TC O(n)   SC O(1)
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void zigZagList(Node* head)
{
	bool flag = true;

	Node* current = head;
	while (current->next != NULL) {
		if (flag) 
		{
			if (current->data > current->next->data)
				swap(current->data, current->next->data);
		}
		else
		{
			if (current->data < current->next->data)
				swap(current->data, current->next->data);
		}

		current = current->next;
		flag = !flag;
	}
}

void push(Node** head_ref, int new_data)
{
	struct Node* new_Node = new Node;

	new_Node->data = new_data;

	new_Node->next = (*head_ref);

	(*head_ref) = new_Node;
}

void printList(struct Node* Node)
{
	while (Node != NULL) {
		printf("%d->", Node->data);
		Node = Node->next;
	}
	printf("NULL");
}

int main(void)
{
	struct Node* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 6);
	push(&head, 8);
	push(&head, 7);
	push(&head, 3);
	push(&head, 4);

	printf("Given linked list \n");
	printList(head);

	zigZagList(head);

	printf("\nZig Zag Linked list \n");
	printList(head);

	return (0);
}
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

class Solution
{
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

    Node *compute(Node *head)
    {
        // your code goes here
        head=reverseList(head);

        Node* cur=head;
        int max=head->data;
        Node* prev=head;
        head=head->next;

        while(head){
            if(head->data>=max){
                max=head->data;
                prev=head;
                head=head->next;
            }
            else{
                prev->next=head->next;
                head=prev->next;
            }
        }

        head=reverseList(cur);

        return head;
    }

};
*/
/*
//Sagrigate even odd elements in linkedlist
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* even=nullptr;
        Node* odd=nullptr;
        Node* e=nullptr;
        Node* o=nullptr;
        
        while(head){
            if(head->data%2==0){
                if(even==nullptr){
                    even=head;
                    e=head;
                }
                else{
                    e->next=head;
                    e=e->next;
                }
            }
            else{
                if(odd==nullptr){
                    odd=head;
                    o=head;
                }
                else{
                    o->next=head;
                    o=o->next;
                }
            }
            head=head->next;
        }
        
        if(even){
            e->next=odd;
        }
        if(odd){
            o->next=nullptr;
        }
        if(even){
            return even;
        }
        return odd;
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