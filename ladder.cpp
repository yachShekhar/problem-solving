
#include<iostream>
#include<vector>
using namespace std;

int solve(int a, vector<int> dp){
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i < a; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[a - 1];
}

int solve(int a){
    vector<int> dp(a);
    return solve(a, dp);
}
int main(int argc, char const *argv[])
{
    int a;
    cin>>a;
    int sol = solve(a);
    cout<<"a "<<sol<<endl;
    return 0;
}
