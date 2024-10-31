#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << item << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
        cout << "Enqueued: " << item << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;
        count--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    int size() {
        return count;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    cout << "Front element: " << queue.getFront() << endl;
    cout << "Rear element: " << queue.getRear() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "After two dequeues:" << endl;
    cout << "Front element: " << queue.getFront() << endl;
    cout << "Rear element: " << queue.getRear() << endl;

    queue.enqueue(60);
    queue.enqueue(70);

    cout << "Queue size: " << queue.size() << endl;

    return 0;
}
