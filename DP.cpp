/**
//Memorise method
#include<iostream>
#include<vector>
using namespace std;

int f(int n, vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
    
    return 0;
}
/**
//Tubulation Method
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
    return 0;
}
/**
//Tabulation method with optimal aproach
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int prev = 1, prev2 = 0;
    dp[0] = prev2, dp[1] = prev;
    for (int i = 2; i <= n; i++){
        dp[i] = prev + prev2;
        prev2 = prev;
        prev = dp[i];
    }
    cout << dp[n] << endl;

    return 0;
}
/**/