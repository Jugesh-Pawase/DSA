/**/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
    }//1 2 3
    cout << endl;
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }//1 2 3
    cout << endl;
    for (auto element:v){
        cout << element << " ";
    }//1 2 3
    cout << endl;
    v.pop_back();//1 2

    vector<int> v2(3, 50);//50 50 50

    swap(v, v2);
    for (auto element:v){
        cout << element << " ";
    }
    cout << endl;
    for (auto element:v2){
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
/**
#include<iostream>
#include<vector>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}

int main()
{
    int a[] = {10, 16, 7, 14, 5, 3, 2, 9};
    vector<pair<int, int>> v;
    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++){
        v.push_back(make_pair(a[i], i));
    }

    sort(v.begin(), v.end(), myCompare);
    for (int i = 0; i < v.size(); i++){
        a[v[i].second] = i;
    }
    for (int i = 0; i < v.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
*/