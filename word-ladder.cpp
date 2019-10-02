//https://leetcode.com/problems/word-ladder/
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
struct QItem {
    string elem;
    int count;
};
bool isAdjacent(string &s1, string &s2) {
    if(s1 == "" || s2 == "") return false;
    int matchCount = 0;
    for(int k = 0; k < s1.size(); k++) {
        if(s1[k] == s2[k]) matchCount++;
    }
    return s1.size() - matchCount == 1;
}

int solve(string &beginWord, string &endWord, vector<string> &wordList){
    // unordered_set<string> wordList;
    // for(int i = 0; i < D.size(); i++){
    //     wordList.insert(D[i]);
    // }
	queue<QItem> q;
    q.push({beginWord, 1});

    while(!q.empty()) {
        QItem item = q.front(); q.pop();
        if(item.elem == endWord) return item.count;
       
        for(vector<string>::iterator itr = wordList.begin(); itr != wordList.end(); itr++) {
            string temp = *itr;
            if(isAdjacent(item.elem, temp)){
                q.push({temp, item.count + 1});
                wordList.erase(itr--);
            }
        }
    }
    return 0;
}

int solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    string beginWord, endWord;
    cin>>beginWord>>endWord;
	int l;
	scanf("%d", &l);
	vector<string> v;
	for(int i = 0; i < l; i++){
        string word;
        cin>>word;
        v.push_back(word);
	}
	return solve(beginWord, endWord, v);
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

// 3
// hot dog
// 3
// hot dog dot
// 3
// hit cog
// 6
// hot dot dog lot log cog
// 5
// hit cog
// 5
// hot   dot   dog   lot   log
// 0