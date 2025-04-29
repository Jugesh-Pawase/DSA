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
//Brut force
//TC O(n*m)
//SC O(1)

#include<bits/stdc++.h>
using namespace std;

void findPair(int arr[], int n, int diff) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(abs(arr[j] - arr[i]) == diff) {
                cout << "Pair Found: (" << arr[i] << ", " << arr[j] << ")";
                  return;
            }
        }
    }

      cout << "No such pair";
}

int main() {

    int arr[] = { 5, 20, 3, 2, 50, 80 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = 78;

    findPair(arr, n, diff);

    return 0;
}
/**
// Pair with given difference
// Better aproach:
//TC O(n*logn)
//SC O(1)
 #include<iostream>
 #include<algorithm>
 using namespace std;

void findPair(int arr[], int n, int diff) {
    sort(arr, arr + n);
    for(int i=0; i<n; i++) {
        int y = arr[i] + diff;
        int low = 0, high = n - 1;
        while(low<high){
            int mid = (low + high);
            if(arr[mid]==y){
                cout << "Pair Found: (" << arr[i] << ", " << arr[mid] << ")";
                  return;
            }
            else if(arr[mid]<y){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
      cout << "No such pair";
}

 int main()
 {
    int arr[] = { 5, 20, 3, 2, 50, 80 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = 78;

    findPair(arr, n, diff);

    return 0;
 }
 /**
 // Pair with given difference
// Optimal aproach:
//TC O(n)
//SC O(n)
 #include<iostream>
 #include<unordered_map>
 using namespace std;

void findPair(int arr[], int n, int diff) {
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++){
        mp[arr[i]] = 1;
    }
    for (int i = 0; i < n; i++){
        int y = arr[i] + diff;
        if(mp[y]){
            cout << "Pair Found: (" << arr[i] << ", " << y << ")";
                  return;
        }
    }
    cout << "Pair does not exist" << endl;
}

 int main()
 {
    int arr[] = { 5, 20, 3, 2, 50, 80 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = 78;

    findPair(arr, n, diff);

    return 0;
 }
 /**
 // Majority element in an array
 //Brut force:  TC-O(n^2)  SC-O(1)
#include <bits/stdc++.h>
using namespace std;

void findMajority(int arr[], int n)
{
    int maxCount = 0;
    int index = -1; // sentinels
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }

    if (maxCount > n / 2)
        cout << arr[index] << endl;

    else
        cout << "No Majority Element" << endl;
}

int main()
{
    int arr[] = { 1, 1, 2, 1, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    findMajority(arr, n);

    return 0;
}
/*
//Majority element in an array
//Brut force:  TC-O(n)  SC-O(n)
#include <bits/stdc++.h>
using namespace std;

void findMajority(int arr[], int size)
{
    unordered_map<int, int> m;
    for(int i = 0; i < size; i++)
        m[arr[i]]++;

    for (int i = 0; i < size; i++)
    {
        if(m[arr[i]] > size / 2)
        {
            cout << "Majority found : " << arr[i] <<endl;
            return;
        }
    }
        cout << "No Majority element" << endl;
}

int main()
{
    int arr[] = {2, 2, 2, 2, 5, 5, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMajority(arr, n);

    return 0;
}
/*
//Majority element in an array
//Optimal Aproach: TC-O(n)   SC-O(1)
#include<iostream>
#include<vector>
using namespace std;

int findMejority(vector<int> v){
    int n = v.size();
    int ele;
    int count = 0;

    //Most Voting Algorithm
    for (int i = 0; i < n; i++){
        if(count==0){
            ele = v[i];
            count++;
        }
        else if(ele==v[i]){
            count++;
        }
        else{
            count--;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++){
        if(ele==v[i]){
            cnt++;
        }
    }

    if(cnt>(n/2)){
        return ele;
    }
    else{
        return -1;
    }
}

int main()
{
    vector<int> v = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << findMejority(v) << endl;

    return 0;
}
/*
// count triplets with sum smaller than a given value
//Brut force  TC O(n^3)  SC O(1)
#include <bits/stdc++.h>
using namespace std;

int countTriplets(int arr[], int n, int sum)
{
    // Initialize result
    int ans = 0;

    // Fix the first element as A[i]
    for (int i = 0; i < n - 2; i++) {
        // Fix the second element as A[j]
        for (int j = i + 1; j < n - 1; j++) {
            // Now look for the third number
            for (int k = j + 1; k < n; k++)
                if (arr[i] + arr[j] + arr[k] < sum)
                    ans++;
        }
    }
    return ans;
}

// Driver program
int main()
{
    int arr[] = { 5, 1, 3, 4, 7 };
    int n = sizeof arr / sizeof arr[0];
    int sum = 12;
    cout << countTriplets(arr, n, sum) << endl;
    return 0; 
}
/**
//Triplets with sum is less than k
//Optimal   TC O(n^2)  SC O(1)
#include<iostream>
#include<algorithm>
using namespace std;

int triplets(int a[], int n, int max){
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n-2; i++){
        int j = i + 1;
        int k = n - 1;
        while(j<k){
            int sum = a[i] + a[j] + a[k];
            if(sum<max){
                ans += (k - j);
                j++;
            }
            else{
                k--;
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {5, 1, 3, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 12;

    cout << triplets(arr, n, max) << endl;

    return 0;
}
/**
//Maximum sum subsequence with no adjacent elements
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int i, int arr[], int n, vector<int> dp){
    if(i<=-1){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }

    int op1 = arr[i] + solve(i - 2, arr, n, dp);
    int op2 = solve(i - 1, arr, n, dp);

    return dp[i] = max(op1, op2);
}

int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> dp(n, -1);

    cout << solve(n - 1, arr, n, dp) << endl;

    return 0;
}
/*
//Merge two sorted arrays
//TC O(nlogn)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m){
    int left = 0, right = n - 1;
    while(left<m && right>=0){
        if(arr1[right]>arr2[left]){
            swap(arr1[right], arr2[left]);
            left++;
            right--;
        }
        else{
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    cout << "first array: ";
    for (int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "second array: ";
    for (int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }
}

int main()
{
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2, 3, 8, 13};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    merge(arr1, arr2, n, m);

    return 0;
}
/*
//Merge two sorted arrays
//Gap method
//TC O((n+m)logn)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swapIfGreater(int arr1[], int arr2[], int ind1, int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(int arr1[], int arr2[], int n, int m){
    int len=(n+m);
    int gap = (len / 2) + (len % 2);

    while(gap>0){
        int left = 0, right = left + gap;
        while(right<len){
            if(left<n && right>=n){
                swapIfGreater(arr1, arr2, left, right - n);
                left++, right++;
            }
            else if(left>=n){
                swapIfGreater(arr2, arr2, left-n, right - n);
                left++, right++;
            }
            else{
                swapIfGreater(arr1, arr1, left, right);
                left++, right++;
            }
        }
        if(gap>1){
            gap = (gap / 2) + (gap % 2);
        }
        else{
            break;
        }
    }

    cout << "first array: ";
    for (int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "second array: ";
    for (int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }
}

int main()
{
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2, 3, 8, 13};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    merge(arr1, arr2, n, m);

    return 0;
}
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

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions is: "
         << cnt << endl;
 return 0;
}
/**
//Count inversion
//time complexity: O(nlogn)
//Space complexity: O(n)
#include<iostream>
#include<vector>
using namespace std;

int merge(int arr[], int low, int mid, int high){
    vector<int> temp;
    int cnt = 0;
    int left = low;
    int right = mid + 1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
            left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(int arr[], int low, int high){
    int cnt = 0;
    if(low>=high){
        return 0;
    }
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    cout << mergeSort(arr, 0, 4) << endl;

    return 0;
}
/*
//Find duplicates
//brut force aproach
//time complexity O(n)   space complexity O(n)
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

int main() {
    long long a[] = {1, 6, 5, 2, 3, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    
    vector<int> duplicates_found = duplicates(a, n);
    
    cout << "Duplicate elements: ";
    for (int element : duplicates_found) {
        cout << element << " ";
    }
    cout << endl;
    
    return 0;
}

/*
//Find duplicates
//Optimal aproach
//time complexity O(n)   space complexity O(1)
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
//Optimal aproach
//TC O(n)   SC O(1)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mincost(int a[], int n){
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

int main()
{
    int a[] = {1, 100, 101};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);

    cout << mincost(a, n) << endl;
    return 0;
}
/**
// Check whether reversing a sub array make the array sorted or not 
//Brut force   TC O(nlogn)   SC O(n)
#include<bits/stdc++.h> 
using namespace std; 
  
// Return true, if reversing the subarray will 
// sort the array, else return false. 
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

int main()
{
    int a[] = {1, 2, 5, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);

    isSorted(a, n) ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;
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

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

/**
//4sum
//Optimal aproach
//time complexity O(n^3)   space complexity O(1)
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    
    return 0;
}
/**
//Median of two sorted arrays
//Brut force  TC O(n)  SC O(n)
#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}
/**
//Median of two sorted arrays
//Better Aproach  TC O(n)  SC O(1)
#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}
/**
//Median of two sorted arrays
//Optimal Aproach  TC O(min(logn1, logn2))  SC O(1)
#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return median(b, a);

    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    //apply binary search:
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) /2;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}
/**
//Median of stram data
//SC O(nlogn)  TC O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    void insertHeap(int &x)
    {
        maxHeap.push(x);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian() 
    {
        if (maxHeap.size() > minHeap.size())
            return (double)maxHeap.top();
        return (double)(maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
/** 
//Median of stram data
//SC O(nlogn)  TC O(n)
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> left_max_heap;
priority_queue<int, vector<int>, greater<int>> right_min_heap;
    void insertHeap(int &x)
    {
        if(left_max_heap.empty() || x<left_max_heap.top()){
            left_max_heap.push(x);
        }
        else{
            right_min_heap.push(x);
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(((left_max_heap.size()) - (right_min_heap.size()))>1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if(left_max_heap.size()<right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian() 
    {
        if(left_max_heap.size() == right_min_heap.size()){
            return (double)(left_max_heap.top() + right_min_heap.top())/2;
        }
        else{
            return left_max_heap.top();
        }
    }

int main()
{
    return 0;
}
/**
//Find sub-arrays with zero sum
//Optimal aproach  SC O(n^2)  TC O(1)
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > findSubArrays(int arr[], int n)
{

	// Array to store all the start and end
	// indices of subarrays with 0 sum
	vector<pair<int, int> > output;
	for (int i = 0; i < n; i++) {
		int prefix = 0;
		for (int j = i; j < n; j++) {
			prefix += arr[j];
			if (prefix == 0)
				output.push_back({ i, j });
		}
	}

	return output;
}

// Function to print all subarrays with 0 sum
void print(vector<pair<int, int> > output)
{
	for (auto it = output.begin(); it != output.end(); it++)
		cout << "Subarray found from Index " << it->first
			<< " to " << it->second << endl;
}

int main()
{

	// Given array
	int arr[] = { 6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	vector<pair<int, int> > output = findSubArrays(arr, n);

	// if we didn’t find any subarray with 0 sum,
	// then subarray doesn’t exists
	if (output.size() == 0) {
		cout << "No subarray exists";
	}
	else {
		print(output);
	}
	return 0;
}
/**
//Find sub-arrays with zero sum
//Optimal aproach  SC O(n)  TC O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        unordered_map<long long int, int> um;
        long long int sum=0;
        long long int ans=0;
        um[0]=1;
        
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(um.find(sum)!=um.end()){
                ans+=um[sum];
            }
            um[sum]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
/*
//Agrssive Cows
//TC O(nlogn)  SC O(1)
#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
public:

    bool canWePlace(int n, int k, vector<int> &stalls, int dist){
        int cntcows=1, last=stalls[0]; 
        for(int i=1; i<n; i++){
            if((stalls[i] - last)>=dist){
                cntcows+=1;
                last=stalls[i];
            }
            if(cntcows>=k)
                return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int low=0, high=stalls[n-1]-stalls[0], mid;
        //int ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(canWePlace(n, k, stalls, mid)){
                //ans=mid;
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

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
**/