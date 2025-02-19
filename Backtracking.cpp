
/*
//Rat in maxe
void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[]){
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }
    
    string dlru="DLRU";
    for(int ind=0; ind<4; ind++){ 
        int nexti=i+di[ind];
        int nextj=j+dj[ind];
        if(nexti>=0 && nexti<n && nextj<n && nextj>=0 && m[nexti][nextj]==1 && vis[nexti][nextj]==0){
            vis[i][j]=1;
            solve(nexti, nextj, m, n, ans, move+dlru[ind], vis, di, dj);
            vis[i][j]=0;
        }
        
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<vector<int>> vis(n, vector<int> (n, 0));
    vector<string> ans;
    int di[4]={1, 0, 0, -1};
    int dj[4]={0, -1, 1, 0};
    
    if(m[0][0]==1) solve(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
}
*/
/*
//Cmbination sum
//TC O(2^t * k)  SC O(k*x)
void findCombinationSum(int ind, int target, vector<int> &A, vector<vector<int>> &ans, vector<int> &ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(ind == A.size()){
            return;
        }
    
    //pick up the value
    if(A[ind]<=target){
        ds.push_back(A[ind]);
        findCombinationSum(ind, target-A[ind], A, ans, ds);
        ds.pop_back();
    }
    //do not pick up the value
    findCombinationSum(ind+1, target, A, ans, ds);
}

//Function to return a list of indexes denoting the required 
//combinations whose sum is equal to given number.
vector<vector<int> > combinationSum(vector<int> &A, int B) {
    // Your code here
    vector<int>ds;
    vector<vector<int>>ans;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    
    findCombinationSum(0, B, A, ans, ds);
    return ans;
}
*/
/*
//Longest Possible Route in a Matrix with Hurdles
//Expected Time Complexity: O(2^(N*M))
//Expected Auxiliary Space: O(N*M)
void solve(int r, int c, vector<vector<int>> &matrix, int &ans, vector<vector<int>> &vis, int xs, int ys, int xd, int yd, int path){
    if(xs==xd && ys==yd){
        if(ans<path){
            ans=path;
            return;
        }
        return;
    }
    
    if(xs<0 || xs>=r || ys<0 || ys>=c || vis[xs][ys]==1 || matrix[xs][ys]==0) return;
    
    vis[xs][ys]=1;
    solve(r, c, matrix, ans, vis, xs+1, ys, xd, yd, path+1);
    solve(r, c, matrix, ans, vis, xs, ys-1, xd, yd, path+1);
    solve(r, c, matrix, ans, vis, xs, ys+1, xd, yd, path+1);
    solve(r, c, matrix, ans, vis, xs-1, ys, xd, yd, path+1);
    vis[xs][ys]=0;
    return;
}

int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
{
    // code here
    int r=matrix.size();
    int c=matrix[0].size();
    vector<vector<int>>vis(r, vector<int>(c, 0));
    int ans=-1, path=0;
    
    if(matrix[xs][ys]==0 || matrix[xd][yd]==0){
        return -1;
    }
    else{
        solve(r, c, matrix, ans, vis, xs, ys, xd, yd, path);
    }
    
    return ans;
}
*/
/*
//n Queen's
//brut force aproach
//Expected Time Complexity: O(n!)  //into while loops
//Expected Auxiliary Space: O(n2) 
bool isSafe(int row, int col, vector<string> &board, int n){
    int duprow=row;
    int dupcol=col;
    
    //upper diagonal
    while(duprow>=0 && dupcol>=0){
        if(board[duprow][dupcol]=='Q'){
            return false;
        }
        duprow--;
        dupcol--;
    }
    
    duprow=row;
    dupcol=col;
    //left
    while(duprow>=0 && dupcol>=0){
        if(board[duprow][dupcol]=='Q'){
            return false;
        }
        dupcol--;
    }
    
    duprow=row;
    dupcol=col;
    //lower diagonal
    while(duprow<n && dupcol>=0){
        if(board[duprow][dupcol]=='Q'){
            return false;
        }
        duprow++;
        dupcol--;
    }
    
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    
    for(row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col]='Q';
            solve(col+1, board, ans, n);
            board[row][col]='.';
        }
    }
}

vector<vector<int>> nQueen(int n) {
    // code here
    vector<vector<string>> ans;
    vector<string> board;
    string s(n, '.');
    for(int i=0; i<n; i++){
        board.push_back(s);
    }
    
    solve(0, board, ans, n);
    
    return ans;
}
*/
/*
//n Queen's
//brut force aproach
//Expected Time Complexity: O(n!)  //into while loops
//Expected Auxiliary Space: O(n^2) 
bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int duprow=row;
    int dupcol=col;
    
    //upper diagonal
    while(duprow>=0 && dupcol>=0){
        if(board[duprow][dupcol]==1){
            return false;
        }
        duprow--;
        dupcol--;
    }
    
    duprow=row;
    dupcol=col;
    //left
    while(duprow>=0 && dupcol>=0){
        if(board[duprow][dupcol]==1){
            return false;
        }
        dupcol--;
    }
    
    duprow=row;
    dupcol=col;
    //lower diagonal
    while(duprow<n && dupcol>=0){
        if(board[duprow][dupcol]==1){
            return false;
        }
        duprow++;
        dupcol--;
    }
    
    return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, vector<int> &temp, int n){
    if(col==n){
        ans.push_back(temp);
        return;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            temp[col]=row+1;
            board[row][col]=1;
            solve(col+1, board, ans, temp, n);
            board[row][col]=0;
        }
    }
}

vector<vector<int>> nQueen(int n) {
    // code here
    vector<int>temp(n);
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    solve(0, board, ans, temp, n);
    
    return ans;
}
*/
/*
//n Queen's
//Optimal aproach
//Expected Time Complexity: O(n!)//factorial
//Expected Auxiliary Space: O(n^2) 
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, vector<int> &temp, int n,
    vector<int> &leftrow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal){
    
    if(col==n){
        ans.push_back(temp);
        return;
    }
    
    for(int row=0; row<n; row++){
        if(board[row][col]==0 && leftrow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
            temp[col]=row+1;
            board[row][col]=1;
            leftrow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+col-row]=1;
            solve(col+1, board, ans, temp, n, leftrow, lowerDiagonal, upperDiagonal);
            board[row][col]=0;
            leftrow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+col-row]=0;
        }
    }
}

vector<vector<int>> nQueen(int n) {
    // code here
    vector<int>temp(n);
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    vector<int>leftrow(n, 0);
    vector<int> lowerDiagonal(2*n-1, 0);
    vector<int> upperDiagonal(2*n-1, 0);
    
    solve(0, board, ans, temp, n, leftrow, lowerDiagonal, upperDiagonal);
    
    return ans;
}
*/
/*
//Sudoku Solver
//Expected Time Complexity: O(9N*N).
//Expected Auxiliary Space: O(N*N).
bool isValid(int grid[N][N], int row, int col, int c){
    for(int i=0; i<9; i++){
        //Check colunm
        if(grid[row][i]==c) return false;
        
        //Check row
        if(grid[i][col]==c) return false;
        
        // Check sub box of grid 
        if(grid[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c) return false;
    }
    
    return true;
}

bool solve(int grid[N][N]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(grid[i][j]==0){
                for(int c=1; c<=9; c++){
                    if(isValid(grid, i, j, c)){
                        grid[i][j]=c;
                        if(solve(grid)==true){
                            return true;
                        }
                            grid[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

//Function to find a solved Sudoku. 
bool SolveSudoku(int grid[N][N])  
{ 
    // Your code here
    solve(grid);
}

//Function to print grids of the Sudoku.
void printGrid (int grid[N][N]) 
{
    // Your code here 
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<grid[i][j]<<" ";
        }
    }
}
*/
/*
//Partition equal subsets
//Brutforce aproach
//exponential time complexity
bool solve(int ind, int arr[], int target){
    if(target==0) return true;
    
    if(ind==0) return (arr[ind]==target);
    
    bool notTake=solve(ind-1, arr, target);
    bool take=false;
    if(arr[ind]<=target) take=(ind-1, arr, target-arr[ind]);
    
    return take || notTake;
}

int equalPartition(int N, int arr[])
{
    // code here
    int sum=0;
    for(int i=0; i<N; i++){
        sum+=arr[i];
    }
    if(sum % 2) return false;
    int target=sum/2;
    
    if(solve(N-1, arr, target)){
        return 1;
    }
    else{
        return 0;
    }
}
*/
/*
//Partition equal subsets
//Brutforce aproach
//Memoization
//exponential time complexity
bool solve(int ind, int arr[], int target, vector<vector<int>> dp){
    if(target==0) return true;
    
    if(ind==0) return (arr[ind]==target);
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool notTake=solve(ind-1, arr, target, dp);
    bool take=false;
    if(arr[ind]<=target) take=solve(ind-1, arr, target-arr[ind], dp);
    
    return dp[ind][target] = take || notTake;
}

int equalPartition(int N, int arr[])
{
    // code here
    int sum=0;
    for(int i=0; i<N; i++){
        sum+=arr[i];
    }
    if(sum % 2) return false;
    int target=sum/2;
    vector<vector<int>> dp(N, vector<int> (target+1, -1));
    
    if(solve(N-1, arr, target, dp)){
        return 1;
    }
    else{
        return 0;
    }
}
*/
/*
//Partition equal subsets
//Optimal aproach
//Tabulation
//Expected Time Complexity: O(N*sum of elements)
//Expected Auxiliary Space: O(N*sum of elements)
int equalPartition(int N, int arr[])
{
    // code here
    int sum=0;
    for(int i=0; i<N; i++){
        sum+=arr[i];
    }
    if(sum % 2) return 0;
    int target=sum/2;
    vector<vector<int>> dp(N, vector<int> (target+1, 0));
    
    for(int i=0; i<N; i++){
        dp[i][0]=1;
    }
    if(arr[0]<=target){
        dp[0][arr[0]]=1;
    }
    
    for(int ind=1; ind<N; ind++){
        for(int k=1; k<=target; k++){
            bool notTake=dp[ind-1][k];
            bool take=false;
            if(arr[ind]<=k) {
                take=dp[ind-1][k-arr[ind]];
            }
            dp[ind][k]=take | notTake;
        }
    }
    
    return dp[N-1][target];
}
*/
/*
//Partition equal subsets
//Optimal aproach
//Tabulation plus space optimization
//Expected Time Complexity: O(N*sum of elements)
//Expected Auxiliary Space: O(sum of elements)
int equalPartition(int N, int arr[])
{
    // code here
    int sum=0;
    for(int i=0; i<N; i++){
        sum+=arr[i];
    }
    if(sum % 2) return 0;
    int target=sum/2;
    vector<int>prev(target+1, 0), cur(target+1, 0);
    
        prev[0]=cur[0]=1;
        prev[arr[0]]=1;
    
    for(int ind=1; ind<N; ind++){
        for(int k=1; k<=target; k++){
            bool notTake=prev[k];
            bool take=false;
            if(arr[ind]<=k) {
                take=prev[k-arr[ind]];
            }
            cur[k]=take | notTake;
        }
        prev=cur;
    }
    
    return prev[target];
}
*/
/*
//M-Coloring Problem
//Expected Time Complexity: O(M^N).
//Expected Auxiliary Space: O(N).
bool isSafe(int node, bool graph[101][101], int color[], int n, int clr){
    for(int i=0; i<n; i++){
        if(i!=node && graph[i][node]==1 && color[i]==clr){
            return false;
        }
    }
    return true;
}

bool solve(int node, bool graph[101][101], int color[], int m, int n){
    if(node==n){
        return true;
    }
    
    for(int i=1; i<=m; i++){
        if(isSafe(node, graph, color, n, i)){
            color[node]=i;
            if(solve(node+1, graph, color, m, n)){
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    int color[n]={0};
    
    if(solve(0, graph, color, m, n)) return true;
    return false;
}
*/
/*
//Kinght tour
//brut force
//time limit excid
bool solve(int i, int j, int cnt, vector<vector<int>>& mat, vector<vector<int>>& grid, int n){
    if(i<0 || j<0 || i>=n || j>=n || mat[i][j]!=-1) return false;

    if(cnt==n*n-1){
        mat[i][j]=cnt;
        if(mat==grid){
            return true;
        }
        mat[i][j]=-1;
        return false;
    }
    
    mat[i][j]=cnt;
    if(solve(i-2, j+1, cnt+1, mat, grid, n)) return true;
    if(solve(i-2, j-1, cnt+1, mat, grid, n)) return true;
    if(solve(i+2, j+1, cnt+1, mat, grid, n)) return true;
    if(solve(i+2, j-1, cnt+1, mat, grid, n)) return true;
    if(solve(i-1, j+2, cnt+1, mat, grid, n)) return true;
    if(solve(i-1, j-2, cnt+1, mat, grid, n)) return true;
    if(solve(i+1, j+2, cnt+1, mat, grid, n)) return true;
    if(solve(i+1, j-2, cnt+1, mat, grid, n)) return true;
    mat[i][j]=-1;

    return false;
}

bool checkValidGrid(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>> mat(n, vector<int>(n, -1));

    return solve(0, 0, 0, mat, grid, n);   
}
*/
/*
//Kinght tour
//brut force //same as above
//time limit excid
bool solve(int i, int j, int cnt, vector<vector<int>>& mat, vector<vector<int>>& grid, int n){
        if(i<0 || j<0 || i>=n || j>=n || mat[i][j]!=-1) return false;

        if(cnt==n*n-1){
            mat[i][j]=cnt;
            if(mat==grid){
                return true;
            }
            mat[i][j]=-1;
            return false;
        }
        
        mat[i][j]=cnt;
        int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
        int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
    
        for (int k = 0; k < 8; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (solve(ni, nj, cnt + 1, mat, grid, n)) return true;
        }
        mat[i][j]=-1;

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> mat(n, vector<int>(n, -1));

        return solve(0, 0, 0, mat, grid, n);   
    }
    */
