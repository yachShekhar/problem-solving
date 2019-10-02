//https://leetcode.com/problems/decode-ways/
#include<bits/stdc++.h>
using namespace std;
#define TOUPPER(str) transform(str.begin(), str.end(),str.begin(), ::toupper)
#define TOLOWER(str) transform(str.begin(), str.end(),str.begin(), ::tolower)
template <typename T> T MAX( T a, T b ){return ( a > b ? a : b );}
template <typename T> T MIN(T a, T b ){return ( a < b ? a : b );}

string getline(){string inputstr; while (inputstr.length()==0 ){ getline(cin, inputstr);} return inputstr;}
template <typename T> string to_str(const T str){stringstream stream; stream << str; return stream.str();}
string to_str(const vector<int> &v, const char delim){string s; for(int i = 0; i < v.size(); i++){s += to_string(v[i]); if(i != v.size() - 1) { s += delim;}} return s;}
template <typename T>int to_int(const T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(const string &s,const char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

set<string> st;

int solve(string &s){
    st.insert("1");
    st.insert("2");
    st.insert("3");
    st.insert("4");
    st.insert("5");
    st.insert("5");
    st.insert("6");
    st.insert("7");
    st.insert("8");
    st.insert("9");
    st.insert("10");
    st.insert("11");
    st.insert("12");
    st.insert("13");
    st.insert("14");
    st.insert("15");
    st.insert("16");
    st.insert("17");
    st.insert("18");
    st.insert("19");
    st.insert("20");
    st.insert("21");
    st.insert("22");
    st.insert("23");
    st.insert("24");
    st.insert("25");
    st.insert("26");

    vector<int> dp(s.size(), 0);
    for(int i = 0; i < MIN(2, (int)s.size()); i++) {
        if(i == 0 && st.find(to_str(s[i])) != st.end()) {
            dp[i] = 1;
        }else if(i > 0 && st.find(to_str(s[i])) != st.end() && st.find(to_str(s[i - 1])+to_str(s[i])) != st.end()){
            dp[i] = dp[i - 1] + 1;
        }else if(i > 0 && (st.find(to_str(s[i])) != st.end() || st.find(to_str(s[i - 1])+to_str(s[i])) != st.end())){
            dp[i] = dp[i - 1];
        }else{
            break;
        }
    }
    for(int i = 2; i < s.size(); i++) {
        if(st.find(to_str(s[i])) != st.end() && st.find(to_str(s[i - 1])+to_str(s[i])) != st.end()){
            dp[i] = dp[i - 1] + dp[i - 2];
        }else if(st.find(to_str(s[i])) != st.end() && st.find(to_str(s[i - 1])+to_str(s[i])) == st.end()){
            dp[i] = dp[i - 1];
        }else if((st.find(to_str(s[i])) == st.end() && st.find(to_str(s[i - 1])+to_str(s[i])) != st.end())){
            dp[i] = dp[i - 2];
        }else{
            break;
        }
    }
	return dp[s.size() - 1];
}

int solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    string s;
    s = getline();
	return solve(s);
}

int main(){
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	
	int t;
	scanf("%d", &t);
	while(t--){
		int output = solve();
		int expected;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}



// 7
// 110
// 1
// 199
// 2
// 12
// 2
// 226
// 3
// 200
// 0
// 0
// 0
// 201
// 1