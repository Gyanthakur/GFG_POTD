// https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1

class Solution {
    String roundToNearest(String str) {
        char[] numArr = str.toCharArray();
        int n = numArr.length;

        if (numArr[n - 1] <= '5') {
            numArr[n - 1] = '0';
        } else {
            numArr[n - 1] = '0';
            int i = n - 2;
            boolean flag = false;

            while (i >= 0) {
                if (numArr[i] == '9') {
                    numArr[i] = '0';
                } else {
                    numArr[i]++;
                    flag = true;
                    break;
                }
                i--;
            }

            if (!flag) {
                return '1' + new String(numArr);
            }
        }

        return new String(numArr);
    }
}