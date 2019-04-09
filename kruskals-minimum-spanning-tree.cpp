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
	int V;
	list<pair<int, PII> > edges;
	public:
		Graph(int V);
		void addEdge(int U, int V, int W);
		void kruskalMST();
};

Graph::Graph(int V){
	this->V = V;	
}

void Graph::addEdge(int U, int V, int W){
	edges.push_back(make_pair(W, make_pair(U, V)));
}

void Graph::kruskalMST(){
	sort(edges.begin(), edges.end());
	DisjointSet d(V);
	FOREACH(it, edges){
		int w = (*it).first;
		int u = (*it).second.first;
		int v = (*it).second.second;

		int fu = d.find(u);
		int fv = d.find(v);
		if(fu != fv){
			d.merge(fu, fv);
		}
	}
}

class DisjointSet{
	int *parent;
	int V;
	public:
		DisjointSet(int V);
		int find(int v);
		void merge(int u, int v);
};

DisjointSet::DisjointSet(int V){
	parent = new int[V];
	this->V = V;
	FOR(i, 0, sizeof(parent)){
		parent[i] = -1;
	}
}

int DisjointSet::find(int v){
	if(parent[v] == -1){
		return v;
	}
	return find(parent[v]);
}

void DisjointSet::merge(int u, int v){
	int uSet = find(u);
	int vSet = find(v);

	if (uSet != vSet) {
		parent[v] = u;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// DisjointSet d(4);
	
	// d.merge(0, 1);
	// d.merge(1, 2);

	// int f = d.find(2);

	Graph g(9); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    cout << "Edges of MST are \n"; 
    g.kruskalMST(); 
	return 0;
}