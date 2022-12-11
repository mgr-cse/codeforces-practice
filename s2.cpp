//https://codeforces.com/problemset/problem/1773/E

#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<tuple<int,int,int>> block;
    for(int i=0; i<n; i++)
    {
        int m;
        cin >> m;
        for(int j=0; j<m; j++)
        {
            int num;
            cin >> num;
            block.push_back({num, i, j});
        }
    }
    sort(block.begin(), block.end());

    int s=0, c=0;
    vector<int> seen(n, 0);
    seen[get<1>(block[0])] = 1; 
    for(int i=1; i<block.size(); i++)
    {
        
        // contigous blocks
        if(get<1>(block[i])==get<1>(block[i-1]) &&
           get<2>(block[i])==(get<2>(block[i-1])+1));
            //do nothing

        else {
            // not contigous, a combine must have been done
            c++;
            // if tower already seen, it must have split
            if(seen[get<1>(block[i])]==1) s++;
        }
        seen[get<1>(block[i])] = 1;
    }
    
    cout << s << " " << c << endl;
}