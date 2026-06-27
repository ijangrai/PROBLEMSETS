#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int l, lim1 = 0, lim2 = 0, n1, n2, cnt = 0;
char c1, c2;
string s  =  "";

void rec(int i) {
    if(lim2 > lim1 || lim1 > l/2) return;

    if(i == l) {

        if(s[0] == c1) {

            for(int i = 0; i < l; i++) {
                cnt += ((int)s[i] - 64)*(i + 1);
            }
            // cout << s << '\n';

        }
        
        return;
    }

    s += c1;
    lim1++;
    rec(i + 1);
    lim1--;
    s.pop_back();


    s  += c2;
    lim2++;
    rec(i + 1);
    lim2--;
    s.pop_back();
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> l >> c1 >> c2;

    l *= 2;
    

    rec(0);
    cout << cnt;

    // char t = 'A';
    // cout << (int)'B'-64;


    
    return 0;
}