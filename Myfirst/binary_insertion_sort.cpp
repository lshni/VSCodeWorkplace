#include <iostream>
#include <vector>
using namespace std;

// 在 arr[0..high] 有序的情况下，找到 key 应插入的位置（返回插入索引）
int binarySearchInsertPos(const vector<int>& arr, int low, int high, int iKey) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == iKey)
            return mid + 1;
        else if (arr[mid] < iKey)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void binaryInsertionSort(vector<int>& arr) {
    int iCount = arr.size();
    for (int iIndex = 1; iIndex < iCount; ++iIndex) {
        int iKey = arr[iIndex];
        int iInsertPos = binarySearchInsertPos(arr, 0, iIndex - 1, iKey);
        int iShiftIndex = iIndex - 1;
        while (iShiftIndex >= iInsertPos) {
            arr[iShiftIndex + 1] = arr[iShiftIndex];
            --iShiftIndex;
        }
        arr[iShiftIndex + 1] = iKey;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int iCount;
    if (!(cin >> iCount)) return 0;
    vector<int> vValues(iCount);
    for (int iIndex = 0; iIndex < iCount; ++iIndex) cin >> vValues[iIndex];

    binaryInsertionSort(vValues);

    for (int iIndex = 0; iIndex < iCount; ++iIndex) {
        if (iIndex) cout << ' ';
        cout << vValues[iIndex];
    }
    cout << '\n';
    return 0;
}
