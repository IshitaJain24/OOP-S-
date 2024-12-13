#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T value) {
        if (top == capacity - 1) {
            throw overflow_error("Stack Overflow");
        }
        arr[++top] = value;
    }

    T pop() {
        if (top == -1) {
            throw underflow_error("Stack Underflow");
        }
        return arr[top--];
    }

    T peek() {
        if (top == -1) {
            throw underflow_error("Stack Underflow");
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack<int> stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}
