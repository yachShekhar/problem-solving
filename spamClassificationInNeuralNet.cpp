//https://www.codechef.com/problems/SPAMCLAS
#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define mem(x,a) memset(x,a,sizeof(x));
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tr(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;
typedef vector<string> VS;
typedef vector<char> VC;

template < class T > T multiply( T a, T b ){return a * b;}
template < class T > T larger( T a, T b ){return ( a > b ? a : b );}
template < class T > T smaller( T a, T b ){return ( a < b ? a : b );}
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T lcm(T a, T b ){return (a*b)/gcd(a,b);}
//Convert int to string
template <typename T> string to_str(T str){stringstream stream; stream << str; return stream.str();}
template <typename T>int to_int(T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(string &s,char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

bool isEven(LL e){
	return e % 2 == 0;
}

pair<int, int> solve(int minX, int maxX, vector<int> &W, vector<int> &B){
	int E = 0, O = 0;
	int S = 2, S1 = 1;
	for(int i = 0; i < W.size(); i++){
		S = (S * W[i] + B[i]) % 2;
		S1 = (S1 * W[i] + B[i]) % 2;
	}
	if(isEven(S) && isEven(S1)){
		E = maxX - minX + 1;
	}else if(isEven(S) || isEven(S1)){
		E = (maxX - minX) / 2;
		if(isEven(S) && (isEven(minX) || isEven(maxX))){
			E += 1;
		}else if(isEven(S1) && (!isEven(minX) || !isEven(maxX))){
			E += 1;
		}
		O = maxX - minX + 1 - E;
	}else{
		O = maxX - minX + 1;
	}

	PII pi(E, O);
	return pi;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		LL n, minX, maxX;
		cin>>n>>minX>>maxX;
		vector<int> W(n);
		vector<int> B(n);
		for(int i = 0; i < n; i++){
			cin>>W[i];
			cin>>B[i];
		}
		PII pi = solve(minX, maxX, W, B);
		cout<<pi.first<<" "<<pi.second<<endl;
	}
}
