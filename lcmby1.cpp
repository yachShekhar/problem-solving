#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define MEM(x,a) memset(x,a,sizeof(x));
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define ROFEACH(it, l) for (auto it =  l.end(); it !=l.begin(); it--)
#define TOUPPER(str) transform(str.begin(), str.end(),str.begin(), ::toupper)
#define TOLOWER(str) transform(str.begin(), str.end(),str.begin(), ::tolower)
typedef long long LL;
typedef long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;
typedef vector<string> VS;
typedef vector<char> VC;
template < class T > T MAX( T a, T b ){return ( a > b ? a : b );}
template < class T > T MIN( T a, T b ){return ( a < b ? a : b );}
template<class T> T GCD(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T LCM(T a, T b ){return (a*b)/gcd(a,b);}
//Convert int to string
template <typename T> string to_str(T str){stringstream stream; stream << str; return stream.str();}
template <typename T>int to_int(T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(string &s,char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

int lcmDiffOne(int arr[], int n) 
{ 
    int dp[n]; 
    for (int i = 0; i< n; i++) 
        dp[i] = 1; 
  
    for (int i=1; i<n; i++) 
    { 
        for (int j=0; j<i; j++) 
        { 
            if ((arr[i] == arr[j]+1) || 
                (arr[i] == arr[j]-1)) 
  
                dp[i] = max(dp[i], dp[j]+1); 
        } 
    } 
  
    int result = 1; 
    for (int i = 0 ; i < n ; i++) 
        if (result < dp[i]) 
            result = dp[i]; 
    return result; 
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int arr[] = {1, 2, 3, 4, 5, 3, 2}; 
	int arr[] = {9,5,7,3,4,2,0,11,7};
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << lcmDiffOne(arr, n); 
    return 0; 
}
