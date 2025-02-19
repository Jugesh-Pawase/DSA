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
/**
// Vallid polindrome
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
    // transform(s.begin(), s.end(), s.begin(), ::tolower);
    string b;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]) || isalpha(s[i]))
        {
            b.push_back(s[i]);
        }
    }
    n = b.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (b[i] != b[n - 1 - i])
        {
            return false;
        }
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
#include <iostream>
#include <string>
#include<vector>
using namespace std;

bool isAnagram(string s, string t)
{
    if(s.size() != t.size()){
        return false;
    }
    int n = s.size();
    vector<int> res(26, 0);
    vector<int> test(26, 0);
    for (int i = 0; i < n; i++)
    {
        res[s[i] - 'a']++;
        test[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (res[i] != test[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";

    cout << isAnagram(s, t);

    return 0;
}
/**/
//Valid Parantheses
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatch(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
    {
        return true;
    }
    return false;
}

bool isValidParentheses(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
           else if (isMatch(st.top(), s[i]))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "{]";
    string s4 = "{[{}]}";
    cout << isValidParentheses(s1) << endl;
    cout << isValidParentheses(s2) << endl;
    cout << isValidParentheses(s3) << endl;
    cout << isValidParentheses(s4) << endl;

    return 0;
}
/**
//Remove Consecutive Characters
#include<iostream>
using namespace std;

string removeConsecutive(string s){
    string res;
    for (int i = 0; i < s.size(); i++){
        if(s[i]==s[i+1]){
            continue;
        }
        res.push_back(s[i]);
    }
    return res;
}

int main()
{
    string s1 = "aabb";
    string s2 = "aabaa";
    cout << removeConsecutive(s1) << endl;
    cout << removeConsecutive(s2) << endl;
    return 0;
}
/*
//Longest Common Prefix
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string> s){
    string prefix = s[0];
    for (int i = 1; i < s.size(); i++){
        int j = 0;
        while (j < prefix.size() && j < s[i].size() && prefix[j] == s[i][j]){
            j++;
        }
        prefix = prefix.substr(0, j);
        if(prefix.empty()){
            break;
        }
    }
    return prefix;
}

int main()
{
    vector<string> v = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(v) << endl;
    return 0;
}
/*
//Mobile Numeric Keypad
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
            res += '0';
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
#include<iostream>
using namespace std;
#include<string>
int main()
{
    string s;
    cin >> s;
    int a[256] = {-1};
    int start = -1,maxlength=0;

    for (int i = 0; i < s.size(); i++){
        if(a[s[i]]>start){
            start = a[s[i]];
        }
        a[s[i]] = i;
        maxlength = max(maxlength, i - start);
    }

    cout << maxlength << endl;

    return 0;
}
/**
//Longest repeating character replacement
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int longestRepeating(string s, int k){
    vector<int> charCount(26, 0);
    int maxCount = 0;
    int maxLength = 0;
    int start = 0;//AABABB
    for (int end = 0; end < s.size(); end++){
        maxCount = max(maxCount, ++charCount[s[end] - 'A']);
        while (end - start + 1 - maxCount > k)
        {
            charCount[s[start] - 'A']--;
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
}

int main()
{
    string str = "AABABBA";
    int k = 1;
    cout << longestRepeating(str, k);

    return 0;
}
/*#include<iostream>
#include<string>
#include<vector>
using namespace std;
//AABABBA
int replace(string s, int k){
    int n = s.size();
    
    vector<int> v(26, 0);
    int length, maxcount=0, ans=0, j=-1;
    for (int i = 0; i < n; i++){
        v[s[i] - 'A']++;
        maxcount=max(maxcount, v[s[i] - 'A']);
        length = i - j;
        if(maxcount+k>=length){
            ans = max(ans, length);
        }
        else{
            j++;
            v[s[j] - 'A']--;
        }
    }
    return ans;
}

int main()
{
    string s ="BAAAB";
    int k = 2;
    cout<<replace(s, k)<<endl;

    return 0;
}
/*
//Group Anagrams
//Time Complexity: O(m*nlogn)
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs){
    unordered_map<string, vector<string>> mp;
    for(auto s:strs){
        string original = s;
        sort(s.begin(), s.end());
        mp[s].push_back(original);
    }

    vector<vector<string>> anagrams;
    for(auto [key, anagramStrings]: mp){
        anagrams.push_back(anagramStrings);
    }

    return anagrams;
}

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
//Time Complexity: O(m*n)
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs){
    unordered_map<string, vector<string>> mp;
    for(auto s:strs){
        vector<int> freq(26, 0);
        string hashString = "";
        for(auto ch:s){
            freq[ch - 'a']++;
        }
        for (int i = 0; i<26; i++){
            hashString.push_back(freq[i]);
            hashString.push_back('#');
        }
        mp[hashString].push_back(s);
    }

    vector<vector<string>> anagrams;
    for(auto [key, anagramStrings]: mp){
        anagrams.push_back(anagramStrings);
    }

    return anagrams;
}

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
#include<iostream>
#include<string>
using namespace std;

string LPS(string s){
    int n = s.size();
    int maxlength = 0;
    string str;
    for (int i = 0; i < n; i++){
        int left = i, right = i;
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        if(maxlength<right-left-1){
            maxlength = right - left - 1;
            str = s.substr(left + 1, maxlength);
        }

        left = i, right = i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        if(maxlength<right-left-1){
            maxlength = right - left - 1;
            str = s.substr(left + 1, maxlength);
        }
    }
    return str;
}

int main()
{
    string s = "ababd";
    cout << LPS(s);

    return 0;
}
/**
//Count palindromic substrings
#include<iostream>
using namespace std;

int palindromeSUbstrings(string s){
    int ans = 0;
    for (int i = 0; i < s.size(); i++){
        int left = i, right = i;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            ans++;
            right++;
            left--;
        }

        left = i, right = i+1;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            ans++;
            right++;
            left--;
        }
    }
    return ans;
}

int main()
{
    string str1 = "abc";
    string str2 = "aaa";

    cout << palindromeSUbstrings(str1) << endl;
    cout << palindromeSUbstrings(str2) << endl;

    return 0;
}
/*
//Count palindromic subsequences
#include<iostream>
#include<vector>
using namespace std;

int countPS(int i, int j, string s, vector<vector<int>>& dp){
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
        return dp[i][j] = countPS(i, j-1, s, dp) + countPS(i+1, j, s, dp) + 1;
    }
    else{
        return dp[i][j] = countPS(i, j-1, s, dp) + countPS(i+1, j, s, dp) - countPS(i+1, j-1, s, dp);
    }
}

int main()
{
    string s;
    cin >> s; // Input example: aba or abca
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1)); // Initializing dp with -1
    cout << countPS(0, n - 1, s, dp);

    return 0;
}
/*
//SmallestWindow
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string smallestWindow(string s, string t){
    int n = s.size();
    if(n<t.size()){
        return "-1";
    }
    unordered_map<char, int> mp;
    for(char ch:t){//auto
        mp[ch]++;
    }
    int requiredCount = t.size();
    int i = 0, j = 0;
    int minWindowSize = INT_MAX;
    int start_i = 0;
    while(j<n){
        char ch = s[j];
        if(mp[ch]>0){
            requiredCount--;
        }
        mp[ch]--;

        while(requiredCount == 0){
            int currentWindowSize = j - i + 1;
            if(minWindowSize > currentWindowSize){
                minWindowSize = currentWindowSize;
                start_i = i;
            }
            mp[s[i]]++;
            if(mp[s[i]] > 0){
                requiredCount++;
            }
            i++;
        }
        j++;
    }
    if(minWindowSize==INT_MAX){
        return "-1";
    }
    return s.substr(start_i, minWindowSize);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << smallestWindow(s, t) << endl;

    return 0;
}
/**
//Wildcard Matching
//Recursion method
// wild = ge*ks
// pattern = geeks
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool f(int i, int j, string pattern, string text){
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        return false;
    }
    if(j<0 && i>=0){
        for (int ii = 0; ii<=i; ii++){
            if(pattern[ii] != '*'){
                return false;
            }
        }
        return true;
    }
    if(pattern[i]==text[j] || pattern[i]=='?'){
        return f(i - 1, j - 1, pattern, text);
    }
    if(pattern[i]=='*'){
        return f(i - 1, j, pattern, text) | f(i, j - 1, pattern, text);
    }
    return false;
}

bool wildCardMatching(string pattern, string text){
    int n = pattern.size();
    int m = text.size();
    return f(n-1, m-1, pattern, text);
}

int main()
{
    string s, t;
    cin >> s >> t;
    
    cout << wildCardMatching(s, t)<< endl;
    return 0;
}
/**
//Wildcard Matching
//Meorizaton method
// wild = ge*ks
// pattern = geeks
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool f(int i, int j, string pattern, string text, vector<vector<int>> dp){
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        return false;
    }
    if(j<0 && i>=0){
        for (int ii = 0; ii<=i; ii++){
            if(pattern[ii] != '*'){
                return false;
            }
        }
        return true;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(pattern[i]==text[j] || pattern[i]=='?'){
        return dp[i][j] = f(i - 1, j - 1, pattern, text, dp);
    }
    if(pattern[i]=='*'){
        return dp[i][j] = f(i - 1, j, pattern, text, dp) | f(i, j - 1, pattern, text, dp);
    }
    return false;
}

bool wildCardMatching(int i, int j, string pattern, string text, vector<vector<int>> dp){
    
    return f(i, j, pattern, text, dp);
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << wildCardMatching(n-1, m-1, s, t, dp) << endl;
    return 0;
}
/**
//Longest proper prefix suffix
//My aproach
//Optimal aproach
#include<iostream>
#include<vector>
using namespace std;

int LPS(string s){
    int n=s.size();
    string prefix;
    string suffix;
    int ans = 0;
    for (int i = 0; i < n-1; i++){
        prefix = prefix + s[i];
        suffix = s[n - 1 - i] + suffix;
        if(prefix == suffix){
            ans = prefix.size();
        }
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;

    cout << LPS(str) << endl;
    return 0;
}
/*
//"abab" "aaaa" "abcdeabcd" "abcdeabab"
//Longest proper prefix suffix
//Optimal aproach
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int LPS(string s){
    int n=s.size();
    vector<int> v(n, 0);
    int i = 0, j = 1;

    if(n==0){
        return 0;
    }
    while(j<n){
        if(s[i]==s[j]){
            v[j] = i + 1;
            i++; j++;
        }
        else{
            if (i != 0){
                //i = v[i-1];
                i = 0;
            }
            else{
                j++;
            }
        }
    }
    return v[n - 1];
}

int main()
{
    string str;
    cin >> str;

    cout << LPS(str) << endl;
    return 0;
}
/**
//Rabin Karp algorithm for pattern search
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define d 256

void search(char txt[], char pat[], int q){
    int n = strlen(txt);
    int m = strlen(pat);    
    int h = 1;
    int t = 0, p = 0;
    int i, j;

    for (i = 0; i < m - 1; i++){
        h = (h * d) % q;
    }

    for (i = 0; i < m; i++){
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    for (i = 0; i <= n - m; i++){
        if(t==p){
            for (j = 0; j < m; j++){
                if(txt[i+j] != pat[j]){
                    break;
                }
            }
            if(j==m){
                cout << "Pattern found at index " << i << endl;
            }
        }
        if(i<n-m){
            t = ((d * (t - (txt[i] * h))) + txt[i + m]) % q;

            if(t<0){
            t = t + q;
            }
        }
    }
}

int main()
{
    char text[]="GEEKS FOR GEEKS";
    char pattern[] = "GEEK";
    int q = 101;

    search(text, pattern, q);

    return 0;
}
/**
//Transform one string to another string
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int transform(string A, string B){
    int m=A.size();
    int n = B.size();
    int c = 0;

    if(m!=n){
        return -1;
    }

    vector<int> v1(256, 0);
    vector<int> v2(256, 0);

    for (int i = 0; i < m; i++){
        v1[A[i]]++;
        v2[B[i]]++;
    }
    for (int i = 0; i < 256; i++){
        if(v1[i]!=v2[i]){
            return -1;
        }
    }
    
    int i = m - 1, j = n - 1;
    while(i>=0 && j>=0){
        if (A[i] == B[j]){
            i--;
            j--;
        }
        else{
            c++;
            i--;
        }
    }
    return c;
}

int main()
{
    string A="EACBD";
    string B="EABCD";

    cout << transform(A, B) << endl;
    return 0;
}
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
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int wordWrap(int i, int rem, int arr[], int k, vector<vector<int>> dp){
    if(i==4){
        return 0;
    }
    if(dp[i][rem] != -1){
        return dp[i][rem];
    }
    int ans;
    if(arr[i]>rem){
        ans = (rem + 1) * (rem + 1) + wordWrap(i + 1, k - arr[i] - 1, arr, k, dp);
    }
    else{
        int choice1=(rem+1)*(rem+1)+ wordWrap(i + 1, k - arr[i] - 1, arr, k, dp);
        int choice2 = wordWrap(i + 1, rem - arr[i] - 1, arr, k, dp);
        ans = min(choice1, choice2);
    }
    dp[i][rem] = ans;
    return dp[i][rem];
}

int main()
{
    int arr[] = {3, 2, 2, 5};
    int k = 6;
    vector < vector<int>> dp(505, vector<int>(2005, -1));
    
    cout << wordWrap(0, k, arr, k, dp);

    return 0;
}
*/