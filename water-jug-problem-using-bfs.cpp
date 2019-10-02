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

void sol(int &x, int &y, int &z){
	queue<pair<int, int> > q;

	q.push({0, 0});
	map<pair<int, int>, bool> visited;

	pair<int, int> finalPair1 = {z, 0};
	pair<int, int> finalPair2 = {0, z};

	while(!q.empty()){
		pair<int, int>  p = q.front();
		q.pop();
		
		// FOREACH(it, visited){
		// 	PII k = it->first;
		// 	int v = it->second;
		// 	cout<<k.first<<", "<<k.second<<" "<<v<<endl;
		// }
		if(visited[{p.first, p.second}]){
			continue;
		}
		visited[{p.first, p.second}] = true;
		if(p == finalPair1 || p == finalPair2){
			cout<<p.first<< " " <<p.second<<endl;
			return;
		}else{
			cout<<p.first<< " " <<p.second<<endl;
		}

		//fill the jug 1
		if(!visited[{x, p.second}]){
			q.push({x, p.second});
		}

		//pour into jug2 from jug1
		if(p.second != y && p.first != 0){
			int j2 = y - p.second > p.first ? p.second + p.first : y;
			int j1 = y - p.second > p.first ? 0 : p.first - y + p.second;
			if(!visited[{j1, j2}]){
				q.push({j1, j2});
			}
		}

		//fill the jug 2
		if(!visited[{p.first, y}]){
			q.push({p.first, y});
		}

		//pour into jug1 from jug2
		if(p.first != x && p.second != 0){
			int j1 = x - p.first > p.second ? p.first + p.second : x;
			int j2 = x - p.first > p.second ? 0 : p.second - x + p.first;
			if(!visited[{j1, j2}]){
				q.push({j1, j2});
			}
		}

		
		//empty jug 1
		if(!visited[{0, p.second}]){
			q.push({0, p.second});
		}
		//empty jug 2
		if(!visited[{p.first, 0}]){
			q.push({p.first, 0});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int x, y, z;
		cin>>x;
		cin>>y;
		cin>>z;	
		sol(x, y, z);
	}
	return 0;
}
