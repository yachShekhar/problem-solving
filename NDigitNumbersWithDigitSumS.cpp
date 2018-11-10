#include<iostream>
#include<vector>
using namespace std;
int modulo = 1000000007;

int sol(int A, int B, int X, vector<vector<int> > &dp){
    if(A <= 0 || B < 0 || 9 * A < B){
        return 0;
    }
    if(A == 1){
        return 1;
    }
    if(dp[A][B] != 0){
        return dp[A][B];
    }
    for(int i = X; i <= 9; i++){
        dp[A][B] += (sol(A - 1, B - i, 0, dp)) % modulo;
    }
    return dp[A][B];
}

void sol(){
    int A;
    int B;
    cin>>A>>B; 
    vector<vector<int> > dp(A + 1, vector<int>(B + 1, 0));
    int s = sol(A, B, 1, dp);

    cout<<"sol "<<s<<endl;
}

int main(int argc, char const *argv[]){
    sol();
    return 0;
}
