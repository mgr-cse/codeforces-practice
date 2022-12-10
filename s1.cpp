//https://codeforces.com/problemset/problem/492/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    set<int> s;
    for(int i=0; i<n; i++)
    {
        int e;
        cin >> e;
        s.insert(e);
    }

    // case 1
    int max_dist_bw_lamps = 0;
    int prev = *s.begin();
    for(int i:s)
    {
        if(i-prev>max_dist_bw_lamps) max_dist_bw_lamps = i-prev;
        prev = i;
    }

    // case 2
    int dist_start = *s.begin();
    int dist_end = l - *s.rbegin();

    double max_dist_bw_lamps_f = max_dist_bw_lamps/2.0;

    double max_dist = max(dist_start, dist_end);
    max_dist = max(max_dist, max_dist_bw_lamps_f); 
    cout << setprecision(9) << max_dist << endl;
}