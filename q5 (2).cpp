#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int capacity;
    int front, rear;
    int size;

public:
    CircularQueue(int maxSize) : capacity(maxSize), front(0), rear(-1), size(0) {
        arr = new int[capacity];
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to reverse the circular queue
    void reverseQueue() {
        if (isEmpty()) {
            cout << "Queue is empty, nothing to reverse!" << endl;
            return;
        }

        int* temp = new int[size];  // Temporary array to store reversed elements
        int index = 0;

        // Store elements in reverse order from rear to front
        for (int i = size - 1; i >= 0; --i) {
            temp[index++] = arr[(front + i) % capacity];
        }

        // Copy reversed elements back to the original queue
        index = 0;
        for (int i = 0; i < size; ++i) {
            arr[(front + i) % capacity] = temp[index++];
        }

        delete[] temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    cout << "Original Queue: ";
    cq.display();

    cq.reverseQueue();

    cout << "Reversed Queue: ";
    cq.display();

    return 0;
}
