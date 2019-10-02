#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sz[2000001];
ll arr[2000001];
ll m[2000001];
ll w[2000001];
ll n, q1, q2, q3, x, y;

void init(ll n) {
    for (ll i = 0; i <= n; i++) {
        arr[i] = i;
        sz[i] = 1;
        if (i <= x) {
            m[i] = 1;
            w[i] = 0;
        } else {
            m[i] = 0;
            w[i] = 1;
        }
    }
}

ll root(ll i) {
    while (arr[i] != i) {
        i = arr[i];
    }
    return i;
}

bool find(ll A, ll B) {
    return root(A) == root(B);
}

void un(ll A, ll B) {
    ll ra = root(A);
    ll rb = root(B);

    if (ra == rb) {
        return;
    }

    if (sz[ra] >= sz[rb]) {
        arr[rb] = ra;
        sz[ra] += sz[rb];
        m[ra] += m[rb];
        w[ra] += w[rb];
    } else {
        arr[ra] = rb;
        sz[rb] += sz[ra];
        m[rb] += m[ra];
        w[rb] += w[ra];
    }
}

int main() {
    cin >> x >> y;
    n = x + y;
    init(n);
    cin >> q1;
    while (q1--) {
        ll a, b;
        cin >> a >> b;
        un(a, b);
    }
    cin >> q2;
    while (q2--) {
        ll a, b;
        cin >> a >> b;
        un(a + x, b + x);
    }
    cin >> q3;
    while (q3--) {
        ll a, b;
        cin >> a >> b;
        un(a, b + x);
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        if (arr[i] == i) {
            ll curr_men = m[i];
            ll remaining_women = y - w[i];
            ans += curr_men * remaining_women;
        }
    }
    cout << ans << endl;
    return 0;
}