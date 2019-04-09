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
	list<PII> *adj;

	public:
		Graph(int V);
		void addEdge(int U, int V, int W);
		void primMST();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<PII>[V];
}

void Graph::addEdge(int U, int V, int W){
	adj[U].push_back(make_pair(V, W));
	adj[V].push_back(make_pair(U, W));
}

void Graph::primMST(){
	VI key(V, INT_MAX);
	VI parent(V, -1);

	vector<bool> inMST(V, false);
	int src = 0;
	priority_queue<PII, vector<PII>, greater<PII> > pq;
	pq.push(make_pair(0, src));

	while(!pq.empty()){
		PII top = pq.top();
		pq.pop();
		int u = top.second;

		FOREACH(it, adj[u]){
			int v = (*it).first;
			int w = (*it).second;
			if(!inMST[v] && key[v] > w){
				key[v] = w;
				parent[v] = u;
				pq.push(make_pair(w, v));
			}
		}
	}
	FOR(i, 0, parent.size()){
		cout<<parent[i]<<" ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V = 9; 
    Graph g(V); 
  
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
  
    g.primMST();
	return 0;
}
