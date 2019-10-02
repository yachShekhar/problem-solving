//https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define MEM(x,a) memset(x,a,sizeof(x));
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define ROFEACH(it, l) for (auto it =  l.end(); it !=l.begin(); it--)
#define TOUPPER(str) transform(str.begin(), str.end(),str.begin(), ::toupper)
#define TOLOWER(str) transform(str.begin(), str.end(),str.begin(), ::tolower)
typedef long long LL;
typedef long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;
typedef vector<string> VS;
typedef vector<char> VC;
template < class T > T MAX( T a, T b ){return ( a > b ? a : b );}
template < class T > T MIN( T a, T b ){return ( a < b ? a : b );}
template<class T> T GCD(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T LCM(T a, T b ){return (a*b)/gcd(a,b);}
//Convert int to string
template <typename T> string to_str(T str){stringstream stream; stream << str; return stream.str();}
template <typename T>int to_int(T num){int val; stringstream stream; stream<<num; stream>>val; return val;}
vector<string> split(string &s,char delim){vector<string> elems;stringstream ss(s); string item;while(getline(ss,item,delim)){elems.push_back(item);}return elems;}

double findKthElem(VI &nums1, VI &nums2, int start1, int start2, int k){
    if (start1 >= nums1.size()) {
        return nums2[start2 + k - 1];
    }
    if(start2 >= nums2.size()){
        return nums1[start1 + k - 1];
    }
    if(k == 1){
        return MIN(nums1[start1], nums2[start2]);
    }
    int index1 = start1 + k / 2 - 1;
    int index2 = start2 + k / 2 - 1;
    int elem1 = index1 >= nums1.size() ? INT_MAX : nums1[index1];
    int elem2 = index2 >= nums2.size() ? INT_MAX : nums2[index2];
    if(elem1 < elem2)
        return findKthElem(nums1, nums2, start1 + k / 2, start2, k - k / 2);
    else
        return findKthElem(nums1, nums2, start1, start2 + k / 2, k - k / 2);
}

double solve(VI &nums1, VI &nums2){
    int total = nums1.size() + nums2.size();
    if(total % 2 == 0){
        return (findKthElem(nums1, nums2, 0, 0, total / 2) + findKthElem(nums1, nums2, 0, 0, total / 2 + 1)) / 2.0;
    }else{
        return findKthElem(nums1, nums2, 0, 0, total / 2 + 1);
    }
	return 0;
}

int main(){
    freopen("1-input", "r", stdin); 
    // freopen("2-output", "w", stdout); 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
        int m, n;
	    scanf("%d %d", &m, &n);
        VI nums1(m);
		FOR(i, 0, m){
			scanf("%d", &nums1[i]);
		}
        VI nums2(n);
		FOR(i, 0, n){
			scanf("%d", &nums2[i]);
		}
		double output = solve(nums1, nums2);
		double expected;
        scanf("%lf", &expected);
    	printf("testcase: %d output:%lf expected:%lf result:%s \n", t, output, expected, output==expected ? "true" : "false");
	}
	return 0;
}



