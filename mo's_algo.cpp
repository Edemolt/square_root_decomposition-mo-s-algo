#include <bits/stdc++.h>
using namespace std;

int blockSize;

struct Query {
    int l, r, idx;
};

const bool compare(Query q1, Query q2) {
    if ((q1.l) / blockSize != (q2.l) / blockSize) return (q1.l) / blockSize < (q2.l) / blockSize;
    else return q1.r < q2.r;
}

class Mo {
public:
    vector<int> arr;
    
    Mo(std::vector<int>& arr) {
        this->arr = arr;
        blockSize = sqrt(arr.size()) + 1; // Calculate block size
    }

    // Sort according to blocks and then r values within the same block

    void query() {
        int querySize;
        cin >> querySize;

        int l, r, i = 0;
        Query q[querySize];

        // Input all the queries (1-based indexing)
        while (i < querySize) {
            cin >> l >> r;
            l--;
            r--; // Adjust for 0-based indexing

            q[i].l = l;
            q[i].r = r;
            q[i].idx = i;

            i++;
        }

        // Sort the queries
        sort(q, q + querySize, compare);

        // Initialize result array and pointers
        vector<int> ans(querySize);
        int curr_left = 0, curr_right = -1, curr_ans = 0;

        for (int i = 0; i < querySize; i++) {
            l = q[i].l;
            r = q[i].r;

            // Add elements to current range
            while (curr_ans > l) {
                curr_left--;
                curr_ans += arr[curr_left];
            }
            while (curr_right < r) {
                curr_right++;
                curr_ans += arr[curr_right];
            }

            // Remove elements from previous range
            while (curr_left < l) {
                curr_ans -= arr[curr_left];
                curr_left++;
            }
            while (curr_right > r) {
                curr_ans -= arr[curr_right];
                curr_right--;
            }

            ans[q[i].idx] = curr_ans;
        }

        // Output query results
        for (int i = 0; i < querySize; i++) {
            cout << "Sum of " << q[i].l + 1 << " to " << q[i].r + 1 << " -> " << ans[i] << std::endl;
        }
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    Mo obj(arr);
    obj.query();
}

int main() {
    solve();
    return 0;
}
