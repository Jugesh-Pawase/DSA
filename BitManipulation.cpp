/**
//To get, set, clear and update bit
#include<iostream>
using namespace std;

int getBit(int n, int pos){
    return (n & (1 << pos)) != 0;
}

int setBit(int n, int pos){
    return n | (1 << pos);
}

int clearBit(int n, int pos){
    int mask = ~(1 << pos);
    return n & mask;
}

int updateBit(int n, int pos, int val){
    int mask = ~(1 << pos);
    n = n & mask;
    return n | (val << pos);
}

int main()
{
    //cout << getBit(5, 2) << endl;
    //cout << setBit(5, 1) << endl;
    //cout << clearBit(5, 2) << endl;
    //cout << updateBit(5, 1, 1) << endl;

    return 0;
}

/**
//Number is power of two or not
#include<iostream>
using namespace std;

bool ispowerof2(int n){
    return (n && !(n & (n - 1)));
}

int main()
{
    cout << ispowerof2(16) << endl;

    return 0;
}

/**
//Number of one's
#include<iostream>
using namespace std;

int numberofones(int n){
    int count = 0;
    while(n){
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    cout << numberofones(8) << endl;

    return 0;
}

/**
//All subsets of set
#include<iostream>
using namespace std;

void subsets(int a[], int n){
    for (int i = 0; i<(1<<n); i++){
        for (int j = 0; j < n; j++){
            if(i & (1<<j)){
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    subsets(a, 4);

    return 0;
}

/**
//To find unique number when except one number all present twice
#include<iostream>
using namespace std;

int unique(int a[], int n){
    int xorsum = 0;
    for (int i = 0; i < n; i++){
        xorsum = xorsum ^ a[i];
    }
    return xorsum;
}

int main()
{
    int a[] = {2, 4, 6, 7, 4, 6 , 2};
    cout << unique(a, 7) << endl;

    return 0;
}

/**
//To find two unique numbers
#include<iostream>
using namespace std;

int setBit(int n, int pos){
    return (n & (1 << pos)) != 0;
}

void unique(int a[], int n){
    int xorsum = 0;
    for (int i = 0; i < n; i++){
        xorsum = xorsum ^ a[i];
    }

    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;
    while(setbit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < n; i++){
        if(setBit(a[i], pos-1)){
            newxor = newxor ^ a[i];
        }
    }
    cout << newxor << endl;
    cout << (tempxor ^ newxor) << endl;
}

int main()
{
    int a[] = {1, 2, 3, 1, 2, 3, 5, 7};
    unique(a, 8);

    return 0;
}

/**/

//To find unique number when except one number all present thrice
#include<iostream>
using namespace std;

int getBit(int n, int pos){
    return (n & (1 << pos)) != 0;
}

int setBit(int n, int pos){
    return (n | (1 << pos));
}

int unique(int a[], int n){
    int result = 0;
    for (int i = 0; i < 64; i++){
        int sum = 0;
        for (int j = 0; j < n; j++){
            if(getBit(a[j], i)){
                sum++;
            }
        }
        if((sum%3) != 0){
            result = setBit(result, i);
        }
    }
    return result;
}

int main()
{
    int a[] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3};
    cout << unique(a, 10) << endl;

    return 0;
}