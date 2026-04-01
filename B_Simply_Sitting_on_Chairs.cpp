#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> pref_safe(n + 2, 0);

    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
        // A chair is "safe" if sitting on it doesn't block the future
        pref_safe[i] = pref_safe[i - 1] + (p[i] <= i ? 1 : 0);
    }

    int max_chairs = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (p[i] > i)
        {
            // If we sit on this 'trap' chair, we can also sit on all
            // safe chairs that appear before index p[i].
            // We sit on i (the trap) + safe chairs before p[i] (excluding i if i was safe).
            int current_total = 1 + pref_safe[p[i] - 1];
            // If chair i itself was safe (p[i] <= i), it's already in the prefix sum.
            // But here i is a trap (p[i] > i), so it's not in pref_safe.
            max_chairs = max(max_chairs, current_total);
        }
    }

    // Also consider the case where we sit ONLY on safe chairs and never sit on a trap
    max_chairs = max(max_chairs, pref_safe[n]);

    cout << max_chairs << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}