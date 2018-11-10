//https://www.codechef.com/problems/CLFIBD
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

template < class T > T MULTIPLY( T a, T b ){return a * b ;}
template < class T > T LARGER( T a, T b ){return ( a > b ? a : b );}
template < class T > T SMALLER( T a, T b ){return ( a < b ? a : b );}
template<class T> T GCD(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T LCM(T a, T b ){return (a*b)/gcd(a,b);}
//Convert int to string
template <typename T> string to_str(T str){stringstream stream; stream << str; return stream.str();}
template <typename T>int to_int(T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(string &s,char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

void sol(string s){
	bool ifNot = false;
	map<char, ULL> mp;
	FOR(i, 0, s.length()){
		if(mp.find(s[i]) == mp.end()){
			mp[s[i]] = 1;	
		}else{
			mp[s[i]] += 1;
		}
		//cout<<"s[i]:"<<s[i]<<" mp[s[i]]: "<<mp[s[i]]<<endl;
	}

	VI v;
	FOREACH(it, mp){
		v.push_back(it->second);
	}

	if(v.size() >= 3){
		sort(v.begin(), v.end());
		
		if(v[2] == v[1] + v[0] && v[3] != v[2] + v[1]){
			swap(v[0], v[1]);
		}
		
		FOR(i, 2, v.size()){
			if(v[i] != v[i - 1] + v[i - 2]){
				ifNot = true;
				break;
			}
		}
	}

	string ou = ifNot ? "Not" : "Dynamic";
	cout<<ou<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		sol(s);
	}
	return 0;
}
