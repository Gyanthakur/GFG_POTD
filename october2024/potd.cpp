#include <iostream>
using namespace std;

const int MOD = 1000000007;
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
long long listToNumber(Node* head) {
    long long num = 0;
    while (head != nullptr) {
        num = (num * 10 + head->data) % MOD;
        head = head->next;
    }
    return num;
}
long long multiplyTwoLists(Node* l1, Node* l2) {
    long long num1 = listToNumber(l1);
    long long num2 = listToNumber(l2);
    return (num1 * num2) % MOD;
}
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* L1 = new Node(3);
    L1->next = new Node(2);
    Node* L2 = new Node(2);

    cout << "L1: ";
    printList(L1);
    cout << "L2: ";
    printList(L2);

    long long result = multiplyTwoLists(L1, L2);
    cout << "Multiplication result: " << result << endl;

    delete L1->next;
    delete L1;
    delete L2;

    return 0;
}
