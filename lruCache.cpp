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

class LRUCache{
	int size;
	map<int, list<map<int, int> >::iterator> mp;
	list<map<int, int> > dq;

	public:
		LRUCache(int size);
		void refer(int k, int v);
		void display();
};

LRUCache::LRUCache(int size){
	this->size = size;
};

void LRUCache::refer(int k, int v){
	if(mp.find(k) == mp.end()){
		if(mp.size() == size){
			map<int, int> last = dq.back();
			dq.pop_back();
			mp.erase(last.begin()->first);
		}
	}else{
		dq.erase(mp[k]);
	}

	dq.push_front(map<int, int>(k, v));
	mp[k] = dq.begin(); 
};

void LRUCache::display(){
};
	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	LRUCache l(5);
	l.display();
	return 0;
};
