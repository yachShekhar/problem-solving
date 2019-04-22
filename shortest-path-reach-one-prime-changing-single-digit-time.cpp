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
	private:
		int V;
		list<int> *adj;
	public:
		Graph(int V){
			this->V = V;
			adj = new list<int>[V];
		}

		void addEdge(int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		void sortestPath(int source, int target){
			queue<int> q;
			q.push(source);
			vector<int> visited(V, 0);
			map<int, int> mp;
			bool targetFound = false;
			visited[source] = 1;
			while(!q.empty()){
				int v = q.front();
				q.pop();
				FOREACH(it, adj[v]){
					if(!visited[*it]){
						mp[*it] = v;
						visited[*it] = visited[v] + 1;
						if(*it == target){
							targetFound = true;
							break;
						}
						q.push(*it);
					}
				}
			}
			int t = target;
			stack<int> s;
			s.push(t);
			while(mp.find(t) != mp.end()){
				t = mp[t];
				s.push(t);
			}
			cout<<"path count:"<<visited[target] - 1<<endl;
			while(!s.empty()){
				cout<<s.top()<<" ";
				s.pop();
			}
			cout<<endl;

		}

};

bool isAdjacent(int prim1, int prim2){
	string str1 = to_string(prim1);
	string str2 = to_string(prim2);
	int diff = 0;

	if(str1[0] != str2[0]){
		diff++;
	}
	if(str1[1] != str2[1]){
		diff++;
	}
	if(str1[2] != str2[2]){
		diff++;
	}
	if(str1[3] != str2[3]){
		diff++;
	}
	return diff == 1;
}

Graph buildGraph(vector<int> &prime){
	cout<<"max prime value: "<<prime[prime.size() - 1]<<endl;
	Graph g(prime[prime.size() - 1] + 1);
	FOR(i, 0, prime.size()) {
		FOR(j, i + 1, prime.size()) {
			if(isAdjacent(prime[i], prime[j])){
				cout<<prime[i]<<" "<<prime[j]<<endl;
				g.addEdge(prime[i], prime[j]);
			}
		}
	}
	return g;
}

vector<int> getPrimeNo(int min, int max){
	vector<int> prime;
	vector<bool> isPrime;
	FOR(i, 2, max + 1){
		prime.push_back(i);
		isPrime.push_back(true);
	}
	vector<int> finalP;
	for(int p = 2; p * p <= max; p++){
		if(isPrime[p - 2]){
			for(int k = p * p; k <= max; k+=p){
				isPrime[k - 2] = false;
			}
		}
	}

	FOR(i, 0, max + 1){
		if(isPrime[i] && prime[i] >= min){
				finalP.push_back(prime[i]);
		}
	}
	return finalP;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// int minRange = 0, maxRange = 50;

	// vector<int> res = getPrimeNo(minRange, maxRange);
	// FOR(i, 0, res.size()){
	// 	cout<<res[i]<<" ";
	// }

	//final setup
	VI primes = getPrimeNo(1000, 9999);
	Graph g = buildGraph(primes);
	int source = 1033, target = 8179;
	g.sortestPath(source, target);
	return 0;
}
