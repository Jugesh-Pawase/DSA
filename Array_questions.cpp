// subarrays = n(n+1)/2;
// subsequences = 2^n;

/**
//max till i
//2 0 7 5 11
//TC O(n)  SC O(1)
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }

    int mx = INT_MIN;
    for (int i = 0; i < n; i++){
       mx = max(mx, a[i]);
       cout << mx << " ";
    }
        return 0;
    }
    */

/**
//Sum of all subarrays of array
//1 2 0 4
//Brut Force: TC O(n^3)
//Optimal: TC O(n^2)

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum = 0;
        for (int j = i; j < n; j++){
            sum += a[j];
            cout << sum << endl;
        }
    }
        return 0;
    }
/**
//Largest arithmetic subarray
//-4 4 -6 6 10 -11 12
//TC O(n)  SSC O(1)
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }
    int ans = 2;
    int curr = 2;
    int pd = a[1] - a[0];
    int j = 2;

    while(j<n){
        if(pd==a[j]-a[j-1]){
            curr++;
        }
        else{
            pd = a[j] - a[j - 1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }

    cout << ans  << endl;
    return 0;
    }
/**
//Record breaking days
//12 15 13 18 20
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n+1];
    a[n] = -1;

    for(int i=0; i<n; i++){
       cin>>a[i];
    }

    if(n==1){
        cout << "1" << endl;
        return 0;
    }

    int ans = 0;
    int mx = -1;
    for (int i = 0; i < n; i++){
        if(a[i]>mx && a[i]>a[i+1]){
            ans++;
        }
        mx = max(mx, a[i]);
    }

        cout << ans << endl;
    return 0;
    }
/**
//Print all subarrays of array
//-1 4 7 2
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            for (int k = i; k <= j; k++){
                cout << a[k] << " ";
            }
                cout << endl;
        }
    }
        return 0;
    }
/**
//Find the circular subarray of maximum sum

#include<iostream>
#include<climits>
using namespace std;

int kadane(int a[], int n){

    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++){
        currSum += a[i];
        maxSum = max(maxSum, currSum);//Modification
        if(currSum<0){
            currSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    int wrapsum;
    int nonwrapsum;
    nonwrapsum = kadane(a, n);

    int totalSum = 0;
    for(int i=0; i<n; i++){
        totalSum += a[i];
        a[i] = -a[i];
    }

    wrapsum = totalSum + kadane(a, n);
    cout << max(wrapsum, nonwrapsum);
    return 0;
    }
/**
//To find there exist sum of pair equal to given k or not in sorted array
//Brut force aproach: O(n^2)
#include<iostream>
using namespace std;

bool pairsum(int a[], int n, int k){
    for (int i = 0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if(a[i]+a[j] == k){
                cout << i << " " << j << endl;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int a[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int k = 31;

    cout << pairsum(a, 8, k) << endl;
    return 0;
}
/**
//To find there exist sum of pair equal to given k or not
//Anothr method to reduce time complexity
//When array is sorted: O(n)

#include<iostream>
using namespace std;

bool pairsum(int a[], int n, int k){
    int low = 0;
    int high = n - 1;

    while(low<high){
        if(a[low]+a[high] == k){
            cout << low << " " << high << endl;
            return true;
        }
        else if(a[low]+a[high] < k){
           low++;
        }
        else{
            high--;
        }
    }
    return false;
}

int main(){
    int a[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int k = 31;

    cout << pairsum(a, 8, k) << endl;
    return 0;
}
/**
//find repeat elment with minimum index
//brute force aproach:O(n^2)
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    int minindex = INT_MAX;
    int index = INT_MAX;
    for (int i = 0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if(a[i]==a[j]){
                index = i;
                minindex = min(minindex, index);
            }
        }
    }

    cout << minindex << endl;
    return 0;
}
/**
//find repeat elment wuth minimum index
//Optimal aproach
//TC O(N)  SC O(N)
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
         cin>>a[i];
    }
    int minidx = INT_MAX;
    const int N = 99; // 1e6 + 2
    int idx[N];
    for(int i=0; i<N; i++){
        idx[i] = -1;
    }
    for(int i=0; i<n; i++){
        if(idx[a[i]] == -1){
            idx[a[i]] = i;
        }else{
            minidx = min(minidx, idx[a[i]]);
        }
    }
    if(minidx==INT_MAX){
        cout << "-1" << endl;
    }
    else{
        cout << minidx << endl;
    }
    return 0;
}
/**
//To find if there exist subarray with sum equal to given s in unsorted array
//2 3 7 12
//Brut Force: TC O(n^2)  like previous problems
//Optimal Aproach
//TC O(n)  SC O(1)
#include<iostream>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }

    int i = 0, j = 0, st = -1, en = -1, sum = 0;

    while(j<n && sum+a[j]<=s){
        sum += a[j];
        j++;
    }

    if(sum==s){
        cout << i + 1 << " " << j + 1 << endl;
        return 0;
    }

    while(j<n){
        sum += a[j];
        while(sum>s){
            sum -= a[i];
            i++;
        }

        if(sum==s){
            st = i + 1;
            en = j + 1;
            break;
        }
        j++;
    }

    cout << st << " " << en << endl;

    return 0;
    }
/**
//Smallest positive missing number
//TC: O(n), SC O(N)    N = 1e6 + 2;
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    const int N = 1e6 + 2;
    bool check[N];
    for (int i = 0; i < N; i++){
        check[i] = false;
    }

    for (int i = 0; i < n; i++){
        if(a[i]>=0){
            check[a[i]] = true;
        }
    }

    int ans = -1;
    for(int i=0; i<N; i++){
        if(check[i]==false){
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
/**
//print spiral shape
#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i<n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;
    while(row_start<=row_end && column_start<=column_end){
        //print row_start
        for (int col = column_start; col <= column_end; col++){
            cout << a[row_start][col] << " ";
        }
        row_start++;

        //print column_end
        for (int row = row_start; row <= row_end; row++){
            cout << a[row][column_end] << " ";
        }
        column_end--;

        //print row_end
        for (int col = column_end; col>=column_start; col--){
            cout << a[row_end][col] << " ";
        }
        row_end--;

        //print column_first
        for (int row = row_end; row >= row_start; row--){
            cout << a[row][column_start] << " ";
        }
        column_start++;
    }

    return 0;
}
/**
//Transpose of matris
#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i<n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < m; j++){
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j < m; j++){
            cout<< a[i][j]<<" ";
        }
        cout << endl;
    }
        return 0;
}
/*
//Matrix multiplication
#include<iostream>
using namespace std;
int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int m1[n1][n2], m2[n2][n3];
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++)
            cin>>m1[i][j];
    }

    for (int i = 0; i < n2; i++){
        for (int j = 0; j < n3; j++)
            cin>>m2[i][j];
    }

    int ans[n1][n3];
     for (int i = 0; i < n1; i++){
        for (int j = 0; j < n3; j++)
            ans[i][j] = 0;
    }

     for (int i = 0; i < n1; i++){
        for (int j = 0; j < n3; j++){
            for (int k = 0; k<n2; k++){
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

     for (int i = 0; i < n1; i++){
        for (int j = 0; j < n3; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
/**
//To search element in an ascending order matrix
#include<iostream>
using namespace std;
int main()
{
    int n, m, target;
    cin >> n >> m >> target;

    int a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int r = 0, c = m - 1;
    bool found = false;
    while(r<n && c>=0){
        if(a[r][c]==target){
            found = true;
            break;
        }
        else if(a[r][c]>target){
            c--;
        }
        else{
            r++;
        }
    }

    if(found){
        cout << "Element found";
    }
    else{
        cout << "element does not exist";
    }

    return 0;
}
/**
//Minimum and Maximum element in array
//TC O(n)  SC O(1)
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        int n = arr.size();
        if (n == 0) return {-1, -1};

        int mini = arr[0], maxi = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] < mini) mini = arr[i];
            if (arr[i] > maxi) maxi = arr[i];
        }

        return {mini, maxi};

    }
};
/**
//Reverse the array
//TC O(n)   SC O(1)
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        for (int i=0; i<n/2; i++){
            int temp=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=temp;
        }
    }
};
/**
//Find the subarray of maximum sum
//-1 4 7 2
//Brut force aproach:O(n^3)
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }

    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            sum = 0;
            for (int k = i; k <= j; k++){
                sum += a[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;
    return 0;
    }
/**
//find subarray of maximum sum
//Brute force aproach:O(n^2)
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
         cin>>a[i];
    }

    int maxsum = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = 0;
        for (int j = i; j < n; j++){
            sum += a[j];
            maxsum = max(maxsum, sum);
        }
    }

    cout << maxsum << endl;
    return 0;
}
/**
//Find the subarray of maximum sum
//Cumilative sum:O(n^2)
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }

    int currSum[n + 1];
    currSum[0] = 0;
    for (int i = 1; i <= n; i++){
        currSum[i] = currSum[i - 1] + a[i - 1];
    }

    int maxSum = INT_MIN;
    for (int i = 1; i <= n; i++){
        int sum = 0;
        for (int j = 0; j < i; j++){
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }

    cout << maxSum << endl;
    return 0;
    }
/**
//Find the subarray of maximum sum
//Kadane method:O(n)
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }

    int sum = 0;
    int maxsum = INT_MIN;
    for (int i=0; i<n; i++){
        sum += a[i];
        maxsum = max(maxsum, sum);//Our credit
        if(sum<0){
            sum = 0;
        }
    }

    cout << maxsum << endl;
    return 0;
    }
/**
//Contain duplicates or not
//Brut force: TC O(n^2)  SC O(1)
for(int i=0; i<nums.size(); i++){
    for(int j=i+1; j<nums.size(); j++){
        if(nums[i]==nums[j]){
            return true;
        }
    }
    return false;
}
/**
//Better Aproach: TC O(nlogn),  SC O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (nums.size() - 1); i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
/**
//Optimal Aproach: TC O(n)  SC O(n)
class Solution {
  public:
    bool checkDuplicates(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> temp(1e4+1, -1);
        for(int i=0; i<n; i++){
            if(temp[arr[i]]==-1){
                temp[arr[i]]=1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
/**
//Chocolate distribution
//7 3
//7 3 2 4 9 12 56
//Time Complexity: O(n log n)
//Auxiliary Space: O(1)

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        //if(m==1) return 0;

        int n = a.size();
        sort(a.begin(), a.end());
        int i=0, j=m-1, ans=INT_MAX;

        while(j<n){
            ans=min(ans, a[j]-a[i]);
            i++,j++;
        }

        return ans;
    }
};

/**
//SearchInrotatedArray
//7 0
//4 5 6 7 0 1 2
//Brut Force: TC O(n), SC O(1)
//Linear Search

//SearchInrotatedArray
//7 0
//4 5 6 7 0 1 2
//Optimal Aproach: TC O(logn),  SC O(1)
//Binary Search

#include<iostream>
using namespace std;

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        int n=arr.size();
        int i=0, j=n-1;

        while(i<=j){
            int m=(i+j)/2;

            if(arr[m]==key){
                return m;
            }

            if(arr[i]<=arr[m]){
                if(arr[i]<=key && key<=arr[m]){
                    j=m-1;
                }
                else{
                    i=m+1;
                }
            }
            else {
                if(arr[m]<=key && key<=arr[j]){
                    i=m+1;
                }
                else {
                    j=m-1;
                }
            }
        }
        return -1;
    }
};
/**
// Next Permutation
// 1 3 6 5 4 2 1
//Time Complexity: O(n)
//Auxiliary Space: O(1)
class Solution {
    public:
      void nextPermutation(vector<int>& arr) {
          // code here
          int n=arr.size();
          int i=n-2, j=n-1, temp;

          while(i>=0 && arr[i]>=arr[i+1]){
              i--;
          }

          if(i>=0){
              while(arr[i]>=arr[j]){
                  j--;
              }
              temp=arr[i];
              arr[i]=arr[j];
              arr[j]=temp;
          }

          i++, j=n-1;
          while(i<j){
              temp=arr[i];
              arr[i]=arr[j];
              arr[j]=temp;
              i++,j--;
          }
      }
  };
/**
//Best day to buy and sell stock
//7 1 5 3 6 4
//Brut force aproach
//TC O(n^2)
#include<iostream>
using namespace std;

int profit(int a[], int n){
    int maxdiff = INT_MIN;
    int diff = 0;
    for (int i = 0; i < n - 1; i++){
        for(int j=i+1; j<n; j++){
            diff = a[j] - a[i];
            maxdiff = max(maxdiff, diff);
        }
    }
    return maxdiff;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << profit(a, n);
    return 0;
}
/**
//Best day to buy and sell stock
//7 1 5 3 6 4
//Optimal Aproach
//TC O(n)
#include<iostream>
using namespace std;

int profit(int price[], int n){
    int maxprofit = 0;
    int minprice = INT_MAX;
    for (int i = 0; i<n; i++){
        minprice = min(minprice, price[i]);
        maxprofit = max(maxprofit, price[i] - minprice);
    }
    return maxprofit;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << profit(a, n);
    return 0;
}
/**
//Best time to buy and sell stock||
//TC O(n)  SC O(1)
 Solution {
  public:
    // Function to find the days of buying and selling stock for max profit.
    int stockBuySell(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i, j=0, ans=0;

        for(i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                ans+=arr[i]-arr[j];
                j=i+1;
            }
        }
        ans += arr[i]-arr[j];

        return ans;
    }
};
/**
//To find repeat and missing number
//TC O(n)
#include<iostream>
using namespace std;

void repeatmiss(int a[], int n){
    int res[99];
    int miss, repeat;
    for (int i = 1; i < 99; i++){
        res[i] = -1;
    }
    for (int i = 0; i < n; i++){
        if(res[a[i]] != -1){
            repeat = a[i];

        }
        else{
            res[a[i]] = i;
        }
    }
    for (int i = 1; i < 99; i++){
       if (res[i] == -1){
           miss = i;
           break;
       }
    }
    cout << repeat << " " << miss << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    repeatmiss(a, n);

    return 0;
}
/**
//To find kth largest element
//TC O(nlogn) SC O(1)
#include<iostream>
using namespace std;

int larg(int a[], int n, int k){
    int count = 1;
    while(count < n-1) {
        for(int i=0; i<n-count; i++) {
            if(a[i] > a[i+1]) {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        count++;
    }
    return a[n - k];
}
/**
//To find kth smallest element
//TC O(nlogn) SC O(1)
#include<iostream>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        return arr[k-1];
    }
};
/**
//To find kth smallest element
//max heap
//TC O(nlogk) SC O(1)
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int, vector<int>> pq;
        int n=arr.size();
        for(int i=0; i<n; i++){
            if(pq.size()<k){
                pq.push(arr[i]);
            }
            else if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};
//Note:Use min heap to find kth larges element
/**
//To find kth smallest element
//Count Fort method
//Time Complexity: O(n + max_element-min_element)
//Auxiliary Space: O(n + max_element-min_element)
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int mn=INT_MAX;
        int mx=INT_MIN;
        int remain=k;

        for (int i=0; i<n; i++){
            mn=min(mn, arr[i]);
            mx=max(mx, arr[i]);
        }
        vector<int> count(mx-mn+1, 0);
        for (int i=0; i<n; i++){
            count[arr[i]-mn]++;
        }
        for(int i=0; i<count.size(); i++){
            remain -=count[i];
            if(remain<=0){
                return i+mn;
            }
        }

        return -1;
    }
};
/**
//To find trapped rain water
//4 2 0 3 2 5
//Brut Force Aproach:TC O(n^2)   SC O(1)
#include <iostream>
#include <vector>
using namespace std;

// Function to return the maximum water that can be stored
int maxWater(vector<int>& arr) {
    int res = 0;

    // For every element of the array
    for (int i = 1; i < arr.size() - 1; i++) {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res += (min(left, right) - arr[i]);
    }

    return res;
}

int main() {
    vector<int> arr = { 2, 1, 5, 3, 1, 0, 4 };
    cout << maxWater(arr);
    return 0;
}
/**
//To find trapped rain water
//4 2 0 3 2 5
//Better Aproach:TC O(n)   SC O(n)
#include <bits/stdc++.h>
using namespace std;

int maxWater(vector<int>& arr) {
    int n = arr.size();

    // Left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    vector<int> left(n);

    // Right[i] contains height of tallest bar to
    // the right of i'th bar including itself
    vector<int> right(n);

    int res = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    // Calculate the accumulated water element by element
    for (int i = 1; i < n - 1; i++) {
        int minOf2 = min(left[i], right[i]);
            res += minOf2 - arr[i];
    }

    return res;
}

int main() {
    vector<int> arr = { 2, 1, 5, 3, 1, 0, 4 };
    cout << maxWater(arr);
    return 0;
}

/**
//To find trapped rain water
//4 2 0 3 2 5
//Optimal Aproach: TC O(n)   SC O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int left=0, right=n-1;
        int lmx=arr[left], rmx=arr[right];
        int ans=0;

        while(left<right){
            if(arr[left]<arr[right]){
                lmx=max(lmx, arr[left]);
                ans+=(lmx-arr[left]);
                left++;
            }
            else{
                rmx=max(rmx, arr[right]);
                ans+=(rmx-arr[right]);
                right--;
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << water(a, n);

    return 0;
}
/**
//1 3 4 2
//Product of an array except self
//Brut force aproach
//TC O(n^2)   SC O(n)
#include<iostream>
using namespace std;

class Solution {
    public:
      vector<int> productExceptSelf(vector<int>& arr) {
          // code here
          int n=arr.size();
          vector<int>res(n, 1);

          for(int i=0; i<n; i++){
              for(int j=0; j<n; j++){
                  if(i!=j){
                      res[i]*=arr[j];
                  }
              }
          }

          return res;
      }
  };

/**
//Product of an array except self
//1 4 3 2
//Better Aproach
//TC O(n)   SC O(n)
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> sufix(n, 1);
        vector<int> res(n);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            sufix[i] = sufix[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = prefix[i] * sufix[i];
        }
        return res;
    }
};
/**
//Product of an array except self
//1 4 3 2
//Time Complexity: O(n)
//Auxiliary Space: O(1)

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>res(n, 1);
        long long left=1;
        long long right=1;

        for(int i=0; i<n; i++){
            res[i]=left;
            left*=arr[i];
        }
        for(int i=n-1; i>=0; i--){
            res[i]*=right;
            right*=arr[i];
        }

        return res;
    }
};
/**
//Maximum product subarray
//Brut force aproach
//TC O(n^2)   SC O(1)
//2 3 -2 4,  -2 0 -1,  1 -3 2 -5 -4 2
// C++ program to find Maximum Product Subarray
// using nested loops

#include <bits/stdc++.h>
using namespace std;

// Function to return the product of max product subarray
int maxProduct(vector<int> &arr) {
    int n = arr.size();

    // Initializing result
    int result = arr[0];

    for (int i = 0; i < n; i++) {
        int mul = 1;

        // traversing in current subarray
        for (int j = i; j < n; j++) {
            mul *= arr[j];

            // updating result every time
            // to keep track of the maximum product
            result = max(result, mul);
        }
    }
    return result;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}

/**
//Optimal aproach
//TC O(n)  SC O(1)
//2 3 -2 4,  -2 0 -1,  1 -3 2 -5 -4 2
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        int left=1, right=1;
        int max_prdct=INT_MIN;

        for(int i=0; i<n; i++){
            if(left==0) left=1;
            if(right==0) right=1;

            left *= arr[i];
            right *= arr[n-1-i];

            max_prdct=max(max_prdct, max(left, right));
        }

        return max_prdct;
    }
};
/**
//Minimum in roted sorted array
//3 4 5 1 2,  4 5 6 7 0 1 2
//Brut force aproach: TC O(n)   SC O(1)
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& arr) {

    int res = arr[0];

    // Traverse over arr[] to find minimum element
    for (int i = 1; i < arr.size(); i++)
        res = min(res, arr[i]);

    return res;
}

int main() {
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    int n = arr.size();

    cout << findMin(arr) << endl;
    return 0;
}

/**
//Minimum in roted sorted array
//Optimal aproach
//TC O(logn)   SC O(1)
//3 4 5 1 2, 4 5 6 7 0 1 2
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        int mn=INT_MAX;

        while(low<=high){
            int mid=(low+high)/2;

            if(arr[low]<=arr[high]) {
                return min(mn,  arr[low]);
            }

            if(arr[low]<=arr[mid]){
                mn=min(mn, arr[low]);
                low=mid+1;
            }
            else {
                mn=min(mn, arr[mid]);
                high=mid-1;
            }
        }

        return mn;
    }
};
/*
//11 15 6 8 9 10 x=16,  11 15 26 38 9 10 x=35=45,
//If there is pair with sum equal to given k in rotated sorted array
//Brut force aproach
//TC O(n^2)   SC O(1)
#include<iostream>
using namespace std;

bool pairsum(int a[], int n, int key){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] + a[j] == key)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << pairsum(a, n, k) << endl;

    return 0;
}
/*
//11 15 6 8 9 10 x=16,  11 15 26 38 9 10 x=35=45,
//If there is pair with sum equal to given k in rotated sorted array
//better aproach:TC O(nlogn)  SC O(1)
//Sort the array and aply Two-Pointer aproach
/*
//11 15 6 8 9 10 x=16,  11 15 26 38 9 10 x=35=45,
//If there is pair with sum equal to given k in rotated sorted array
//Optimal aproach:TC O(n)  SC O(1)
//Two-Pointer Aproach
#include<iostream>
using namespace std;

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int pivot=-1, low, high;

        for (int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]) {
                pivot=i;
            }
        }

        if(pivot==-1){
            pivot=n-1;
        }

        low=(pivot+1)%n;
        high=pivot;

        while(low!=high){
            int sum=arr[low]+arr[high];
            if(sum==target) return true;

            if(sum<target){
                low=(low+1)%n;
            }else{
                high=(n+high-1)%n;
            }
        }

        return false;
    }
};
/*
//3sum
//Brutforce Aproach: TC O(n^3)   SC O(1)
//for(i=0)for(j=i+1)for(k=j+1)....

//3sum
//Optimal Aproach: TC O(n^2)   SC O(1)
//-1 0 1 2 -1 -4,  0 1 1,  0 0 0,
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        int n=arr.size();
        sort(arr.begin(), arr.end());

        for(int i=0; i<n-2; i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            int low=i+1, high=n-1;

            while(low<high){
                int sum=arr[i]+arr[low]+arr[high];
                if(sum==target){
                    return true;
                }
                else if(sum<target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }

        return false;
    }
};
//3sum  LeetCode Problem
//Optimal Aproach: TC O(n^2)   SC O(1)
//-1 0 1 2 -1 -4,  0 1 1,  0 0 0,
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    while (low < high && nums[high] == nums[high - 1]) {
                        high--;
                    }
                    low++;
                    high--;
                } else if (sum < 0) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        return result;
    }
};
/**
//Container with most water
//1 8 6 2 5 4 8 3 7
//Brute force aproach: TC O(n^2)   SC O(1)
// C++ Program to find the maximum amount of water
// by iterating over all possible boundaries

#include <vector>
#include <iostream>
using namespace std;

int maxWater(vector<int> &arr) {
    int n = arr.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            // Calculate the amount of water
            int amount = min(arr[i], arr[j]) * (j - i);

            // Keep track of maximum amount of water
            res = max(amount, res);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 1, 8, 6, 4, 6, 5, 5};
    cout << maxWater(arr);
}
/**
//Optimal aproach:Two-Pointer
//Time Complexity: O(n)
//Auxiliary Space: O(1)
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0, j=n-1, max_water=0;

        while(i<j){
            int water=(j-i)*min(arr[i], arr[j]);
            max_water = max(water, max_water);

            if(arr[i]<arr[j]){
                i++;
            }else{
                j--;
            }
        }

        return max_water;
    }
};
/**
//Kth smallest element with left and right index
//7 10 4 3 20 15 k=3
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res[n];
    for(int i=0; i<n; i++){
        res[i] = a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++){
        if(res[k-1]==a[i]){
            cout << i << " " << n - 1 - i;
            break;
        }
    }
        return 0;
}
/**
 //Merge Overlaping intervals
 //Time Complexity: O(n log n)
 //Note:We have solve problem in O(n) time but we also have sorted array which took O(n log n) time
//Auxiliary Space: O(1)
 //{{1,3},{2,4},{6,8},{9,10}}  {{6,8},{1,9},{2,4},{4,7}}
 Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>res;
        int i=0;

        sort(arr.begin(), arr.end());

        while(i<n){
            int j=i+1;
            while(j<n && arr[i][1]>=arr[j][0]){
                arr[i][1]=max(arr[i][1],arr[j][1]);
                j++;
            }
            res.push_back(arr[i]);
            i=j;
        }

        return res;
    }
};
/**
//Minimum number of merge operations to make an array polindrom
//TC O(n)   SC O(1)
//15 4 15,  1 4 5 1, 11 14 15 99
#include<iostream>
using namespace std;

int operations(int a[], int n){
    int l = 0, r = n - 1;
    int ans = 0;
    while(l<r){
        if(a[l]==a[r]){
            l++;
            r--;
        }
        else if(a[l]<a[r]){
            l++;
            a[l] += a[l - 1];
            ans++;
        }
        else{
            r--;
            a[r] += a[r + 1];
            ans++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << operations(a, n);

    return 0;
}

/*
//Arrange the numbers to form biggest number
//Time Complexity: O(n log n)
//Auxiliary Space: O(n)
class Solution {
  public:
    static bool myCompaire(string &s1, string &s2) {
        return (s1 + s2) > (s2 + s1);
    }

    string findLargest(vector<int> &arr) {
        int n = arr.size();
        vector<string> numbers;
        for (int i = 0; i < n; i++) {
            numbers.push_back(to_string(arr[i]));
        }

        sort(numbers.begin(), numbers.end(), myCompaire);

        if (numbers[0] == "0") {
            return "0";
        }

        string res = "";
        for (string &num : numbers) {
            res += num;
        }

        return res;
    }
};
/**
// Longest subarray with sum divisible by k
//Brute force aproach  TC O(n^2)  SC O(1)
// 2 7 6 1 4 5 k=3;
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // Complete the function
        int n=arr.size();
        int max_len=0;
        
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum = (sum + arr[j]) % k;
                
                if(sum==0){
                    max_len=max(j-i+1, max_len);
                }
            }
        }
        
        return max_len;
    }
};
/*
// function to find the longest subarray with sum divisible by k
//Optimal Aproach:PrefixSum Time Complexity: O(n)   Auxiliary Space: O(min(n, k))
//Note:every onen has some extra value and trying to subtract and become divisible by k
//positive try to become 0 and negative try to become -k*n

class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // Complete the function
        int n=arr.size();
        unordered_map<int, int>prefix;
        int max_len=0, sum=0;
        
        for(int i=0; i<n; i++){
            sum = (((sum + arr[i]) % k)+k)%k;
            
            if(sum==0){
                max_len=i+1;
            }
            else if(prefix.find(sum) != prefix.end()){
                max_len=max(i-prefix[sum], max_len);
            }
            else{
                prefix[sum]=i;
            }
        }
        
        return max_len;
    }
};
*/