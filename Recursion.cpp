/**
//Sum of n natural numbers
#include<iostream>
using namespace std;

int sum(int n){
    if(n==0){
        return 0;
    }
    return (n + sum(n - 1));
}

int main()
{
    int n;
    cin >> n;

    cout << sum(n) << endl;
    return 0;
}

/**
//To find nth power of number
#include<iostream>
using namespace std;

int power(int n, int p){
    if(p==0){
        return 1;
    }

    return n * power(n, p - 1);
}

int main()
{
    int n, p;
    cin >> n >> p;

    cout << power(n, p) << endl;
    return 0;
}

/**
//To find factorial of number
#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;

    cout << factorial(n) << endl;
    return 0;
}

/**
//To find nth fibonacci number
#include<iostream>
using namespace std;

int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    return (fib(n - 1) + fib(n - 2));
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}

/**
//Decresing order numbers
#include<iostream>
using namespace std;

void dec(int n){
    if(n==0){
        return;
    }

    cout << n << endl;
    dec(n - 1);
}

int main()
{
    int n;
    cin >> n;
    dec(n);

    return 0;
}

/**
//To print incresing order numbers
#include<iostream>
using namespace std;

void inc(int n){
    if(n==0){
        return;
    }
    inc(n - 1);
    cout << n << endl;
}

int main()
{
    int n;
    cin >> n;
    inc(n);

    return 0;
}

/**
//To check wether array is sorted or not
#include<iostream>
using namespace std;

bool sorted(int a[], int n){
    if(n==1){
        return true;
    }
    return ((a[0] < a[1]) && sorted(a + 1, n - 1));
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    cout << sorted(a, 5) << endl;
    
    return 0;
}

/**
//To find first and last occurance of number
#include<iostream>
using namespace std;

int firstocc(int a[], int n, int i, int key){
    if(a[i]==key){
        return i;
    }
    if(i==n){
        return -1;
    }
    return firstocc(a, n, i + 1, key);
}

int lastocc(int a[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    int restarray = lastocc(a, n, i + 1, key);
    if(restarray != -1){
        return restarray;
    }
    if(a[i]==key){
        return i;
    }
    return -1;
}

int main()
{
    int a[] = {4, 2, 1, 2, 5, 2, 7};
    cout << firstocc(a, 7, 0, 2) << endl;
    cout << lastocc(a, 7, 0, 2) << endl;

    return 0;
}

/**
//To reverse the string
#include<iostream>
using namespace std;

void reverse(string s){
    if(s.length()==0){
        return;
    }
    string ros = s.substr(1);
    reverse(ros);
    cout << s[0];
}

int main()
{
    reverse("JUGESH");
    return 0;
}

/**
//To replace pi with 3.14
#include<iostream>
using namespace std;

void replacepi(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout << "3.14";
        replacepi(s.substr(2));
    }
    else{
        cout << s[0];
        replacepi(s.substr(1));
    }
}

int main()
{
    replacepi("pippppiiiipi");

    return 0;
}

/**
//To remove duplicates
#include<iostream>
using namespace std;

string removeDup(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string ans = removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return ch + ans;
}

int main()
{
    cout << removeDup("aaaabbbeeecdddd");
    return 0;
}
/**
#include<iostream>
using namespace std;

string move(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string ans = move(s.substr(1));
    if(ch=='x'){
        return ans + ch;
    }
    return ch + ans;
}

int main()
{
    cout << move("xixxncxhgxxdc");
    return 0;
}
/**
//Substrings
#include<iostream>
using namespace std;

void subseq(string s, string ans){
    if(s.length()==0){
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    subseq(ros, ans);
    subseq(ros, ans + ch);
}

int main()
{
    subseq("ABC", "");
    return 0;
}

/**
//Substrings wiht ascii values
#include<iostream>
using namespace std;

void subseq(string s, string ans){
    if(s.length()==0){
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int code = ch - '0';
    string ros = s.substr(1);
    subseq(ros, ans);
    subseq(ros, ans + ch);
    subseq(ros, ans + to_string(code));
}

int main()
{
    subseq("AB", "");
    return 0;
}
/**/