//https://leetcode.com/problems/palindrome-number/
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

int solve(int x){
    if(x < 0) return false;
    int rev = 0, temp = x;
    while(temp != 0){
        rev = (rev * 10) + (temp % 10);
        temp /= 10;
    }

	return rev == x;
}

int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while(t--){
		int l;
		scanf("%d", &l);
		int output = solve(l);
		bool expected;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}



// 8
// -121
// 0
// 0
// 1
// 1
// 1
// 9
// 1
// 10
// 0
// 11
// 1
// 121
// 1
// 234
// 0