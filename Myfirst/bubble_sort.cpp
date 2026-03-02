#include <bits/stdc++.h>
using namespace std;

// A simple class encapsulating bubble sort for a vector of integers.
class BubbleSorter {
public:
    // Sort the vector in-place using bubble sort algorithm.
    // Takes a reference to a vector<int> and returns nothing.
    static void sort(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - 1 - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break; // early exit if already sorted
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // generate 10 random integers between 0 and 99
    std::mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, 99);

    vector<int> data(10);
    for (int &x : data) {
        x = dist(rng);
    }

    cout << "Original array:\n";
    for (int x : data) cout << x << " ";
    cout << "\n";

    // sort using our BubbleSorter
    BubbleSorter::sort(data);

    cout << "Sorted array:\n";
    for (int x : data) cout << x << " ";
    cout << "\n";

    return 0;
}
