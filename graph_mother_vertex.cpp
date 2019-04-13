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
class Graph {
	int V;
	list<int> *adj;
	public:
		Graph(int V){
			this->V = V;
			adj = new list<int>[V];
		}

		void addEdge(int u, int v){
			adj[u].push_back(v);
		}

		void dfs(int v, vector<bool> &visited){
			visited[v] = true;
			FOREACH(it, adj[v]){
				if(!visited[*it]){
					dfs(*it, visited);
				}
			}
		}

		int findMother(){
			int mv = 0;
			vector<bool> visited(V, false);
			FOR(i, 0, V){
				if(!visited[i]){
					dfs(i, visited);
					mv = i;
				}
			}
		
			fill(visited.begin(), visited.end(), false);
			dfs(mv, visited);
			FOR(i, 0, V){
				if(!visited[i]){
					return -1;
				}
			}
			return mv;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
  
    cout << "A mother vertex is " << g.findMother(); 
  
	return 0;
}
