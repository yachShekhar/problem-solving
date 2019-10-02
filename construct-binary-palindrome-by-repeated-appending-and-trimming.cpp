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
// function to apply DFS 
void dfs(int parent, int ans[], vector<int> connectchars[]) 
{ 
    // set the parent marked 
    ans[parent] = 1; 
  
    // if the node has not been visited set it and 
    // its children marked 
    for (int i = 0; i < connectchars[parent].size(); i++) { 
        if (!ans[connectchars[parent][i]]) 
            dfs(connectchars[parent][i], ans, connectchars); 
    } 
} 
  
void printBinaryPalindrome(int n, int k) 
{ 
    int arr[n], ans[n]; 
  
    // link which digits must be equal 
    vector<int> connectchars[k]; 
  
    for (int i = 0; i < n; i++) 
        arr[i] = i % k; 
  
    // connect the two indices 
    for (int i = 0; i < n / 2; i++) { 
        connectchars[arr[i]].push_back(arr[n - i - 1]); 
        connectchars[arr[n - i - 1]].push_back(arr[i]); 
    } 
  
    // set everything connected to  
    // first character as 1 
    dfs(0, ans, connectchars); 
  
    for (int i = 0; i < n; i++) 
        cout << ans[arr[i]]; 
} 
  
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 10, k = 4; 
    printBinaryPalindrome(n, k); 
    return 0; 
}
