//Count ways to N'th Stair(Order does not matter)
#include <iostream>
using namespace std;

class Solution {
  public:
    int countWays(int n) {
        // Maximum number of 2-stair steps possible
        int maxTwoSteps = n / 2;
        return maxTwoSteps + 1; // Count all combinations from y = 0 to y = maxTwoSteps
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter the number of stairs: ";
    cin >> n;

    int result = obj.countWays(n);
    cout << "Number of ways to reach the top: " << result << endl;

    return 0;
}
