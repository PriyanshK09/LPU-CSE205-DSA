#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> max_heap;
    vector<int> scores;
    int score;

    // Input the scores
    while (cin >> score) {
        scores.push_back(score);
    }

    // Insert the scores into the max heap
    for (int i = 0; i < scores.size(); i++) {
        max_heap.push(scores[i]);
    }

    // Output the scores in max heap order
    while (!max_heap.empty()) {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }

    return 0;
}
