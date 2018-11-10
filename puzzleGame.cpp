#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
template<class T> T smaller( T a, T b ){return ( a < b ? a : b );}
//Convert int to string

const bool isPrime[18] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1};

map<LL,bool> vp;
const int N = 3;
bool isFound = false;

LL toNum(vector<vector<int> > vvi){
	long long ans = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			ans = ans*10 + vvi[i][j];
    return ans;
}
// vector<vector<int> > of(vector<vector<int> > &vvi){
// 	vector<vector<int> > v(3, vector<int>(3));
// 	v[0][0] = vvi[0][0]; v[0][1] = vvi[0][1]; v[0][2] = vvi[0][2];
// 	v[1][0] = vvi[1][0]; v[1][1] = vvi[1][1]; v[1][2] = vvi[1][2];
// 	v[2][0] = vvi[2][0]; v[2][1] = vvi[2][1]; v[2][2] = vvi[2][2];
// 	return v;
// }

map<LL, int> mp; 

void sol(vector<vector<int> > vvii){
	queue<vector<vector<int> > > q;
	q.push(vvii);
	while(!q.empty()){
		vector<vector<int> > vvi = q.front();
		q.pop();
		LL tn = toNum(vvi);
		if(vp[tn]){
			continue;
		}else{
			vp[tn] = true;
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					if(i + 1 < N && isPrime[vvi[i][j] + vvi[i + 1][j]]){
						//vector<vector<int> > tv = of(vvi);
						// int tmp = tv[i][j];
						// tv[i][j] = tv[i + 1][j];
						// tv[i + 1][j] = tmp;
						swap(vvi[i][j], vvi[i+1][j]);
						LL tnv = toNum(vvi);
						if(mp.find(tnv) == mp.end()){
							mp[tnv] = 1 + mp[tn];
							q.push(vvi);
						}
						swap(vvi[i][j], vvi[i+1][j]);
					}
					if(j + 1 < N && isPrime[vvi[i][j] + vvi[i][j + 1]]){
						swap(vvi[i][j], vvi[i][j+1]);
						LL tnv = toNum(vvi);
						if(mp.find(tnv) == mp.end()){
							mp[tnv] = 1 + mp[tn];
							q.push(vvi);
						}
						swap(vvi[i][j], vvi[i][j+1]);
					}
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	vector<vector<int> > vvi(3, vector<int>(3));
	//int start_s=clock();
	vector<vector<int> > v(3, vector<int>(3));
	int counter = 0;
	for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				v[i][j] = ++counter;
			}
	}
	sol(v);
	while(t--){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				cin>>vvi[i][j];	
			}
		}
		LL s = toNum(vvi);
		if(vp[s]){
			cout<<mp[s]<<endl;
		}else{
			cout<<-1<<endl;
		}
	}

	//int stop_s=clock();
	//cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}
