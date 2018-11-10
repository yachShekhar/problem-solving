//https://www.codechef.com/problems/H1
#include<bits/stdc++.h>
using namespace std;

int x[] =  {0, 0, -1, 1};
int  y[] = {1, -1, 0, 0};
map<int,int> ans;

int canSwap(int i, int j , int x ,int y, int arr[][3]){
    // 1 2 3 4 5 6 7 8 9
    
    if(x < 0 || x >= 3 || y < 0 || y >=3)
        return -1;
    int n = arr[i][j] + arr[x][y];
    
    if(n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 ){
        swap(arr[i][j], arr[x][y]);
        int now = 0;
        for(int i = 0; i <3 ; i++){
            for(int j = 0; j < 3 ; j++){
                
                now = now*10 + arr[i][j];
            }
        }
        swap(arr[i][j], arr[x][y]);
        return now;
    }
    
    return -1;
}

int solve(int now){
    queue<pair<int,int> > q;
    map<int,bool > mp;
   
    q.push({now, 0});
    while(!q.empty()){
        pair<int,int> tp = q.front();
        int old = tp.first;
        q.pop();
        if(mp[tp.first])
            continue;
        ans[tp.first] = tp.second;
        mp[tp.first] = true;
        int arr[3][3];
      
        for(int i = 2; i >= 0; i--){
            for(int j = 2; j >= 0; j--){
                arr[i][j] = tp.first%10;
                tp.first/=10;
            }
        }
     
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 4; k++){
                    int val = canSwap(i, j, i + x[k], j + y[k], arr) ;
                    if(val != -1){
                        q.push({val, tp.second + 1});
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int start_s=clock();
    solve(123456789);
    while(t--){
        int now = 0;
        int arr[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin>>arr[i][j];
                now = now*10 + arr[i][j];
            }
        }
        if(ans.find(now) != ans.end())
            cout<<ans[now]<<"\n";
        else
            cout<<-1<<"\n";
    }
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}
