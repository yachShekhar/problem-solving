#include<iostream>
#include<vector>
using namespace std;

int sol(vector<int> &A, int n){
	int i = 0;
	for (int reach = 0; i < n && i <= reach; ++i){
        	reach = max(i + A[i], reach);
		cout<<"i: "<<i<<" reach: "<<reach<<endl;
	}
    	return i == n;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}	
	int s = sol(v, n);
	cout<<"For a given input is? "<<s<<endl;
	return 0;
}
