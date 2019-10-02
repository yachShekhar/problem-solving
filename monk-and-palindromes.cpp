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
string to_str(const vector<int> &v){string s; FOR(i, 0, v.size()){s += to_string(v[i]); if(i != v.size() - 1) { s += ",";}} return s;}

const int MODULO = 1000000000 + 7;

int root(vector<int> &v, int u){
    while(u != v[u]){
        u = v[u];
    }
    return u;
}

void make_union(vector<int> &v, vector<int> &s, int p, int q){
    int a = root(v, p), b = root(v, q);
    if(a != b){
        if(s[a] >= s[b]){
            v[b] = a;
            s[a] += s[b];
        }else{
            v[a] = b;
            s[b] += s[a];
        }
    }
}

int solve(int N, int Q, vector<pair<int, int> > &pos){
    vector<int> s(N + 1);
    vector<int> v(N + 1);
    FOR(i, 1, N + 1){
        s[i] = 1;
        v[i] = i;
    }
    FOR(i, 0, Q){
        pair<int, int> pair = pos[i];
        int p = pair.first, q = pair.second;
        if(p == q){
            continue;
        }
        while(p > q){
            make_union(v, s, p, q);
            p--; q++;
        }
        while(p < q){
            make_union(v, s, p, q);
            p++; q--;
        }
    }
    long res = 1;
    int mul = 10;
    FOR(i, 1, N + 1){
        if(i == v[i]){
            res = (res * mul) % MODULO;
        }
    }
	return res;
}

int solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
    cin>>N;
    int Q;
    cin>>Q;
    vector<pair<int, int> > pos(Q);
    FOR(i, 0, Q){
        int f,s;
        cin>>f>>s;
        pos[i] = make_pair(f, s);
    }
	return solve(N, Q, pos);
}

int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	
	int t;
	scanf("%d", &t);
	while(t--){
		int output = solve();
		int expected;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}





// 2
// 5
// 3
// 2 4
// 3 5
// 1 5
// 100
// 5
// 2
// 2 4
// 3 5
// 1000