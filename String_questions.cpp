/**
//Convert lower case letters to upper case
//Convert upper case letters to lower case
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = "adsfjhalksdjf";

    //Convert lowercase letters to upper case
    for(int i=0; i<str.size(); i++){
      if(str[i]>='a' && str[i]<='z'){
          str[i] -= 32;
        }
    }
    cout << str << endl;

    //Convert into lower case
    for(int i=0; i<str.size(); i++){
      if(str[i]>='A' && str[i]<='Z'){
          str[i] += 32;
        }
    }
    cout << str << endl;

    return 0;
}
/**/

/**
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s = "fakjsdfhlak";

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;

    return 0;
}
/**/

/**
//Form maximum number from given number
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s = "498723659";
    sort(s.begin(), s.end(), greater<int>());
    cout << s << endl;

    return 0;
}
/**/

/*
//Maximum time occure letter
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s = "fajdkhfdslfhaoifd";

    int freq[26];
    for (int i = 0; i < 26; i++){
        freq[i] = 0;
    }

    for (int i = 0; i < s.size(); i++){
        freq[s[i] - 'a']++;
    }

    char ans;
    int maxf = 0;
    for (int i = 0; i<26; i++){
        if(freq[i]>maxf){
            maxf = freq[i];
            ans = i + 'a';
        }
    }

    cout << maxf << " " << ans << endl;

    return 0;
}
-----------------------------------------------------------------------------------------------
/**
// Vallid polindrome
//Time Complexity: O(n)   Auxiliary Space: O(1)
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        s[i] = tolower(s[i]);
    }
    string b;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]) || isalpha(s[i]))
        {
            b.push_back(s[i]);
        }
    }
    n = b.size();
    int i=0, j=n-1;
    while(i<j){
        if(b[i] != b[j]) return false;
        i++, j--;
    }

    return true;
}

int main()
{
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";
    cout << isPalindrome(s1);
    cout << isPalindrome(s2);
    cout << isPalindrome(s3);

    return 0;
}
/*
// Valid Anagram
//Time Complexity: O(n + m)    Auxiliary Space: O(1)
class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        if(s1.size() != s2.size()) return false;
        int n=s1.size();
        vector<int> a(26, 0), b(26, 0);

        for(int i=0; i<n; i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(a[i] != b[i]) return false;
        }

        return true;
    }
};
/**
//Valid Parantheses
//Time Complexity: O(n)    Auxiliary Space: O(n)
class Solution {
  public:
    bool isMatch(char a, char b) {
        if ((a == '(' && b == ')') || (a == '[' && b == ']') ||
            (a == '{' && b == '}')) {
            return true;
        }
        return false;
    }

    bool isBalanced(string& s) {
        // code here
        int n=s.size();
        stack<char>st;

        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if (st.empty()) {
                    return false;
                }
                if(isMatch(st.top(), s[i])){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
/**
//Remove Consecutive Characters
//Time Complexity: O(n)    Auxiliary Space: O(n)
class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        int n = s.size();
        string res;

        for(int i=0; i<n-1; i++){
            if(s[i] != s[i+1]){
                res.push_back(s[i]);
            }
        }
        res.push_back(s[n-1]);

        return res;
    }
};
/*
//Longest Common Prefix
//Time Complexity: O(n*min(|arri|))    Auxiliary Space: O(min(|arri|))
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string res=arr[0];
        int n=arr.size();

        for(int i=1; i<n; i++){
            string str=arr[i];
            int j=0;
            while(j<res.size() && j<str.size()){
                if(res[j]==str[j]){
                    j++;
                }
                else{
                    res=res.substr(0, j);
                    break;
                }
            }
            if(res.size()==0){
                return "";
            }
        }

        return res;
    }
};
/*
//Mobile Numeric Keypad
//Expected Time Complexity: O(Length of String)
//Expected Auxiliary Space: O(Length of String)
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string sentnum(string s){
    string res;
    vector<string> v = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555",
        "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
    for (int i = 0; i < s.size(); i++){
        if(s[i]==' '){
            res += "0";
        }
        else{
            res += v[s[i] - 'A'];
        }
    }
    return res;
}

int main()
{
    string s1 = "GEEKSFORGEEKS";
    string s2 = "HELLO WORLD";

    cout << sentnum(s1) << endl;
    cout << sentnum(s2) << endl;

    return 0;
}
/**
//Duplicacte characters in string
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s = "geeksforgeeks";
    int a[26] = {0};

    for (int i = 0; i < s.size(); i++){
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++){
        if(a[i]>1){
            char c = 'a' + i;
            cout << c << ", count = " << a[i] << endl;
        }
    }

        return 0;
}
/**
//Longest substring without repeating character
//Optimal Aproach 1st: Sliding Window     (dont care about 2nd solution, use this always)
//TC = = O(n + n) = O(n)    SC = O(1)   because vector<int> freq(26, 0) is of fixed size
class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        vector<int>freq(26, 0);
        int n=s.size();
        int j=0, cnt=0,max_cnt=0;

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
            cnt++;
            if(freq[s[i]-'a']<=1){
                max_cnt=max(cnt, max_cnt);
            }
            else{
                while(freq[s[i]-'a']>1){
                    freq[s[j]-'a']--;
                    j++, cnt--;
                }
            }
        }

        return max_cnt;
    }
};
//Longest substring without repeating character
//Optimal Aproach 2nd: TC O(1)  SC O(1)      sloding window with advance logic
class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        vector<int>temp(26, -1);
        int n=s.size();
        int start=-1,max_len=0;

        for(int i=0; i<n; i++){
            if(temp[s[i]-'a']>start){
                start=temp[s[i]-'a'];
            }
            temp[s[i]-'a']=i;

            max_len=max(max_len, i-start);
        }

        return max_len;
    }
};
/**
//Longest repeating character replacement
//BrutForce Aproach:TC O(n^2)   SC O(1)
class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
         int n=s.size();
         int max_cnt=0;

         for(int i=0; i<n; i++){
             int cnt=0, ops=k, j=i;

             while(j<n){
                 if(s[i]==s[j]){
                     cnt++, j++;
                 }
                 else{
                    if(ops>0){
                        cnt++,ops--,j++;
                    }
                    else{
                        break;
                    }
                 }
             }
             max_cnt=max(cnt, max_cnt);
         }

         return max_cnt;
    }
};
//Longest repeating character replacement
//Optimal:SlidingWindow but not usefull: TC O(26*(n+n))  SC O(1)
class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
         int n=s.size();
         int left=0, max_freq=0, max_len=0;
         int freq[26]={0};

         for(int right=0; right<n; right++){
             freq[s[right]-'A']++;
             max_freq=max(max_freq, freq[s[right]-'A']);

             while((right-left+1-max_freq)>k){
                 freq[s[left]-'A']--;
                 left++, max_freq=0;
                 for(int i=0; i<26; i++){
                     max_freq=max(freq[i], max_freq);
                 }
             }

             max_len=max(max_len, right-left+1);
         }

         return max_len;
    }
};
//Longest repeating character replacement
//Optimal:SlidingWindow but not usefull: TC O((n+n))  SC O(1)
class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
         int n=s.size();
         int left=0, max_freq=0, max_len=0;
         int freq[26]={0};

         for(int right=0; right<n; right++){
             freq[s[right]-'A']++;
             max_freq=max(max_freq, freq[s[right]-'A']);

             while((right-left+1-max_freq)>k){
                 freq[s[left]-'A']--;
                 left++;
             }

             max_len=max(max_len, right-left+1);
         }

         return max_len;
    }
};
};
//Longest repeating character replacement
//Optimal:SlidingWindow TC O(n)  SC O(1)
class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
         int n=s.size();
         int left=0, max_freq=0, max_len=0;
         int freq[26]={0};

         for(int right=0; right<n; right++){
             freq[s[right]-'A']++;
             max_freq=max(max_freq, freq[s[right]-'A']);

             if((right-left+1-max_freq)>k){
                 freq[s[left]-'A']--;
                 left++;
             }

             max_len=max(max_len, right-left+1);
         }

         return max_len;
    }
};
/*
//Group Anagrams
//Time Complexity: O(m*nlogn)     Space Complexity: O(m*n)
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        unordered_map<string, vector<string>>mp;

        for(auto s:arr){
            string original=s;
            sort(s.begin(), s.end());
            mp[s].push_back(original);
        }

        vector<vector<string>> anagrams;
        for(auto vec: mp){
            anagrams.push_back(vec.second);
        }

        return anagrams;
    }
};

//Dont see in main function
int main()
{
    vector<string> st = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(st);

    // Outputting the result
    for (const auto& vec : result) {
        for (const auto& str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
/**
//Group Anagrams
//Time Complexity: O(m*n)     Space Complexity: O(m*n)
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        unordered_map<string, vector<string>>mp;

        for(auto s:arr){
            vector<int> freq(26, 0);
            string hashstring="";
            for(int i=0; i<s.size(); i++){
                freq[s[i]-'a']++;
            }
            for(int i=0; i<26; i++){
                hashstring.push_back(freq[i]);
                hashstring.push_back('#');
            }
            mp[hashstring].push_back(s);
        }

        vector<vector<string>> anagrams;
        for(auto vec: mp){
            anagrams.push_back(vec.second);
        }

        return anagrams;
    }
};

//Dont see in main function
int main()
{
    vector<string> st = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(st);

    // Outputting the result
    for (const auto& vec : result) {
        for (const auto& str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
//Longest palindromic substring
//BrutForce Aproach:TC O(n^3)    SC O(1)
#include <bits/stdc++.h>
using namespace std;

bool checkPal(string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

// function to find the longest palindrome substring
string longestPalindrome(string& s) {
    int n = s.size();
    int maxLen = 1, start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (checkPal(s, i, j) && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s = "forgeeksskeegfor";
    cout << longestPalindrome(s) << endl;
    return 0;
}
/*
//Longest palindromic substring
//Optimal Aproach: TC O(n^2)   Sc O(1)
class Solution {
  public:
    string longestPalindrome(string s) {
        // code here
        int n=s.size();
        int start=0, max_len=1;
        for(int i=0; i<n; i++){
            int left=i, right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                left--, right++;
            }
            if((right-left-1)>max_len){
                max_len=right-left-1;
                start=left+1;
            }

            left=i, right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                left--, right++;
            }
            if((right-left-1)>max_len){
                max_len=right-left-1;
                start=left+1;
            }
        }

        return s.substr(start, max_len);
    }
};
/*
//Count palindromic substrings leetCode problem solution
//TC O(n^2)   SC O(1)
class Solution {
  public:
    int countPS(string &s) {
        // code here
        int ans = 0, n=s.size();
        for (int i = 0; i < n; i++) {
            int left = i, right = i;
            while (left>=0 && right<n && s[left]==s[right]) {
                ans++;
                right++;
                left--;
            }

            left = i, right = i + 1;
            while (left>=0 && right<n && s[left]==s[right]) {
                ans++;
                right++;
                left--;
            }
        }
        return ans;
    }
};
//Count palindromic substrings gfg problem solution
//TC O(n^2)   SC O(1)
class Solution {
  public:
    int countPS(string &s) {
        // code here
        int ans = 0, n=s.size();
        for (int i = 0; i < n; i++) {
            int left = i, right = i;
            while (left>=0 && right<n && s[left]==s[right]) {
                if((right-left+1)>1){
                    ans++;
                }
                right++;
                left--;
            }

            left = i, right = i + 1;
            while (left>=0 && right<n && s[left]==s[right]) {
                if((right-left+1)>1){
                    ans++;
                }
                right++;
                left--;
            }
        }
        return ans;
    }
};
/*
//Count palindromic subsequences
//TC: O(n^2)     SC O(n^2)
class Solution {
  public:
    int func(int i, int j, string s, vector<vector<int>>& dp){
        if(i > j){
            return 0;
        }
        if(i == j){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j] = func(i, j-1, s, dp) + func(i+1, j, s, dp) + 1;
        }
        else{
            return dp[i][j] = func(i, j-1, s, dp) + func(i+1, j, s, dp) - func(i+1, j-1, s, dp);
        }
    }

    int countPS(string &s) {
        // Your code here
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return func(0, n-1, s, dp);
    }
};
/*
//SmallestWindow
//TC O(n)   SC O(1)
class Solution {
  public:
    string smallestWindow(string &s1, string &s2) {
        // Your code here
        int n=s1.size(), m=s2.size();
        vector<int> freq(26, 0);
        int frq=0, start=0, left=0, min_len=INT_MAX;
        for(int i=0; i<m; i++){
            freq[s2[i]-'a']--;
            frq++;
        }

        for(int right=0; right<n; right++){
            if(freq[s1[right]-'a']<0) frq--;
            freq[s1[right]-'a']++;

            while(frq<=0 && left<n){
                if(min_len > (right-left+1)){
                    min_len=right-left+1;
                    start=left;
                }

                if(freq[s1[left]-'a']<=0) frq++;
                freq[s1[left]-'a']--;
                left++;
            }
        }

        if(min_len==INT_MAX){
            return "";
        }
        else{
            return s1.substr(start, min_len);
        }
    }
};
/**
//Wildcard Matching
//Recursion method: TC O(2^(n + m))   SC O(n+m){recursion stack}
// wild = ge*ks   pattern = geeks
class Solution{
    public:
    bool func(int i, int j, string &wild, string &pattern){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;

        if(j<0 && i>=0){
            for (int ii = 0; ii<=i; ii++){
                if(wild[ii] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(wild[i]==pattern[j] || wild[i]=='?'){
            return func(i-1, j-1, wild, pattern);
        }
        if(wild[i]=='*'){
            return func(i-1, j, wild, pattern) | func(i, j-1, wild, pattern);
        }
        return false;
    }

    bool match(string wild, string pattern)
    {
        // code here
        int n=wild.size(), m=pattern.size();
        return func(n-1, m-1, wild, pattern);
    }
};
/**
//Wildcard Matching
//Memoizaton method: TC O(n*m)      SC O(n*m)
// wild = ge*ks    pattern = geeks
class Solution{
    public:
    bool func(int i, int j, string &wild, string &pattern, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;

        if(j<0 && i>=0){
            for (int ii = 0; ii<=i; ii++){
                if(wild[ii] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(wild[i]==pattern[j] || wild[i]=='?'){
            return dp[i][j] = func(i-1, j-1, wild, pattern, dp);
        }
        if(wild[i]=='*'){
            return dp[i][j] = func(i-1, j, wild, pattern, dp) | func(i, j-1, wild, pattern, dp);
        }
        return false;
    }

    bool match(string wild, string pattern)
    {
        // code here
        int n=wild.size(), m=pattern.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n-1, m-1, wild, pattern, dp);
    }
};
/**
//Longest proper prefix suffix
//BrutForce aproach: TC O(n^2)   SC O(1)
class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        // Your code goes here
        int n=s.size();
        int max_len=0;
        for(int i=1; i<n; i++){
            int j=0, k=i;
            while(k<n && s[j]==s[k]){
                j++, k++;
            }
            if(k==n){
                max_len=max(max_len, n-i);
            }
        }

        return max_len;
    }
};
/*
//"abab" "aaaa" "abcdeabcd" "abcdeabab"
//Longest prefix suffix
//Optimal aproach: TC O(n)    SC O(n)
class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        // Your code goes here
        int n=s.size();
        vector<int> res(n, 0);
        int i=0, j=1;
        
        while(j<n){
            if(s[i]==s[j]){
                res[j]=i+1;
                i++, j++;
            }
            else{
                if(i==0){
                    j++;
                }
                else{
                    i=res[i-1];       //In almost all cases found that i=0
                }
            }
        }
        
        return res[n-1];
    }
};
/**
//Rabin Karp algorithm for pattern search
//TC O(n+m)   SC O(1)
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            int n = text.size();
            int m = pattern.size();
            int h = 1, d=256;
            int t = 0, p = 0, q=11;
            int i, j;
            vector<int>res;

            for (i = 0; i < m - 1; i++){
                h = (h * d) % q;
            }

            for (i = 0; i < m; i++){
                p = (p * d + pattern[i]) % q;
                t = (t * d + text[i]) % q;
            }

            for (i = 0; i <= n - m; i++){
                if(t==p){
                    for (j = 0; j < m; j++){
                        if(text[i+j] != pattern[j]){
                            break;
                        }
                    }
                    if(j==m){
                        res.push_back(i+1);
                    }
                }
                if(i<n-m){
                    t = ((d * (t - (text[i] * h))) + text[i + m]) % q;

                    if(t<0){
                        t = t + q;
                    }
                }
            }
            
            return res;
        }
     
};
/**
//Transform one string to another string
//TC O(n)     SC O(1)
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int n=A.size(), m=B.size();
        if(n!=m) return -1;
        
        vector<int>freq1(256, 0), freq2(256, 0);       dont be smart take size 256
        for(int i=0; i<n; i++){
            freq1[A[i]]++;
            freq2[B[i]]++;
        }
        for(int i=0; i<256; i++){
            if(freq1[i] != freq2[i]) return -1;
        }
        
        int i=n-1, j=n-1, cnt=0;
        while(i>=0 && j>=0){
            if(A[i]==B[j]){
                i--, j--;
            }
            else{
                cnt++;
                i--;
            }
        }
        
        return cnt;
    }
};
/**
//Boye Moore algorithm for pattern search
//Its looking my aproach
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void search(char text[], char pattern[]){
    int m = strlen(text);
    int n = strlen(pattern);

    for (int i = 0; i <= m - n; i++){
        int j;
        for (j = 0; j < n; j++){
            if(text[i+j] != pattern[j]){
                break;
            }
        }
        if(j==n){
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main()
{
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";

    search(txt, pat);
    return 0;
}
/**
//WordWrap
//TC O(n^2)     SC O(n^2)
class Solution {
  public:
int rec(int i, int rem, vector<int> &arr, int k, vector<vector<int>> &dp){
    if(i==arr.size()) return 0;
    if(dp[i][rem] != -1) return dp[i][rem];
    
    int ans;
    if(arr[i]>rem){
        ans=(rem+1)*(rem+1) + rec(i+1, k-arr[i]-1, arr, k, dp);
    }
    else{
        int choice1=rec(i+1, rem-arr[i]-1, arr, k, dp);
        int choice2=(rem+1)*(rem+1) + rec(i+1, k-arr[i]-1, arr, k, dp);
        ans=min(choice1, choice2);
    }
    dp[i][rem]=ans;
    return dp[i][rem];
}

int solveWordWrap(vector<int> arr, int k) {
    // Code here
    int n=arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    
    return rec(0, k, arr, k, dp);
}
};
*/