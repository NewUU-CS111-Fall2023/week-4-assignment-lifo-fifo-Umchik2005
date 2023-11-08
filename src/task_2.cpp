#include <iostream>
#include <stack>
#include <sstream>


bool ifArrangeTrains(int n, vector<int> trainOrder) {
    stack<int> s;
    int currentCar = 1; 

    for (int i = 0; i < n; i++) {
        if (trainOrder[i] == currentCar) {
            currentCar++;
        } else {
            while (!s.empty() && s.top() == currentCar) {
                s.pop();
                currentCar++;
            }
            s.push(trainOrder[i]);
        }
    }

    while (!s.empty() && s.top() == currentCar) {
        s.pop();
        currentCar++;
    }

    return (currentCar == n + 1);
}

int main() {
    int n;
    std::cin >> n;

    vector<int> trainOrder(n);
    for (int i = 0; i < n; i++)
        std::cin >> trainOrder[i];

    if (ifArrangeTrains(n, trainOrder))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    return 0;
}