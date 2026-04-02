#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mid = n / 2;
        
        cout << mid;
        for(int i = n; i > mid; i--)
            cout << " " << i;
        for(int i = mid - 1; i >= 1; i--)
            cout << " " << i;
        cout << "\n";
    }
    return 0;
}
