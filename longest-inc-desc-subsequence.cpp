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


VI LIS(int l, VI &v){
    VI dp(l, 0);
    if(v.size() == 0) return dp;
    FOR(i, 1, l){
        if(v[i] == v[i - 1]){
            dp[i] = dp[i - 1] + 1;
        }else{
            dp[i] = dp[i - 1];
        }
    }
    return dp;
}

//length of array having longest increasing decreasing subsequence
int solve(int l, VI &v){
    VI lis = LIS(l, v);
    reverse(begin(v), end(v));
    VI rlis = LIS(l, v);
    reverse(begin(rlis), end(rlis));

    int mx = 0;
    FOR(i, 0, l){
        mx = MAX(mx, lis[i] + rlis[i] - 1 - i);
    }
    return mx;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, l;
	cin>>t>>l;
    vector<int> v(l);
	while(t--){
        FOR(i, 0, l){
            int d;
            cin>>v[i];
        }	  
	}
    FOR(i, 0, l){
        cout<<v[i]<<endl;
    }
    cout<<solve(l, v)<<endl;
	return 0;
}

