#include <iostream>
using namespace std;

class DualQueue {
private:
    int* arr;
    int capacity;
    int front1, rear1, front2, rear2, size1, size2;

public:
    DualQueue(int maxSize) : capacity(maxSize), size1(0), size2(0) {
        arr = new int[capacity];
        front1 = 0;
        rear1 = -1;
        front2 = capacity - 1;
        rear2 = capacity;
    }

    void enqueue1(int value) {
        if (size1 + size2 == capacity) {
            cout << "Queues are full!" << endl;
            return;
        }
        rear1 = (rear1 + 1) % capacity;
        arr[rear1] = value;
        size1++;
    }

    void enqueue2(int value) {
        if (size1 + size2 == capacity) {
            cout << "Queues are full!" << endl;
            return;
        }
        rear2 = (rear2 - 1 + capacity) % capacity;
        arr[rear2] = value;
        size2++;
    }

    void dequeue1() {
        if (size1 == 0) {
            cout << "Queue 1 is empty!" << endl;
            return;
        }
        front1 = (front1 + 1) % capacity;
        size1--;
    }

    void dequeue2() {
        if (size2 == 0) {
            cout << "Queue 2 is empty!" << endl;
            return;
        }
        front2 = (front2 - 1 + capacity) % capacity;
        size2--;
    }

    int frontQueue1() {
        return size1 == 0 ? -1 : arr[front1];
    }

    int frontQueue2() {
        return size2 == 0 ? -1 : arr[front2];
    }

    bool isEmpty1() {
        return size1 == 0;
    }

    bool isEmpty2() {
        return size2 == 0;
    }

    ~DualQueue() {
        delete[] arr;
    }
};

int main() {
    DualQueue dq(100);

    dq.enqueue1(10);
    dq.enqueue1(20);

    dq.enqueue2(30);
    dq.enqueue2(40);

    while (!dq.isEmpty1()) {
        cout << "Queue 1: " << dq.frontQueue1() << endl;
        dq.dequeue1();
    }

    while (!dq.isEmpty2()) {
        cout << "Queue 2: " << dq.frontQueue2() << endl;
        dq.dequeue2();
    }

    return 0;
}
