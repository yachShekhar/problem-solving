//https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
#include <bits/stdc++.h>

using namespace std;
#define TOUPPER(str) transform(str.begin(), str.end(),str.begin(), ::toupper)
#define TOLOWER(str) transform(str.begin(), str.end(),str.begin(), ::tolower)
template < class T > T MAX( T a, T b ){return ( a > b ? a : b );}
template < class T > T MIN( T a, T b ){return ( a < b ? a : b );}

string getline(){string inputstr; while (inputstr.length()==0 ){ getline(cin, inputstr);} return inputstr;}
template <typename T> string to_str(const T str){stringstream stream; stream << str; return stream.str();}
string to_str(const vector<int> &v, const char delim){string s; for(int i = 0; i < v.size(); i++){s += to_string(v[i]); if(i != v.size() - 1) { s += delim;}} return s;}
template <typename T>int to_int(const T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(const string &s,const char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

typedef vector<vector<int> > VVI;
const int MODULO = 1000000007;

int solve(VVI &dp, int N, int S, int start){
    if(9 * N < S) return 0;
    if(N == 1) return 1;
    if(dp[N][S] != 0){
        return dp[N][S];
    }
    for(int i = start; i <= MIN(9, S); i++){
        int result = solve(dp, N - 1, S - i, 0);
        // if(result == 0) dp[N][S] = 0;
        dp[N][S] += result;
        dp[N][S] = dp[N][S] % MODULO;
    }
    return dp[N][S];
}

int solve(int N, int S){
    if(S == 0) return 0;
    VVI dp(N + 1, vector<int>(S + 1, 0));
    return solve(dp, N, S, 1);
}

int solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, S;
    cin>>N>>S;
	return solve(N, S);
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





// 5
// 2 18
// 1
// 3 1
// 1
// 2 4
// 4
// 1 9
// 1
// 1 0
// 0