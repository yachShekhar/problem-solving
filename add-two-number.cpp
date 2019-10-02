//https://leetcode.com/problems/add-two-numbers/

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tempHead = nullptr;
        ListNode *NULLOBJ = new ListNode(0);
        NULLOBJ->next = NULL;

        int extra = 0;
        while(l1 != NULL){
            if(l2 == NULL){
                l2 = NULLOBJ;
            }
            int val = l1->val + l2->val + extra;
            extra = 0;
            if(val >= 10){
                extra = val / 10;
                val %= 10;
            }
            ListNode *l3 = new ListNode(val);
            l3->val = val;
            if(tempHead == nullptr){
                head = l3;
                tempHead = head;
            }else{
                head->next = l3;
                head = head->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l2 != NULL){
            if(l1 == NULL){
                l1 = NULLOBJ;
            }
            int val = l1->val + l2->val + extra;
            extra = 0;
            if(val >= 10){
                extra = val / 10;
                val %= 10;
            }
            ListNode *l3 = new ListNode(val);
            l3->val = val;
            if(tempHead == nullptr){
                head = l3;
                tempHead = head;
            }else{
                head->next = l3;
                head = head->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if(extra > 0){
            ListNode *extraNode = new ListNode(extra);
            extraNode->next = NULL;
            head->next = extraNode;
        }
        return tempHead;
    }
};

int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *sol = Solution().addTwoNumbers(l1, l2);

    while(sol != NULL){
        cout<<sol->val<<" ";
        sol = sol->next;
    }
    cout<<endl;
    return 0;
}