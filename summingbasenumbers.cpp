#include<bits/stdc++.h>
using namespace std;

map<char, int> p;
map<int, string> q;
string n1 = "12A", n2 = "321";
int base=16, sum = 0, a, b, t = -1, c, r;


void b10(string n, int i, int &t) {
    if(n.empty()) {
        // cout << sum;

        t = sum;
        sum = 0;
        return;
    }
    
    int digit = p[n[n.length()-1]];
    sum += digit*(pow(base, i));
    n.pop_back();

    // cout << n1 << '\n';

    b10(n, i+1, t);
}

void rev(int n, string result) {
    if(n == 0 && !result.empty()) {
        reverse(result.begin(), result.end());
        cout << result;

        return;
    }

    r = n % base;

    rev(n/base, result + q[r]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    p['0']=0; q[0]="0";
    p['1']=1; q[1]="1";
    p['2']=2; q[2]="2";
    p['3']=3; q[3]="3";
    p['4']=4; q[4]="4";
    p['5']=5; q[5]="5";
    p['6']=6; q[6]="6";
    p['7']=7; q[7]="7";
    p['8']=8; q[8]="8";
    p['9']=9; q[9]="9";
    p['A']=10; q[10]="A";
    p['B']=11; q[11]="B";
    p['C']=12; q[12]="C";
    p['D']=13; q[13]="D";
    p['E']=14; q[14]="E";
    p['F']=15; q[15]="F";

    cin >> base >> n1 >> n2;

    b10(n1, 0, t);
    a = t;
    
    b10(n2, 0, t);
    b = t;
    
    c = a + b;

    rev(c, "");
    
    return 0;
}