/**
//Check whether permutation of two arrays satisfy the condition a[i] + b[i] >= k.
//TC: O(nlogn)    SC O(1)
class Solution {
  public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
        // Your code goes here
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end(), greater<int>());

        for(int i=0; i<arr1.size(); i++){
            if(arr1[i]+arr2[i]<k) return false;
        }

        return true;
    }
};
/*
//Common Elements in Three Sorted Arrays
//BrutForce Aproach
//TC O(n1+n2+n3)   SC O(n1+n2+n3) of unordered_map
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{
    int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
    map<int, int> mp;

    for (int i = 0; i < n1; i++){
        mp[arr1[i]] = 1;
    }
    for (int i = 0; i < n2; i++){
        if(mp[arr2[i]]==1){
            mp[arr2[i]] = 2;
        }
    }
    for (int i = 0; i < n3; i++){
        if(mp[arr3[i]]==2){
            mp[arr3[i]] = 3;
        }
    }

    vector<int> res;
    for (auto ele : mp){
        if (ele.second == 3){
            res.push_back(ele.first);
        }
    }

    return res;
}
/**
// Function to find common elements in three arrays.
//Optimal Aproach:TC O(l+m+n)   SC O(1)
class Solution {
  public:
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int i=0, j=0, k=0;
        int l=arr1.size(), m=arr2.size(), n=arr3.size();
        vector<int> res;

        while(i<l && j<m && k<n){
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
                res.push_back(arr1[i]);

                while(arr1[i]==arr1[i+1] && i<l){
                    i++;
                }
                while(arr2[j]==arr2[2+1] && j<m){
                    j++;
                }
                while(arr3[k]==arr3[k+1] && k<n){
                    k++;
                }
                i++,j++,k++;
            }
            else if(arr1[i]<arr2[j]){
                i++;
            }
            else if(arr2[j]<arr3[k]){
                j++;
            }
            else{
                k++;
            }
        }

        if(res.empty()){
            res.push_back(-1);
            return res;
        }
        else{
            return res;
        }
    }
};
/**
//Search an element in an array where difference between adjacent elements is atmost k
//Brutforce:TC O(n). SC O(1)
class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // code here
        int n=arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]==x) return i;
        }
        return -1;
    }
};
/**
//Search an element in an array where difference between adjacent elements is atmost k
//Optimal Approach: TC O(n) SC O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // code here
        int n=arr.size(), i=0;
        while(i<n){
            if(arr[i]==x) return i;
            i = i+max(1, abs(arr[i]-x)/k);
        }
        return -1;
    }
};
/**
//Celling in sorted array
//Brut Force: TC O(n)   SC O(1)
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        if(arr[n-1]<x) return -1;
        for(int i=0; i<n; i++){
            if(arr[i]>=x) return i;
        }
    }
};

/*
//Celling in sorted array
//Optimal Aproach: TC O(logn) SC O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        if(arr[n-1]<x) return -1;
        int low=0, high=n-1, res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<x){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};
/**
//Pair with given difference
//Brut force: TC O(n*m) SC O(1)
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
        int n=arr.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int diff=abs(arr[j] - arr[i]);
                if(diff == x) {
                    return true;
                }
            }
        }
        return false;
    }
};
/**
// Pair with given difference
// Better aproach(binary search): TC O(n*logn) SC O(1)
 class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            int target = arr[i] + x;
            if (binary_search(arr.begin() + i + 1, arr.end(), target)) {
                return true;
            }
        }

        return false;
    }
};
 /**
 // Pair with given difference
// Better aproach(two pointer): TC O(n*logn) SC O(1)
 class Solution {
  public:
   bool findPair(vector<int> &arr, int x) {
    int n = arr.size();

    sort(arr.begin(), arr.end());
    int j = 1;
    for (int i=0; i<n-1; i++) {
        while (j<n && arr[j]-arr[i] < x) j++;
        if(i==j) j++;  //when x=0
        if (j<n && i != j && arr[j]-arr[i] == x) return true;
    }

    return false;
   }
};
 /**
 // Pair with given difference
// Optimal aproach: TC O(n) SC O(n)
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        unordered_map<int, int> mp;
        int n=arr.size();

        for (int i = 0; i < n; i++){
            mp[arr[i]] += 1;
        }
        for (int i = 0; i < n; i++){
            int y = arr[i] + x;
            if(x==0){
                if(mp[y]>=2) return true;
            }
            else{
                if(mp[y]) return true;
            }
        }
        return false;
    }
};
 /**
 // Majority element in an array
 //Brut force:  TC-O(n^2)  SC-O(1)
class Solution{
public:
    int majorityElement(vector<int> &arr){
        // code here
        int n = arr.size();
        int maxCount = 0, ele;
        for (int i = 0; i < n; i++){
            int count = 0;
            for (int j = 0; j < n; j++){
                if (arr[i] == arr[j]) count++;
            }

            if (count > maxCount){
                maxCount = count;
                ele=arr[i];
            }
        }

        if (maxCount > n / 2){
            return ele;
        }
        else{
            return -1;
        }
    }
};
/*
//Majority element in an array
//Brut force:  TC-O(n)  SC-O(n)
class Solution{
public:
    int majorityElement(vector<int> &arr){
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (auto ele : mp)
        {
            if (ele.second > n / 2)
                return ele.first;
        }
        return -1;
    }
};
/*
//Majority element in an array
//Optimal Aproach: TC-O(n)   SC-O(1)
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ele=arr[0], count=1;
        for(int i=1; i<n; i++){
            if(ele==arr[i]){
                count++;
            }
            else{
                count--;
                if(count<0){
                    ele=arr[i];
                    count=1;
                }
            }
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            if(arr[i]==ele) cnt++;
        }

        if(cnt > n/2){
            return ele;
        }
        else{
            return -1;
        }
    }
};
/*
// count triplets with sum smaller than a given value
//Brut force:  TC O(n^3)  SC O(1)
#include <bits/stdc++.h>
using namespace std;

int countTriplets(int arr[], int n, int sum)
{
    // Initialize result
    int ans = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++)
                if (arr[i] + arr[j] + arr[k] < sum)
                    ans++;
        }
    }
    return ans;
}
/**
//Triplets with sum is less than k
//Optimal Aproach (Three Pointer):   TC O(n^2)  SC O(1)
class Solution {
  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr, arr+n);
        int count = 0;
        for(int i=0; i<n-2; i++){
            int left=i+1, right=n-1;
            while(left<right){
                long long addition=arr[i]+arr[left]+arr[right];
                if(addition<sum){
                    count = count+(right-left);
                    left++;
                }
                else{
                    right--;
                }
            }
        }

        return count;
    }
};
/**
//Maximum sum subsequence with no adjacent elements
//DP/Memoization: TC (n)   SC O(n) of array and stack
class Solution {
  public:
    int rec(int i, int n, vector<int>& arr, vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];

        int ch1=arr[i] + rec(i+2, n, arr, dp);
        int ch2=rec(i+1, n, arr, dp);
        return dp[i]  = max(ch1, ch2);
    }

    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n, -1);
        return rec(0, n, arr, dp);
    }
};
//Recursion: TC O(2^n)  SC O(n) of arr due to recursive call
//Using tabulation: TC (n)   SC O(n) of stack
//Using space optimization: TC (n)   SC O(1)
/*
//Merge two sorted arrays
//Optimal Aproach-1O(nlogn + mlogm)   SC O(1)
class Solution{
public:
    void mergeArrays(vector<int> &a, vector<int> &b){
        // code here
        int n=a.size(), m=b.size();
        int left = 0, right = n - 1;
        while (left < m && right >= 0){
            if (a[right] > b[left]){
                swap(a[right], b[left]);
                left++;
                right--;
            }
            else{
                break;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};
/*
//Merge two sorted arrays
//Optimal Aproach-2 (Gap method): TC O((n+m)logn)    SC O(1)
class Solution
{
public:
    void swapFunc(int left, int right, vector<int> &a, vector<int> &b, int n)
    {
        if (left < n && right < n)
        {
            // both in a
            if (a[left] > a[right])
                swap(a[left], a[right]);
        }
        else if (left < n && right >= n)
        {
            // a and b
            if (a[left] > b[right - n])
                swap(a[left], b[right - n]);
        }
        else
        {
            // both in b
            if (b[left - n] > b[right - n])
                swap(b[left - n], b[right - n]);
        }
    }

    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size();
        int len = n + m;
        int gap = (len / 2) + (len % 2);

        while (gap > 0)
        {
            int left = 0, right = gap;
            while (right < len)
            {
                swapFunc(left, right, a, b, n);
                left++, right++;
            }

            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};
/*
//Count inversion
//brut force: TC O(n^2) SC O(1)
#include <bits/stdc++.h>
using namespace std;

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++;
        }
    }
    return cnt;
}
/**
//Count inversion
//Optimal Aproach: time complexity: O(nlogn) Space complexity: O(n)
class Solution{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int cnt = 0;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high){
            if (arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        while (left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high){
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++){
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high){
        int cnt = 0;
        if (low >= high){
            return 0;
        }
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);

        return cnt;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr){
        // Your Code Here
        int n=arr.size();
        return mergeSort(arr, 0, n-1);
    }
};
/*
//Find duplicates
//brut force aproach: time complexity O(n)   space complexity O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> duplicates(long long arr[], int n) {
    unordered_map<long long, int> freqMap;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    for (auto& entry : freqMap) {
        if (entry.second > 1) {
            result.push_back(entry.first);
        }
    }

    if (result.empty()) {
        result.push_back(-1);
    }
    sort(result.begin(),result.end());
    return result;
}
/*
//Find duplicates
//Optimal aproach: time complexity O(n)   space complexity O(1)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> duplicates(int arr[], int n){
    vector<int> res;
    int index;

    for (int i = 0; i < n; i++){
        index = arr[i] % n;
        arr[index] += n;
    }

    for (int i = 0; i < n; i++){
        if((arr[i]/n)>1){
            res.push_back(i);
        }
    }

    if(res.empty()){
        res.push_back(-1);
    }

    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 6, 3, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> result = duplicates(arr, n);
    for(auto it:result){
        cout << it << " ";
    }

    return 0;
}

/*
//Make all elements equal with minimum cost
//BrutForce aproach: TC O(n^2)   SC O(1)
int minCost(vector<int> &arr) {
    int n = arr.size();
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        int currentCost = 0;
        for (int j = 0; j < n; j++) {
            currentCost += abs(arr[j] - arr[i]);
        }
        ans = min(ans, currentCost);
    }

    return ans;
}
/*
//Make all elements equal with minimum cost
//Optimal aproach-1(Meidan): TC O(n)   SC O(1)
int mincost(int a[], int n){
    //sort(a, a+n);  if given array is not sorted
    int res = 0;
    int y;
    if(n%2==1){
        y = a[n / 2];
    }
    else{
        y = (a[n / 2] + a[(n - 2) / 2]) / 2;
    }

    for (int i = 0; i < n; i++){
        res += abs(a[i] - y);
    }

    return res;
}
/*
//Make all elements equal with minimum cost
//Optimal aproach-2(add difference): TC O(n)  Sc (1)
int minCost(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = 0;

    while(low<high){
        ans += arr[high] - arr[low];
        low++, high--;
    }

    return ans;
}
//To be solve(leetCode):Make all elements equal with minimum cost
/**
// Check whether reversing a sub array make the array sorted or not
//Brut force: TC O(nlogn)   SC O(n)
bool checkReverse(int arr[], int n)
{
    // Copying the array.
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];

    // Sort the copied array.
    sort(temp, temp + n);

    // Finding the first mismatch.
    int front;
    for (front = 0; front < n; front++)
        if (temp[front] != arr[front])
            break;

    // Finding the last mismatch.
    int back;
    for (back = n - 1; back >= 0; back--)
        if (temp[back] != arr[back])
            break;

    // If whole array is sorted
    if (front >= back)
        return true;

    // Checking subarray is decreasing or not.
    while (front < back)
    {
        if (arr[front] < arr[front+1])
            return false;
        front++;
    }

    return true;
}

// Driver Program
int main()
{
    int arr[] = { 1, 2, 5, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    checkReverse(arr, n)? (cout << "Yes" << endl):
                          (cout << "No" << endl);
    return 0;
}
/**
//Check if reversing subsarray make array sorted or not
//Optimal aproach   time complexity O(n)   space complexity O(1)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int n){
    int x = -1, y = -1;
    for (int i = 0; i < n-1; i++){
        if(a[i]>a[i+1]){
            if(x==-1){
                x = i;
            }
            y = i + 1;
        }
    }
    reverse(a + x, a + y + 1);
    if(x!=-1){
        for (int i = 0; i < n-1; i++){
            if(a[i]>a[i+1]){
                return false;
            }
        }
    }
    return true;
}
/*
//4sum
//Brut force   TC O(n^4)   SC O(n)
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
/**
//4sum
//Optimal aproach: time complexity O(n^3)   space complexity O(1)
class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        vector<vector<int>>res;
        for(int i=0; i<n-3; i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && arr[j]==arr[j-1]) continue;

                int low=j+1, high=n-1;
                while(low<high){
                    long long sum=arr[i]+arr[j]+arr[low]+arr[high];
                    if(sum==target){
                        res.push_back({arr[i], arr[j], arr[low], arr[high]});
                        low++, high--;

                        while(arr[low]==arr[low-1] && low<high) low++;
                        while(arr[high]==arr[high+1] && high>low) high--;
                    }
                    else if(sum<target){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }

        return res;
    }
};
/**
//Median of two sorted arrays
//Brut force  TC O(n)  SC O(n)
class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int n1=a.size(), n2=b.size();
        int n=n1+n2;
        vector<int>temp;

        int i=0, j=0;
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                temp.push_back(a[i++]);
            }
            else{
                temp.push_back(b[j++]);
            }
        }

        while(i<n1) temp.push_back(a[i++]);
        while(j<n2) temp.push_back(b[j++]);

        double ans;
        if(n%2 == 1){
            ans = temp[n/2];
        }
        else{
            ans = (temp[(n-2)/2]+temp[n/2])/2;
        }

        return ans;
    }
};
/**
//Median of two sorted arrays
//Better Aproach  TC O(n)  SC O(1)
class Solution{
public:
    double medianOf2(vector<int> &a, vector<int> &b){
        int n1 = a.size(), n2 = b.size();
        int n = n1 + n2;
        // required indices:
        int ind2 = n / 2;
        int ind1 = ind2 - 1;
        int cnt = 0;
        double ind1el = -1, ind2el = -1;

        int i = 0, j = 0;
        while (i < n1 && j < n2){
            if (a[i] < b[j]){
                if (cnt == ind1) ind1el = a[i];
                if (cnt == ind2) ind2el = a[i];
                cnt++, i++;
            }
            else{
                if (cnt == ind1) ind1el = b[j];
                if (cnt == ind2) ind2el = b[j];
                cnt++, j++;
            }
        }

        // copy the left-out elements:
        while (i < n1){
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++, i++;
        }
        while (j < n2){
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++, j++;
        }

        if (n % 2 == 1){
            return ind2el;
        }

        return (ind1el + ind2el) / 2;
    }
};
/**
//Median of two sorted arrays
//Optimal Aproach  TC O(min(logn1, logn2))  SC O(1)
class Solution{
public:
    double medianOf2(vector<int> &a, vector<int> &b){
        int n1 = a.size(), n2 = b.size();
        // if n1 is bigger swap the arrays:
        if (n1 > n2) return medianOf2(b, a);

        int n = n1 + n2;              // total length
        int left = (n1 + n2 + 1) / 2; // length of left half
        // apply binary search:
        int low = 0, high = n1;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            // calculate l1, l2, r1 and r2;
            double l1 = INT_MIN, l2 = INT_MIN;
            double r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1) r1 = a[mid1];
            if (mid2 < n2) r2 = b[mid2];
            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1){
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2;
            }

            // eliminate the halves:
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0; // dummy statement
    }
};
/**
//Median of stram data
//BrutForce: TC O(n*nlogn)=O(n^2logn)  SC O(n)
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        int n=arr.size();
        vector<double>temp, res;
        for(int i=0; i<n; i++){
            temp.push_back(arr[i]);
            sort(temp.begin(), temp.end());

            int m=temp.size();
            double ans;
            if(m%2 == 1){
                ans=temp[m/2];
            }
            else{
                ans=(temp[(m-2)/2]+temp[m/2])/2;
            }
            res.push_back(ans);
        }

        return res;
    }
};
/**
//Median of stram data
//Optimal Aproach: TC O(nlogn)  SC O(n)
class Solution{
public:
    // Max-heap for the left half
    priority_queue<int> left_max_heap;
    // Min-heap for the right half
    priority_queue<int, vector<int>, greater<int>> right_min_heap;
    // Insert new element into one of the heaps
    void addNum(int x){
        if (left_max_heap.empty() || x < left_max_heap.top()){
            left_max_heap.push(x);
        }
        else{
            right_min_heap.push(x);
        }

        // Balance the two heaps so that their sizes differ by at most 1
        if (left_max_heap.size() > right_min_heap.size() + 1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if (left_max_heap.size() < right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }

    // Get the current median
    double getCurrentMedian(){
        if (left_max_heap.size() == right_min_heap.size()){
            return (left_max_heap.top() + right_min_heap.top()) / 2.0;
        }
        else{
            return left_max_heap.top();
        }
    }

    // Main function to get median after each insertion
    vector<double> getMedian(vector<int> &arr){
        int n=arr.size();
        vector<double> res;
        for (int i=0; i<n; i++){
            addNum(arr[i]);
            res.push_back(getCurrentMedian());
        }
        return res;
    }
};
/**
//Find sub-arrays with zero sum
//BrutForce aproach  TC O(n^2)  SC O(1)
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int n=arr.size(), cnt=0;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum += arr[j];

                if(sum==0) cnt++;
            }
        }

        return cnt;
    }
};
/**
//Find sub-arrays with zero sum
//Optimal aproach  TC O(n)   SC O(n)
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        mp[0] = 1; // To count subarrays that sum to 0 from index 0

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (mp.find(sum) != mp.end()) {
                count += mp[sum];
            }
            mp[sum]++;
        }

        return count;
    }
};
/*
//Agrssive Cows
//BrutForce Aproach(without BinarySearch): TC O(n^2)  SC O(1)
//Agrssive Cows
//Optimal Aproach(BinarySearch): TC O(nlogn)  SC O(1)
class Solution {
  public:
    bool canWePlace(vector<int> &stalls, int dist, int k, int n){
        int cowCount=1, lastCow=stalls[0];
        for(int i=1; i<n; i++){
            if(stalls[i]-lastCow >= dist){
                cowCount++;
                lastCow=stalls[i];
            }
            if(cowCount >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int n=stalls.size(), ans=-1;
        int low=1, high=stalls[n-1]-stalls[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(canWePlace(stalls, mid, k, n)==true){
                //ans=mid
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        //return ans;
        return high;
    }
};
**/