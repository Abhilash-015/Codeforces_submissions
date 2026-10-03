#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // available[c] = whether there is currently a word
        // whose first letter is c.
        bool available[26] = {};

        for (int i = 0; i < n; i++) {
            string w;
            cin >> w;
            available[w[0] - 'a'] = true;
        }

        vector<string> a(m);
        for (auto &s : a)
            cin >> s;

        /*
            An abbreviation can be formed when every character
            in it is currently available.

            We repeatedly search for an abbreviation that can
            be formed. Once formed, its characters become
            available for future abbreviations.
        */

        vector<bool> used(m, false);
        int remaining = m;

        while (remaining > 0) {
            bool progress = false;

            for (int i = 0; i < m; i++) {
                if (used[i])
                    continue;

                bool possible = true;

                for (char c : a[i]) {
                    if (!available[c - 'A']) {
                        possible = false;
                        break;
                    }}

                if (possible) {
                    used[i] = true;
                    remaining--;
                    progress = true;

                    // This abbreviation is now a word,
                    // so its first letter becomes available.
                    available[a[i][0] - 'A'] = true;
                }
            }

            if (!progress)
                break;
        }

        cout << (remaining == 0 ? "YES\n" : "NO\n");
    }

    return 0;
}