#include <iostream>
using namespace std;

// Base class (Abstraction + Inheritance)
class StackBase {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void peek() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

// Derived class (Encapsulation + Implementation)
class Stack : public StackBase {
private:
    int *arr;
    int top;
    int size;

public:
    // Constructor
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    // Push element
    void push(int value) override {
        if (isFull()) {
            cout << "Stack is FULL!\n";
        } else {
            arr[++top] = value;
            cout << "Pushed: " << value << endl;
        }
    }

    // Pop element
    void pop() override {
        if (isEmpty()) {
            cout << "Stack is EMPTY!\n";
        } else {
            cout << "Popped: " << arr[top--] << endl;
        }
    }

    // Peek (top element)
    void peek() override {
        if (isEmpty()) {
            cout << "Stack is EMPTY!\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Check empty
    bool isEmpty() override {
        return (top == -1);
    }

    // Check full
    bool isFull() override {
        return (top == size - 1);
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

// Main function
int main() {
    int size, choice, value;

    cout << "Enter stack size: ";
    cin >> size;

    Stack s(size);

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check Empty\n5. Check Full\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is EMPTY\n";
            else
                cout << "Stack is NOT EMPTY\n";
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is FULL\n";
            else
                cout << "Stack is NOT FULL\n";
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}