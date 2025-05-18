/*
//Minimize Difference in Task Priorities
//Time Complexity: O(n log n) Auxiliary Space: O(1)
class Solution {
  public:
    int minDiff(vector<int>& arr, int k, int m, int t) {
        // write code here
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
//Time Complexity: O(n + d*log d)=O(nlogn), where n is the size of the array and d is the count of distinct elements in the array.
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
//Optimal Aproach-1(Heap): TC O(nlogn)   SC O(n)    //most time ask til these
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
*/