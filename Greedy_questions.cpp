/*
//program for activity selection problem when input activities may not be sorted.
#include <bits/stdc++.h>
using namespace std;

struct Activitiy {
    int start, finish;
};

bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}

// Returns count of the maximum set of activities that can be done by a single person, one at a time.
void printMaxActivities(Activitiy arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr + n, activityCompare);

    cout << "Following activities are selected :\n";

    // The first activity always gets selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish
         << ")";

    // Consider rest of the activities
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << ", (" << arr[j].start << ", "
                 << arr[j].finish << ")";
            i = j;
        }
    }
}

// Driver code
int main()
{
    Activitiy arr[] = { { 5, 9 }, { 1, 2 }, { 3, 4 },
                        { 0, 6 }, { 5, 7 }, { 8, 9 } };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    printMaxActivities(arr, n);
    return 0;
}
*/
/*
//Minimum coins/demostrations required to reach a target
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(N)
class Solution{
public:
    vector<int> minPartition(int N)                                  
    {
        // code here
        int demo[]={1,2,5,10,20,50,100,200,500,2000};
        int n=10;
        vector<int>ans;
        for(int i=n-1; i>=0; i--){
            while(N>=demo[i]){
                ans.push_back(demo[i]);
                N-=demo[i];
            }
        }
        return ans;
    }
};
*/
/*
//Minimum sum of two numbers formed from digits of an array
//Expected Time Complexity: O(N*logN)
//Expected Auxiliary Space: O(N)
class Solution{   
public:
    string sumString(string str1, string str2){
        if(str1.length()<str2.length()){
            swap(str1, str2);
        }
        string str="";
        int n1=str1.length(), n2=str2.length();
        int diff=n1-n2;
        int carry=0;
        
        for(int i=n2-1; i>=0; i--){
            int sum=(str1[i+diff]-'0')+(str2[i]-'0')+carry;
            str.push_back(sum%10 + '0');
            carry=sum/10;
        }
        for(int i=n1-n2-1; i>=0; i--){
            int sum=(str1[i]-'0')+carry;
            str.push_back(sum%10 + '0');
            carry=sum/10;
        }
        if(carry){
            str.push_back(carry+'0');
        }
        
        if(str=="") return "0";
        reverse(str.begin(), str.end());  
      
        return str;
    }
    
    string solve(int arr[], int n) {
        // code here
        sort(arr, arr+n);
        string num1="",num2="";
        for(int i=0; i<n; i++){
            
            if(i%2==0){
                if(arr[i]==0){
                    continue;
                }
                else{
                    num1+=to_string(arr[i]);                                                         
                }
            }
            else{
                if(arr[i]==0){
                    continue;
                }
                else{
                    num2+=to_string(arr[i]);                                                         
                }
            }
        }
        return sumString(num1, num2);
    }
};
*/
/*
//Minimum sum of absolute difference of pairs of two arrays
//tc o(n)  sc o(1)
class Solution{
public:
    long long findMinSum(vector<int> &A,vector<int> &B,int N){
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long long ans=0;
        for(int i=0; i<N; i++){
            ans+=abs(A[i]-B[i]);
        }
        return ans;
    }
};
*/
/*
//maximum equal sum of three stacks
//tc o(n)  sc o(1) 
class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1=0,sum2=0,sum3=0;
       
        for(int i=0; i<N1; i++){
            sum1+=S1[i];
        }
        for(int i=0; i<N2; i++){
            sum2+=S2[i];
        }
        for(int i=0; i<N3; i++){
            sum3+=S3[i];
        }
        
        int top1=0,top2=0,top3=0;
        int ans=0;
        
        while(true){
            if(top1==N1 || top2==N2 || top3==N3) break;
            if(sum1==sum2 && sum2==sum3){
                ans=sum1;
                break;
            }
            
            if(sum1>=sum2 && sum1>=sum3){
                sum1-=S1[top1++];
            }
            else if(sum2>=sum1 && sum2>=sum3){
                sum2-=S2[top2++];
            }
            else{
                sum3-=S3[top3++];
            }
        }
        return ans;
    }
};
*/
/*
//Job Sequencing Problem with deadline
//Time Complexity: O(N log N) + O(N*M).
//Space Complexity: O(M)

#include<bits/stdc++.h>
using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 
Output: 3 90
*/
/*
//Fractional knapsack
//tc o(n*logn)  sc o(1);
class Solution {
  public:
    static bool compare(Item a, Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, compare);
        double totalValue = 0.0;
        for (int i = 0; i < n; i++) {
            if (w >= arr[i].weight) {
                totalValue += arr[i].value;
                w -= arr[i].weight;
            } else {
                totalValue += ((double)arr[i].value / (double)arr[i].weight) * (double)w;
                break;
            }
        }
        return totalValue;
    }
};
*/
/*
//Find smallest number with given number of digits and sum of digits
//TC O(d)  sc O(1)
class Solution {
  public:
    string smallestNumber(int s, int d) {             
        // code here
        if(s>9*d) return "-1";
        string ans="";
        for(int i=d-1; i>=0; i--){
            if(s>9){
                ans = "9"+ans;
                s-=9;
            }
            else{
                if(i==0){
                    ans=to_string(s)+ans;
                }
                else{
                    ans=to_string(s-1)+ans;
                    i--;
                    while(i>0){
                        ans="0"+ans;
                        i--;
                    }
                    ans="1"+ans;
                }
            }
        }
        return ans;
    }
};
*/
/*
//Maximize sum of consecutive differences in a circular array
//TC O(n*logn)    SC O(n)

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n=arr.size();
        vector<int>v(n);
        int l=0, r=n-1;
        int j=0;
        while(l<r){
            v[j++]=arr[l++];
            v[j++]=arr[r--];
        }
        if(n%2==1){
            v[j]=arr[l];
        }
        long long sum=0;
        for(int i=0; i<n-1; i++){
            sum+=abs(v[i]-v[i+1]);
        } 
        sum+=abs(v[n-1]-v[0]);
        
        return sum;
    }
};
*/
/*
//Maximize sum of consecutive differences in a circular array
//Tc O(n*logn). SC O(1)
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n=arr.size();
        long long sum=0;
        
        for(int i=0; i<n/2; i++){
            sum-=(2*arr[i]);
            sum+=(2*arr[n-1-i]);
        }
        
        return sum;
    }
};
*/
/*
//Chocolate cutting problem
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
 
   long long int t;
   cin>>t;
   while(t--)
   {
      long long int n,m,i,j,total,ans=0;
      cin>>m>>n;
 
      long long int h[m-1],v[n-1];
      for(i=0;i<m-1;++i) 
          cin>>h[i];
 
      for(i=0;i<n-1;++i)
          cin>>v[i];
 
      sort(h,h+m-1,greater<int>());
      sort(v,v+n-1,greater<int>());
 
      i=0;
      j=0;
      long long int vertical=1,horizontal=1;
      while(i<m-1 && j<n-1)
      {
          if(h[i]>v[j])
          {
              ans+=h[i]*vertical;
              horizontal++;
              i++;
          }
 
          else
          {
              ans+=v[j]*horizontal;
              vertical++;
              j++;
          }
      }
 
      total=0;
      while(i<m-1)
      {
          total+=h[i];
          i++;
      }
 
      ans+=total*vertical;
 
      total=0;
      while(j<n-1)
      {
          total+=v[j];
          j++;
      }
 
      ans+=total*horizontal;
 
      cout<<ans<<endl;
 
   }
 
 
     return 0;
}
*/