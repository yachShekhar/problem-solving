#include<vector>
#include<iostream>
using namespace std;

int kmpMatch(string &str, string &pattern, vector<int> &lp){
	int j = -1;
	for(int i = 0; i < str.size(); i++){
		if(j + 1 == pattern.size() - 1){
			return i + 1 - pattern.size();
		}else if(str[i] == pattern[j + 1]){
			j++;
		}else{
			while(pattern[lp[j]] != str[i] && j != 0){
				j = lp[j];
			}
			if(j == 0){
				j = -1;
			}
		}	
	}
	return -1;
}

vector<int> lsp(string &pattern){
	vector<int> lp(pattern.size(), 0);
	int i = 0, j = 1, l = 0;
	while(j != pattern.size()){
		if(pattern[i] == pattern[j]){
			l++;
			lp[j] = l;
			i++;
			j++;
		}else{
			if(i == 0){
				j++;
			}else{
				i--;
			}
			l = lp[i];
		}
	}
	return lp;
}

int main(){
	string str;
	string pattern;
	cin>>str>>pattern;
	vector<int> lp = lsp(pattern);
	int s = kmpMatch(str, pattern, lp);
	cout<<"For a given string: "<<str<<" and pattern: "<<pattern<<" output is: "<<s<<endl;
	return 0;
}
