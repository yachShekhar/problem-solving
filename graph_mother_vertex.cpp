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

class Graph{
	int v;
	list<int> *adj;
	public:
		Graph(int v);
		void addEdge(int v, int w);
		void dfs(int v, bool visited[]);
		int find_mother();
};

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
};

void Graph::addEdge(int v, int w){
	this->adj[v].push_back(w);
}

void Graph::dfs(int v, bool visited[]){
	visited[v] = true;
	FOREACH(it, adj[v]){
		if(!visited[*it]){
			visited[*it] = true;
			dfs(*it, visited);
		}	
	}
}

int Graph::find_mother(){
	int mv;
	bool visited[v];
	FOR(i, 0, v){
		visited[i] = false;
	}
	FOR(i, 0, v){
		if(!visited[i]){
			dfs(i, visited);
			mv = i;
		}
	}
	FOR(i, 0, v){
		visited[i] = false;
	}
	dfs(mv, visited);
	FOR(i, 0, v){
		if(!visited[i]){
			return -1;
		}
	}
	return mv;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// Create a graph given in the above diagram
   	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(6, 4);
	g.addEdge(5, 6);
	g.addEdge(5, 2);
	g.addEdge(6, 0);
	cout << "A mother vertex is " << g.find_mother();

	return 0;
}
