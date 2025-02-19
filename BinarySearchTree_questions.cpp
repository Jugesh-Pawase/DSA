/*
//Lowest common ancestor in BST
//Expected Time Complexity: O(Height of the BST).
//Expected Auxiliary Space: O(Height of the BST). we can reduce auxilury space by using while loop so SC(1).
class Solution{
  public:
    Node* LCA(Node *root, int n1, int n2)
        {
            // code here
       if(root==nullptr){
           return root;
       }

       int curr=root->data;

       if(curr<n1 && curr<n2){
           return LCA(root->right, n1, n2);
       }
       if(curr>n1 && curr>n2){
           return LCA(root->left, n1, n2);
       }

       return root;
    }
};
*/
/*
//Search in binary search tree
//Expected Time Complexity: O(Height of the BST)
//Expected Auxiliary Space: O(1).
bool search(Node* root, int x) {
    // Your code here
    while(root){
        if(root->data==x)return true;
        if(root->data<x){
            root=root->right;
        }else{
            root=root->left;
        }
    }
    return false;
}
*/
/*
//minimum element in bst
//Expected Time Complexity: O(Height of the BST)
//Expected Auxiliary Space: O(1).
class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        if(!root) return -1;
        while(root->left) root=root->left;
        return root->data;
    }
};
*/
/*
//predecor and successor of given node
//Expected Time Complexity: O(Height of the BST).
//Expected Auxiliary Space: O(Height of the BST).
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        Node* node=root;
        while(root){      //successor
            if(root->key<=key){
                root=root->right;
            }
            else{
                suc=root;
                root=root->left;
            }
        }
        
        while(node){      //predecor
            if(node->key>=key){
                node=node->left;
            }
            else{
                pre=node;
                node=node->right;
            }
        }
    }
};
*/
/*
//Check for dead end
//Expected Time Complexity: O(N), where N is the number of nodes in the BST.
//Expected Space Complexity: O(N) due to recursion
class Solution{
  public:
    bool solve(Node* root, int min, int max){
        if(!root) return false;
        if(min==max) return true;
        return solve(root->left, min, root->data-1) || solve(root->right, root->data+1, max);                   
    }
  
    bool isDeadEnd(Node *root)
    {
        //Your code here
        return solve(root, 1, INT_MAX);
    }
};
*/
/*
//Convert binary tree to BST
//Expected Time Complexity: O(NLogN).
//Expected Auxiliary Space: O(N).
class Solution{
  public:
    void inorder_binaryTree(Node* root, vector<int> &v){
        if(!root) return;
        inorder_binaryTree(root->left, v);
        v.push_back(root->data);
        inorder_binaryTree(root->right, v);
    }
    
    void inorder_bst(Node* root, vector<int> &v, int &i){
        if(!root) return;
        inorder_bst(root->left, v, i);
        root->data=v[i];
        i++;
        inorder_bst(root->right, v, i);
    }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int>v;
        inorder_binaryTree(root, v);
        sort(v.begin(), v.end());
        int i=0;
        inorder_bst(root, v, i);
        return root;
    }
};
*/
/*
//Kth largest element in BST
//Brut force
//tc O(n) sc O(n)
class Solution
{
    public:
    void solve(Node* root, vector<int> &v, int &i){
        if(!root) return;
        solve(root->left, v, i);
        v.push_back(root->data);
        i++;
        solve(root->right, v, i);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int>v;
        int i=0;
        solve(root, v, i);
        int n=v.size();
        return v[n-K];
    }
};
*/
/*
//Kth largest element in BST
//tc O(N) sc O(H)
class Solution
{
    public:
    int ans;
    void solve(Node* root, int &i, int K){
        if(!root) return;
        solve(root->right, i, K);
        if(i==K){
            ans=root->data;
            i++;
            return;
        }else{
            i++;
        }
        solve(root->left, i, K);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        ans=-1;
        int i=1;
        solve(root, i, K);
        return ans;
    }
};
*/
/*
//Check tree is valid BST or not
//tc O(n). sc O(n)

class Solution {
  public:
  void solve(Node* root, vector<int>&v){
      if(!root) return;
      solve(root->left, v);
      v.push_back(root->data);
      solve(root->right, v);
  }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        vector<int>v;
        solve(root, v);
        int n=v.size();
        for(int i=1; i<n; i++){
            if(v[i]<=v[i-1]){
                return false;
            }
        }
        return true;
    }
};
*/
/*
//Check tree is valid BST or not
//tc O(n). sc O(1)

class Solution {
  public:
   bool solve(Node* root, int min, int max){
       if(!root) return true;
       if(root->data<=min || root->data>=max){
           return false;
       }
       return solve(root->left, min, root->data) && solve(root->right, root->data, max);               
   }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        return solve(root, INT_MIN, INT_MAX);
    }
};
*/
/*
//Kth smallest element in BST
//TC O(N).   SC O(1)

class Solution {
  public:
    int ans;
    void solve(Node* root, int K, int &i){
        if(!root) return;
        solve(root->left, K, i);
        if(i==K){
            ans=root->data;
            i++;
            return;
        }else{
            i++;
        }
        solve(root->right, K, i);
    }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        ans = -1;
        int i=1;
        solve(root, K, i);
        return ans;
    }
};
*/
/*
//Delete node from BST
//TC O(H)    SC O(1)
Node* findLastRight(Node* root){
    if(root->right==nullptr){
        return root;
    }
    return findLastRight(root->right);
}

Node* helper(Node* root){
    if(root->left==nullptr){
        return root->right;
    }
    if(root->right==nullptr){
        return root->left;
    }
    Node* rightChild=root->right;
    Node* lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(!root) return root;
    if(root->data==X){
        return helper(root);
    }
    Node* dummy=root;
    while(!root){
        if(root->data>X){
            if(root->left!=nullptr && root->left->data==X){
                root->left=helper(root->left);
            }else{
                root=root->left;
            }
        }else{
            if(root->right!=nullptr && root->right->data==X){
                root->right=helper(root->right);
            }else{
                root=root->right;
            }
        }
    }
    return dummy;
}
*/
/*
//Flater a BST into sorted list
//TC O(n)   SC O(1)
class Solution
{
public:
    void inorder(Node* curr, Node* &prev){
        if(!curr) return;
        inorder(curr->left, prev);
        prev->left=nullptr;
        prev->right=curr;
        prev=curr;
        inorder(curr->right, prev);
    };

    Node *flattenBST(Node *root)
    {
        // code here
        Node* dummy=new Node(-1);
        Node* prev=dummy;
     
        inorder(root, prev);   
        prev->left=nullptr;
        prev->right=nullptr;
        
        Node* res = dummy->right;
        return res;
    }
};
*/
/*
//Construct tree from preorder traversal
//TC O(N)    SC O(1)
class Solution {
  public:
    Node* solve(int pre[], int size, int &i, int bound){
        if(i>=size || pre[i]>bound){
            return nullptr;
        }
        Node* node = newNode(pre[i++]);
        node->left=solve(pre, size, i, node->data);  //leftChild
        node->right=solve(pre, size, i, bound);       //rightChilld
        return node;
    }
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        int i=0;
        return solve(pre, size, i, INT_MAX);
    }
};
*/
/*
//Count BST nodes that lies in given range
//Brut force
//TC O(N).   SC O(1)

class Solution{
public:
    int ans;
    void solve(Node* root, int l, int h){
        if(!root) return;
        solve(root->left, l, h);
        if(root->data>=l && root->data<=h){
            ans++;
        }
        solve(root->right, l, h);
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here
      ans=0;
      solve(root, l, h);
      return ans;
    }
};
*/
/*
//Count BST nodes that lies in given range
//optimal aproach
//TC O(N).   SC O(1)

class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here  
      if(!root) return 0;
      
      if(root->data>=l && root->data<=h){
          return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
      }
      else if(root->data<l){
          return getCount(root->right, l, h);
      }
      else{
          return getCount(root->left, l, h);
      }
    }
};
*/
/*
//Populate Next pointer of node in BST to inorder successor
//Expected Time Complexity: O(n)
//Expected Auxiliary Space: O(logn)
class Solution {
  public:
    void inorder(Node* root, Node* &prev){
        if(!root) return;
        
        inorder(root->left, prev);
        
        if(prev!=nullptr){
            prev->next=root;
        }
        prev=root;
        
        inorder(root->right, prev);
    }

    void populateNext(Node *root) {
        // code here
         Node* prev=nullptr;
         inorder(root, prev);
    }
};
*/
/*
//Convert normal BST to balanced BST
//Expected Time Complexity: O(n)
//Expected Auxiliary Space: O(n)
class Solution{
    
    public:
    void inorder(Node* root, vector<Node*> &v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    
    Node* solve(vector<Node*> &v, int start, int end){
        if(start>end) return nullptr;
        
        int mid=(start+end)/2;
        Node* node=v[mid];
        
        node->left=solve(v, start, mid-1);
        node->right=solve(v, mid+1, end);
        
        return node;
    }
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	vector<Node*> v;
    	inorder(root, v);
    	int n=v.size();
    	
    	return solve(v, 0, n-1);
    }
};
*/
/*
//Merge two BST's
//Expected Time Complexity: O(m+n)
//Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)
class Solution {
  public:
    void inorder(Node* root, vector<int> &v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    void mergeTrees(vector<int> &v, vector<int>&v1, vector<int> &v2, int &i, int &j){
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j]){
                v.push_back(v1[i]);
                i++;
            }else{
                v.push_back(v2[j]);
                j++;
            }
        }
        
        while(i<v1.size()){
            v.push_back(v1[i]);
            i++;
        }
        
        while(j<v2.size()){
            v.push_back(v2[j]);
            j++;
        }
    }  
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> v1;
        vector<int> v2;
    	inorder(root1, v1);
    	inorder(root2, v2);
    	
    	vector<int>v;
    	int i=0,j=0;
    	mergeTrees(v, v1, v2, i, j);
    	
    	return v;
    }
};
*/