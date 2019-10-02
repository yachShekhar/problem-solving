//https://leetcode.com/problems/wildcard-matching/
#include<bits/stdc++.h>
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

bool solve(string &s, string &p, int i, int j, vector<vector<int> > &dp){
    if(i >= s.size() && j >=p.size()) return true;
    else if(i < s.size() && j >= p.size()) return false;
    else if(i >= s.size() && j < p.size()) {
        for(int k = j; k < p.size(); k++) {
            if(p[k] != '*') return false;
        }
        return true;
    } else if(dp[i][j] != -1) {
        return dp[i][j];
    }else if(s[i] == p[j] || p[j] == '?') {
        dp[i][j] = solve(s, p, i + 1, j + 1, dp);
    } else if(p[j] == '*'){
        dp[i][j] = solve(s, p, i, j + 1, dp) || solve(s, p, i + 1, j, dp);
    }else{
        dp[i][j] = false;
    }
	return dp[i][j];
}

bool solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, p;
    s = getline();
    p = getline();
    vector<vector<int> > dp(s.size(), vector<int>(p.size(), -1));
	return solve(s, p, 0, 0, dp);
}

int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	
	int t;
	scanf("%d", &t);
	while(t--){
		bool output = solve();
		bool expected;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}



// 5
// acdcb
// a*c?b
// 0
// adceb
// *a*b
// 1
// cb
// ?a
// 0
// aa
// *
// 1
// aa
// a
// 0
// ab
// ab
// 1
// ab
// *ab
// 1