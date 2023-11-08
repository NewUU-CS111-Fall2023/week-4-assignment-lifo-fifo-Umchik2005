#include <iostream>

struct Node {
  int data;
  Node *next;
};

class Stack {
    private:
    Node *initially;

    public:
    Stack() {
        initially = nullptr;
        }

    void push(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = initially;
        initially = newNode;
    }

    int pop() {
        if (initially == nullptr) {
        std::cout << "Stack is empty." << "\n";
        return -1;
        }

        Node *tmp = initially;
        int data = tmp->data;
        initially = initially->next;
        delete tmp;

        return data;
    }

    int top() {
    if (initially == nullptr) {
        std::cout << "Stack is empty." << "\n";
        return -1;
    }

        return initially->data;
    }

    bool isEmpty() {
        return initially == nullptr;
    }
};

int main() {
  Stack numbers;
  numbers.push(123);
  numbers.push(456);
  numbers.push(789);
  std::cout << numbers.top() << std::endl;
  numbers.pop();
  std::cout << numbers.top() << std::endl;
  numbers.pop();
  std::cout << numbers.top() << std::endl;
  numbers.pop();
  std::cout << numbers.isEmpty() << std::endl; // 1 -> true 0 -> false
  return 0;
}