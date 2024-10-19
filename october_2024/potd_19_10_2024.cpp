//Nearest multiple of 10


class Solution {
public:
string roundToNearest(string str) {
        // Complete the function
        int n = str.length();
        
        // Check the last digit to determine rounding
        if (str[n-1] <= '5') {
            // Round down by setting the last digit to '0'
            str[n-1] = '0';
            return str;
        }
        // Round up
        str[n-1] = '0';  // Set last digit to '0'
        int i = n - 2;    // Start from the second last digit
        
        // Handle carry-over in case of '9'
        while (i >= 0 && str[i] == '9') {
            str[i] = '0'; // Set all '9's to '0'
            i--;
        }

        // If all digits were '9', prepend '1'
        if (i < 0) {
            str = '1' + str;
        } else {
            // Increase the current digit
            str[i]++;
        }

        return str;
    }
};
