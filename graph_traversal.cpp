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
		void bfs(int s);
		void dfs(int s);
};

Graph::Graph(int v){
	this->v = v;
  	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::bfs(int s){
	bool *visited = new bool[v];
	FOR(i, 0, v){
		visited[i] = false;
	}

	visited[s] = true;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int f = q.front();
		cout<<f<<endl;
	       	q.pop();
		FOREACH(it, adj[f]){
			if(!visited[*it]){
				visited[*it] = true;
				q.push(*it);
			}	
		}
	}	
}

void Graph::dfs(int s){
	bool *visited = new bool[v];
	FOR(i, 0, v){
		visited[i] = false;
	}
	stack<int> st;
	st.push(s);
	visited[s] = true;

	while(!st.empty()){
		int f = st.top();
		st.pop();
		cout<<f<<endl;
		FOREACH(it, adj[f]){
			if(!visited[*it]){
				visited[*it] = true;
				st.push(*it);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
    	g.addEdge(1, 2);
   	g.addEdge(2, 0);
   	g.addEdge(2, 3);
   	g.addEdge(3, 3);
	cout<<"bfs traversal....."<<endl;
	g.bfs(2);
	cout<<"dfs traversal....."<<endl;
	g.dfs(2);
	return 0;
}
