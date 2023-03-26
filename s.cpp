#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> c(n), d(n);
        for(int i=0; i<n; i++) {
            cin >> c[i];
        }
        for(int i=0; i<n; i++) {
            cin >> d[i];
        }
        int max_c = *max_element(c.begin(), c.end()); // maximum element in array c
        int max_d = *max_element(d.begin(), d.end()); // maximum element in array d
        ll ans = (ll)max_c * max_d; // initialize the answer
        for(int i=1; i<=max_c; i++) { // try swapping each element from 1 to max_c
            vector<int> c2 = c, d2 = d; // make a copy of arrays c and d
            for(int j=0; j<n; j++) {
                if(c2[j] == i) { // if c[j] is equal to i, swap it with the corresponding element in d
                    swap(c2[j], d2[j]);
                }
            }
            int new_max_c = *max_element(c2.begin(), c2.end()); // find the new maximum element in c2
            int new_max_d = *max_element(d2.begin(), d2.end()); // find the new maximum element in d2
            ll new_ans = (ll)new_max_c * new_max_d; // calculate the new answer
            ans = min(ans, new_ans); // update the answer if the new answer is smaller
        }
        cout << ans << "\n"; // output the answer
    }
    return 0;
}
