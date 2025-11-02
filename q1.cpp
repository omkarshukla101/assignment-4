#include <iostream>
using namespace std;
class Queue{
private:
    int* queueArray;
    int frontIndex, rearIndex, capacity;

public:
        Queue(int size) {
        capacity = size;
        queueArray = new int[capacity];
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty() {
        return frontIndex == -1;
    }

    bool isFull() {
        return rearIndex == capacity - 1;
    }

    void enqueue(int value) {
        if(isFull()) {
            cout << "Queue is full.\n";
            return 0;
        }
        if(isEmpty()) frontIndex = 0;
        rearIndex++;
        queueArray[rearIndex] = value;
        cout << value << " enqueued.\n";
    }

    void dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty.\n";
            return 0;
        }
        cout << queueArray[frontIndex] << " dequeued.\n";
        if(frontIndex == rearIndex) {
            frontIndex = rearIndex = -1;
        } else {
            frontIndex++;
        }
    }

    void peek() {
        if(isEmpty()) {
            cout << "Queue is empty.\n";
            return 0;
        }
        cout << "Front element: " << queueArray[frontIndex] << endl;
    }

    void display() {
        if(isEmpty()) {
            cout << "Queue is empty.\n";
            return 0;
        }
        cout << "Queue elements: ";
        for(int i = frontIndex; i <= rearIndex; i++)
            cout << queueArray[i] << " ";
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter size of queue: ";
    cin >> size;
    Queue queue(size);

    do {
        cout << "Queue:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Enter value to enqueue: "; cin >> value; queue.enqueue(value); break;
            case 2: queue.dequeue(); break;
            case 3: queue.peek(); break;
            case 4: queue.display(); break;
            case 5: cout << (queue.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n"); break;
            case 6: cout << (queue.isFull() ? "Queue is full.\n" : "Queue is not full.\n"); break;
            case 0: cout <<  break;
            default: cout << "Invalid choice!\n"; 
        }
    } while(choice != 0);

    return 0;
}
