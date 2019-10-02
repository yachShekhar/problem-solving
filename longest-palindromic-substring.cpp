//https://leetcode.com/problems/longest-palindromic-substring/
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

string formatString(string &s) {
	string str = "#";
	for(const char c : s){
		str += to_str(c) + "#";
	}
	return str;
}

string solve(string &s) {
	string str = formatString(s);
	vector<int> pl(str.size(), 1);
	int i = 1, sz = str.size(), l = 0, r = 0, c=0;
	while(i < sz) {
		//assign the mirror value
		if(i < r){
			pl[i] = MIN(r - i, pl[c - (i - c)]);
		}

		//expanding around the ith element
		int right = i, left = i;
		if(i < r){
			right += pl[i]/2 ;
			left =  i - (right - i);
		}
		while(left - 1 > -1 && right + 1 < sz && str[left - 1] == str[right + 1]) {
			left--;
			right++;
		}
		int plen = right - left + 1;
		pl[i] = MAX(pl[i], plen);

		//assign the new center and its boundary
		if(i + (pl[i] / 2) > r){
			c = i;
			r = i + (pl[i] / 2);
			l = left;
		}

		i++;
	}
	int len = INT_MIN;
	for(int i = 0; i < sz; i++){
		if(len < pl[i]){
			c = i;
			len = pl[i];
		}
	}
	string pstring = "";
	for(int i = c - (len / 2); i <= c + (len / 2); i++){
		if(str[i] != '#'){
			pstring += str[i];
		}
	}
	return pstring;
}

string solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	return solve(s);
}
int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	
	int t;
	scanf("%d", &t);
	while(t--){
		auto output = solve();
		auto expected = output;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}



// 1
// malayalam
// malayalam
// babad
// bab
// cbbd
// bb



// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
// # m # a # l # a # y #  a  #  l  #  a  #  m  #

