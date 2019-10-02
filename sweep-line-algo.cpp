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

#define first x;
#define second y;
typedef pair<int, int> PII;

class Line {
    public :
        PII left;
        PII right;
        Line(PII left, PII right){
            this->left = left;
            this->right = right;
        }
};

map<PII, Line*> cache;
void intersection(vector<Line*> &line) {
    vector<PII> q;
    for(int i = 0; i < line.size(); i++) {
        q.push_back(line.at(i)->left);
        q.push_back(line.at(i)->right);
        cache[line.at(i)->right] = line.at(i);
    }
    sort(q.begin(), q.end(), less<int>());
    for(int i = 0; i < q.size(); i++) {
        PII point = q.at(i);
    }
}

int main() {
    Line *AC = new Line(make_pair(1, 4), make_pair(5, 2));
    Line *BD = new Line(make_pair(2, 1), make_pair(7, 7));
    vector<Line*> line(2);
    line[0] = AC;
    line[1] = BD;
    intersection(line);
    return 0;
}
