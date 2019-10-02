// https://leetcode.com/problems/longest-substring-without-repeating-characters/
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

int solve(string s){
    if(s.empty()) return 0;
    map<char, int> mp;
    int mx = 1; 
    int longestVal = 0;
    int i = 0;
    int lastMatchedIndex = 0;
    for(char& c : s) {
        if(mp.find(c) != mp.end() && mp[c] >= lastMatchedIndex){
            longestVal = i - mp[c];
            lastMatchedIndex = mp[c];
        }else{
            longestVal = (i - 1 < 0 ? 0 : longestVal) + 1;
        }
        mx = MAX(mx, longestVal);
        mp[c] = i;
        i++;
    }
    return mx;
}

int main(){
    cout<<solve("abba")<<endl;
    return 0;
}