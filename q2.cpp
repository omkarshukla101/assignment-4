#include <iostream>
using namespace std;
class CircularQueue {
private:
    int* queueArray;
    int frontIndex, rearIndex, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        queueArray = new int[capacity];
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty() { return frontIndex == -1; }
    bool isFull() { return ((rearIndex + 1) % capacity) == frontIndex; }

    void enqueue(int value) {
        if(isFull()) return;
        if(isEmpty()) frontIndex = 0;
        rearIndex = (rearIndex + 1) % capacity;
        queueArray[rearIndex] = value;
    }

    void dequeue() {
        if(isEmpty()) return;
        if(frontIndex == rearIndex) frontIndex = rearIndex = -1;
        else frontIndex = (frontIndex + 1) % capacity;
    }

    void peek() {
        if(isEmpty()) return;
        cout << queueArray[frontIndex] << endl;
    }

    void display() {
        if(isEmpty()) return;
        int i = frontIndex;
        while(true) {
            cout << queueArray[i] << " ";
            if(i == rearIndex) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cin >> size;
    CircularQueue queue(size);

    do {
        cin >> choice;
        switch(choice) {
            case 1: cin >> value; queue.enqueue(value); break;
            case 2: queue.dequeue(); break;
            case 3: queue.peek(); break;
            case 4: queue.display(); break;
            case 5: cout << queue.isEmpty() << endl; break;
            case 6: cout << queue.isFull() << endl; break;
        }
    } while(choice != 0);

    return 0;
}
