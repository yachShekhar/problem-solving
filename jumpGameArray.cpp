//https://www.interviewbit.com/problems/jump-game-array/
#include<iostream>
#include<vector>
using namespace std;

int sol(vector<int> &A, int n){
	int i = 0;
	int count = 0;
	for (int reach = 0; i < n && i <= reach; ++i){
		// reach = max(i + A[i], reach);
		if(i + A[i] > reach && reach <= n - 1){
			reach = i + A[i];
			count++;
			if(reach == n - 1) break;
		}
        	
		// cout<<"i: "<<i<<" reach: "<<reach<<endl;
	}
    	return i == n ? count : -1;
}

int main(){
	freopen("1-input", "r", stdin); 
    freopen("2-output", "w", stdout); 
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