/*
//Remove invalid parantheses
//Expected Time Complexity: O(2|S|)
//Expected Auxiliary Space: O(1)

int findRemovels(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    return st.size();
}

void solve(string s, vector<string> &ans, unordered_map<string, bool> &mp, int removels){
    if(mp[s]) return;
    mp[s]=true;
    
    if(removels==0){
        int removels_needed=findRemovels(s);
        if(removels_needed==0){
            ans.push_back(s);
        }
        return;
    }
    
    for(int i=0; i<s.length(); i++){
        string leftPart=s.substr(0, i);
        string rightPart=s.substr(i+1);
        string join=leftPart+rightPart;
        solve(join, ans, mp, removels-1);
    }
}

vector<string> removeInvalidParentheses(string s) {
    // code here
    vector<string> ans;
    unordered_map<string, bool> mp;
    int min_removels=findRemovels(s);
    solve(s, ans, mp, min_removels);
    sort(ans.begin(), ans.end());
    return ans;
}
*/
/*
//Word break
//Expected Time Complexity: O(len(s)2)
//Expected Space Complexity: O(len(s))
unordered_map<string, int>dp;

int solve(string s, vector<string> &dictionary, int n){
    int sz=s.length();
    if(sz==0) return 1;
    if(dp[s]!=0) return dp[s];
    
    for(int i=1; i<=sz; i++){
        int f=0;
        string ss=s.substr(0, i);
        for(int j=0; j<n; j++){
            if(ss.compare(dictionary[j])==0){
                f=1;
                break;
            }
        }
        if(f==1 && solve(s.substr(i), dictionary, n)==1) return dp[s]=1;
    }
    return dp[s]=-1;
}

int wordBreak(int n, string s, vector<string> &dictionary) {
    //code here
    if(solve(s, dictionary, n)==1)return 1;
    else return 0;
}
*/
/*
//Find all possible palindromic partitions of a String
//Expected Time Complexity: O(N* 2^N)
//Expected Auxiliary Space: O(N^2), 
bool isPalindrome(string s, int start, int end){
    while(start < end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void partition(string s, vector<vector<string>> &ans, vector<string> &temp, int index){
    if(index==s.length()){
        ans.push_back(temp);
        return;
    }
    
    for(int i=index; i<s.length(); i++){
        if(isPalindrome(s, index, i)){
            temp.push_back(s.substr(index, i-index+1));
            partition(s, ans, temp, i+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> allPalindromicPerms(string S) {
    // code here
    vector<string> temp;
    vector<vector<string>> ans;
    partition(S, ans, temp, 0);
    return ans;
}
*/
/*
//Find shortest safe route in a matrix
int solve(int r, int c, vector<vector<int>> &mat, vector<vector<bool>> &vis, set<pair<int, int>> &st, int i, int j, int cnt){
    if(i<0 || i>=r || j<0 || j>=c || vis[i][j] || st.count({i, j})){
        return INT_MAX;
    }
    if(j==c-1){
        return cnt;
    }
    
    vis[i][j]=true;
    int l1=solve(r, c, mat, vis, st, i+1, j, cnt+1);
    int l2=solve(r, c, mat, vis, st, i-1, j, cnt+1);
    int l3=solve(r, c, mat, vis, st, i, j+1, cnt+1);
    int l4=solve(r, c, mat, vis, st, i, j-1, cnt+1);
    vis[i][j]=false;
    
    return min({l1, l2, l3, l4});
}

int findShortestPath(vector<vector<int>> &mat)
{
    // code here
    int r=mat.size();
    int c=mat[0].size();
    int ans=INT_MAX;
    
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    set<pair<int, int>> st;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(mat[i][j]==0){
                pair<int, int> p(i, j);
                st.insert(p);
                if(i+1<r){
                    pair<int, int> p(i+1, j);
                    st.insert(p);
                }
                if(i-1>=0){
                    pair<int, int> p(i-1, j);
                    st.insert(p);
                }
                if(j+1<c){
                    pair<int, int> p(i, j+1);
                    st.insert(p);
                }
                if(j-1>=0){
                    pair<int, int> p(i, j-1);
                    st.insert(p);
                }
            }
        }
    }
    
    for(int i=0; i<r; i++){
        if(st.count({i, 0})==0){
            int length = solve(r, c, mat, vis, st, i, 0, 1);
            ans=min(ans, length);
        }
    }
    
    if(ans==INT_MAX) return -1;
    else return ans;
}
*/
/*
//Partition of a set into K subsets with equal sum
//Expected Time Complexity: O(N* 2^N).
//Expected Auxiliary Space: O(2^N).
void solve(int a[], int n, int k, int curSum, int sum, bool &ans, vector<bool> &vis, int cnt){
    if(cnt==k-1){
        ans=true;
        return;
    }
    
    if(curSum>sum){
        return;
    }
    
    if(curSum==sum){
        return solve(a, n, k, 0, sum, ans, vis, cnt+1);
        if(ans==true){
            return;
        }
    }
    
    for(int i=0; i<n; i++){
        if(vis[i]==false){
            vis[i]=true;
            solve(a, n, k, curSum+a[i], sum, ans, vis, cnt);
            if(ans==true){ 
                return;
            }
            vis[i]=false;
        }
    }
    
    return;
}

bool isKPartitionPossible(int a[], int n, int k)
{
        //Your code here
        if(k>n){
            return false;
        }
        
        if(k==1){
            return true;
        }
        
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=a[i];
        }
        
        if((sum%k)!=0){
            return false;
        }
        
        bool ans=false;
        vector<bool> vis(n, false);
        solve(a, n, k, 0, sum/k, ans, vis, 0);
        
        return ans;
}
*/
/*
//Tug of War gfg
#include<iostream>
using namespace std;
void solve(vector<int> arr, int n, int i, int sum1, int sum2, vector<int> arr1, vector<int> arr2, int &min_dif){
    if(i==n){
        if(arr1.size()==(n+1)/2 || arr2.size()==(n+1)/2){
            if(abs(sum1-sum2)<min_dif){
                min_dif=abs(sum1-sum2);
                for (int i = 0; i < n; i++){
                    res[i] = false;
                }
                for(int i=0; i<arr1.size(); i++){
                    res[arr1[i]]=true;
                }
            }
        }
        return;
    }

    arr1.push_back(i);//ic=nclude int first set
    solve(arr, n, i+1, sum1+arr[i], sum2, arr1, arr2, min_dif);
    arr1.pop_back();

    arr2.push_back(i);//include in second set
    solve(arr, n, i+1, sum1, sum2+arr[i], arr1, arr2, min_dif);
    arr2.pop_back();
}
void tugOfWar(vector<int> &arr, int n)
{
    // write your code here
    vector<int> arr1, arr2;
    vector<bool> res;
    int min_dif=INT_MAX;
    solve(arr, n, 0, 0, 0, arr1, arr2, min_dif);
    coout<<"Set1: "
    for(int i=0; i<n; i++){
        if(res[i]==true){
            cout<<arri<<" ";
        }
    }cout<<endl;
    coout<<"Set2: "
    for(int i=0; i<n; i++){
        if(res[i]==false){
            cout<<arri<<" ";
        }
    }cout<<endl;
    cout<<"Minimum absolute difference: "<<min_diff<<endl;
}

int main()
{
    return 0;
}
*/
/*
//Tug of war coding ninga
#include <bits/stdc++.h> 

void solve(vector<int> arr, int n, int i, int sum1, int sum2, int n1, int n2, int &min_dif){
    if(i==n){
        if(n1==(n+1)/2 || n2==(n+1)/2){
            if(abs(sum1-sum2)<min_dif){
                min_dif=abs(sum1-sum2);
            }
        }
        return;
    }

    solve(arr, n, i+1, sum1+arr[i], sum2, n1+1, n2, min_dif);
    solve(arr, n, i+1, sum1, sum2+arr[i], n1, n2+1, min_dif);
}

int tugOfWar(vector<int> &arr, int n)
{
    // write your code here
    int min_dif=INT_MAX;
    solve(arr, n, 0, 0, 0, 0, 0, min_dif);
    return min_dif;
}
*/
/*
//Largest number in k swaps
//TC O(n^k)    SC O(n)
void solve(string str, int n, string &max, int k, int idx){
    if(k==0){
        return;
    }
    
    char maxc=str[idx];
    for(int i=idx+1; i<n; i++){
        if(maxc<str[i]){
            maxc=str[i];
        }
    }
    
    if(maxc != str[idx]){
        k--;
    }
    //7599    9579 9597    9975 9957
    for(int i=idx; i<n; i++){
        if(maxc==str[i]){
            swap(str[idx], str[i]);
            if(str.compare(max)>0){
                max=str;
            }
            solve(str, n, max, k, idx+1);
            swap(str[idx], str[i]);
        }
    }
}

//Function to find the largest number after k swaps.
string findMaximumNum(string str, int k)
{
    // code here.
    int n=str.length();
    string max=str;
    solve(str, n, max, k, 0);
    return max;
}
*/