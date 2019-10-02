//https://leetcode.com/problems/surrounded-regions/
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

void dfs(vector<vector<char> > board, int r, int c, int n, int m, vector<vector<bool> > &visited){
    if(r < 0 || r >= n) return;
    if(c < 0 || c >= m) return;

    if(!visited[r][c] && board[r][c] == 'O'){
        visited[r][c] = true;
        dfs(board, r - 1, c, n, m, visited);
        dfs(board, r + 1, c, n, m, visited);
        dfs(board, r, c - 1, n, m, visited);
        dfs(board, r, c + 1, n, m, visited);
    }
}

int solve(vector<vector<char> > &board, int n, int m){
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        if(board[i][0] == 'O' && !visited[i][0]){
            dfs(board, i, 0, n, m, visited);
        }
        if(board[i][m - 1] == 'O' && !visited[i][m - 1]){
            dfs(board, i, m - 1, n, m, visited);
        }
    }
    for(int i = 0; i < m; i++){
        if(board[0][i] == 'O' && !visited[0][i]){
            dfs(board, 0, i, n, m, visited);
        }
        if(board[n - 1][i] == 'O' && !visited[n - 1][i]){
            dfs(board, n - 1, i, n, m, visited);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            if(!visited[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }

	return 0;
}

int solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
    cin>>n>>m;
    vector<vector<char> > board(n, vector<char>(m));
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>board[i][j];
        }
	}
	return solve(board, n, m);
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
// 3 3
// X O X
// O X O
// X O X
// 4 4
// X X X X
// X O O X
// X X O X
// X O X X