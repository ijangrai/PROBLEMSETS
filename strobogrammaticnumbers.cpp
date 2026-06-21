#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll l, u, strobo;
int ans = 0;

void basecase() {
    if(0 >= l && 0 <= u) ans++;
    if(1 >= l && 1 <= u) ans++;
    if(8 >= l && 8 <= u) ans++;
}

void strob(ll n)  {
    if(n >= l && n <= u) ans++;
}

void rec(int n, string t1, string t2, int sz)  {
    if(n == sz)  {
        reverse(t2.begin(), t2.end());

        strob(stoll(t1 + t2));
        strob(stoll(t1+'0'+t2));
        strob(stoll(t1+'1'+t2));
        strob(stoll(t1+'8'+t2));
        // cout << t1 << t2 << '\n';
        // cout << t1 << '0' << t2 << '\n';
        // cout << t1 << '1' << t2 << '\n';
        // cout << t1 << '8' << t2 << '\n';

        reverse(t2.begin(), t2.end());
        

        return;
    }

    rec(n + 1, t1 + '1', t2 + '1', sz);
    
    if(!t1.empty()) rec(n + 1, t1 + '0', t2 + '0', sz);
    rec(n + 1, t1 + '8', t2 + '8', sz);
    rec(n + 1, t1 + '6', t2 + '9', sz);
    rec(n + 1, t1 + '9', t2 + '6', sz);
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin  >> l >> u;
    ll n = l, m = u;
    int cnt1 = 0, cnt2 = 0;
    
    while(n > 0) {
        n /= 10;
        cnt1++;
    }
    while(m > 0) {
        m /= 10;
        cnt2++;
    }

    basecase();

    rec(0, "", "", 1);
    rec(0, "", "", 2);
    rec(0, "", "", 3);
    rec(0, "", "", 4);
    rec(0, "", "", 5);
    rec(0, "", "", 6);
    rec(0, "", "", 7);

    cout << ans;


    return 0;
}