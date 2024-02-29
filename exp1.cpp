#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseArray(vector<int> A) {
    int start = 0;
    int end = A.size() - 1;

    // Swap elements from the start and end until they meet in the middle
    while (start < end) {
        swap(A[start], A[end]);
        start++;
        end--;
    }

    return A;
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> A(N);

    cout << "Enter " << N << " integers:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> result = reverseArray(A);

    cout << "Reversed array:" << endl;
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}


