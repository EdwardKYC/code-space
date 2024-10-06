#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    unordered_set<int> playlist; 
    int left = 0, max_len = 0;

    for (int right = 0; right < n; right++) {
        while (playlist.find(songs[right]) != playlist.end()) {
            playlist.erase(songs[left]);
            left++; 
        }
        playlist.insert(songs[right]);
        max_len = max(max_len, right - left + 1);
    }
    cout << max_len << '\n';

    return 0;
}
    