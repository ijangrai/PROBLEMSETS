#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int m = 1;

void rec(int n) {
    if(n == 0) {
        
        while(!q.empty()) {

            cout << q.front() << ' ';
            q.pop();
        }

        cout << '\n';
        return;
    }

    if(abs(n) % 5 > 2) {

        q.push((abs(n) % 5 - 5)*m);

        rec(abs(n) / 5 + 1);
    }
    else {

        q.push((abs(n) % 5)*m);

        rec(abs(n) / 5);
    }


}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    
    while(t--) {
        int n; cin >> n;

        if(n == 0) {
            cout << 0 << '\n';
            continue;
        }
        
        m = (n < 0) ? m = -1 : m = 1;
        

        rec(n);
    }

    

    return 0;
}