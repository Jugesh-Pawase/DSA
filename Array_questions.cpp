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
/**/
// Next Permutation
// 1 3 6 5 4 2 1
#include <iostream>
using namespace std;

void reverse(int a[], int n, int start)
{
    int end = n - 1;
    while (start < end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

void nextPermutation(int a[], int n)
{
    int i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1])
    {
        i--;
    }
    if (i >= 0)
    {
        int j = n - 1;
        while (j >= 0 && a[i] >= a[j])
        {
            j--;
        }
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    reverse(a, n, i + 1);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Current permutation: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    nextPermutation(a, n);
    cout << "Next peermutation: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
/**
//Best day to buy and sell stock
//7 1 5 3 6 4
//Brut force aproach
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
//To find repeat and missing number
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

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << larg(a, n, k);

    return 0;
}
/**
//To find trapped rain water
//4 2 0 3 2 5
#include<iostream>
using namespace std;

int water(int a[], int n){
    int left = 0, right=n-1, ans=0;
    int leftmax = 0, rightmax = 0;
    while(left<=right){
        if(leftmax<=rightmax){
            if(leftmax<=a[left]){
                leftmax = a[left];
            }
            else{
                ans = ans + (leftmax - a[left]);
            }
            left++;
        }
        else{
            if(rightmax<=a[right]){
                rightmax = a[right];
            }
            else{
                ans = ans + (rightmax - a[right]);
            }
            right--;
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
    cout << water(a, n);

    return 0;
}
/**
//1 3 4 2
//Product of an array except self
//Brut force aproach
#include<iostream>
using namespace std;

void product(int a[], int n){
    int res[n];
    for (int i = 0; i < n; i++){
        int ans = 1;
        for (int j = 0; j < n; j++){
            if(j!=i){
                ans = ans * a[j];
            }
        }
        res[i] = ans;
    }
    for(int i=0; i<n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Original array: ";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Product array: ";
    product(a, n);
    return 0;
}

/**
//Product of an array except self
//1 4 3 2
#include<iostream>
using namespace std;

void product(int a[], int n){
    int prefixsum[n], sufixsum[n], res[n];
    prefixsum[0] = 1, sufixsum[n - 1] = 1;
    for (int i = 1; i < n; i++){
        prefixsum[i] = prefixsum[i - 1] * a[i - 1];
    }
    for (int i = n-2; i >-1; i--){
        sufixsum[i] = sufixsum[i + 1] * a[i + 1];
    }
    for (int i = 0; i < n; i++){
        res[i] = prefixsum[i] * sufixsum[i];
    }
    for (int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Original array: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Product array: ";
    product(a, n);

    return 0;
}
/**
//Maximum product subarray
//Brut force aproach
//2 3 -2 4,  -2 0 -1,  1 -3 2 -5 -4 2
#include<iostream>
using namespace std;

int maxprosub(int a[], int n){
    int pro = 1;
    int maxpro = INT_MIN;
    for (int i = 0; i < n; i++){
        pro = pro * a[i];
        maxpro = max(maxpro, pro);
        if(pro<=0){
            pro = 1;
        }
    }
    return maxpro;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << maxprosub(a, n);

    return 0;
}
/**
//Optimal aproach
//2 3 -2 4,  -2 0 -1,  1 -3 2 -5 -4 2
#include<iostream>
using namespace std;

int maxprosub(int a[], int n){
    int prefix = 1;
    int sufix = 1;
    int maxpro = INT_MIN;
    for (int i = 0; i < n; i++){
        prefix = prefix * a[i];
        sufix = sufix * a[n - 1 - i];
        maxpro = max(maxpro, max(prefix, sufix));
        if(prefix==0){
            prefix = 1;
        }
        if(sufix==0){
            sufix = 1;
        }
    }
    return maxpro;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << maxprosub(a, n);

    return 0;
}
/**
//Minimum in roted sorted array
//3 4 5 1 2,  4 5 6 7 0 1 2
//My brut force aproach
#include<iostream>
using namespace std;
int minimum(int a[], int n){
    int low = 0, high = n - 1;
    int minimum = INT_MAX;
    while(low<=high){
        minimum = min(minimum, min(a[low], a[high]));
        low++;
        high--;
    }
    return minimum;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << minimum(a, n) << endl;

    return 0;
}

/**
//Minimum in roted sorted array
//Optimal aproach
//3 4 5 1 2, 4 5 6 7 0 1 2
#include<iostream>
using namespace std;

int minimum(int a[], int n){
    int low = 0, mid, high = n - 1, ans = INT_MAX;
    while(low<=high){
        mid = (low + high) / 2;

        //if(a[low]<=a[mid] && a[mid]<=a[high]){ this syntax is 100% correct
        //    ans = min(ans, a[low]);
        //    break;
        //}

        if(a[low]<a[mid]){
            ans = min(ans, a[low]);
            low = mid + 1;
        }
        else{
            ans=min(ans, a[mid]);
            high = mid - 1;
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

    cout << minimum(a, n);
    return 0;
}
/*
//11 15 6 8 9 10 x=16,  11 15 26 38 9 10 x=35=45,
//If there is pair with sum equal to given k in rotated sorted array
//Brut force aproach
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
//Optimal aproach
#include<iostream>
using namespace std;

bool pairsum(int a[], int n, int key){
    int i, low, high;
    for (i = 0; i < n; i++){
        if(a[i]>a[i+1]){
            break;
        }
    }
    high = i, low = i + 1;
    while(low!=high){
        if(a[low]+a[high] == key){
            return true;
        }
        else if(a[low]+a[high] < key){
            low = (low + 1) % n;
        }
        else{
            high = (n + high - 1) % n;
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
//3sum
//-1 0 1 2 -1 -4,  0 1 1,  0 0 0,
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

    sort(a, a+n);

    for(int i=0; i<n-2; i++){
        if (i > 0 && a[i] == a[i - 1]) {
                continue;
            }
        int low = i + 1, high = n - 1;
        while(low<high){
            int sum = a[i] + a[low] + a[high];
            if(sum==k){
                cout << a[i] << " " << a[low] << " " << a[high] << endl;
                while (low < high && a[low] == a[low + 1]) {
                        low++;
                    }
                while (low < high && a[high] == a[high - 1]) {
                    high--;
                    }
                low++;
                high--;
            }
            else if(sum<k){
                low++;
            }
            else{
                high--;
            }
        }
    }

    return 0;
}
/**
//Container with most water
//1 8 6 2 5 4 8 3 7
//Brute force aproach: O(n^2)
//Optimal aproach: O(n)
#include<iostream>
using namespace std;

int water(int a[], int n){
    int l = 0, r = n - 1, ans = 0;
    while(l<r){
        int lh = a[l];
        int rh = a[r];
        int minh = min(lh, rh);
        ans = max(ans, minh * (r - l));
        if(lh<rh){
            l++;
        }
        else{
            r--;
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
    cout << water(a, n);
    return 0;
}
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
 //{{1,3},{2,4},{6,8},{9,10}}  {{6,8},{1,9},{2,4},{4,7}}
 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;

vector<vector<int>> overlappedInterval(vector<vector<int>> intervals){
    vector<vector<int>> res;
    if(intervals.size()==0){
        return res;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];
    for(auto it : intervals){
        if(temp[1]>=it[0]){
            temp[1] = max(temp[1], it[0]);
        }
        else{
            res.push_back(temp);
            temp = it;
        }
    }
    res.push_back(temp);
    return res;
}

 int main()
 {
    vector<vector<int>> intervals = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    vector<vector<int>> merged = overlappedInterval(intervals);

    cout << "The Merged Intervals are: ";
    for (auto it : merged) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
 }
/**
//Minimum number of merge operations to make an array polindrom
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
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool comparator(string first,string second)
{
    string one = first+second;
    string two = second+first;

    int i=0;
    while(one[i] && two[i])
    {
        if(one[i]>two[i])
            return true;
        else if(one[i]<two[i])
            return false;
        ++i;
    }

    return false;
}

int main() {
    //code
    int tc;
    cin>>tc;
    while(tc--)
    {
        int len;
        vector<string> arr;

        //Take Array inputs
        int i;
        string temp;
        cin>>len;
        for(i=0; i<len; ++i)
        {
            cin>>temp;
            arr.push_back(temp);
        }

        sort(arr.begin(),arr.end(),comparator);

        for(i=0; i<len; ++i)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
/**
// Longest subarray with sum divisible by k
//Brute force aproach  TC O(n^2)  SC O(1)
// 2 7 6 1 4 5 k=3;
#include<iostream>
using namespace std;

int length(int a[],int n, int k){
    int count = 0, maxCount = 0;
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = i; j < n; j++){
            sum += a[j];
            if(sum%k == 0){
                count = j - i + 1;
            }
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << length(a, n, k);
    return 0;
}
/*
// function to find the longest subarray with sum divisible by k
#include <bits/stdc++.h>
using namespace std;

int longestSubarrWthSumDivByK(int arr[], int n, int k)
{
    // unordered map 'um' implemented as
    // hash table
    unordered_map<int, int> um;

    int max_len = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];

        int mod = ((curr_sum % k) + k) % k;

        // if true then sum(0..i) is divisible
        // by k
        if (mod == 0)
            // update 'max_len'
            max_len = i + 1;

        // if value 'mod_arr[i]' not present in 'um'
        // then store it in 'um' with index of its
        // first occurrence
        else if (um.find(mod) == um.end())
            um[mod] = i;

        else
            // if true, then update 'max_len'
            if (max_len < (i - um[mod]))
            max_len = i - um[mod];
    }

    // return the required length of longest subarray with
    // sum divisible by 'k'
    return max_len;
}

int main()
{
    int arr[] = { 2, 7, 6, 1, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Length = "
        << longestSubarrWthSumDivByK(arr, n, k);

    return 0;
}
*/