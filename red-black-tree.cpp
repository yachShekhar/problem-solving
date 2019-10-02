#include <bits/stdc++.h>

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

const bool RED = true, BLACK = false;
class Node {
    public:
        int key;
        Node *left, *right;
        bool color;
        Node(int key, Node *left, Node *right, bool color) {
            this->key = key;
            this->left = left;
            this->right = right;
            this->color = color;
        }
};

class BST {
    Node *root = NULL;
    private:
        bool isRed(Node *node) {
            return node == NULL ? BLACK : node->color; 
        }
        Node* search(int key, Node *node) {
           if(node == NULL) return NULL;
           if(key == node->key){
               return node;
           } else if(key < node->key) {
               return search(key, node->left);
           } else{
               return search(key, node->right);
           }
        };
        Node* insert(int key, Node *node) {
            if(node == NULL){
                node = new Node(key, NULL, NULL, RED);
            }
            if(key < node->key) {
               node->left = insert(key, node->left);
            } else if(key > node->key) {
               node->right = insert(key, node->right);
            }
            if(isRed(node->right) && !isRed(node->left)) {
                node = rotateLeft(node);
            }
            if(isRed(node->left) && node->left != NULL && isRed(node->left->left)){
                node = rotateRight(node);
            }
            if(isRed(node->left) && isRed(node->right)) {
                node = flipColors(node);
            }
            return node;
        };

        Node* rotateLeft(Node *node) {
            Node *x = node->right;
            node->right = x->left;
            x->left = node;
            x->color = node->color;
            node->color = RED;
            return x;
        };

        Node* rotateRight(Node *node) {
            Node *x = node->left;
            node->left = x->right;
            x->right = node;
            x->color = node->color;
            node->color = RED;
            return x;
        };

        Node* flipColors(Node *node) {
            node->left->color = BLACK;
            node->right->color = BLACK;
            node->color = RED;
            return node;
        };
    public:
        void insert(int key) {
            root = insert(key, root);
        }

        Node* search(int key) {
            return search(key, root);
        }

        BST(){

        }
};

int solve(vector<int> &v, int searchKey){
    BST *bst = new BST();
    for(int i = 0; i < v.size(); i++) {
        bst->insert(v[i]);
    }
	return bst->search(searchKey)->key;
}

int solve(){
	int l, s;
	scanf("%d %d", &l, &s);
	vector<int> v(l);
	for(int i = 0; i < l; i++){
		scanf("%d", &v[i]);
	}
	return solve(v, s);
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
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

