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
        std::cin >> querySize;

        int l, r, i = 0;
        Query q[querySize];

        // Input all the queries (1-based indexing)
        while (i < querySize) {
            std::cin >> l >> r;
            l--;
            r--; // Adjust for 0-based indexing

            q[i].l = l;
            q[i].r = r;
            q[i].idx = i;

            i++;
        }

        // Sort the queries
        std::sort(q, q + querySize, compare);

        // Initialize result array and pointers
        std::vector<int> ans(querySize);
        int currL = 0, currR = -1, currAns = 0;

        for (int i = 0; i < querySize; i++) {
            l = q[i].l;
            r = q[i].r;

            // Add elements to current range
            while (currL > l) {
                currL--;
                currAns += arr[currL];
            }
            while (currR < r) {
                currR++;
                currAns += arr[currR];
            }

            // Remove elements from previous range
            while (currL < l) {
                currAns -= arr[currL];
                currL++;
            }
            while (currR > r) {
                currAns -= arr[currR];
                currR--;
            }

            ans[q[i].idx] = currAns;
        }

        // Output query results
        for (int i = 0; i < querySize; i++) {
            std::cout << "Sum of " << q[i].l + 1 << " to " << q[i].r + 1 << " -> " << ans[i] << std::endl;
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
