#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &q) {
    if(q.empty()) return;

    int n = q.size();
    int half = n / 2;
    stack<int> s;

    // Push first half into stack
    for(int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue back the stack elements
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Move the first half to the back to restore order
    for(int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

    // Push first half into stack again
    for(int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // Interleave stack and remaining queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, value;
    cin >> n; // Number of elements
    for(int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    interleaveQueue(q);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
