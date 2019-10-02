//https://leetcode.com/problems/3sum/
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

int solve(vector<int> &v){
	if(v.empty()) return 0;
	sort(v.begin(), v.end(), less<int>());
	vector<vector<int> > res;
   	int sz = v.size();
   	for(int i = 0; i < sz; i++) {
	   int target = v[i];
	   int left = i + 1, right = sz - 1;
	   while(left < right) {
		   int sum = v[left] + v[right];
			if(-1 * target == v[left] + v[right]) {
				vector<int> row(3);
			   	row[0] = target;
			   	row[1] = v[left];
			   	row[2] = v[right];
			   	res.push_back(row);
		   		int leftValue = v[left], rightValue = v[right];
				while(left < sz && v[left] == leftValue) left++;
				while(right > i && v[right] == rightValue) right--;
			}else if(sum < -1 * target){
				left++;
			} else right--;
	   }
	   while(i + 1 < sz && v[i + 1] == target) i++;
   } 
	return 0;
}

int solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int l;
	scanf("%d", &l);
	vector<int> v(l);
	for(int i = 0; i < l; i++){
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
		int output = solve();
		int expected;
        cin>>expected;
    	printf("==============testcase: %d===========\n", t);
		cout<<"===>output:"<<output<<" expected:"<<expected<<" result:"<<(output==expected ? "true" : "false")<<endl;
	}
	return 0;
}



// 1
// 4
// 1 -1 -1 0
// 6
// -1 0 1 2 -1 -4