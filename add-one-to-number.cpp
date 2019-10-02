//https://www.interviewbit.com/problems/add-one-to-number/
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

string getline(){string inputstr; while (inputstr.length()==0 ){ getline(cin, inputstr);} return inputstr;}
template <typename T> string to_str(const T str){stringstream stream; stream << str; return stream.str();}
template <typename T>int to_int(const T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(const string &s,const char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}
string to_str(const vector<int> &v, const char delim){string s; FOR(i, 0, v.size()){s += to_string(v[i]); if(i != v.size() - 1) { s += delim;}} return s;}

vector<int> solve(vector<int> &A){
    int carry = 0;
    stack<int> st;
    for(int i = A.size() - 1; i >= 0; i--){
        int n = A[i];
        if(i == A.size() - 1){
            n += 1;
        }else{
            n += carry;
        }
        carry = n / 10;
        n = n % 10;
        if(i == 0 && n == 0 && carry == 0){
            continue;
        }
        st.push(n);
    }
    if(carry != 0){
        st.push(carry);
    }
    vector<int> res;
    bool isFirst = false;
    while(!st.empty()){
        if(!isFirst && st.top() == 0) {
            st.pop();
        }
        else{ 
            isFirst = true;
            res.push_back(st.top());
            st.pop();
        }
    }
	return res;
}

vector<int> solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int l;
	scanf("%d", &l);
	vector<int> v(l);
	FOR(i, 0, l){
		scanf("%d", &v[i]);
	}
	return solve(v);
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





// 4
// 1
// 0
// 1
// 4
// 0 0 1 2
// 1 3
// 3
// 9 9 9
// 1 0 0 0
// 3
// 1 2 3
// 1 2 4
