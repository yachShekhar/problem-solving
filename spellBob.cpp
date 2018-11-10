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

bool sol(string fvs, string svs){
	int count = 0;
	FOR(i, 0, 3){
		if(fvs[i] == 'o' || svs[i] == 'o'){
			count  = 1;	
			FOR(j, 0, 3){
				if(j != i && (fvs[j] == 'b' || svs[j] == 'b')){
					count++;
				}
			}
		}
		if(count == 3){
			break;
		}
	}	
	
	return count == 3 ? true : false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string f, s;
		cin>>f>>s;
		bool isBO = sol(f, s);
		string res = isBO ? "yes"  : "no";
	       cout<<res<<endl;	
				
	}
	return 0;
}
