#include <iostream>
#include <queue>
using namespace std;
class StackUsingOneQueue {
private:
    queue<int> q;

public:
    void push(int value) {
        int n = q.size();
        q.push(value);
        for(int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if(q.empty()) return;
        q.pop();
    }

    int top() {
        if(q.empty()) return -1;
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        queue<int> temp = q;
        while(!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingOneQueue stack;
    int choice, value;
    do {
        cin >> choice;
        switch(choice) {
            case 1: cin >> value; stack.push(value); break;
            case 2: stack.pop(); break;
            case 3: cout << stack.top() << endl; break;
            case 4: stack.display(); break;
            case 5: cout << stack.isEmpty() << endl; break;
        }
    } while(choice != 0);
    return 0;
}
