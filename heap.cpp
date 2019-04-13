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

class MaxHeap {
    vector<int> list;
    public:
        bool empty(){
            return list.empty();
        }
        //insert multiple node
        void insert(const vector<int> &v){
            list.insert(list.end(), v.begin(), v.end());
            heapify();
        }
        //insert only one node 
        void insert(int e){
            list.push_back(e);
            int i = list.size() - 1;
            int ip = ceil((i - 1)/2);
            while(i >= 0 && ip >=0 &&  list[ip] < list[i]){
                swap(ip, i);
                i = ceil((i - 1)/2);
                ip = ceil((i - 1)/2);
            }
        };

        //remove only one node
        int remove(){
            int e;
            if(!list.empty()){
                e = list[0];
                list[0] = list[list.size() - 1];
                list.erase(list.begin() + list.size() - 1);;
            }
            int i = 0;
            int lsize = list.size();

            while(2 * i + 2 < lsize && list[i] < MAX(list[2 * i + 1], list[2 * i + 2])){
                if(list[2 * i + 1] > list[2 * i + 2]){
                    swap(i, 2 * i + 1);
                    i = 2 * i + 1;
                }else{
                    swap(i, 2 * i + 2);
                    i = 2 * i + 2;
                }
            }
            while(2 * i + 1 < lsize && list[i] < list[2 * i + 1]){
                swap(i, 2 * i + 1);
                i = 2 * i + 1;
            }
            
            return e;
        }

    private:
        void swap(int li, int ri){
            int tmp = list[li];
            list[li] = list[ri];
            list[ri] = tmp;
            // cout<<"li: "<<li<<" ri: "<<ri<<" list[li]: "<<list[li]<<" list[ri]: "<<list[ri]<<endl;
        }
        void heapify(){
            int lsize = list.size();
            ROF(j, list.size() - 1, -1){
                int i = j;
                //both left and right child is present
                while(2 * i + 2 < lsize && list[i] < MAX(list[2 * i + 1], list[2 * i + 2])){
                    if(list[2 * i + 1] > list[2 * i + 2]){
                        swap(i, 2 * i + 1);
                        i = 2 * i + 1;
                    }else{
                        swap(i, 2 * i + 2);
                        i = 2 * i + 2;
                    }
                }
                 //only left child is present
                while(2 * i + 1 < lsize && list[i] < list[2 * i + 1]){
                    swap(i, 2 * i + 1);
                    i = 2 * i + 1;
                }
            }
        }
};


class MinHeap {
    vector<int> list;
    public:
        bool empty(){
            return list.empty();
        }
        //insert multiple node
        void insert(const vector<int> &v){
            list.insert(list.end(), v.begin(), v.end());
            heapify();
        }
        //insert only one node 
        void insert(int e){
            list.push_back(e);
            int i = list.size() - 1;
            int ip = ceil((i - 1)/2);
            while(i >= 0 && ip >=0 &&  list[ip] > list[i]){
                swap(ip, i);
                i = ceil((i - 1)/2);
                ip = ceil((i - 1)/2);
            }
        };

        //remove only one node
        int remove(){
            int e;
            if(!list.empty()){
                e = list[0];
                list[0] = list[list.size() - 1];
                list.erase(list.begin() + list.size() - 1);;
            }
            int i = 0;
            int lsize = list.size();

            while(2 * i + 2 < lsize && list[i] > MIN(list[2 * i + 1], list[2 * i + 2])){
                if(list[2 * i + 1] < list[2 * i + 2]){
                    swap(i, 2 * i + 1);
                    i = 2 * i + 1;
                }else{
                    swap(i, 2 * i + 2);
                    i = 2 * i + 2;
                }
            }
            while(2 * i + 1 < lsize && list[i] > list[2 * i + 1]){
                swap(i, 2 * i + 1);
                i = 2 * i + 1;
            }
            
            return e;
        }

    private:
        void swap(int li, int ri){
            int tmp = list[li];
            list[li] = list[ri];
            list[ri] = tmp;
            // cout<<"li: "<<li<<" ri: "<<ri<<" list[li]: "<<list[li]<<" list[ri]: "<<list[ri]<<endl;
        }
        void heapify(){
            int lsize = list.size();
            ROF(j, list.size() - 1, -1){
                int i = j;
                //both left and right child is present
                while(2 * i + 2 < lsize && list[i] > MIN(list[2 * i + 1], list[2 * i + 2])){
                    if(list[2 * i + 1] < list[2 * i + 2]){
                        swap(i, 2 * i + 1);
                        i = 2 * i + 1;
                    }else{
                        swap(i, 2 * i + 2);
                        i = 2 * i + 2;
                    }
                }
                while(2 * i + 1 < lsize && list[i] > list[2 * i + 1]){
                    swap(i, 2 * i + 1);
                    i = 2 * i + 1;
                }
            }
        }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	MinHeap mh;
    int n;
    cin>>n;
    vector<int> v;
    while(n--){
        int i;
        cin>>i;
        v.push_back(i);
        mh.insert(i);
    }
    // mh.insert(v);
    while(!mh.empty()){
        cout<<mh.remove()<<" ";
    }
	return 0;
}
