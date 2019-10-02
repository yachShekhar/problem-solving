//https://www.interviewbit.com/problems/rod-cutting/
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
const int MAX_LENGTH = 1000000000;
vector<vector<int> > dp(MAX_LENGTH, vector<int>(MAX_LENGTH));
vector<int> res;

int solve(vector<int> &v, int left, int right, vector<vector<int> > &dp) {
    if(left + 1 == right) return 1;
    if(left > right) return 0;
    int count = 0;
    for(int i = left; i < right; i++){
        if(v[count++] == )
        dp[left][right] = right - left + solve(v, left, i, dp) + solve(v, i, right, dp);
    }
    return dp[left][right];
}

vector<int> solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int l, n;
	scanf("%d%d", &l, &n);
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}
    vector<int> indexes;
    return indexes;
}

int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	int t;
	scanf("%d", &t);
	while(t--){
		string output = to_str(solve(), ' ');
		string expected = getline();
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}



// 1
// 9 3
// 3 4 6
// 3 6 4
// 11 4
// 2 3 6 8
// 6 3 2 8
// 6 3
// 1 2 5
// 2 1 5