//https://codeforces.com/problemset/problem/131/A
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
typedef long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;
typedef vector<string> VS;
typedef vector<char> VC;
template < class T > T MAX( T a, T b ){return ( a > b ? a : b );}
template < class T > T MIN( T a, T b ){return ( a < b ? a : b );}
template<class T> T GCD(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T LCM(T a, T b ){return (a*b)/gcd(a,b);}
//Convert int to string
template <typename T> string to_str(T str){stringstream stream; stream << str; return stream.str();}
template <typename T>int to_int(T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(string &s,char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

void solve(){
    
}

int main(){
	int i,l=0;
    char s[100];
    scanf("%s",s);
    for(i=1; i<strlen(s); i++) {
        if(s[i]>=65&&s[i]<=90) {
            l++;
        }
    }
    if(l == strlen(s) - 1) {
        for(i=0; i<strlen(s); i++) {
            if(s[i] >= 65 && s[i] <= 90)
            s[i] = 97 + s[i] - 65;
            else if(s[i] >= 97 && s[i] <= 122)
            s[i]= 65 + s[i] - 97;
        }
    }

    printf("%s\n",s);
    return 0;
}
