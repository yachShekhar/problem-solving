//https://www.interviewbit.com/problems/min-jumps-array/
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

void solve(vector<int> &v, vector<int> &dp, int k){
    for(int i = 1; i <= v[k] && k + i < v.size(); i++) {
        if(dp[k + i] > dp[k] + 1) {
            dp[k + i] = dp[k] + 1;
            solve(v, dp, k + i);
        };
    }
}

int solve(vector<int> &v) {
    if(v.size() == 1) return 0;
    if(v.size() == 0 || v[0] == 0) return -1;
    vector<int> dp(v.size(), INT_MAX);
    dp[0] = 0;
    solve(v, dp, 0);
	return dp[v.size() - 1] == INT_MAX ? -1 : dp[v.size() - 1];
}

int solve(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l;
	scanf("%d", &l);
	vector<int> v(l);
	for(int i = 0; i < l; i++){
		scanf("%d", &v[i]);
	}
	return solve(v);
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

