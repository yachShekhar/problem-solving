// https://www.hackerrank.com/challenges/taum-and-bday/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=7-day-campaign
#include<fstream>

using namespace std;
int MODULO = 1000000000; 
long taumBday(int b, int w, int bc, int wc, int z) {
    long p = 1L * b * bc + 1L * w * wc;
    long q = 1L * b * bc + 1L * w * (bc + z);
    long r = 1L * b * (wc + z) + 1L * w * wc;
    long l = (q < r ? q : r);
    return p < l ? p : r;
}

int main(int argc, char const *argv[])
{

    long a = taumBday(11152, 43844, 788543, 223872, 972572);
    cout << "sol " << a << endl;
    return 0;
}
