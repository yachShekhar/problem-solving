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

int preIndex = 0;
void solve(int pre[], int in[], map<int, int> inIndexMap, int start, int end){
	if(start > end){
		return;
	}
	int preValue = pre[preIndex++];
	int rootIndex = inIndexMap[preValue];

	solve(pre, in, inIndexMap, start, rootIndex - 1);
	solve(pre, in, inIndexMap, rootIndex + 1, end);
	
	cout<<in[rootIndex]<<" ";
}

void solve(int in[], int pre[], int n){
	map<int, int> inIndexMap;
	FOR(i, 0, n){
		inIndexMap[in[i]] = i;
	}
	solve(pre, in, inIndexMap, 0, n - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int pre[n];
		int in[n];
		FOR(i, 0, n){
			cin>>in[i];			
		}
		FOR(i, 0, n){
			cin>>pre[i];
		}
		solve(in, pre, n);
	}
	return 0;
}
