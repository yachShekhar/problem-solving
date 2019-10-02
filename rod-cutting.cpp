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

void solve(vector<int> &v, int start, int end, int N, vector<int> &res) {
    if(start >= end) return;
    int mid = (N - start) / 2;
    int min = INT_MAX, index = 0;
    for(int i = end - 1; i >= start; i--) {
        if(abs(v[i] - mid) < min) {
            min = abs(v[i] - mid) ;
            index = i;
        }
    }
    res.push_back(v[index]);
    solve(v, start, index, v[index], res);
    solve(v, index + 1, end, N, res);
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
	solve(v, 0, v.size(), l, indexes);
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

