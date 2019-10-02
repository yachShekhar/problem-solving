//https://www.interviewbit.com/problems/shortest-common-superstring/
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

vector<vector<string>> allPermutations;
void  sol(vector<string> &v, stack<string> &permuatation, int size) {
    if(permuatation.size() == size) {
        vector<string> temp(size);
        for(int i = 0; i < size; i++){
            string top = permuatation.top();
            permuatation.pop();
            temp[i] = top;
        }
        allPermutations.push_back(temp);
        for(int i = 0; i < size; i++) {
            permuatation.push(temp[i]);
        }
    }
   for (auto it = v.begin(); it != v.end(); ++it) {
        permuatation.push(*it);
        v.erase(it);
         sol(v, permuatation, size);
        v.push_back(permuatation.top());
        permuatation.pop();
   }
}

string cat(string &s1, string &s2) {
    if(s1.size() < s2.size()) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    int j = 0;
    for(int i = s1.size() - s2.size(); i < s1.size(); i++) {
        if(s1[i] == s2[j]){
            j++;
        }else {
            j = 0;
            if(s1[i] == s2[j]){
                j++;
            }
        }
    }
    while(j != s2.size()){
        s1 += s2[j];
        j++;
    }
    return s1;
}

string  sol(vector<string> &v){
    stack<string> permutation;
     sol(v, permutation, v.size());
    string shortestSuperset = "";
    for(vector<string> perm : allPermutations){
        string shortstr = "";
        for(string s: perm){
            if(s == ""){
                shortstr = s;
            } else {
                shortstr = cat(shortstr, s);
            }
        }
        if(shortestSuperset == "") {
            shortestSuperset = shortstr;
        }else if(shortstr.size() < shortestSuperset.size()) {
            shortestSuperset = shortstr;
        }
    }
    return shortestSuperset;
}
string  sol(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int l;
	scanf("%d", &l);
	vector<string> v(l);
	for(int i = 0; i < l; i++){
		cin>>v[i];
	}
	return  sol(v);
}
int main(){
    // string s1="bba", s2="abab";
    // string a = cat(s1, s2);
    // cout<<a<<endl;
    freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
	
	int t;
	scanf("%d", &t);
	while(t--){
		string output =  sol();
        cout<<output.size()<<endl;
		string expected;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}



// 1
// 2
// abc bcd
// abcd
// 4
// abcd cdef fgh de 
// abcdefgh
// 2
// aaaa aa
// aaaa