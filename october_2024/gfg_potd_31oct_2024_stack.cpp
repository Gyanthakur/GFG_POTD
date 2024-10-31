#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        } else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }

    int top() const {
        if (!data.empty()) {
            return data.back();
        }
        std::cerr << "Stack is empty!" << std::endl;
        return -1; // or any error code
    }

    bool isEmpty() const {
        return data.empty();
    }

    int size() const {
        return data.size();
    }

    void display() const {
        if (data.empty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = data.size() - 1; i >= 0; i--) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Top\n";
        std::cout << "4. Check if Empty\n";
        std::cout << "5. Get Size\n";
        std::cout << "6. Display Stack\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                std::cout << "Top element: " << stack.top() << std::endl;
                break;
            case 4:
                std::cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << std::endl;
                break;
            case 5:
                std::cout << "Stack size: " << stack.size() << std::endl;
                break;
            case 6:
                stack.display();
                break;
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 7);

    return 0;
}
