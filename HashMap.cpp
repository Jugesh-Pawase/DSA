/*#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int hash[13] = {0};
    for (int i = 0; i < n; i++){
        hash[a[i]]++;
    }
    int q;
    cin >> q;
    int number;
    while(q--){
        cin >> number;
        cout << hash[number] << endl;
    }
    return 0;
}
/**
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int hash[26]={0};
    for(int i=0; i<s.size(); i++){
        hash[s[i] - 'a']++;
    }
    //for (int i = 0; i<26; i++){
    //    char c = 'a' + i;
    //    cout << c << "->" << hash[i] << endl;
    //}
    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c - 'a']<<endl;
    }
    return 0;
}
/**/
#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    //inserting elemens in map
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    
    int q;
    cin >> q;
    int number;
    //Gives frequency of element
    while(q--){
        cin >> number;
        cout << mp[number] << " ";
    }
    return 0;
}