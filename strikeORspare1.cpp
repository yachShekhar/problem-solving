//https://www.codechef.com/problems/PINS
#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define mem(x,a) memset(x,a,sizeof(x));
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tr(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
typedef unsigned long long LL;
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

map<LL, LL> mp;
map<LL, LL> mpv;
LL n = 100000;
bool isEven(LL n){
	return n%2 == 0;
}
void sol(){
	mp[1] = 1;
	mpv[1] = 1;
	FOR(i, 2, n + 1){ 
		LL num = i / 2;
		if(!isEven(i)){
			num += 1;
		}
		if(mp.find(num) == mp.end()){
			mp[num] = mp[num - 1];		
		}else{
			mp[num] = 10 * mp[num];
		}
		mpv[i] = mp[num];
	}
}

int main(){
	int t;
	cin>>t;
	sol();
	while(t--){
		int n;
		cin>>n;
		cout<<1<<" "<<mpv[n]<<endl;
	}
	return 0;
}
