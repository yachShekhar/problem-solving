//https://www.hackerrank.com/challenges/reduced-string/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
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
//read full line from stdin
void readline(string &inputstr){while (inputstr.length()==0 ) getline(cin, inputstr);}
//case int to string
template <typename T> string to_str(T str){stringstream stream; stream << str; return stream.str();}
//cast a string number integer
template <typename T>int to_int(T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(string &s,char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

string solve(string &s){
    int l = s.size();
    int i = 0;
    set<int> idx;
    stack<int> st;
    while(i <= l - 1){
        st.push(i);
        ++i;
        int prev = st.top();
        while(prev >= 0 && i <= l - 1 && s[prev] == s[i]){
            st.pop();
            idx.insert(prev);
            idx.insert(i);
            prev = st.size() != 0 ? st.top() : -1;
            ++i;
        }
    }

    string res="";
    FOR(i, 0, l){
        if(idx.find(i) == idx.end()){
            res += s[i];
        }
    }
    return res == "" ? "Empty String" : res;
}




// 5
// aaabccddd
// abd
// aa
// Empty String
// baab
// Empty String
// cbaabc
// Empty String
// baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab
// Empty String


int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while(t--){
		string s;
        readline(s);
  
		string output = solve(s);
		string expected;
        readline(expected);
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
};           