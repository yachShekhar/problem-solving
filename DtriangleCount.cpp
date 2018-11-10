#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define MEM(x,a) memset(x,a,sizeof(x));
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define ROFEACH(it, l) for (auto it =  l.end(); it !=l.begin(); it--)
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


int sol(int n, int k){
	int tempU = n - k + 1;
	tempU = tempU <= 0 ? 0 : tempU;
//	int tempD = n - 2 * k + 1 <= 0 ? 0 : n - 2 * k + 1;
	int tnU = tempU * (tempU + 1) / 2;
//	int tnD = tempD * (tempD + 1) / 2;
	return tnU;
}

int main(){
	int t;
	cin>>t;
	int countT = 0;
	while(t--){
		int n, k;
		cin>>n>>k;
		int sl = sol(n, k);
		countT++;
		cout<<"Case "<<countT<<": "<<sl<<endl;		
	}
	return 0;
}
