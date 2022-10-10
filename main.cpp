#include <bits/stdc++.h>
using namespace std;
bool a[10000001];
bool b[10000001];
void solve(bool a[], bool b[], long long n, long long m, long long k) {
    for (int i=1;i<=n;i++) {
        if (a[i]==true) {
            if (i-k<1) {
                b[i+k]=true;
                b[n-k+i]=true;
            }
            else if (i+k>n) {
                b[k-(n-i)]=true;
                b[i-k]=true;
            }
            else {
                b[i+k]=true;
                b[i-k]=true;
            }
        }
    }
}
int main() {        
    long long n,m,k,t;
    cin >> n;
    cin >> m;
    cin >> k;
    cin >> t;
    for (int i=0;i<m;i++) {
        int x; 
        cin >> x;
        a[x]=true;
    }
    for (int i=1;i<=t;i++) {
        if (i%2!=0) solve(a,b,n,m,k);
        else solve(b,a,n,m,k);
    }
    int count=0;
    if (t%2==0) {
        for (int i=1;i<=n;i++) {
            if (a[i]==true) count++;
        }
    }
    else {
        for (int i=1;i<=n;i++) {
            if (b[i]==true) count++;
        }
    }
    cout << count;
}