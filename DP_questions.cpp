/*
//Knapsack with duplicte items
//memoiation
//tc o(n*w)   sc o(n*w)+o(n)
class Solution{
public:
    int solve(int i, int j, int val[], int wt[], vector<vector<int>> &dp){
        if(i==0) return int(j/wt[0])*val[0];
        if(dp[i][j] != -1) return dp[i][j];
        
        int notTake =solve(i-1, j, val, wt, dp);
        int take=0;
        if(wt[i]<=j){
            take =val[i] + solve(i, j-wt[i], val, wt, dp);
        }
        return dp[i][j] = max(take, notTake);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(W+1, -1));
        return solve(N-1, W, val, wt, dp);
    }
};
*/
/*
//Knapsack with duplicte items
//tabulation
//tc o(n*w)   sc o(n*w)
int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(W+1, 0));
        for(int w=0; w<=W; w++){
            dp[0][w]=int(w/wt[0])*val[0];
        }
        for(int ind=1; ind<N; ind++){
            for(int w=0; w<=W; w++){
                int notTake =dp[ind-1][w];
                int take=0;
                if(wt[ind]<=w){
                     take =val[ind] + dp[ind][w-wt[ind]];
                }
                dp[ind][w] = max(take, notTake);
            }
        }
        return dp[N-1][W];
    }
};
*/
/*
//Knapsack with duplicte items
//space optimization
//tc o(n*w)   sc o(n)+o(w)
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int>prev(W+1, 0), curr(W+1, 0);
        for(int w=0; w<=W; w++){
            prev[w]=int(w/wt[0])*val[0];
        }
        for(int ind=1; ind<N; ind++){
            for(int w=0; w<=W; w++){
                int notTake =prev[w];
                int take=0;
                if(wt[ind]<=w){
                     take =val[ind] + curr[w-wt[ind]];
                }
                curr[w] = max(take, notTake);
            }
            prev=curr;
        }
        return prev[W];
    }
};
*/
/*
//Knapsack with duplicte items
//space optimization
//tc o(n*w)   sc o(w)
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int>prev(W+1, 0);
        for(int w=0; w<=W; w++){
            prev[w]=int(w/wt[0])*val[0];
        }
        for(int ind=1; ind<N; ind++){
            for(int w=0; w<=W; w++){
                int notTake =prev[w];
                int take=0;
                if(wt[ind]<=w){
                     take =val[ind] + prev[w-wt[ind]];
                }
                prev[w] = max(take, notTake);
            }
        }
        return prev[W];
    }
};
*/
/*
//Maximum number of balance binary trees possible with given height h
//tc o(h)   sc o(h)
class Solution {
  public:
    long long int countBT(int h) { 
        // code here
        long long int mod=1000000007;
        int dp[h+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=h; i++){
            dp[i]=(dp[i-1]*(2*dp[i-2]%mod+dp[i-1]%mod))%mod;
        }
        return dp[h];
    }
};
*/
/*
//Reach a given with player can score 3, 5 or 10 points
//tc o(n)   sc o(n)
class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	vector<int> table(n+1, 0);
    	table[0]=1;
    	for(int i=3; i<=n; i++){
    	    table[i] += table[i-3];
    	}
    	for(int i=5; i<=n; i++){
    	    table[i] += table[i-5];
    	}	
    	for(int i=10; i<=n; i++){
    	    table[i] += table[i-10];
    	}
    	
    	return table[n];
    }
};
*/
/*
class Solution{
public:	
//Maximum diference 0's and 1's of binary string
//tc o(s)   sc o(1)
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int mxtil_i=0;
	    int mx=-1;//INTMIN
	    for(int i=0; i<S.length(); i++){
	        int x = (S[i]=='0')?1:-1;
	        mxtil_i += x;
	        if(mxtil_i>mx) mx=mxtil_i;
	        if(mxtil_i<0) mxtil_i=0;
	    }
	    return mx;
	}
};
*/
/*
//number of ways to reach nth stair
//tc o(2^n)  sc o(2^n)
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int f(int ind){
        if(ind==0) return 1;
        if(ind==1) return 1;
        int left=f(ind-1);
        int right=f(ind-2);
        return left+right;
    }
    int countWays(int n)
    {
        // your code here
        return f(n);
    }
};
*/
/*
//number of ways to reach nth stair
//tc o(n)  sc o(n)+o(n)
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.     
    int f(int ind, vector<int> &dp){
        if(ind==0) return 1;
        if(ind==1) return 1;
        if(dp[ind] != -1) return dp[ind];
        int left=f(ind-1, dp);
        int right=f(ind-2, dp);
        return dp[ind]=left+right;
    }
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};
*/
/*
//number of ways to reach nth stair
//tc o(n)  sc o(n)
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.     
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1, 0);
        dp[0]=1;
        dp[1]=1;
        for(int ind=2; ind<=n; ind++){
            int left=dp[ind-1];
            int right=dp[ind-2];
            dp[ind]=left+right;
        }
        return dp[n];
    }
};
*/
/*
//number of ways to reach nth stair
//tc o(n)  sc o(1)
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.     
    int countWays(int n)
    {
        // your code here
        int prev=1;
        int prev2=1;
        for(int ind=2; ind<=n; ind++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
*/
/*
//Permutation coificient
//Tc (k) sc o(1)
class Solution{
    public:
    int permutationCoeff(int n, int k){
      int p=1;
      for(int i=0; i<k; i++){
          p *= (n-i);
      }
      return p;
    }
};
*/
/*
//LongestRepeatingSubsequence
//tc o(n^2)    sc o(n^2)
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){                            
		    // Code here
		    int n=str.length();
		    int dp[n+1][n+1];
		    
		    for(int i=0; i<=n; i++){
		        for(int j=0; j<=n; j++){
		            if(i==0 || j==0){
		                dp[i][j]=0;
		            }
		            else if(str[i-1]==str[j-1] && i!=j){
		                dp[i][j]=dp[i-1][j-1]+1;
		            }
		            else{
		                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}

};
*/
/*
//maxSum PairWith Difference LessThan K
tc o(n*logn)    sc o(n) or o(1)
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here  
        sort(arr, arr+N, greater<int>());
        int s=0;
        int i=0;
        while(i<N-1){
            int x=abs(arr[i]-arr[i+1]);
            if(x<K){
                s = s+arr[i]+arr[i+1];
                i=i+2;
            }
            else{
                i++;
            }
        }
        return s;
    }
};
*/
/*
//Longest subsequence with difference between adjacent elements is 1
tc o(n^2)    sc o(n)
class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here                                 
        int dp[n];
        for(int i=0; i<n; i++){
            dp[i]=1;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(abs(a[i]-a[j])==1){
                   dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int mx=0;
        for(int i=0; i<n; i++){
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
*/
/*
//Longest subsequence with difference between adjacent elements is 1
tc o(n)    sc o(n)
int longestSubseq(int n, vector<int> &a){
        unordered_map<int, int> mp;
        int mx=0;
        for(int i=0; i<n; i++){
            int l=0;
            if(mp[a[i]-1]) l=mp[a[i]-1];
            if(mp[a[i]+1] && mp[a[i]+1]>l) l=mp[a[i]+1];
            mp[a[i]]=l+1;
            mx=max(mx, mp[a[i]]);
        }
        return mx;
    }
*/
/*
//Minimum coins to reach a target
tc o(2^n) sc o(2^n)
class Solution{

	public:
	int f(int i, int V, vector<int> &coins){        
	    if(i==0){
	        if(V%coins[0]==0){
	            return V/coins[0];
	        }
	        return 1e9;
	    }    
	        
	    int notTake=f(i-1, V, coins);
	    int take=1e9;
	    if(V-coins[i]>=0){
	        take=1+f(i, V-coins[i], coins);
	    }
	    return min(take, notTake);
	}
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    int ans = f(M-1, V, coins);
	    if(ans>=1e9) return -1;
	    return ans;
	}
	  
};
*/
/*
//Minimum coins to reach a target
tc o(n*target) sc o(n*target) + o(n)
class Solution{

	public:
	int f(int i, int V, vector<int> &coins, vector<vector<int>> &dp){                         
	    if(i==0){
	        if(V%coins[0]==0){
	            return V/coins[0];
	        }
	        return 1e9;
	    }    
	    if(dp[i][V] != -1) return dp[i][V];
	    int notTake=f(i-1, V, coins, dp);
	    int take=1e9;
	    if(V-coins[i]>=0){
	        take=1+f(i, V-coins[i], coins, dp);
	    }
	    return dp[i][V] = min(take, notTake);
	}
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M, vector<int>(V+1, -1));
	    int ans = f(M-1, V, coins, dp);
	    if(ans>=1e9) return -1;
	    return ans;
	}
	  
};
*/
/*
//Minimum coins to reach a target
tc o(n*target) sc o(n*target)
int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M, vector<int>(V+1, 0));
	    for(int v=0; v<=V; v++){
	        if(v%coins[0]==0){
	            dp[0][v] = v/coins[0];
	        }
	        else{
	            dp[0][v] = 1e9;   
	        }
	    }
	    for(int i=1; i<M; i++){
	        for(int v=0; v<=V; v++){
	           int notTake=dp[i-1][v];
	           int take=1e9;
	           if(v-coins[i]>=0){
	               take=1+dp[i][v-coins[i]];
	           }
	           dp[i][v] = min(take, notTake);
	        }
	    }
	    int ans = dp[M-1][V];
	    if(ans>=1e9) return -1;
	    return ans;
	}
*///We can optimize this also
/*
//length of longest increasing subsequence.
//tc o(n^2)    sc o(n)
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>dp(n, 1);
       for(int i=1; i<n; i++){
           for(int j=0; j<i; j++){
               if(a[j]<a[i]){
                   dp[i]=max(dp[i], dp[j]+1);
               }
           }
       }
       int mx=0;
       for(int i=0; i<n; i++){
           mx=max(mx, dp[i]);
       }
       return mx;
    }
};
*/
/*
//length of longest increasing subsequence.
//tc o(n*logn)    sc o(n)
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int dp[n+1];
       for(int i=1; i<=n; i++){
           dp[i]=1e9;
       }
       dp[0]=-1;
       for(int i=0; i<n; i++){
           int idx=upper_bound(dp, dp+n+2, a[i])-dp;
           if(dp[idx-1]<a[i] && dp[idx]>=a[i]){
               dp[idx]=a[i];
           }
       }
       int mx=0;
       for(int i=n; i>=0; i--){
           if(dp[i] != 1e9){
               mx=i;
               break;
           }
       }
       return mx;
    }
};
*/
/*
//length of longest common subsequence in two strings.
//tc o(n*m)    sc o(n*m)
class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        // your code here
		    int dp[n+1][m+1];
		    
		    for(int i=0; i<=n; i++){
		        for(int j=0; j<=m; j++){
		            if(i==0 || j==0){
		                dp[i][j]=0;
		            }
		            else if(str1[i-1]==str2[j-1]){
		                dp[i][j]=dp[i-1][j-1]+1;
		            }
		            else{
		                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
            return dp[n][m];
	}
};
*/
/*
//House robber
//Oprimal soluiom tc o(n)  sc o(1)
#include<iostream>
using namespace std;

long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;

    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;

        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;

    }
    return prev;
}
*/
/*
//House robber 2
//Oprimal soluiom tc o(n)  sc o(1)
#include<iostream>
using namespace std;

long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

long long int robStreet(int n, vector<int> &arr){
    vector<int> arr1;
    vector<int> arr2;
    
    if(n==1)
       return arr[0];
    
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(arr[i]);
        if(i!=n-1) arr2.push_back(arr[i]);
    }
    
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    
    return max(ans1,ans2);
}


int main() {

  vector<int> arr{1,5,1,2,6};
  int n=arr.size();
  cout<<robStreet(n,arr);
}
*/
/*
//Decoding message
//Expected Time Complexity: O(n)
//Expected Space Complexity: O(n) where n  = |str|
class Solution {
	public: 
		int CountWays(string str){
		    // Code here
		    if(str.length()==0 || str[0]=='0') return 0;       
		    if(str.length()==1) return 1;
		    int prev=1,prev2=1;
		    for(int i=1; i<str.length(); i++){
		        int d=str[i]-'0';
		        int dd=(str[i-1]-'0')*10+d;
		        int curr=0;
		        if(d>0) curr+=prev;
		        if(dd>=10 && dd<=26) curr+=prev2;
		        if(curr == 0) return 0;
		        prev2=prev;
		        prev=curr;
		    }
		    return prev;
		}
};
*/
/*
//Unique Paths
//Expected Time Complexity: O(A*B).
//Expected Auxiliary Space: O(A*B).
class Solution {
public:
    int f(int i, int j, int a, int b, vector<vector<int>> &dp) {
        if (i == a - 1 && j == b - 1) return 1;

        if (i >= a || j >= b) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = f(i, j + 1, a, b, dp);
        int down = f(i + 1, j, a, b, dp);

        return dp[i][j] = right + down;
    }

    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b) {
        vector<vector<int>> dp(a, vector<int>(b, -1));
        return f(0, 0, a, b, dp);
    }
};
*/
/*
//Jump game
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(1)
class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        int mx=0;
        for(int i=0; i<N; i++){
            if(i>mx) return 0;
            mx=max(mx, i+A[i]);
        }
        return 1;
    }
};
*/
/*
//Knapsack With distinct items
//Brutforce
//tc o(2^ N*W)   sc o(2^ N*W) 
class Solution{
public:
    int solve(int i, int j, int val[], int wt[], vector<vector<int>> &dp){
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int notTake =solve(i-1, j, val, wt, dp);
        int take=0;
        if(wt[i]<=j){
            take =val[i] + solve(i-1, j-wt[i], val, wt, dp);
        }
        return dp[i][j] = max(take, notTake);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(W+1, -1));
        return solve(N-1, W, val, wt, dp);
    }
};
*/
/*
//Knapsack with distinct items
tc o(N*W)   sc o(N*W)+o(N)
class Solution{
public:
    int solve(int i, int j, int val[], int wt[], vector<vector<int>> &dp){
        if(i==0) {
            if(wt[0]<=j){
                return val[0];
            }
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int notTake =solve(i-1, j, val, wt, dp);
        int take=0;
        if(wt[i]<=j){
            take =val[i] + solve(i-1, j-wt[i], val, wt, dp);
        }
        return dp[i][j] = max(take, notTake);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(W+1, -1));
        return solve(N-1, W, val, wt, dp);
    }
};
*/
/*
//Knapsack with distinct items
//Expected Time Complexity: O(N*W).
//Expected Auxiliary Space: O(N*W)
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(W+1, 0));    
        for(int w=wt[0]; w<=W; w++){
            dp[0][w]=val[0];
        }
        for(int i=1; i<N; i++){
            for(int j=0; j<=W; j++){
                int notTake =dp[i-1][j];
                int take=0;
                if(wt[i]<=j){
                take =val[i] + dp[i-1][j-wt[i]];
                }
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[N-1][W];
    }
};
*/
/*
//ncr
//Expected Time Complexity: O(n*r)
//Expected Auxiliary Space: O(r)
class Solution{
public:
    int nCr(int n, int r){
        // code here
        int mod=1000000007;
        if(n<r) return 0;
        if(r>(n-r)) r=n-r;
        vector<int> dp(r+1, 0);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=min(i, r); j>0; j--){
                dp[j]=(dp[j]+dp[j-1])%mod;
            }
        }
        return dp[r];
    }
};
*/
/*
//nth catalan number
//Expected Time Complexity: O(N^2).
//Expected Auxiliary Space: O(N).
class Solution
{
    public:
    //Function to find the nth catalan number.    
    int findCatalan(int n) 
    {
        vector<long long>dp(n+1, 0); //int is invalid for long integers
        dp[0]=1,dp[1]=1;
        int mod=1000000007;
        if(n==0 || n==1) return 1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] = (dp[i]+(dp[j]*dp[i-j-1])%mod)%mod;
            }
        }
        return dp[n];
    }
};
*/
/*
//Edit distance
//Brut force
class Solution {
  public:
    int f(int i, int j, string s, string t){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(s[i]==t[j]){
            return f(i-1, j-1, s, t);
        }
        int insert=1+f(i, j-1, s, t);
        int remove=1+f(i-1, j, s, t);
        int replace=1+f(i-1, j-1, s, t);
        return min(insert, min(remove, replace));
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.length(), m=t.length();              
        return f(n-1, m-1, s, t);
    }
};
*/
/*
//Edit distance
//Memoization
class Solution {
  public:
    int f(int i, int j, string s, string t, vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = f(i-1, j-1, s, t, dp);
        }
        int insert=1+f(i, j-1, s, t, dp);
        int remove=1+f(i-1, j, s, t, dp);
        int replace=1+f(i-1, j-1, s, t, dp);
        return dp[i][j]=min(insert, min(remove, replace));        
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.length(), m=t.length();  
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, t, dp);
    }
};
*/
/*
//Edit distance
//dynamic programing
//Expected Time Complexity: O(|str1|*|str2|)
//Expected Space Complexity: O(|str1|*|str2|)
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n=s.length(), m=t.length();  
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            dp[i][0]=i;
        }
        for(int j=1; j<=m; j++){
            dp[0][j]=j;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insert=1+dp[i][j-1];
                    int remove=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min(insert, min(remove, replace));            
            
                }
            }
        }
        return dp[n][m];
    }
};
*/
/*
//Edit distance
//dynamic programing
//Expected Time Complexity: O(|str1|*|str2|)
//Expected Space Complexity: O(min(|str1|, |str2|))
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n=s.length(), m=t.length();  
        vector<int>prev(m+1, 0), curr(m+1, 0);
        for(int j=1; j<=m; j++){
            prev[j]=j;
        }
        for(int i=1; i<=n; i++){
            curr[0]=i;
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    int insert=1+curr[j-1];
                    int remove=1+prev[j];
                    int replace=1+prev[j-1];
                    curr[j]=min(insert, min(remove, replace));           
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};
*/
/*
//Gold mine
//Expected Time Complexity: O(n*m)
//Expected Auxiliary Space: O(n*m)
class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        for(int j=m-2; j>=0; j--){
            for(int i=0; i<n; i++){
                int right=M[i][j]+M[i][j+1];
                int rightUp=(i==0)?0:M[i][j]+M[i-1][j+1];
                int rightDown=(i==n-1)?0:M[i][j]+M[i+1][j+1];
                M[i][j] = max(right, max(rightUp, rightDown));
            }
        }
        int res=M[0][0];
        for(int i=1; i<n; i++){
            res=max(res, M[i][0]);
        }
        return res;
    }
};
*/
/*
//CarAsembly
//Brutforce
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(N)
class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      //Code Here
      int n=a[0].size();
      vector<int> t1(n, 0), t2(n, 0);
      t1[0]=e[0]+a[0][0];
      t2[0]=e[1]+a[1][0];
      for(int i=1; i<n; i++){
          t1[i]=min(t1[i-1]+a[0][i], t2[i-1]+T[1][i]+a[0][i]);
          t2[i]=min(t2[i-1]+a[1][i], t1[i-1]+T[0][i]+a[1][i]);
      }
      return min(t1[n-1]+x[0], t2[n-1]+x[1]);
  }
};
*/
/*
//CarAsembly
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(1)
class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      //Code Here
      int n=a[0].size();
      
      int prev1=e[0]+a[0][0];
      int prev2=e[1]+a[1][0];
      for(int i=1; i<n; i++){
          int curr1=min(prev1+a[0][i], prev2+T[1][i]+a[0][i]);
          int curr2=min(prev2+a[1][i], prev1+T[0][i]+a[1][i]);
          prev1=curr1;
          prev2=curr2;
      }
      return min(prev1+x[0], prev2+x[1]);
  }
};
*/
/*
//Maximum cuts
//Expected Time Complexity : O(n)
//Expected Auxiliary Space: O(n)
class Solution
{
    public:
    int f(int n, int x, int y, int z, vector<int>&dp){
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int op1=INT_MIN, op2=INT_MIN, op3=INT_MIN;
        if(x<=n) op1=f(n-x,x,y,z,dp);
        if(y<=n) op2=f(n-y,x,y,z,dp);
        if(z<=n) op3=f(n-z,x,y,z,dp);
        return dp[n]=1+max(op1, max(op2, op3));
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1, -1);
        int ans = f(n, x, y, z, dp);
        if(ans<0) return 0;
        return ans;
        //Your code here
    }
};
*/
/*
//Maximum sum of strictly increasing subsequence
//Expected Time Complexity: O(N2)
//Expected Auxiliary Space: O(N)
class Solution{
	public:
	int maxSumIS(int arr[], int n)                                      
	{  
	    // Your code goes here
	    vector<int>dp(n, 0);
	    for(int i=0; i<n; i++){
	        dp[i]=arr[i];
	    }
	    for(int i=1; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(arr[j]<arr[i]){
	                dp[i]=max(dp[i], dp[j]+arr[i]);
	            }
	        }
	    }
	    int mx=dp[0];
	    for(int i=1; i<n; i++){
	        mx=max(mx, dp[i]);
	    }
	    return mx;
	}  
};
*/
/*
//EggDroping  //imp
//Expected Time Complexity : O(N*(K^2))
//Expected Auxiliary Space: O(N*K)
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int f(int n, int k, vector<vector<int>>&dp){
        if(n==1) return k;
        if(k==0) return 0;
        
        if(dp[n][k] != -1) return dp[n][k];
        int ans=INT_MAX;
        for(int i=1; i<=k; i++){
            int broken=f(n-1, i-1, dp);
            int notbroken=f(n, k-i, dp);
            int mx=max(broken, notbroken);
            ans=min(ans, mx+1);
        }
        return dp[n][k]=ans;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
       // dp[0][0]=0;
        return f(n, k, dp);
    }
};
*/
/*
//Maximum length chain
//note: TC O(n)    SC O(1)
/The structure to use is as follows
// struct val{
// 	int first;
// 	int second;
// };

class Solution{
public:
    static bool comp(pair<int, int>a, pair<int, int>b){
        return a.second<b.second;
    }
    // You are required to complete this method              
    int maxChainLen(struct val p[],int n){
        //Your code here
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++){
            v.push_back({p[i].first, p[i].second});
        }
        sort(v.begin(), v.end(), comp);
        int i=0,j=1,c=1;
        while(j<n){
            if(v[i].second<v[j].first){
                c++;
                i=j;
                j++;
            }
            else{
                j++;
            }
        }
        return c;
    }
};
*/
/*
//Maximum side of square matrix with all 1's
//Expected Time Complexity: O(n*m)
//Expected Auxiliary Space: O(n*m)
class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        vector<vector<int>> s(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            s[i][0]=mat[i][0];
        }
        for(int j=0; j<m; j++){
            s[0][j]=mat[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mat[i][j]==1){
                    s[i][j]=min({s[i-1][j], s[i][j-1], s[i-1][j-1]})+1;                
                }
                else{
                    s[i][j]=0;
                }
            }
        }
        int mx=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mx=max(mx, s[i][j]);
            }
        }
        return mx;
    }
};
*/
/*
//Maximum path sum in matrix
//Expected Time Complexity: O(n * n)
//Expected Auxiliary Space: O(n * n)
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        for(int i=N-2; i>=0; i--){
            for(int j=0; j<N; j++){
                int down=Matrix[i][j]+Matrix[i+1][j];
                int downRight=(j==N-1)?0:Matrix[i][j]+Matrix[i+1][j+1];
                int downLeft=(j==0)?0:Matrix[i][j]+Matrix[i+1][j-1];
                Matrix[i][j] = max(down, max(downRight, downLeft));
            }
        }
        int res=Matrix[0][0];
        for(int j=1; j<N; j++){
            res=max(res, Matrix[0][j]);
        }
        return res;
    }
};
*/
/*
//Minimum jumps
//Expected Time Complexity: O(n)
//Expected Space Complexity: O(1)
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int mxR=arr[0];
        int step=arr[0];
        int jump=1;
        
        if(n==1) return 0;
        else if(arr[0]==0) return -1;
        else{
            for(int i=1; i<n; i++){
                if(i==n-1) return jump;
                mxR=max(mxR, i+arr[i]);
                step--;
                if(step==0){
                    jump++;
                    if(i>=mxR) return -1;
                    step=mxR-i;
                }
            }
        }
    }
};
*/
/*
//Minimum removals required to make subtracton of min and max element is less than equal to k
//brut force
//Time Complexity :O(n2) 
//Auxiliary Space: O(n2)
class Solution{
    public:
    int solve(int i, int j, int k, vector<int> arr, vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(arr[j]-arr[i]<=k) return 0;
        if(dp[i][i] != -1) return dp[i][j];
        return dp[i][j]=1+min(solve(i+1, j, k, arr, dp), solve(i, j-1, k, arr, dp));
    }
    int removals(vector<int>& arr, int k){
        //Code here
        int n=arr.size();
        if(n==1) return 0;
        sort(arr.begin(), arr.end());
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, n-1, k, arr, dp);                                    
    }
};
*/
/*
//Minimum removals required to make subtraction of min and max element is less than equal to k
////Time Complexity :O(n*logn) 
//Auxiliary Space: O(1)
class Solution{
    public:
    int removals(vector<int>& arr, int k){                
        //Code here
        int n=arr.size();
        if(n==1) return 0;
        sort(arr.begin(), arr.end());
        int ans=n-1;
        for(int i=0; i<n; i++){
            int j=upper_bound(arr.begin()+i, arr.end(), arr[i]+k)-arr.begin()-1;       
            ans=min(ans, n-(j-i+1));
        }
        return ans;
    }
};
*/
/*
//Longest common substring
//Expected Time Complexity: O(n*m).
//Expected Auxiliary Space: O(n*m)
class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        int dp[n+1][m+1];
		int ans=0;   
		    for(int i=0; i<=n; i++){
		        for(int j=0; j<=m; j++){
		            if(i==0 || j==0){
		                dp[i][j]=0;
		            }
		            else if(s1[i-1]==s2[j-1]){
		                dp[i][j]=dp[i-1][j-1]+1;
		                ans=max(ans, dp[i][j]);
		            }
		            else{
		                dp[i][j]=0;
		            }
		        }
		    }
            return ans;
    }
};
*/
/*
//Prtition of array iinto two parts with equal sum
//Expected Time Complexity: O(N*sum of elements)
//Expected Auxiliary Space: O(sum of elements)
class Solution{
public:
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
};
*/
/*
//Longest palindromic subsequence
//Expected Time Complexity: O(n*m).
//Expected Auxiliary Space: O(n*m)
class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        string B=A;
        reverse(B.begin(), B.end());
        int dp[n+1][n+1];
		    
		    for(int i=0; i<=n; i++){
		        for(int j=0; j<=n; j++){
		            if(i==0 || j==0){
		                dp[i][j]=0;
		            }
		            else if(A[i-1]==B[j-1]){
		                dp[i][j]=dp[i-1][j-1]+1;
		            }
		            else{
		                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
            return dp[n][n];
    }
};
*/
/*
//Longest alternating(inceasing decreasing) subsequence
//brut force
//tc o(n^2)    sc o(n)
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {                  
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(2, 1));
        int mx=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i]>arr[j]){
                    dp[i][0]=max(dp[i][0], dp[j][1]+1);
                }
                else if(arr[i]<arr[j]){
                     dp[i][1]=max(dp[i][1], dp[j][0]+1);
                }
            }
            mx=max(mx, max(dp[i][0], dp[i][1]));
        }
        return mx;
    }
};
*/
/*
//Longest alternating(inceasing decreasing) subsequence
//Expected Time Complexity: O(n)
//Expected Space Complexity: O(1)
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int mx1=1, mx2=1;
        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){
                mx1=mx2+1;
            }
            else if(arr[i]<arr[i-1]){
                mx2=mx1+1;
            }
        }
        return max(mx1, mx2);
    }
};
*/
/*
//maximum profit and number of jobs done  skeep this question
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int start, end, profit;
};

// Comparator function to sort jobs by end time
bool jobComparator(Job a, Job b) {
    return a.end < b.end;
}

// Function to find the last job which doesn't conflict with the job[i]
int findLastNonConflictingJob(vector<Job>& jobs, int i) {
    int low = 0, high = i - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (jobs[mid].end <= jobs[i].start) {
            if (jobs[mid + 1].end <= jobs[i].start) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to find the maximum profit and number of jobs done
pair<int, int> weightedJobScheduling(vector<Job>& jobs) {
    int n = jobs.size();
    
    // Sort jobs by end time
    sort(jobs.begin(), jobs.end(), jobComparator);

    // Initialize DP arrays
    vector<int> dp(n);
    vector<int> count(n);

    dp[0] = jobs[0].profit;
    count[0] = 1;

    for (int i = 1; i < n; ++i) {
        int inclProfit = jobs[i].profit;
        int inclCount = 1;

        int l = findLastNonConflictingJob(jobs, i);

        if (l != -1) {
            inclProfit += dp[l];
            inclCount += count[l];
        }

        if (inclProfit > dp[i - 1]) {
            dp[i] = inclProfit;
            count[i] = inclCount;
        } else {
            dp[i] = dp[i - 1];
            count[i] = count[i - 1];
        }
    }

    return {dp[n - 1], count[n - 1]};
}

int main() {
    vector<Job> jobs = {
        {1, 3, 5},
        {2, 5, 6},
        {4, 6, 5},
        {7, 8, 8},
        {6, 9, 6}
    };

    pair<int, int> result = weightedJobScheduling(jobs);
    cout << "Maximum profit: " << result.first << endl;
    cout << "Number of jobs done: " << result.second << endl;

    return 0;
}
*/
/*
//Coin game
//Expected Time Complexity: O(n)
//Expected Auxiliary Space: O(n)
class Solution {
  public:
    int findWinner(int n, int x, int y) {         
        // code here
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            if(i-1>=0 && dp[i-1]==0) dp[i]=1;
            else if(i-x>=0 && dp[i-x]==0) dp[i]=1;    
            else if(i-y>=0 && dp[i-y]==0) dp[i]=1;
            else dp[i]=0;
        }
        return dp[n];
    }
};
*/
/*
//Count Derangements (Permutation such that no element appears in its original position)
//Expected Time Complexity: O(2^n)
//Expected Auxiliary Space: O(n)
//gfg dont have practice section
#include <bits/stdc++.h>
using namespace std;
 
int countDer(int n)
{
  // Base cases
  if (n == 1) return 0;
  if (n == 2) return 1;
 
  return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}
 
int main()
{
    int n = 4;
    cout << "Count of Derangements is "
         << countDer(n);
    return 0;
}
*/
/*
//Count Derangements (Permutation such that no element appears in its original position)
//Expected Time Complexity: O(n)
//Expected Auxiliary Space: O(n)
#include <bits/stdc++.h>
using namespace std;
 
int countDer(int n)
{
    // Create an array to store 
    // counts for subproblems
    int der[n + 1] = {0};
 
    // Base cases
    der[1] = 0;
    der[2] = 1;
 
    // Fill der[0..n] in bottom up manner 
    // using above recursive formula
    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] + der[i - 2]);
 
    // Return result for n
    return der[n];
}
 
// Driver code
int main()
{
    int n = 4;
    cout << "Count of Derangements is "
         << countDer(n);
    return 0;
}
*/
/*
//Count Derangements (Permutation such that no element appears in its original position)
//Expected Time Complexity: O(n)
//Expected Auxiliary Space: O(1)
#include <iostream>
using namespace std;
 
int countDer(int n)
{
 
    // base case
    if (n == 1 or n == 2) {
        return n - 1;
    }
 
    // Variable for just storing
    // previous values
    int prev2 = 0;
    int prev = 1;
 
    // using above recursive formula
    for (int i = 3; i <= n; ++i) {
        int cur = (i - 1) * (prev + prev2);
        prev2 = prev;
        prev = cur;
    }
 
    // Return result for n
    return prev;
}
 
// Driver Code
int main()
{
 
    cout << "Count of Derangements is " << countDer(4);
    return 0;
}
*/
/*
//Optimal Strategy For A Game
//Expected Time Complexity : O(n*n)
//Expected Auxiliary Space: O(n*n)
class Solution{
    public:
    long long f(int i, int j, int arr[], vector<vector<long long>>&dp){   
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        long long x=arr[i]+min(f(i+2, j, arr, dp), f(i+1, j-1, arr, dp));
        long long y=arr[j]+min(f(i+1, j-1, arr, dp), f(i, j-2, arr, dp));
        return dp[i][j]=max(x, y);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>>dp(n, vector<long long>(n, -1));
        return f(0, n-1, arr, dp);
    }
};
*/
/*
//Matrix chain multiplication
//TC O(n!) exponentil  sc o(n!)
class Solution{
public:
    int f(int i, int j, int arr[]){
        if(i==j) return 0;
        int mn=1e9;
        for(int k=i; k<j; k++){
            int step=arr[i-1]*arr[k]*arr[j] + f(i, k, arr) + f(k+1, j, arr);
            mn=min(mn, step);
        }
        return mn;
    }                                 
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return f(1, N-1, arr);
    }
};
*/
/*
//Matrix chain multiplication
//TC O(n^3)   SC O(n^2)+O(n)
class Solution{
public:
    int f(int i, int j, int arr[], vector<vector<int>>&dp){
        if(i==j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int mn=1e9;
        for(int k=i; k<j; k++){
            int step=arr[i-1]*arr[k]*arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
            mn=min(mn, step);
        }
        return dp[i][j]=mn;
    }                                 
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(N, -1));
        return f(1, N-1, arr, dp);
    }
};
*/
/*
//Matrix chain multiplication
//TC O(n^3)   SC O(n^2)
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(N));
        for(int i=1; i<N; i++) dp[i][i]=0;
        
        for(int i=N-1; i>=1; i--){
            for(int j=i+1; j<N; j++){
                int mn=1e9;
                for(int k=i; k<j; k++){
                    int step=arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mn=min(mn, step);
                }
                dp[i][j]=mn;
            }
        }
        return dp[1][N-1];
    }
};
*/
/*
//Best Time to Buy and Sell Stock at most two transactions allowed
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(N)
class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){        
            //Write your code here..
            int n=price.size();
            vector<int>dp(n, 0);
            int mn=price[0], mx=price[n-1];
            for(int i=n-2; i>=0; i--){
                mx=max(mx, price[i]);
                dp[i]=max(dp[i+1], mx-price[i]);           
            }
            for(int i=1; i<n; i++){
                mn=min(mn, price[i]);
                dp[i]=max(dp[i-1], dp[i]+(price[i]-mn));
            }
            return dp[n-1];
        }
};
*/
/*
//Maximum sum rectangle
//Expected Time Complexity:O(R*R*C)
//Expected Auxillary Space:O(R*C)
class Solution {
  public:
    int kadane(vector<int>temp, int n){
        int mx=INT_MIN, sum=0;
        for(int i=0; i<n; i++){
            sum+=temp[i];
            mx=max(mx, sum);
            if(sum<0){
                sum=0;
            }
        }
        return mx;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int max_sum=INT_MIN;
        for(int i=0; i<C; i++){
            vector<int>temp(R, 0);
            for(int j=i; j<C; j++){
                for(int k=0; k<R; k++){
                    temp[k]+=M[k][j];
                }
                int sum=kadane(temp, R);
                if(max_sum<sum){
                    max_sum=sum;
                }
            }
        }
        return max_sum;
    }
};
*/
/*
//Longest subarray with sum 0
//TC O(n).   SC O(n)
int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}
*/
/*
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//Longest submatrix with sum 0
class Solution{
  public:
  pair<int, int> subSum(vector<int>A, int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0, ending_ind=-1;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
            ending_ind=i;
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                if(maxi<i - mpp[sum]){
                    maxi=i-mpp[sum];
                    ending_ind=i;
                } 
                
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    pair<int, int>p(maxi, ending_ind); 
    return p;
}
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int r=a.size();
      int c=a[0].size();
      int starting_row=0,ending_row=0,starting_col=0,ending_col=0;                    
      int mxln=0;
        for(int i=0; i<r; i++){
            vector<int>temp(c, 0);
            for(int j=i; j<r; j++){
                for(int k=0; k<c; k++){
                    temp[k]+=a[j][k];
                }
                pair<int, int>p=subSum(temp, c);
                if(mxln*(ending_row-starting_row+1)<p.first*(j-i+1)){
                    mxln=p.first;
                    starting_row=i;
                    ending_row=j;
                    starting_col=p.second-p.first+1;
                    ending_col=p.second;
                }
            }
        }
        
        vector<vector<int>>res;
        for(int i=starting_row; i<=ending_row; i++){
            vector<int>v;
            for(int j=starting_col; j<=ending_col; j++){
                v.push_back(a[i][j]);
            }
            res.push_back(v);
        }
        return res;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
*/