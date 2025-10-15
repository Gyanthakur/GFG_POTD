/* Nth Natural Number
Given a positive integer n. You have to find nth natural number after removing all the numbers containing the digit 9.

Examples :

Input: n = 8
Output: 8
Explanation: After removing natural numbers which contains digit 9, first 8 numbers are 1,2,3,4,5,6,7,8 and 8th number is 8.

Input: n = 9
Output: 10
Explanation: After removing natural numbers which contains digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10 and 9th number is 10. */
#include <iostream>
using namespace std;

class Solution
{
public:
    int findNthNaturalNumber(int n)
    {
        int count = 0;   // Counter for valid numbers
        int current = 1; // Current number to check

        while (count < n)
        {
            // Convert current number to string and check if it contains '9'
            if (to_string(current).find('9') == string::npos)
            {
                count++; // Valid number found
            }
            current++; // Move to the next number
        }

        return current - 1; // Return the last valid number found
    }
};

int main()
{
    Solution obj;

    cout << "The 8th natural number (excluding 9s) is: " << obj.findNthNaturalNumber(8) << endl; // Output: 8
    cout << "The 9th natural number (excluding 9s) is: " << obj.findNthNaturalNumber(9) << endl; // Output: 10

    return 0;
}