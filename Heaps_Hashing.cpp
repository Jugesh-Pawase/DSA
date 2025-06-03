/*
//Minimize Difference in Task Priorities
//Time Complexity: O(n log n) Auxiliary Space: O(1)
class Solution {
  public:
    int minDiff(vector<int>& arr, int k, int m, int t) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int minDiff=INT_MAX;

        for(int i=0; i<=n-k; i++){
            int count = 0;
            for(int j=i; j<i+k; j++){
                if(arr[j] >= t) count++;
            }

            if(count >= m){
                int diff = arr[i+k-1]-arr[i];
                minDiff = min(minDiff, diff);
            }
        }

        return (minDiff==INT_MAX) ? -1: minDiff;
    }
};
/*
//Top K frequent elements
//BrutForce: Time Complexity: O(n + d*log d)=O(nlogn), where n is the size of the array and d is the count of distinct elements in the array.
//Auxiliary Space: O(d)
class Solution {
  public:
    static bool compare(pair<int, int> p1, pair<int, int> p2){
        if(p1.second == p2.second)
            return p1.first > p2.first;

        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int> &arr, int k) {
        unordered_map<int, int>mp;
        int n=arr.size();

        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }

        vector<pair<int, int>> freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(), compare);

        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(freq[i].first);
        }

        return res;
    }
};
/*
//Optimal Aproach-1(Heap): TC O(klogk)   SC O(n)    //most time ask til these
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
        unordered_map<int, int>mp;
        int n=arr.size();

        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

        for(auto it:mp){
            int value=it.first, freq=it.second;
            q.push({freq, value});

            if(q.size()>k) q.pop();
        }

        vector<int>res(k);
        for(int i=0; i<k; i++){
            res[k-1-i] = q.top().second;
            q.pop();
        }

        return res;
    }
};
/*
//Optimal Aproach-2(Bucket Sort):TC(n)  SC(n)    //100& correct
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
        unordered_map<int, int>mp;
        int n=arr.size();

        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }

        vector<vector<int>>bucket(n+1);

        for(auto it:mp){
            int value=it.first, freq=it.second;
            bucket[freq].push_back(value);
        }

        vector<int>res;
        for(int i=n; i>0; i--){
            while(bucket[i].size()>0 && k>0){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return res;
    }
};
/*
//K largest elements
//BrutForce: TC O(nlogn)    SC O(1)
vector<int> kLargest(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end(), greater<int>());

    vector<int> res(arr.begin(), arr.begin() + k);
    return res;
}

//Optimal Aproach: TC O(nlogk)   SC O(k)
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<int, vector<int>,
        greater<int>>q(arr.begin(), arr.begin()+k);

        for(int i=k; i<n; i++){
            if(q.top() < arr[i]){
                q.pop();
                q.push(arr[i]);
            }
        }

        vector<int> res(k);
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
/*
//Kth smallest element in an array
//BrutForce: TC O(nlogn)   SC O(1)
int kthSmallest(int arr[], int N, int K){
    sort(arr, arr + N);

    return arr[K - 1];
}

//Optimal Aproach(heap): TC O(nlogk)   SC O(k)
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        int n=arr.size();
        priority_queue<int>pq;

        for(int i=0; i<n; i++){
            if(pq.size() < k){
                pq.push(arr[i]);
            }
            else{
                if(pq.top()>arr[i]){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }

        return pq.top();
    }
};
/*
//Most reapiting element
//TC O(n)    SC O(k)
class Solution {
public:
    int maxRepeating(int k, vector<int>& arr) {
        vector<int> freq(k, 0);  // frequency array of size k

        for (int num : arr) {
            freq[num]++;
        }

        int maxFreq = freq[0], result = 0;
        for (int i = 1; i < k; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                result = i;
            }
        }

        return result;
    }
};
/*
//K-th smallest element after removing some integers from natural numbers
//BrutForce: TC O(n*k)    SC O(1)
int findkthSmall(const vector<int>& arr, int k) {
    int cnt = 0, num = 1;
    while (cnt < k) {
        bool isValid = true;

        // Check if the number is removed
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == num) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            cnt++;
        }
        num++;
    }
    return num - 1;
}
//Bettter Aproach(sorting): TC O(nlogn)   SC O(1)
int findkthSmall(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    for (int num : arr) {

        //  increment k because the position of k has
        // effectively moved forward due to the removal.
        if (num <= k)
            k++;
        else
            break;
    }
    return k;
}
//Optimal Aproach(hashMap): TC O(n+k)    SC O(n)
int findKthSmall(vector<int>& arr, int k) {
    unordered_set<int> removed(arr.begin(), arr.end());
    int cnt = 0, num = 1;

    while (cnt < k) {

        // Check only valid numbers, skipping removed ones
        if (!removed.count(num))
            cnt++;
        num++;
    }
    return num - 1;
}
//Optimal(MyAproach): TC O(n)   SC O(1)   if given array is sorted
#include <bits/stdc++.h> 
int kthSmallest(vector<int> &arr, int k){
    // Write your code here.
    int n=arr.size();

    for(int i=0; i<n; i++){
        if(arr[i]<=k){
            k++;
        }
        else{
            break;
        }
    }

    return k;
}
/*
//K closest elements
//BrutForce: TC O(n)    SC O(1)
class Solution {
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int i = 0;
        while (i < n && arr[i] < x) i++;

        int left = i - 1;
        int right = (i < n && arr[i] == x) ? i + 1 : i;

        vector<int> res;

        while (left >= 0 && right < n && k > 0) {
            int leftVal = x - arr[left];
            int rightVal = arr[right] - x;

            if (rightVal < leftVal) {
                res.push_back(arr[right]);
                right++;
            } else {
                res.push_back(arr[left]);
                left--;
            }
            k--;
        }

        while (left >= 0 && k > 0) {
            res.push_back(arr[left]);
            left--;
            k--;
        }

        while (right < n && k > 0) {
            res.push_back(arr[right]);
            right++;
            k--;
        }

        return res;
    }
};
//Simple Aproach(binarySearch): TC O(logn + k)    SC O(1)
class Solution {
  public:
    int helper(int low, int high, int x, vector<int>& arr){
        if(arr[high] <= x) return high;
        if(arr[low] >= x) return low;

        int mid=(low+high)/2;
        if(arr[mid]<=x && arr[mid+1]>x){
            return mid;
        }
        else if(arr[mid] < x){
            return helper(mid+1, high, x, arr);
        }
        else{
            return helper(low, mid-1, x, arr);
        }
    }

    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int idx=helper(0, n-1, x, arr);

        int left, right;
        left = (arr[idx] == x) ? idx-1:idx;
        right=idx+1;

        vector<int> res;

        while(k && left>=0 && right<n){
            int x1 = x-arr[left];
            int x2 = arr[right]-x;

            if(x1<x2){
                res.push_back(arr[left--]);
            }
            else{
                res.push_back(arr[right++]);
            }

            k--;
        }

        while(k && left>=0){
            res.push_back(arr[left--]);
            k--;
        }

        while(k && right<n){
            res.push_back(arr[right++]);
            k--;
        }

        return res;
    }
};
//its not optimal than above but still interviewer might want this solution as your knowledge and this is most prefer
//Aproach(Heap): TC O(nlogk)  SC O(k)
class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        priority_queue<pair<int, int>>q;

        for(int i=0; i<n; i++){
            if(arr[i] == x) continue;

            q.push({abs(x-arr[i]), -arr[i]});
            if(q.size()>k) q.pop();
        }

        vector<int>res;
        while(!q.empty()){
            res.push_back(-q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
/*
//Kth largest element in a stream
//BrutFore Aproach: TC O(n^2*logn)     SC O(n)
vector<int> kthSmallest(vector<int> arr, int k) {
    vector<int> res;
    vector<int> topK;

    for (int i = 0; i < arr.size(); i++) {
        topK.push_back(arr[i]);
        sort(topK.begin(), topK.end());

        if (topK.size() >= k) {
            res.push_back(topK[i+1 - k]);
        }
        else {
            res.push_back(-1);
        }
    }

    return res;
}

//Expected Aproach(heap): TC O(nlogk)    SC O(k)  //if we ignore the space for answer
 Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int, vector<int>, greater<int>>q;
        vector<int>res;

        for(int i=0; i<n; i++){
            q.push(arr[i]);
            if(q.size() > k){
                q.pop();
            }

            if(q.size()<k){
                res.push_back(-1);
            }
            else{
                res.push_back(q.top());
            }
        }

        return res;
    }
};
/*
//Minimum cost of ropes
//BrutForce(sorting): TC O(n^2*logn)    SC O(1)
class Solution {
  public:
    int minCost(vector<int>& arr) {
        int totalCost = 0;
        while (arr.size() > 1) {
            sort(arr.begin(), arr.end());

            int first = arr[0];
            int second = arr[1];

            arr.erase(arr.begin());
            arr.erase(arr.begin());

            int cost = first + second;
            totalCost += cost;

            arr.push_back(cost);
        }

        return totalCost;
    }
};

//Expected Aproach(Heap): TC O(nlogn)    SC O(n)
class Solution {
  public:
    int minCost(vector<int> &arr) {
        priority_queue<int, vector<int>,
        greater<int>> pq(arr.begin(), arr.end());
        int res = 0;

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            res += first + second;
            pq.push(first + second);
        }

        return res;
    }
};
/*
//Longest subArray with 0 sum
//BrutForce Aproach: TC O(n^2)    SC O(1)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum += arr[j];
                
                if(sum == 0){
                    ans = max(ans, j-i+1);
                }
            }
        }
        
        return ans;
    }
};

//Optimal Aproach(Hashmap): TC O(n)   SC O(n)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, int>mp;
        int sum=0, ans=0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(sum == 0){
                ans = i+1;
            }
            else if(mp.find(sum) != mp.end()){
                ans = max(ans, i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        
        return ans;
    }
};
/*
//Count distinct elements in every window
//BrutForce: TC O(n*k)  SC  O(k)
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n=arr.size();
        vector<int>res;
        
        for(int i=0; i<=n-k; i++){
            unordered_set<int>st;
            for(int j=i; j<i+k; j++){
                st.insert(arr[j]);
            }
            res.push_back(st.size());
        }
        
        return res;
    }
};

//Optimal Aproach(HashMap): TC O(n)   SC O(k)
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n=arr.size();
        unordered_map<int, int>frec;
        vector<int>res;
        
        for(int i=0; i<k; i++){
            frec[arr[i]]++;
        }
        
        res.push_back(frec.size());
        for(int i=k; i<n; i++){
            frec[arr[i]]++;
            frec[arr[i-k]]--;
            
            if(frec[arr[i-k]] == 0){
                frec.erase(arr[i-k]);
            }
            
            res.push_back(frec.size());
        }
        
        return res;
    }
};
/*
//Group shifted strings
//TC O(n*m)   SC O(n*m)
class Solution {
public:
    string getHash(const string& s) {
        string key;
        for (int i = 1; i < s.size(); i++) {
            int diff = (s[i] - s[i - 1] + 26) % 26;
            key += to_string(diff) + "#";
        }
        return key;
    }

    vector<vector<string>> groupShiftedString(vector<string>& arr) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : arr) {
            string hash = getHash(s);
            groups[hash].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& group : groups) {
            res.push_back(group.second);
        }

        return res;
    }
};
/*
//Maximum of all subarrays of size k
//BrutForce:TC O(n*k)   SC O(1)
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>res;
        for(int i=0; i<=n-k; i++){
            int maxK=INT_MIN;
            for(int j=i; j<i+k; j++){
                maxK=max(maxK, arr[j]);
            }
            res.push_back(maxK);
        }
        
        return res;
    }
};
//BetterAproach:TC O(n*logn)  SC O(n)      it's n not k
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<pair<int, int>> pq;
        vector<int>res;
        
        for(int i=0; i<k; i++){
            pq.push({arr[i], i});
        }
        res.push_back(pq.top().first);
        
        for(int i=k; i<n; i++){
            pq.push({arr[i], i});
            
            while(pq.top().second <= i-k) pq.pop();
            
            res.push_back(pq.top().first);
        }
        
        return res;
    }
};
//OptimalAproach(Deque): TC O(n)     SC O(k)
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    // to store the results
    vector<int> res;
    // create deque to store max values
    deque<int> dq(k);
    // Process first k (or first window) elements of array
    for (int i = 0; i < k; ++i) {
        // For every element, the previous smaller elements 
        // are useless so remove them from dq
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            // Remove from rear
            dq.pop_back();
        }
        // Add new element at rear of queue
        dq.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (int i = k; i < arr.size(); ++i) {      
        // The element at the front of the queue is the largest 
        // element of previous window, so store it
        res.push_back(arr[dq.front()]);

        // Remove the elements which are out of this window
        while (!dq.empty() && dq.front() <= i - k) {
            // Remove from front of queue
            dq.pop_front();
        }

        // Remove all elements smaller than the currently being 
        // added element (remove useless elements)
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        // Add current element at the rear of dq
        dq.push_back(i);
    }

    // store the maximum element of last window
    res.push_back(arr[dq.front()]);

    return res;
}
};
/*
//Merge K sorted lists
//BrutForce(Merge one by one):TC (n*k*k)   SC O(1)

//Linked list Node structure
// struct Node
// {
//     int data;
//     Node* next;

//     Node(int x){
//         data = x;
//         next = NULL;
//     }

// };

class Solution {
  public:
    Node* mergeTwoLists(Node* head1, Node* head2){
        Node* dummy = new Node(-1);
        Node* curr=dummy;
        
        while(head1!=nullptr && head2!=nullptr){
            if(head1->data <= head2->data){
                curr->next = head1;
                head1=head1->next;
            }
            else{
                curr->next=head2;
                head2=head2->next;
            }
            curr=curr->next;
        }
        
        if(head1 != nullptr){
            curr->next=head1;
        }
        else{
            curr->next=head2;
        }
        
        return dummy->next;
    }
  
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node* res;
        for(Node* node:arr){
            res=mergeTwoLists(res, node);
        }
        
        return res;
    }
};
//Optimal Aproach(MinHeap): TC O(nlogk)   SC O(k)    //n=elements k=lists
class Solution {
  public:
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // Min-heap based on node data
        }
    };
  
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<Node*, vector<Node*>, compare>pq;
        
        Node* dummy = new Node(-1);
        Node* tail=dummy;
        
        for(Node* head:arr){
            if(head != nullptr) pq.push(head);
        }
        
        while(!pq.empty()){
            Node* top=pq.top();
            pq.pop();
            
            tail->next=top;
            tail=top;
            
            if(top->next != nullptr){
                pq.push(top->next);
            }
        }
        
        return dummy->next;
    }
};
/*
//Smallest positive missing number in an unsorted array
//BrutForce Aproach(sorting): TC O(nlogn)   SC O(1)
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n=arr.size(), res=1;
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++){
            if(arr[i] == res){
                res++;
            }
            else if(res < arr[i]){
                break;
            }
        }
        
        return res;
    }
};
//BrutForce Aproach(Hashmap):TC O(n)    SC O(1e6)=O(n)
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n=arr.size();
        unordered_map<int, int>mp;
        
        for(int i=0; i<n; i++){
            if(arr[i] > 0){
                mp[arr[i]]++;
            }
        }
        
        for(int i=1; i<=1e6; i++){
            if(mp.find(i) == mp.end()){
                return i;
            }
        }
    }
};
//Expected Aproach(index mapping): TC O(n)    SC O(1)
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n=arr.size();

        // Place each number in its correct index (i.e., nums[i] = i + 1)
        for(int i=0; i<n; i++){
            while(arr[i]>0 && arr[i]<=n && arr[arr[i]-1]!=arr[i]){
                swap(arr[arr[i]-1], arr[i]);
            }
        }
        
        // Find the first location where index+1 != value
        for(int i=0; i<n; i++){
            if(arr[i] != i+1) return i+1;
        }
        
        // If all positions are correct, answer is n + 1
        return n+1;
    }
};
/*
//Count surparsser       //simillar to count inversions
//BrutForce: TC O(n^2)   SC O(1)
class Solution {
  public:
    vector<int> findSurpasser(vector<int>& arr) {
        int n=arr.size();
        vector<int>res;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=i+1; j<n; j++){
                if(arr[j] > arr[i]){
                    count++;
                }
            }
            res.push_back(count);
        }
        
        return res;
    }
};

//Optimal Aproach: TC O(nlogn)    SC O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Merge function to sort the array and update surpasser counts
int merge(vector<int> &arr, int lo, int mid, int hi, 
                            unordered_map<int, int> &m) {
  
    int n1 = mid - lo + 1;
    int n2 = hi - mid;
    vector<int> left(n1), right(n2); 
    
    // Copy data into temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[lo + i]; 
        
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j]; 

    int i = 0, j = 0, k = lo;
    
    // Merging two halves
    while (i < n1 && j < n2) {
      
        // All elements in right[j..n2] are greater than left[i]
        // So add n2 - j, in surpasser count of left[i]
        if (left[i] < right[j]) {
            m[left[i]] += n2 - j;  
            arr[k++] = left[i++];
        } 
        else {
            arr[k++] = right[j++];
        }
    }

    // Copy remaining elements of left[] if any
    while (i < n1)
        arr[k++] = left[i++];

    // Copy remaining elements of right[] if any
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(vector<int> &arr, int lo, int hi, 
               unordered_map<int, int> &m) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        
        // Sort left and right half
        mergeSort(arr, lo, mid, m); 
        mergeSort(arr, mid + 1, hi, m);
        
        // Merge them
        merge(arr, lo, mid, hi, m);  
    }
}

vector<int> findSurpasser(vector<int>& arr) {
    int n = arr.size();
    
    // Map to store surpasser counts
    unordered_map<int, int> m;
    
    // Duplicate array to perform merge Sort
    // so that orginial array is not modified
    vector<int> dup = arr;  

    mergeSort(dup, 0, n - 1, m);  

    // Store surpasser counts in result array
    // in the same order as given array
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = m[arr[i]]; 
    
    return res;
}

int main() {
    vector<int> arr = {2, 7, 5, 3, 8, 1};
    vector<int> res = findSurpasser(arr);  
    for (int count : res)
        cout << count << " ";
    return 0;
}
/*
//Sum of lengths of subarrays with distinct elements
//TC O(n)   SC O(n)

class Solution {
  public:
    int sumoflength(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>st;
        long long ans=0;
        int j=0;
        for(int i=0; i<n; i++){
            while(j<n && st.find(arr[j])==st.end()){
                st.insert(arr[j]);
                j++;
            }
            long long len = j-i;
            ans += (len*(len+1))/2;
            st.erase(arr[i]);
        }
        
        return static_cast<int>(ans % 1000000007);
    }
};
*/