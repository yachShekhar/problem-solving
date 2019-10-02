//https://leetcode.com/problems/regular-expression-matching/
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

string getline(){string inputstr; while (inputstr.length()==0 ){ getline(cin, inputstr);} return inputstr;}//read line from stdin
template <typename T> string to_str(T str){stringstream stream; stream << str; return stream.str();}//Convert int to string
template <typename T>int to_int(T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(string &s,char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

bool solve(string &s, string &p, int i, int j, vector<vector<int> > &dp){
    if(i < s.size() && j >= p.size()){
        return false;
    }else if(i >= s.size() && j >= p.size()){
        return true;
    }else if(i >= s.size() && j < p.size()){
        int countStar = 0; 
        int jLeft = p.size() - j - 1;
        while(++j < p.size()){
            if(p[j] == '*'){
                countStar++;
            }
            j++;
        }
        return countStar == (jLeft / 2) + 1;
    }else{
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] != p[j] && p[j] != '.'){
            if(p[j + 1] == '*'){
                dp[i][j] = solve(s, p, i, j + 2, dp);
            }else{
                dp[i][j] = false;
            }
        }else if(s[i] == p[j] || p[j] == '.'){
            if(p[j + 1] != '*'){
                dp[i][j] = solve(s, p, i + 1, j + 1, dp);
            }else{
                dp[i][j] = solve(s, p, i + 1, j, dp) || solve(s, p, i, j + 2, dp);
            }
        }
    }
	return dp[i][j];
}
bool solve(string &s, string &p){
    vector<vector<int> > dp(s.size(), vector<int>(p.size(), -1));
    return solve(s, p, 0, 0, dp);
}
int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while(t--){
		string s, p;
        cin>>s>>p;
        // s="";
        // p="c*c*";
		bool output = solve(s, p);
		bool expected;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}



// 9
// ab .*c
// 0
// aaa aaaa
// 0
// aa a*
// 1
// aa a
// 0
// ab .*
// 1
// aab c*a*b
// 1
// mississippi mis*is*p*.
// 0
// abcba c*a.*b
// 0
// abcbab c*a.*b
// 1