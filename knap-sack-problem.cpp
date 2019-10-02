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

int solve(vector<int> w, vector<int> p, int profit, int M, int i, vector<vector<int> > &dp){
    if(i >= w.size()) return profit;
	if(M <= 0) return profit;
    if(dp[i][M] != 0){
        return dp[i][M];
    }
    if(w[i] > M){
        dp[i][M] = solve(w, p, profit, M, i + 1, dp);
    }else{
        dp[i][M] = MAX(solve(w, p, profit + p[i], M - w[i], i + 1, dp), solve(w, p, profit, M, i + 1, dp));
    }
    return dp[i][M];
}

int solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int W, M;
    cin>>W>>M;
    vector<int> weight(W);
    vector<int> profit(W);
    FOR(i, 0, W){
        cin>>weight[i];
    }
    FOR(i, 0, W){
        cin>>profit[i];
    }
    vector<vector<int> > dp(W, vector<int>(M + 1, 0));
    int res = solve(weight, profit, 0, M, 0, dp);
	return res;
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
// 4 8
// 2 3 4 5
// 1 2 5 6
// 8
// 7 15
// 2 3 5 7 1 4 1
// 10 5 15 7 6 18 3
// 54