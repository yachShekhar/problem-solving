//https://www.codechef.com/JUNE18B/problems/NAICHEF
#include<iostream>
#include<cmath>
#include<vector>
#include <iomanip>    
using namespace std;

double solve(int n, int a, int b, vector<int> &ar){
    double ac = 0, bc = 0;
    for(int i = 0; i < n; i++){
        if(ar[i] == a){
            ac++;
        }
        if(ar[i] == b){
            bc++;
        }
    }

    return (ac * bc) / (n * n);
}

int main(int argc, char const *argv[]){
	int t;
	cin>>t;
       	while(t--){
		int n, a, b;
	       	cin>>n>>a>>b;
		vector<int> ar(n);	
		for(int i = 0; i < n; i++){
			cin>>ar[i];
		}
		double ans = solve(n, a, b, ar);
		printf("%.10f\n", ans);
	}
		return 0;
}
