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
template < class T > T MAX( T a, T b ){return ( a > b ? a : b );}
template < class T > T MIN( T a, T b ){return ( a < b ? a : b );}
template<class T> T GCD(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T LCM(T a, T b ){return (a*b)/gcd(a,b);}

string getline(){string inputstr; while (inputstr.length()==0 ){ getline(cin, inputstr);} return inputstr;}
template <typename T> string to_str(const T str){stringstream stream; stream << str; return stream.str();}
template <typename T>int to_int(const T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(const string &s,const char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}
string to_str(const vector<int> &v, const char delim){string s; FOR(i, 0, v.size()){s += to_string(v[i]); if(i != v.size() - 1) { s += delim;}} return s;}

const int MODULO = 1000000000 + 7;


int root(vector<int> &stu, int u) {
    while (u != stu[u]) {
        u = stu[u];
    }
    return u;
}

void make_union(vector<int> &stu, vector<int> &sz, int p, int q){
    int u = root(stu, p);
    int v = root(stu, q);
    if(u != v){
        if(sz[u] > sz[v]){
            sz[u] = (sz[u] + sz[v]) % MODULO;
            sz[v] = 1;
            stu[v] = u;
        }else{
            sz[v] = (sz[v] + sz[u]) % MODULO;
            sz[u] = 1;
            stu[u] = v;
        }
    }
}

int solve(vector<pair<int, int> > &rel, int N, int M) {
    vector<int> stu(N);
    vector<int> sz(N, 1);
    
    FOR(i, 0, N) {
        stu[i] = i;
    }
    FOR(i, 0, M) {
        pair<int, int> pair = rel[i];
        make_union(stu, sz, pair.first - 1, pair.second - 1);
    }
    long res = 1;
    FOR(i, 0, N){
        res = (res * sz[i]) % MODULO;
    }   
    return res;
}

int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	scanf("%d", &t);
	while(t--){
		int N, M;
        cin>>N>>M;
        vector<pair<int, int> > rel(M);
        FOR(i, 0, M){
            int u,v;
            cin>>u>>v;
            rel[i] = make_pair(u, v);
        }
		int output = solve(rel, N, M);
        cout<<output<<endl;
		int expected;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}



// 1
// 5 4
// 1 2
// 2 3
// 1 3
// 4 5
// 6