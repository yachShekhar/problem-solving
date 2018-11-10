//https://www.codechef.com/problems/PCJ18C
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define mem(x,a) memset(x,a,sizeof(x));
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tr(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<char> vc;

template < class T > T multiply( T a, T b ){return a * b;}
template < class T > T larger( T a, T b ){return ( a > b ? a : b );}
template < class T > T smaller( T a, T b ){return ( a < b ? a : b );}
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T lcm(T a, T b ){return (a*b)/gcd(a,b);}
//Convert int to string
template <typename T> string to_str(T str){stringstream stream; stream << str; return stream.str();}
template <typename T>int to_int(T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(string &s,char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

void sol(LL n, LL a,LL k){
	LL angle = (n - 2) * 180;
	LL d_n = (angle - n * a) * 2;
	LL d_d = (n)*(n-1);
	LL gc = gcd(d_n, d_d);
	d_n/=gc;
	d_d/=gc;
	LL ans_n = a*(d_d) + (k-1)*(d_n);
	gc  = gcd(ans_n, d_d);
	ans_n /= gc;
	d_d/=gc;
	cout<<ans_n<<" "<<d_d<<"\n";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, a, k;
		cin>>n>>a>>k;
		sol(n, a, k);
	}
	return 0;
}
