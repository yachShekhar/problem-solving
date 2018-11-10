//http://codeforces.com/problemset/problem/339/A
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
template < class T > T MAX(T a, T b ){return ( a > b ? a : b );}
template < class T > T MIN(T a, T b ){return ( a < b ? a : b );}
template<class T> T GCD(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T LCM(T a, T b ){return (a*b)/gcd(a,b);}
//Convert int to string
template <typename T> string to_str(T str){stringstream stream; stream << str; return stream.str();}
template <typename T>int to_int(T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(string &s,char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

int main(){
	string s;
	cin>>s;
	map<char, int> mp;
	mp['1'] = 0;
	mp['2'] = 0;
	mp['3'] = 0;
	
	for(int i = 0; i < s.size(); i = i + 2){
		mp[s[i]] = mp[s[i]] + 1;
	}
	
	string sol = "";
	FOR(i, 0, mp['1']){
		sol = sol + "1";
		if(i != mp['1'] - 1){
			sol = sol + "+";
		}
	}
	
	FOR(i, 0, mp['2']){
		if(!sol.empty()){
			sol = sol + "+";
		}
		sol = sol + "2";
	}

	FOR(i, 0, mp['3']){
		if(!sol.empty()){
			sol = sol + "+";
		}
		sol = sol + "3";
	}

	cout<<sol<<endl;
	return 0;
}
