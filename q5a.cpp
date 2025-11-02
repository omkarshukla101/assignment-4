#include <iostream>
#include <queue>
using namespace std;
class StackUsingQueues {
private:
    queue<int> queue1, queue2;

public:
    void push(int value) {
        while(!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        queue1.push(value);

        while(!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }
    }

    void pop() {
        if(queue1.empty()) return;
        queue1.pop();
    }

    int top() {
        if(queue1.empty()) return -1;
        return queue1.front();
    }

    bool isEmpty() {
        return queue1.empty();
    }

    void display() {
        queue<int> temp = queue1;
        while(!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingQueues stack;
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
