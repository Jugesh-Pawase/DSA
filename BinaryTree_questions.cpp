/*
//Maximum depth of tree
//tc o(n)    sc o(n)
class Solution{
  public:
    int maxDepth(Node *root) {
        if(root == nullptr) return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};
*/
/*
//Level order traversal of binary tree
//tc o(n)    sc o(n)
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      vector<int> ans;
      queue<Node*>q;
      if(root==nullptr) return ans;
      q.push(root);
      while(!q.empty()){
          Node* node=q.front();
          q.pop();
          ans.push_back(node->data);
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
      }
      return ans;
    }
};
*/
/*
//Reverse level order traversal of binary tree
//tc o(n)    sc o(n)
vector<int> reverseLevelOrder(Node *root)
{
    // code here
      vector<int> ans;
      queue<Node*>q;
      if(root==nullptr) return ans;
      q.push(root);
      while(!q.empty()){
          Node* node=q.front();
          q.pop();
          ans.push_back(node->data);
          if(node->right) q.push(node->right);
          if(node->left) q.push(node->left);
      }
      reverse(ans.begin(),  ans.end());
      return ans;
}
*/
/*
//Check if tree is subTree of another tree
//Expected Time Complexity: O(N^2).
//Expected Auxiliary Space: O(N).
class Solution
{
  public:
    bool ans=false;
    bool match(Node* T, Node* S){
        if(T!=nullptr && S!=nullptr){
            bool a=match(T->left, S->left);
            bool b=match(T->right, S->right);
            if(T->data==S->data && a==true && b==true){
                return true;
            }
            else{
                return false;
            }
        }
        else if(T==nullptr && S==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    
    void inorder(Node* T, Node* S){
        if(T==nullptr) return;
        
        inorder(T->left, S);
        bool x=match(T, S);
        if(x==true){
            ans=x;
            return;
        }
        inorder(T->right, S);
    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        inorder(T, S);
        return ans;
    }
};
*/
/*
//Mirror of bainary tree
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the
class Solution {
  public:
    Node* postorder(Node* node){
        if(node==nullptr) return nullptr;   //void return; these will also work
        postorder(node->left);
        postorder(node->right);
        Node* temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        postorder(node);
    }
};
*/
/*
//Left view of binary tree
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the Tree).
void preorder(Node* root, int level, vector<int>&res){
    if(root==nullptr) return;
    if(level==res.size()){
        res.push_back(root->data);
    }
    preorder(root->left, level+1, res);
    preorder(root->right, level+1, res);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   preorder(root, 0, res);
   return res;
}
*/
/*
//Right view of binary tree
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the Tree).
class Solution
{
    public:
    void preorder(Node* root, int level, vector<int>&res){
        if(root==nullptr) return;
        if(level==res.size()){
            res.push_back(root->data);
        }
        preorder(root->right, level+1, res);
        preorder(root->left, level+1, res);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>res;
       preorder(root, 0, res);
       return res;
    }
};
*/
/*
//Zizag traversal of binary tree
//Expected Time Complexity: O(n).
//Expected Auxiliary Space: O(n).
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	queue<Node*>q;
    	bool bln=true;
    	if(root==nullptr) return ans;
    	q.push(root);
    	while(!q.empty()){
    	    int sz=q.size();
    	    vector<int>temp(sz);
    	    for(int i=0; i<sz; i++){
    	        Node* node=q.front();
    	        q.pop();
    	        if(bln){
    	            temp[i]=node->data;
    	        }
    	        else{
    	            temp[sz-1-i]=node->data;
    	        }
    	        if(node->left) q.push(node->left);
    	        if(node->right) q.push(node->right);
    	    }
    	    for(int i=0; i<sz; i++){
    	        ans.push_back(temp[i]);
    	    }
    	    bln=!bln;
    	}
    	return ans;
    }
};
*/
/*
//Leaves at same level or not
//Expected Time Complexity: O(n)
//Expected Auxiliary Space: O(height of tree)
class Solution{
  public:
    int ans;
    void solve(Node* root, int h, int &mxh){
        if(ans==0) return;
        if(!root->left && !root->right){
            if(mxh==-1){
                mxh=h;
            }
            else{
                if(mxh!=h){
                    ans=0;
                }
            }
            return;
        }
        solve(root->left, h+1, mxh);
        solve(root->right, h+1, mxh);
    }
    bool check(Node *root)
    {
        //Your code here
        int mxh=-1;
        int h=0;
        ans=1;
        solve(root, h, mxh);
        return ans;
    }
};
*/
/*
//Check tree is hieght balancwd or not
//Expected time complexity: O(N)
//Expected auxiliary space: O(h)
class Solution{
    public:
    int f=1;
    int solve(Node* root){
        if(!root) return 0;
        int lh=solve(root->left);
        int rh=solve(root->right);
        if(abs(lh-rh)>1)f=0;
        return 1+max(lh, rh);
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        solve(root);//imp
        return f;
    }
};
*/
/*
//Sum of subTrees
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(height of tree)
class Solution {
  public:
    int solve(Node* node){
        if(!node) return 0;
        int a=solve(node->left);
        int b=solve(node->right);
        int x=node->data;
        node->data=a+b;
        return x+a+b;
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};
*/
/*
//CDheck trees are isomorphic or not
//Expected Time Complexity: O(min(M, N));
//Expected Auxiliary Space: O(min(H1, H2))
class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->data != root2->data) return false;
    bool a=isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
    bool b=isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
    return a||b;
    }
};
*/
/*
//Check two trees are same or not
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the Tree).
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        return r1->data==r2->data && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
};
*/
/*
//Build tree from preordr and inorder traversal
//Expected Time Complexity: O(N*N).
//Expected Auxiliary Space: O(N).
class Solution{
    public:
    int idx=0;

    int search(int in[], int start, int end, int key){
        for(int i=start; i<=end; i++){
            if(in[i]==key){
                return i;
            }
        }
        return -1;
    }

    Node* solve(int in[], int pre[], int start, int end){
        if(start>end) return nullptr;
        Node* node=new Node(pre[idx]);
         if(start==end){
             idx++;
             return node;
         }
        int pos=search(in, start, end, pre[idx]);
        idx++;
        node->left=solve(in, pre, start, pos-1);
        node->right=solve(in, pre, pos+1, end);
        return node;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return solve(in, pre, 0, n-1);
    }
};
*/
/*
//Diameter of binary tree
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the Tree).
class Solution {
  public:
    int mxd=0;
    int solve(Node* root){
        if(!root) return 0;
        int lh=solve(root->left);
        int rh=solve(root->right);
        mxd=max(mxd, lh+rh);
        return 1+max(lh, rh);
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        solve(root);
        return mxd;
    }
};
*/
/*
//Top view of binary tree
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(N).
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root) return ans;
        map<int, int>mp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
            if(mp.find(line)==mp.end()){
                mp[line]=node->data;
            }
            if(node->left){
                q.push({node->left, line-1});
            }
            if(node->right){
                q.push({node->right, line+1});
            }
        }

        for(auto it:mp){
            ans.push_back(it.second);
        }

        return ans;
    }

};
*/
/*
//Bottom view of binary tree
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(N).
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root) return ans;
        map<int, int>mp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;

            mp[line]=node->data;

            if(node->left){
                q.push({node->left, line-1});
            }
            if(node->right){
                q.push({node->right, line+1});
            }
        }

        for(auto it:mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
*/
/*
//Diagonal traversal of tree
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(N).
vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   queue<Node*>q;
   if(!root) return ans;
   q.push(root);

   while(!q.empty()){
       Node* node=q.front();
       q.pop();
       while(node){
           ans.push_back(node->data);
           if(node->left) q.push(node->left);
           node=node->right;
       }
   }

   return ans;
}
*/
/*
//Boundary traversal of bainary tree
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the Tree).
class Solution {
public:
    bool isLeaf(Node* root){
        if(!root->left && !root->right){
            return true;
        }
        return false;
    }

    void addLeftBoundary(Node* root, vector<int> &ans){
        while(root){
            if(!isLeaf(root)) ans.push_back(root->data);
            if(root->left){
                root=root->left;
            } else{
                root=root->right;
            }
        }
    }

    void addRightBoundary(Node* root, vector<int> &ans){
        vector<int> temp;
        while(root){
            if(!isLeaf(root)) temp.push_back(root->data);
            if(root->right){
                root=root->right;
            } else{
                root=root->left;
            }
        }
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }

    void addLeafNodes(Node* root, vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) addLeafNodes(root->left, ans);
        if(root->right) addLeafNodes(root->right, ans);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(!root) return ans;

        if(!isLeaf(root)) ans.push_back(root->data);
        if(root->left) addLeftBoundary(root->left, ans);
        if(root) addLeafNodes(root, ans);
        if(root->right) addRightBoundary(root->right, ans);

        return ans;
    }
};
*/
/*
//function to construct tree from string
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(N)
class Solution{
public:
    int i=0;
    void solve(Node* root, string str){
        if(i<str.size() && isdigit(str[i])){
            int sum=0;
            while(i<str.size() && isdigit(str[i])){
                sum*=10;
                sum+=str[i]-'0';
                i++;
            }
            root->data=sum;
        }

        if(i<str.size() && str[i]=='('){
            root->left=new Node(0);
            i++;
            solve(root->left, str);
            if(root->left->data==0){
                root->left=nullptr;
            }
        }

        if(i<str.size() && str[i]=='('){
            root->right=new Node(0);
            i++;
            solve(root->right, str);
            if(root->right->data==0){
                root->right=nullptr;
            }
        }

        if(i>=str.size() || str[i]==')'){
            i++;
            return;
        }
    }
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        Node* root=new Node(0);
        solve(root, str);
        return root;
    }
};
*/
/*
//Minimum swap required to convert binary tree to binary search tree
//Expected Time Complexity: O(NlogN)
//Expected Auxiliary Space: O(N)
class Solution{
  public:
    void inorder(vector<int>&A, vector<int> &v, int n, int index)
{
	if(index >= n)
		return;
	inorder(A, v, n, 2 * index + 1);

	v.push_back(A[index]);
	inorder(A, v, n, 2 * index + 2);
}

int minSwaps(vector<int> &v)
{
	vector<pair<int,int> > t(v.size());
	int ans = 0;
	for(int i = 0; i < v.size(); i++){
		t[i].first = v[i], t[i].second = i;
	}

	sort(t.begin(), t.end());
	for(int i = 0; i < t.size(); i++)
	{
		// second element is equal to i
		if(i == t[i].second)
			continue;
		else
		{
			// swapping of elements
			swap(t[i].first, t[t[i].second].first);
			swap(t[i].second, t[t[i].second].second);
		}

		// Second is not equal to i
		if(i != t[i].second){
			--i;
		}
		ans++;
	}
	return ans;
}
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        vector<int> v;
        inorder(A, v, n, 0);
	    return minSwaps(v);
    }


};
*/
/*
//To check duplicate subtree
//Expected Time Complexity: O(N)
//Expected Space Complexity: O(N)
class Solution {
  public:
    unordered_map<string, int>mp;
    string solve(Node* root){
        if(!root){
            return "$";
        }

        if(!root->left && !root->right){
            string s = to_string(root->data);
            return s;
        }

        string s = to_string(root->data) + "," + solve(root->left) + "," + solve(root->right);
        mp[s]++;

        return s;
    }
    int dupSub(Node *root) {
         // code here
         mp.clear();
         solve(root);
         for(auto x:mp){
             if(x.second >= 2){
                 return 1;
             }
         }
         return 0;
    }
};
*/
/*
//Check if graph is tree or not
//Expected Time Complexity: O(N+M)
//Expected Auxiliary Space: O(N)
class{
  public:
    bool isCycle(int src, int prt, vector<vector<int>> &adjecent, vector<bool>&vis){
        vis[src]=true;
        for(auto i:adjecent[src]){
            if(!vis[i]){
                if(isCycle(i, src, adjecent, vis)) return true;
            }
            else if(i!=prt) return true;
        }
        return false;
    }

    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        // Creating adjacency list from the edge list
        vector<vector<int>> adjecent(n);
        for(int i = 0; i < m; i++) {
            int u = adj[i][0];
            int v = adj[i][1];
            adjecent[u].push_back(v);
            adjecent[v].push_back(u);
        }
        vector<bool> vis(n, false);

        if(isCycle(0, -1, adjecent, vis)) return false;

        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }

        return true;
    }
};
*/
/*
//Lowest common ancestor
//Expected Time Complexity:O(N).
//Expected Auxiliary Space:O(Height of Tree).
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
       if(root==nullptr || root->data==n1 || root->data==n2){
           return root;
       }

       root->left=lca(root->left, n1, n2);
       root->right=lca(root->right, n1, n2);

       if(root->left==nullptr){
           return root->right;
       }
       else if(root->right==nullptr){
           return root->left;
       }
       else{
           return root;
       }
    }
};
*/
/*
//Minimum distance between two nodes
//Expected Time Complexity: O(n).
//Expected Auxiliary Space: O(Height of the Tree).
class Solution{
    public:
    int minDist=0;

    int solve(Node* root, int a, int b){
        if(!root) return 0;

        int left=solve(root->left, a, b);
        int right=solve(root->right, a, b);

        if(left && right){     //LCA
            minDist=left + right;
            return 0;
        }
        else if(root->data==a || root->data==b){ // node is a or b
            if(left || right){
                minDist=max(left, right);
                return 0;
            }
            else{
                return 1;
            }
        }
        else if(left || right){   //node is between a & b
            return max(left, right)+1;
        }
        else{  //node is neither between a & b
            return 0;
        }
    }
    // Should return minimum distance between a and b in a tree with given root
    int findDist(Node* root, int a, int b) {
        // Your code here
        solve(root, a, b);
        return minDist;
    }
};
*/
/*
//Kth Ancestor
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(N)
int ans;
int solve(Node* root, int k, int node){
    if(!root) return 0;
    if (root->data == node) {
        return 1;  // Found the target node
    }

    int left=solve(root->left, k, node);
    int right=solve(root->right, k, node);

    if (left || right) {
        int distance = max(left, right);
        if (distance == k) {
            ans = root->data;  // Found the k-th ancestor
            return 0;  // Stop further exploration
        }
        return distance + 1;  // Continue moving up the tree
    }

    return 0;  // Node not found in this path
}
// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    ans=-1;      //important chanege take whole day
    solve(root, k, node);
    return ans;
}
*/
/*
//Maximum width of binary tree   gfg-easy
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Width of the tree).
class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        if(!root) return 0;
        int ans=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            ans=max(ans, sz);
            for(int i=0; i<sz; i++){
                Node* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
*/
/*
//Maximum Width   leetcode-medium
//tc O(n)  sc O(Width of the tree).
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // Your code here
        if (!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int sz = q.size();
            unsigned long long min = q.front().second;
            unsigned long long first, last;
            for (int i = 0; i < sz; i++) {
                unsigned long long curId = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0)
                    first = curId;
                if (i == sz - 1)
                    last = curId;
                if (node->left) {
                    q.push({node->left, 2 * curId + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * curId + 2});
                }
            }
            ans = max(ans, int(last - first + 1));
        }
        return ans;
    }
};
*/
/*
//Maximum sum path
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the Tree).
class Solution {
  public:
    int ans=INT_MIN;
    int solve(Node* root){
        if(!root) return 0;

        int left=max(0, solve(root->left));
        int right=max(0, solve(root->right));

        ans=max(ans, root->data+left+right);

        return root->data+max(left, right);
    }
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        // Your code goes here
        solve(root);
        return ans;
    }
};
*/
