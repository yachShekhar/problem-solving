//https://leetcode.com/problems/zigzag-conversion/
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

string solve(string &s, int k){
    if(k == 1) return s;
    int total = k + (k - 2);
    string res = "";
    int i = 0;
    while(i < s.size()){
        res += s[i];
        i += total;
    }

    int a = total - 2, b = 2;
    bool isFirst = true;
    int j = 1;
    while(j < k - 1){
        i = j;
        while(i < s.size()){
            res += s[i];
            if(isFirst){
                i += a;
                isFirst = false;
            }else{
                i += b;
                isFirst = true;
            }
        }
        a -= 2;
        b += 2;
        j++;
        isFirst = true;
    }

    i = k - 1;
    while(i < s.size()){
        res += s[i];
        i += total;
    }
    return res;
}

int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while(t--){
        int k;
        string s;
        cin>>k>>s;
		string output = solve(s, k);
		string expected;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}

// 4
// 1 ABCDEFGH
// ABCDEFGH
// 2 ABCDEFGH
// ACEGBDFH
// 4 PAYPALISHIRING
// PINALSIGYAHRPI
// 3 PAYPALISHIRING
// PAHNAPLSIIGYIR


// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// P A Y P A L I S H I R  I  N  G

// P     I     N
// A   L S   I G
// Y A   H R   
// P     I

// 6
// 4 2
// 2 4

//0 1 2 3 4 5 6 7 8 9 10 11 12 13
//P A Y P A L I S H I R  I  N  G

//k = 3
//P   A   H   N
//A P L S I I G
//Y   I   R

//total = 3 + 3/2 = 4
//k = 3 4 5 6
//t = 4 5 8 10

